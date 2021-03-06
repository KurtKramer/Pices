using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using SipperFile;

using PicesInterface;


namespace SipperFile
{
  public partial class ImageViewer : Form
  {
    private  PicesClassList         classes        = null;
    private  PicesDataBase          dbConn         = null;
    private  PicesDataBaseImage     image          = null;
    private  PicesRaster            raster         = null;
    private  PicesFeatureVector     featureVector  = null;
    private  PicesRunLog            runLog         = null;
    private  PicesSipperFile        sipperFile     = null;
    private  PicesSipperDeployment  deployment     = null;

    private PicesDataBaseLogEntry extractionLogEntry = null;
    private PicesDataBaseLogEntry classLogEntry      = null;

    private  PicesClass           classUserValidatesAs = null;  // Will only be set if USER validates during this Dialog session.

    private  int      lastHeight = 0;
    private  int      lastWidth  = 0;

    private  int      leftPanelLastHeight = 0;
    private  int      leftPanelLastWidth  = 0;

    private  int      rightPanelLastHeight = 0;
    private  int      rightPanelLastWidth  = 0;

    private  float    zoomFactor = 1.0f;

    private  bool     displayGrid = false;

    
    private  PicesPointList  sizeCoordinates = new PicesPointList ();
    private  float           imageSize = 0.0f;
    private  bool            sizeCoordinatesSelEnabled = false;

    private  const double  pixelsPerScanLineDefault = 3800.0;
    private  const double  chamberWidthDefault      = 0.096f;
    private  const double  mmPerMeter               = 1000.0;
    private  const double  scanRateDefault          = 24950.0;
    private  const double  flowRate1Default         = 0.5;

    private  double  flowRate1    = flowRate1Default;
    private  double  scanRate     = scanRateDefault;
    private  double  chamberWidth = chamberWidthDefault;

    private  double mmPerPixelAccrossChamber = chamberWidthDefault * mmPerMeter / pixelsPerScanLineDefault;
    private  double mmPerPixelWithFlow       = flowRate1Default    * mmPerMeter / scanRateDefault;

    // next set of static fields Specify which data fields are to which data label.  It will be fixed for all instances of ImageViewer.
    private static int[]    dataFieldAssignments = null;
    private static string   configFileName       = null;

    private Label[]    DataLabels = null;
    private TextBox[] displayDataFields = null;

    Pen    coordinateLinePen   = new Pen   (Color.Red, 2.0f);
    Brush  coordinateLineBrush = new SolidBrush (Color.Red);
           

    private PicesInstrumentData instrumentData = null;

    public  PicesClass  ClassUserValidatesAs  {get {return classUserValidatesAs;}}


    public ImageViewer (PicesRaster         _raster,
                        PicesDataBaseImage  _image,
                        PicesClassList      _classes
                       )
    {
      runLog  = new PicesRunLog ();
      raster  = _raster;
      classes = _classes;
      dbConn  = PicesDataBase.GetGlobalDatabaseManagerNewInstance (runLog);
      image   = _image;

      sizeCoordinates = image.SizeCoordinates;

      if  (raster == null)
      {
        raster = PicesRaster.GetOrigSipperImage (image.SipperFileName,
                                                 image.ByteOffset,
                                                 image.TopLeftRow,
                                                 image.TopLeftCol,
                                                 image.Height,
                                                 image.Width,
                                                 image.ConnectedPixelDist,
                                                 runLog
                                                );
      }

      if  (raster == null)
      {
        MessageBox.Show ("Could not locate source image or SipperFile[" + image.SipperFileName + "]");
        return;
      }

      {
        uint  scanLine = image.TopLeftRow;
        scanLine = 4096 * (uint)(scanLine / 4096);
        instrumentData = dbConn.InstrumentDataGetByScanLine (image.SipperFileName, image.TopLeftRow);
        sipperFile = dbConn.SipperFileRecLoad(image.SipperFileName);
      }

      double pixelsPerScanLine =  pixelsPerScanLineDefault;
     

      if  (instrumentData != null)
      {
        if  (instrumentData.ActiveColumns > 0)
          pixelsPerScanLine = instrumentData.ActiveColumns;
        if  (instrumentData.FlowRate1 > 0.0)
          flowRate1 = instrumentData.FlowRate1;
      }

      if  (sipperFile != null)
      {
        if  (sipperFile.ScanRate > 0.0)
          scanRate = sipperFile.ScanRate;
        deployment = dbConn.SipperDeploymentLoad (sipperFile.CruiseName, sipperFile.StationName, sipperFile.DeploymentNum);
        if  (deployment != null)
          chamberWidth = deployment.ChamberWidth;
      }

      if  ((dataFieldAssignments == null)  ||  (DataLabels == null))
        ConfigurationLoad ();

      InitializeComponent();
      if  (image != null)
      {
        extractionLogEntry = dbConn.LogEntriesSelect (image.ExtractionLogEntryId);
        classLogEntry      = dbConn.LogEntriesSelect (image.ClassLogEntryId);
      }

      mmPerPixelAccrossChamber = chamberWidth * mmPerMeter / pixelsPerScanLine;
      mmPerPixelWithFlow       = mmPerMeter * flowRate1 / scanRate;
 
      DataLabels = new Label[4];
      DataLabels[0] = DataLabel0;
      DataLabels[1] = DataLabel1;
      DataLabels[2] = DataLabel2;
      DataLabels[3] = DataLabel3;

      displayDataFields = new TextBox[4];
      displayDataFields[0] = DataField0;
      displayDataFields[1] = DataField1;
      displayDataFields[2] = DataField2;
      displayDataFields[3] = DataField3;

      UpdateDataFields ();

      ImageFileName.Text = image.ImageFileName;
    }



    private void  InitializeScreenFields ()
    {
      if  (!String.IsNullOrEmpty (ActiveTrainingLibraries.Model1Name))
        TrainingLibrary1.Text = ActiveTrainingLibraries.Model1Name;

      if  (!String.IsNullOrEmpty (ActiveTrainingLibraries.Model2Name))
        TrainingLibrary2.Text = ActiveTrainingLibraries.Model2Name;

      ValidatedClassName.Text = image.ValidatedClassName;

      ConnectedComponentDist.Text = image.ConnectedPixelDist.ToString ();

      if  (extractionLogEntry != null)
      {
        DateExtracted.Text = extractionLogEntry.DateTimeStart.ToString ();
        ViewExtractionLogButton.Enabled = true;
      }
      else
      {
        ViewExtractionLogButton.Enabled = false;
      }

      if  (classLogEntry != null)
      {
        DateClass.Text = classLogEntry.DateTimeStart.ToString ();
        ViewClassLogButton.Enabled = true;
      }
      else
      {
        ViewClassLogButton.Enabled = false;
      }

      SizeCoordinatesSelEnabledSetUp ();
    }  /* PopulateClassChooser */



    private void  SizeCoordinatesSelEnabledSetUp ()
    {
      if  (SizeCoordinatesSelEnabled == null)
        return;

      if  (sizeCoordinatesSelEnabled)
        SizeCoordinatesSelEnabled.Text = "Disable";
      else
        SizeCoordinatesSelEnabled.Text = "Enable";
    }



    private  void  ConfigurationLoad ()
    {
      configFileName = OSservices.AddSlash (PicesSipperVariables.ConfigurationDirectory ()) + "ImageViewer.cfg";
      System.IO.StreamReader i = null;
      dataFieldAssignments = new int[4];
      dataFieldAssignments[0] = PicesInstrumentData.GetFieldNum ("Depth");
      dataFieldAssignments[1] = PicesInstrumentData.GetFieldNum ("Temperature");
      dataFieldAssignments[2] = PicesInstrumentData.GetFieldNum ("Oxygen");
      dataFieldAssignments[3] = PicesInstrumentData.GetFieldNum ("Salinity");

      try {i = new System.IO.StreamReader (configFileName);}  catch  (Exception) {i = null;}
      if  (i != null)
      {
        String  nextLine = null;

        while  (true)
        {
          try  {nextLine = i.ReadLine ();}  catch (Exception) {break;}
          if  (nextLine == null)
            break;

          nextLine = nextLine.Trim ();
        
          if  ((nextLine.Length < 3)  ||  (nextLine.Substring (0, 2) == "//"))
            continue;

          String[] fields = nextLine.Split ('\t');
          if  (fields.Length != 2)
            continue;

          String  fieldName  = fields[0];
          String  fieldValue = fields[1];

          switch  (fieldName)
          {
            case  "DataLabel0":  dataFieldAssignments[0] = PicesInstrumentData.GetFieldNum (fieldValue);   break;
            case  "DataLabel1":  dataFieldAssignments[1] = PicesInstrumentData.GetFieldNum (fieldValue);   break;
            case  "DataLabel2":  dataFieldAssignments[2] = PicesInstrumentData.GetFieldNum (fieldValue);   break;
            case  "DataLabel3":  dataFieldAssignments[3] = PicesInstrumentData.GetFieldNum (fieldValue);   break;
          }
        }
      
        i.Close ();
      }

    }  /* ConfigurationLoad */



    private  void  ConfigurationSave ()
    {
      if  (dataFieldAssignments == null)
        return;

      if  (String.IsNullOrEmpty (configFileName))
        return;

      System.IO.StreamWriter  o = null;
      try{o = new System.IO.StreamWriter (configFileName);}  catch  (Exception){o = null; return;}
      
      o.WriteLine ("//ImageViewer Configuration File");
      o.WriteLine ("//");
      o.WriteLine ("//DateTime Saved" + "\t" + DateTime.Now.ToString ("F"));
      o.WriteLine ("//");
      o.WriteLine ("DataLabel0" + "\t" + PicesInstrumentData.FieldName (dataFieldAssignments[0]));
      o.WriteLine ("DataLabel1" + "\t" + PicesInstrumentData.FieldName (dataFieldAssignments[1]));
      o.WriteLine ("DataLabel2" + "\t" + PicesInstrumentData.FieldName (dataFieldAssignments[2]));
      o.WriteLine ("DataLabel3" + "\t" + PicesInstrumentData.FieldName (dataFieldAssignments[3]));
      o.Close ();
      o = null;
    }  /* ConfigurationSave*/


    private  void  UpdateDataFields ()
    {
      if  ((instrumentData == null)  ||  (dataFieldAssignments == null))
        return;

      for (int x = 0; x < DataLabels.Length; x++)
      {
        DataLabels       [x].Text = PicesInstrumentData.FieldName(dataFieldAssignments[x]);
        displayDataFields[x].Text = instrumentData.FieldToStr(dataFieldAssignments[x]);
      }
    }  /* UpdatedataFields*/




    private void MakePredictions()
    {
      if  (!ActiveTrainingLibraries.ModelsAreAvailable ())
      {
        // Since there are NO training models loaded;  there is no point doing the work for a prediction.
        return;
      }

     featureVector = dbConn.FeatureDataRecLoad (image);
      if  (featureVector == null)
      {
        featureVector = new PicesFeatureVector (raster, image.ImageFileName, null, runLog);
        // Since we had to compute the FeatureDatya from the raster we now need to
        // get the instrument data that matches it.
        if  (instrumentData != null)
          featureVector.AddInstrumentData (instrumentData);

        dbConn.FeatureDataInsertRow (image.SipperFileName, featureVector);
      }

      float  esd = 0.0f;
      float  eBv = 0.0f;
      float  filledArea = image.PixelCount;
      float  cropWidth = 3800.0f;   // (3900.0f - 200.0f);
      float  flowRate2 = 0.5f;
      
      if  (featureVector != null)
        filledArea = featureVector.FilledArea;
   
      if  (sipperFile != null)
        scanRate = sipperFile.ScanRate;

      esd = (float)(2.0 * Math.Sqrt (filledArea *  (0.096 / cropWidth) * 1000.0 * (flowRate1 / sipperFile.ScanRate) * 1000.0 / 3.1415926));
      eBv = (float)((4.0 / 3.0) * Math.PI * Math.Pow (Math.Sqrt (filledArea *  (chamberWidth / cropWidth) * 1000 * (flowRate1 / scanRate) * 1000.0 / Math.PI), 3));

      PicesPrediction  model1Prediction1 = new PicesPrediction (null, 0, 0.0f);
      PicesPrediction  model1Prediction2 = new PicesPrediction (null, 0, 0.0f);
      PicesPrediction  model2Prediction1 = new PicesPrediction (null, 0, 0.0f);
      PicesPrediction  model2Prediction2 = new PicesPrediction (null, 0, 0.0f);

      ActiveTrainingLibraries.MakePredictions (featureVector, 
                                               ref model1Prediction1, 
                                               ref model1Prediction2, 
                                               ref model2Prediction1, 
                                               ref model2Prediction2, 
                                               runLog
                                              );

      if  (model1Prediction1 != null)
      {
        Lib1Pred1Class.Text = model1Prediction1.ClassName;
        Lib1Pred1Prob.Text  = model1Prediction1.Probability.ToString ("##0.00%");
        Lib1Pred1Votes.Text = model1Prediction1.Votes.ToString ("#,##0");
      }

      if  (model1Prediction2 != null)
      {
        Lib1Pred2Class.Text = model1Prediction2.ClassName;
        Lib1Pred2Prob.Text  = model1Prediction2.Probability.ToString ("##0.00%");
        Lib1Pred2Votes.Text = model1Prediction2.Votes.ToString ("#,##0");
      }

      if  (model2Prediction1 != null)
      {
        Lib2Pred1Class.Text = model2Prediction1.ClassName;
        Lib2Pred1Prob.Text  = model2Prediction1.Probability.ToString ("##0.00%");
        Lib2Pred1Votes.Text = model2Prediction1.Votes.ToString ("#,##0");
      }

      if  (model1Prediction2 != null)
      {
        Lib2Pred2Class.Text = model2Prediction2.ClassName;
        Lib2Pred2Prob.Text  = model2Prediction2.Probability.ToString ("##0.00%");
        Lib2Pred2Votes.Text = model2Prediction2.Votes.ToString ("#,##0");
      }

      if  (featureVector != null)
        AreaMMSquare.Text = featureVector.AreaMMSquare.ToString ("#,##0.000");

      ESD.Text = esd.ToString ("#,##0.00");
      EBv.Text = eBv.ToString ("##0.0000");

      return;
    }  /* MakePredictions */



    private  void  GetZoomFactor ()
    {
      float  origZoomFactor = zoomFactor;
      bool  divideBy100 = false;
      String s = ZoomFactor.Text;
      if  (s[s.Length - 1] == '%')
      {
        s = s.Substring (0, s.Length - 1);
        divideBy100 = true;
      }

      zoomFactor = PicesKKStr.StrToFloat (s);
      if  (zoomFactor <= 0.0f)
      {
        zoomFactor = origZoomFactor;
        divideBy100 = false;
      }

      if  (divideBy100)
        zoomFactor = zoomFactor / 100.0f;

      if  (zoomFactor <= 0.0f)
        zoomFactor = 1.0f;

      int  largestDim = Math.Max (raster.Height, raster.Width);
      int  zoomedLargestDim = (int)((float)largestDim * zoomFactor + 0.5f);

      if  (zoomedLargestDim > 4096)
      {
        zoomFactor = 4096.0f / (float)(zoomedLargestDim + 1);
      }

      int  smallestDim = Math.Min (raster.Height, raster.Width);
      int  zoomedSmalestDim = (int)((float)smallestDim * zoomFactor + 0.5f);
      if  (zoomedSmalestDim < 3)
      {
        zoomFactor = 3.0f / (float)(zoomedSmalestDim + 1);
      }

      ZoomFactor.Text = zoomFactor.ToString ("##0.0%");
    }  /* GetZoomFactor */




    private  Bitmap  ReSize (Bitmap  src,
                             float   factor
                            )
    {
      int nWidth   = (int)((float)src.Width  * factor + 0.5f);
      int nHeight  = (int)((float)src.Height * factor + 0.5f);

      Bitmap result = new Bitmap (nWidth, nHeight);
      Graphics g = Graphics.FromImage( (Image) result );
      g.DrawImage (src, 0, 0, nWidth, nHeight );
      
      return result;
    }


    private  void  LoadPlanktonImage ()
    {
      GetZoomFactor ();
      Bitmap  bm = raster.BuildBitmap ();

      if  (zoomFactor != 1.0f)
        bm = ReSize (bm, zoomFactor);

      {
        // Lets add hash marks.
        Graphics  g = Graphics.FromImage (bm);

        double pixelsPERmmAccrossChamberZoom = zoomFactor * 1.0 / mmPerPixelAccrossChamber;
        double pixelsPERmmWithFlowZoom       = zoomFactor * 1.0 / mmPerPixelWithFlow;

        int  x = 0;
        Brush  hashMarkBrush = Brushes.Red;
        Pen    gridPen   = new Pen (Color.FromArgb (30, 255, 0, 0));

        // Vertical Hash Marks
        while  (true)
        {
          int  hashPos = (int)((float)x * pixelsPERmmWithFlowZoom + 0.5f);
          if  (hashPos >= bm.Height - 4)
            break;

          int hashLen = 4;
          if  ((x % 10) == 0)
            hashLen = 8;
          
          g.FillRectangle (hashMarkBrush, 0, hashPos, hashLen, 2);
          g.FillRectangle (hashMarkBrush, bm.Width - (hashLen + 1), hashPos, hashLen, 2);
          if  (displayGrid)
            g.DrawLine (gridPen, 0, hashPos, bm.Width - 1, hashPos);
          x++;
        }

        x = 0;

        // Horizontal Hash Marks
        while  (true)
        {
          int  hashPos = (int)((float)x * pixelsPERmmAccrossChamberZoom + 0.5f);
          if  (hashPos >= bm.Width)
            break;

          int hashLen = 4;
          if  ((x % 10) == 0)
            hashLen = 8;
          
          g.FillRectangle (hashMarkBrush, hashPos, 0, 2, hashLen);
          g.FillRectangle (hashMarkBrush, hashPos, bm.Height - (hashLen + 1), 2, hashLen);
          if  (displayGrid)
            g.DrawLine (gridPen, hashPos, 0, hashPos, bm.Height - 1);
          x++;
        }

        DrawSizeCoordinates (g);
      }

      PlanktonImage.Height = bm.Height;
      PlanktonImage.Width  = bm.Width;

      PlanktonImage.Image = bm;
    }  /* LoadPlanktonImage */



    private  void  AddImageToTraningLibraries  ()
    {
      if  (!ActiveTrainingLibraries.ModelsAreAvailable ())
      {
        MessageBox.Show ("There are no selected Training Models to add Image to.");
        return;
      }

      if  (image.ValidatedClass == null)
      {
        MessageBox.Show ("No Validated Class Selected.");
        return;
      }

      TrainingModel2  tm1 = ActiveTrainingLibraries.Model1 ();
      if  (tm1 == null)
        tm1 = ActiveTrainingLibraries.Model2 ();

      if  (tm1 == null)
      {
        MessageBox.Show ("No active training library specified.");
        return;
      }

      if  (!tm1.IncludesClass (image.ValidatedClass))
      {
        MessageBox.Show ("Training Model[" + tm1.ModelName + "]  does not include a definition for class[" + image.ValidatedClass.Name + "].", "ImageViewer.AddImageToTraningLibraries");
      }
      else
      {
        try
        {
          tm1.AddImageToTrainingLibray (image.ImageFileName, raster, image.ValidatedClass, true);
        }
        catch  (Exception e)
        {
          MessageBox.Show ("Error adding image to TrainingModel2[" + tm1.ModelName + "]" + "\n\n" + e.ToString (), "ImageViewer.AddImageToTraningLibraries");
        }
      }
    }  /* AddImageToTraningLibraries */



    private void  ImageViewer_Load (object sender, EventArgs e)
    {
      InitializeScreenFields ();

      lastHeight = Height;
      lastWidth  = Width;

      leftPanelLastHeight = LeftPanel.Height;
      leftPanelLastWidth  = LeftPanel.Width;

      rightPanelLastHeight = RightPanel.Height;
      rightPanelLastWidth  = RightPanel.Width;

      float  factorHeight = (float)PlanktonImage.Height / (float)(raster.Height + 1);
      float  factorWidth  = (float)PlanktonImage.Width  / (float)(raster.Width  + 1);

      float  smallestFactor = Math.Min (factorHeight, factorWidth);
      if  (smallestFactor < 1.0f)
      {
        zoomFactor = smallestFactor;
        ZoomFactor.Text = smallestFactor.ToString ("##0.0%");
      }

      MakePredictions ();

      LoadPlanktonImage ();

      if  (raster.Width < (LeftPanel.Width - 20))
      {
        int widthReduction = (LeftPanel.Width - 20) - raster.Width;
        int newWidth = this.Width - widthReduction;

        if  (newWidth < this.MinimumSize.Width)
          newWidth = this.MinimumSize.Width;

        Width = newWidth;
      }


      if  (raster.Height < (LeftPanel.Height - 20))
      {
        int heightReduction = (LeftPanel.Height - 20) - raster.Height;
        int newHeight = this.Height - heightReduction;

        if  (newHeight < this.MinimumSize.Height)
          newHeight = this.MinimumSize.Height;

        Height = newHeight;
      }

    }  /* ImageViewer_Load*/



    private void ImageViewer_Resize (object sender, EventArgs e)
    {
      if  (lastHeight == 0)
        return;

      int  deltaHeight = Height - lastHeight;
      int  deltaWidth  = Width  - lastWidth;

      LeftPanel.Height   += deltaHeight;
      RightPanel.Height  += deltaHeight;

      LeftPanel.Width += deltaWidth;
      RightPanel.Left += deltaWidth;

      lastWidth = Width;
      lastHeight = Height;
    }



    private void LeftPanel_SizeChanged (object sender, EventArgs e)
    {
      int  deltaHeight = LeftPanel.Height - leftPanelLastHeight;
      int  deltaWidth  = LeftPanel.Width  - leftPanelLastWidth;

      PlanktonImage.Height += deltaHeight;
      PlanktonImage.Width  += deltaWidth;

      leftPanelLastHeight = LeftPanel.Height;
      leftPanelLastWidth  = LeftPanel.Width;

      LoadPlanktonImage ();
    }



    private void RightPanel_SizeChanged(object sender, EventArgs e)
    {
      int  deltaHeight = RightPanel.Height - rightPanelLastHeight;
      int  deltaWidth  = RightPanel.Width  - rightPanelLastWidth;

      rightPanelLastHeight = RightPanel.Height;
      rightPanelLastWidth  = RightPanel.Width;
    }



    private void ZoomFactor_SelectedIndexChanged(object sender, EventArgs e)
    {
      ZoomFactor.Text = ZoomFactor.Items[ZoomFactor.SelectedIndex].ToString ();
      LoadPlanktonImage ();
    }



    private void ImageViewer_FormClosing (object sender, FormClosingEventArgs e)
    {
      if  (image.SizeCoordinates.NotEqual (sizeCoordinates))
      {
        image.SizeCoordinates = sizeCoordinates;
        image.ImageSize       = imageSize;
        dbConn.ImagesUpdateImageSize (image.ImageFileName, sizeCoordinates, imageSize);
      }

      dbConn.Close ();
      dbConn = null;
      GC.Collect ();
    }



    private void ZoomFactor_Leave(object sender, EventArgs e)
    {
      float  oldZoomFactor = zoomFactor;
      GetZoomFactor ();
      if  (zoomFactor != oldZoomFactor)
        LoadPlanktonImage ();
    } /* ZoomFactor_Leave */  




    private void AddToTrainingLibrary_Click (object sender, EventArgs e)
    {
      AddImageToTraningLibraries ();
    }



    private void BreakDownTrainingLibrary1Button_Click (object sender, EventArgs e)
    {
      if  (ActiveTrainingLibraries.Model1 ()  == null)
        return;

      if  (ActiveTrainingLibraries.Model1 ().ModelType == TrainingModel2.ModelTypes.Dual)
      {
        PredictionBreakDownDisplayDual  pbdd = new PredictionBreakDownDisplayDual (dbConn, 
                                                                                   image, 
                                                                                   raster, 
                                                                                   ActiveTrainingLibraries.Model1 (), 
                                                                                   instrumentData, 
                                                                                   runLog
                                                                                  );
        pbdd.ShowDialog ();
        pbdd = null;
      }
      else
      {
        PredictionBreakDownDisplay  pbdd = new PredictionBreakDownDisplay (dbConn, image, raster, ActiveTrainingLibraries.Model1 (), instrumentData, runLog);
        pbdd.ShowDialog ();
        pbdd = null;
      }
    }


    private void BreakDownTrainingLibrary2Button_Click (object sender, EventArgs e)
    {
      if  (ActiveTrainingLibraries.Model2 ()  == null)
        return;

      if  (ActiveTrainingLibraries.Model2 ().ModelType == TrainingModel2.ModelTypes.Dual)
      {
        PredictionBreakDownDisplayDual  pbdd = new PredictionBreakDownDisplayDual (dbConn, 
                                                                                   image, 
                                                                                   raster, 
                                                                                   ActiveTrainingLibraries.Model2 (), 
                                                                                   instrumentData, 
                                                                                   runLog
                                                                                  );
        pbdd.ShowDialog ();
        pbdd = null;
      }
      else
      {
        PredictionBreakDownDisplay  pbdd = new PredictionBreakDownDisplay (dbConn, image, raster, ActiveTrainingLibraries.Model2 (), instrumentData, runLog);
        pbdd.ShowDialog ();
        pbdd = null;
      }
    }

    
    private  void  SelectDataField (int  dataLabelNum)
    { 
      String  existingSelField = DataLabels[dataLabelNum].Text;
      SelectAInstrumentDataField  f = new SelectAInstrumentDataField (existingSelField);
      f.ShowDialog ();
      
      string  newSelectedDataFieldStr = f.SelectedDataField;
      int  fieldIdxNew  =  PicesInstrumentData.GetFieldNum (newSelectedDataFieldStr);
      if  (fieldIdxNew >= 0)
      {
        dataFieldAssignments[dataLabelNum] = fieldIdxNew;
        DataLabels[dataLabelNum].Text = PicesInstrumentData.FieldName (fieldIdxNew);
        ConfigurationSave ();
      }

      UpdateDataFields ();
    }  /* SelectDataField */



    
    private void DataLabel_MouseDoubleClick(object sender, MouseEventArgs e)
    {
      for  (int x = 0;  x < DataLabels.Length;  x++)
      {
        if  (sender == DataLabels[x])
        {
          SelectDataField (x);
          break;
        }
      }
    }



    private void DisplayGridButton_Click(object sender, EventArgs e)
    {
      displayGrid = !displayGrid;
      LoadPlanktonImage ();
    }

    private void Lib1Pred1Class_TextChanged (object sender, EventArgs e)
    {

    }

    private void Lib1Pred2Class_TextChanged (object sender, EventArgs e)
    {

    }

    private void Lib2Pred1Class_TextChanged (object sender, EventArgs e)
    {

    }

    private void Lib2Pred2Class_TextChanged (object sender, EventArgs e)
    {

    }


    private void SelectClassButtom_Click (object sender, EventArgs e)
    {
      String  rootDir = "";
      PicesClassList  activeClasses = null;
      if  (ActiveTrainingLibraries.Model1 () != null)
      {
        rootDir = ActiveTrainingLibraries.Model1 ().RootDir;
        activeClasses = ActiveTrainingLibraries.Model1 ().MLClasses ();
      }

      if  (classes == null)
        classes = dbConn.MLClassLoadList ();
      SelectAPicesClass  sapc = new SelectAPicesClass (classes, rootDir, activeClasses);

      if  (!String.IsNullOrEmpty (ValidatedClassName.Text))
        sapc.SelectedClass = PicesClassList.GetUniqueClass (ValidatedClassName.Text, "");

      sapc.ShowDialog (this);
      if  (sapc.SelectionMade  &&  (sapc.SelectedClass != null))
      {
        PicesClass  validatdClass = sapc.SelectedClass;
        ValidatedClassName.Text = validatdClass.Name;
        image.ValidatedClass = validatdClass;
        dbConn.ImagesUpdateValidatedClass (image.ImageFileName, validatdClass);
        classUserValidatesAs = validatdClass;
      }
    }


    private  void  SizeCoordinatesAdd (int row, int col)
    {
      int  rowAdj = (int)((float)row / zoomFactor + 0.5f);
      int  colAdj = (int)((float)col / zoomFactor + 0.5f);

      while  (sizeCoordinates.Count >= 3)
        sizeCoordinates.RemoveAt (0);

      sizeCoordinates.Add (new PicesPoint (rowAdj, colAdj));
      LoadPlanktonImage ();
    }  /* SizeCoordinatesAdd */


    private void ImageSizeAuto_Click (object sender, EventArgs e)
    {
      sizeCoordinates = raster.DeriveImageLength ();
      LoadPlanktonImage ();
    }


    private  System.Drawing.Point  AdjustForZoomFactor (PicesPoint  p)
    {
      int  adjRow = (int)((float)p.Row * zoomFactor + 0.5f);
      int  adjCol = (int)((float)p.Col * zoomFactor + 0.5f);
      return new Point (adjCol, adjRow);
    }


    private void  DrawSizeCoordinates (Graphics g)
    {
      if  ((sizeCoordinates == null)  ||  (sizeCoordinates.Count < 1))
        return;

      imageSize = sizeCoordinates.ComputeSegmentLens ((float)mmPerPixelWithFlow, (float)mmPerPixelAccrossChamber);

      PicesPoint  lastPoint = sizeCoordinates[0];
      Point  lastPointAdj = AdjustForZoomFactor (lastPoint);
      
      g.FillEllipse (coordinateLineBrush, lastPointAdj.X, lastPointAdj.Y, 3.0f, 3.0f);
      int x = 1;
      while  (x < sizeCoordinates.Count)
      {
        PicesPoint  nextPoint = sizeCoordinates[x];
        Point  nextPointAdj = AdjustForZoomFactor (sizeCoordinates[x]);
        g.FillEllipse (coordinateLineBrush, nextPointAdj.X, nextPointAdj.Y, 3.0f, 3.0f);
        g.DrawLine (coordinateLinePen, lastPointAdj, nextPointAdj);
        lastPoint = nextPoint;
        lastPointAdj = nextPointAdj;
        ++x;
      }

      ImageSize.Text = imageSize.ToString ("###,##0.0") + " mm";
    }  /* DrawSizeCoordinates */



    private void PlanktonImage_Click (object sender, EventArgs e)
    {
      if  (e.GetType () != typeof (MouseEventArgs))
        return;

      MouseEventArgs mea = (MouseEventArgs)e;
      if  (mea.Button != MouseButtons.Left)
        return;

      if  (sizeCoordinatesSelEnabled)
      {
        SizeCoordinatesAdd (mea.Y, mea.X);
      }
    }

    private void ImageSizeClearButton_Click (object sender, EventArgs e)
    {
      sizeCoordinates.Clear ();
      imageSize = 0.0f;
      LoadPlanktonImage ();
    }


    private void SizeCoordinatesSelEnabled_Click (object sender, EventArgs e)
    {
      sizeCoordinatesSelEnabled = !sizeCoordinatesSelEnabled;
      SizeCoordinatesSelEnabledSetUp ();
    }

    private void ViewExtractionLogButton_Click (object sender, EventArgs e)
    {
      if  (extractionLogEntry != null)
      {
        LogEntryViewer lev = new LogEntryViewer (extractionLogEntry);
        lev.ShowDialog (this);
      }
    }

    private void ViewClassLogButton_Click (object sender, EventArgs e)
    {
      if  (classLogEntry != null)
      {
        LogEntryViewer lev = new LogEntryViewer (classLogEntry);
        lev.ShowDialog (this);
      }
    }

    private void EditButton_Click (object sender, EventArgs e)
    {
      ImageEditor  ie = new ImageEditor (raster);
      ie.ShowDialog (this);
    }


  }  /* ImageViewer*/
}