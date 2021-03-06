namespace PicesCommander
{
  partial class SaveFeatureData
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.components = new System.ComponentModel.Container ();
      this.TitleLabel = new System.Windows.Forms.Label ();
      this.ImageCountlabel = new System.Windows.Forms.Label ();
      this.ImageCount = new System.Windows.Forms.TextBox ();
      this.MissingFeatureDataLabel = new System.Windows.Forms.Label ();
      this.ImagesLoadedLabel = new System.Windows.Forms.Label ();
      this.FeatureFileNameLabel = new System.Windows.Forms.Label ();
      this.FeatureFileName = new System.Windows.Forms.TextBox ();
      this.FeatureFileNameBrowseButton = new System.Windows.Forms.Button ();
      this.ImagesLoaded = new System.Windows.Forms.TextBox ();
      this.ImagesMissingFeatureData = new System.Windows.Forms.TextBox ();
      this.errorProvider1 = new System.Windows.Forms.ErrorProvider (this.components);
      this.StartButton = new System.Windows.Forms.Button ();
      this.CancelSaveButton = new System.Windows.Forms.Button ();
      this.backGroundTimer = new System.Windows.Forms.Timer (this.components);
      this.RunTimeParameters = new System.Windows.Forms.Panel ();
      this.NormalizeData = new System.Windows.Forms.CheckBox ();
      this.FileFrmatLabel = new System.Windows.Forms.Label ();
      this.FileFormat = new System.Windows.Forms.ComboBox ();
      this.RunTimeStatus = new System.Windows.Forms.Panel ();
      this.ImagesWritten = new System.Windows.Forms.TextBox ();
      this.ImagesWrittenLabel = new System.Windows.Forms.Label ();
      this.ImagesFilteredOut = new System.Windows.Forms.TextBox ();
      this.ImagesFilteredOutLabel = new System.Windows.Forms.Label ();
      this.SaveProgress = new System.Windows.Forms.ProgressBar ();
      this.BackGroundSatus = new System.Windows.Forms.TextBox ();
      this.BackGroundStatusLabel = new System.Windows.Forms.Label ();
      this.CruiseLabel = new System.Windows.Forms.Label ();
      this.SipperFileLabel = new System.Windows.Forms.Label ();
      this.DeploymentLabel = new System.Windows.Forms.Label ();
      this.StationsLabel = new System.Windows.Forms.Label ();
      this.CruiseName = new System.Windows.Forms.TextBox ();
      this.StationName = new System.Windows.Forms.TextBox ();
      this.DeploymentNum = new System.Windows.Forms.TextBox ();
      this.SipperFile = new System.Windows.Forms.TextBox ();
      this.SelectionCriteria = new System.Windows.Forms.Panel ();
      this.ClassName = new System.Windows.Forms.TextBox ();
      this.ClassNameLabel = new System.Windows.Forms.Label ();
      this.DepthLabel = new System.Windows.Forms.Label ();
      this.DepthMax = new System.Windows.Forms.TextBox ();
      this.DepthMin = new System.Windows.Forms.TextBox ();
      this.SizeMax = new System.Windows.Forms.TextBox ();
      this.SizeMin = new System.Windows.Forms.TextBox ();
      this.SizeLabel = new System.Windows.Forms.Label ();
      this.ProbMax = new System.Windows.Forms.TextBox ();
      this.ProbMin = new System.Windows.Forms.TextBox ();
      this.ProbabilityLabel = new System.Windows.Forms.Label ();
      this.GroupName = new System.Windows.Forms.TextBox ();
      this.GroupNameLabel = new System.Windows.Forms.Label ();
      this.SelectionCriteriaLabel = new System.Windows.Forms.Label ();
      this.RunTimeParametersLabel = new System.Windows.Forms.Label ();
      this.RunTimeStatusLabel = new System.Windows.Forms.Label ();
      this.StatsTimer = new System.Windows.Forms.Timer (this.components);
      this.IncludeSampleImages = new System.Windows.Forms.CheckBox ();
      this.IncludeSampleImagesNumPerClass = new System.Windows.Forms.ComboBox ();
      this.IncludeSampleImagesNumPerClassLabel = new System.Windows.Forms.Label ();
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit ();
      this.RunTimeParameters.SuspendLayout ();
      this.RunTimeStatus.SuspendLayout ();
      this.SelectionCriteria.SuspendLayout ();
      this.SuspendLayout ();
      // 
      // TitleLabel
      // 
      this.TitleLabel.AutoSize = true;
      this.TitleLabel.Font = new System.Drawing.Font ("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.TitleLabel.Location = new System.Drawing.Point (228, 9);
      this.TitleLabel.Name = "TitleLabel";
      this.TitleLabel.Size = new System.Drawing.Size (249, 24);
      this.TitleLabel.TabIndex = 0;
      this.TitleLabel.Text = "Save Feature Data to Disk";
      // 
      // ImageCountlabel
      // 
      this.ImageCountlabel.AutoSize = true;
      this.ImageCountlabel.Location = new System.Drawing.Point (9, 60);
      this.ImageCountlabel.Name = "ImageCountlabel";
      this.ImageCountlabel.Size = new System.Drawing.Size (67, 13);
      this.ImageCountlabel.TabIndex = 1;
      this.ImageCountlabel.Text = "Image Count";
      this.ImageCountlabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // ImageCount
      // 
      this.ImageCount.CausesValidation = false;
      this.ImageCount.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ImageCount.Location = new System.Drawing.Point (12, 76);
      this.ImageCount.Name = "ImageCount";
      this.ImageCount.ReadOnly = true;
      this.ImageCount.Size = new System.Drawing.Size (90, 22);
      this.ImageCount.TabIndex = 2;
      this.ImageCount.TabStop = false;
      this.ImageCount.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // MissingFeatureDataLabel
      // 
      this.MissingFeatureDataLabel.AutoSize = true;
      this.MissingFeatureDataLabel.Location = new System.Drawing.Point (385, 60);
      this.MissingFeatureDataLabel.Name = "MissingFeatureDataLabel";
      this.MissingFeatureDataLabel.Size = new System.Drawing.Size (107, 13);
      this.MissingFeatureDataLabel.TabIndex = 15;
      this.MissingFeatureDataLabel.Text = "Missing Feature Data";
      this.MissingFeatureDataLabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
      // 
      // ImagesLoadedLabel
      // 
      this.ImagesLoadedLabel.AutoSize = true;
      this.ImagesLoadedLabel.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
      this.ImagesLoadedLabel.Location = new System.Drawing.Point (121, 60);
      this.ImagesLoadedLabel.Name = "ImagesLoadedLabel";
      this.ImagesLoadedLabel.Size = new System.Drawing.Size (80, 13);
      this.ImagesLoadedLabel.TabIndex = 13;
      this.ImagesLoadedLabel.Text = "Images Loaded";
      this.ImagesLoadedLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // FeatureFileNameLabel
      // 
      this.FeatureFileNameLabel.AutoSize = true;
      this.FeatureFileNameLabel.Location = new System.Drawing.Point (7, 8);
      this.FeatureFileNameLabel.Name = "FeatureFileNameLabel";
      this.FeatureFileNameLabel.Size = new System.Drawing.Size (93, 13);
      this.FeatureFileNameLabel.TabIndex = 3;
      this.FeatureFileNameLabel.Text = "Feature File Name";
      this.FeatureFileNameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // FeatureFileName
      // 
      this.FeatureFileName.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.FeatureFileName.Location = new System.Drawing.Point (10, 24);
      this.FeatureFileName.Name = "FeatureFileName";
      this.FeatureFileName.Size = new System.Drawing.Size (556, 22);
      this.FeatureFileName.TabIndex = 4;
      this.FeatureFileName.Validating += new System.ComponentModel.CancelEventHandler (this.FeatureFileName_Validating);
      // 
      // FeatureFileNameBrowseButton
      // 
      this.FeatureFileNameBrowseButton.Location = new System.Drawing.Point (570, 24);
      this.FeatureFileNameBrowseButton.Name = "FeatureFileNameBrowseButton";
      this.FeatureFileNameBrowseButton.Size = new System.Drawing.Size (75, 20);
      this.FeatureFileNameBrowseButton.TabIndex = 7;
      this.FeatureFileNameBrowseButton.Text = "Browse";
      this.FeatureFileNameBrowseButton.UseVisualStyleBackColor = true;
      this.FeatureFileNameBrowseButton.Click += new System.EventHandler (this.BrowseFeatureFileNameButton_Click);
      // 
      // ImagesLoaded
      // 
      this.ImagesLoaded.CausesValidation = false;
      this.ImagesLoaded.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ImagesLoaded.Location = new System.Drawing.Point (124, 76);
      this.ImagesLoaded.Name = "ImagesLoaded";
      this.ImagesLoaded.ReadOnly = true;
      this.ImagesLoaded.Size = new System.Drawing.Size (111, 22);
      this.ImagesLoaded.TabIndex = 14;
      this.ImagesLoaded.TabStop = false;
      this.ImagesLoaded.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // ImagesMissingFeatureData
      // 
      this.ImagesMissingFeatureData.CausesValidation = false;
      this.ImagesMissingFeatureData.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ImagesMissingFeatureData.Location = new System.Drawing.Point (388, 76);
      this.ImagesMissingFeatureData.Name = "ImagesMissingFeatureData";
      this.ImagesMissingFeatureData.ReadOnly = true;
      this.ImagesMissingFeatureData.Size = new System.Drawing.Size (111, 22);
      this.ImagesMissingFeatureData.TabIndex = 16;
      this.ImagesMissingFeatureData.TabStop = false;
      this.ImagesMissingFeatureData.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // errorProvider1
      // 
      this.errorProvider1.ContainerControl = this;
      // 
      // StartButton
      // 
      this.StartButton.Location = new System.Drawing.Point (25, 612);
      this.StartButton.Name = "StartButton";
      this.StartButton.Size = new System.Drawing.Size (75, 23);
      this.StartButton.TabIndex = 4;
      this.StartButton.Text = "Start";
      this.StartButton.UseVisualStyleBackColor = true;
      this.StartButton.Click += new System.EventHandler (this.StartButton_Click);
      // 
      // CancelSaveButton
      // 
      this.CancelSaveButton.Location = new System.Drawing.Point (605, 612);
      this.CancelSaveButton.Name = "CancelSaveButton";
      this.CancelSaveButton.Size = new System.Drawing.Size (75, 23);
      this.CancelSaveButton.TabIndex = 5;
      this.CancelSaveButton.Text = "Cancel";
      this.CancelSaveButton.UseVisualStyleBackColor = true;
      this.CancelSaveButton.Click += new System.EventHandler (this.CancelSaveButton_Click);
      // 
      // backGroundTimer
      // 
      this.backGroundTimer.Tick += new System.EventHandler (this.backGroundTimer_Tick);
      // 
      // RunTimeParameters
      // 
      this.RunTimeParameters.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.RunTimeParameters.Controls.Add (this.IncludeSampleImagesNumPerClassLabel);
      this.RunTimeParameters.Controls.Add (this.IncludeSampleImagesNumPerClass);
      this.RunTimeParameters.Controls.Add (this.IncludeSampleImages);
      this.RunTimeParameters.Controls.Add (this.NormalizeData);
      this.RunTimeParameters.Controls.Add (this.FileFrmatLabel);
      this.RunTimeParameters.Controls.Add (this.FileFormat);
      this.RunTimeParameters.Controls.Add (this.FeatureFileNameBrowseButton);
      this.RunTimeParameters.Controls.Add (this.FeatureFileName);
      this.RunTimeParameters.Controls.Add (this.FeatureFileNameLabel);
      this.RunTimeParameters.Location = new System.Drawing.Point (23, 316);
      this.RunTimeParameters.Name = "RunTimeParameters";
      this.RunTimeParameters.Size = new System.Drawing.Size (657, 96);
      this.RunTimeParameters.TabIndex = 17;
      // 
      // NormalizeData
      // 
      this.NormalizeData.AutoSize = true;
      this.NormalizeData.Location = new System.Drawing.Point (178, 68);
      this.NormalizeData.Name = "NormalizeData";
      this.NormalizeData.Size = new System.Drawing.Size (98, 17);
      this.NormalizeData.TabIndex = 10;
      this.NormalizeData.Text = "Normalize Data";
      this.NormalizeData.UseVisualStyleBackColor = true;
      // 
      // FileFrmatLabel
      // 
      this.FileFrmatLabel.AutoSize = true;
      this.FileFrmatLabel.Location = new System.Drawing.Point (9, 52);
      this.FileFrmatLabel.Name = "FileFrmatLabel";
      this.FileFrmatLabel.Size = new System.Drawing.Size (58, 13);
      this.FileFrmatLabel.TabIndex = 9;
      this.FileFrmatLabel.Text = "File Format";
      this.FileFrmatLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // FileFormat
      // 
      this.FileFormat.FormattingEnabled = true;
      this.FileFormat.Location = new System.Drawing.Point (10, 66);
      this.FileFormat.Name = "FileFormat";
      this.FileFormat.Size = new System.Drawing.Size (121, 21);
      this.FileFormat.TabIndex = 8;
      this.FileFormat.Validating += new System.ComponentModel.CancelEventHandler (this.FileFormat_Validating);
      this.FileFormat.SelectedIndexChanged += new System.EventHandler (this.FileFormat_SelectedIndexChanged);
      // 
      // RunTimeStatus
      // 
      this.RunTimeStatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.RunTimeStatus.Controls.Add (this.ImagesWritten);
      this.RunTimeStatus.Controls.Add (this.ImagesWrittenLabel);
      this.RunTimeStatus.Controls.Add (this.ImagesFilteredOut);
      this.RunTimeStatus.Controls.Add (this.ImagesFilteredOutLabel);
      this.RunTimeStatus.Controls.Add (this.SaveProgress);
      this.RunTimeStatus.Controls.Add (this.BackGroundSatus);
      this.RunTimeStatus.Controls.Add (this.BackGroundStatusLabel);
      this.RunTimeStatus.Controls.Add (this.ImagesMissingFeatureData);
      this.RunTimeStatus.Controls.Add (this.MissingFeatureDataLabel);
      this.RunTimeStatus.Controls.Add (this.ImagesLoaded);
      this.RunTimeStatus.Controls.Add (this.ImagesLoadedLabel);
      this.RunTimeStatus.Controls.Add (this.ImageCount);
      this.RunTimeStatus.Controls.Add (this.ImageCountlabel);
      this.RunTimeStatus.Location = new System.Drawing.Point (23, 452);
      this.RunTimeStatus.Name = "RunTimeStatus";
      this.RunTimeStatus.Size = new System.Drawing.Size (657, 144);
      this.RunTimeStatus.TabIndex = 18;
      // 
      // ImagesWritten
      // 
      this.ImagesWritten.CausesValidation = false;
      this.ImagesWritten.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ImagesWritten.Location = new System.Drawing.Point (522, 76);
      this.ImagesWritten.Name = "ImagesWritten";
      this.ImagesWritten.ReadOnly = true;
      this.ImagesWritten.Size = new System.Drawing.Size (111, 22);
      this.ImagesWritten.TabIndex = 23;
      this.ImagesWritten.TabStop = false;
      this.ImagesWritten.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // ImagesWrittenLabel
      // 
      this.ImagesWrittenLabel.AutoSize = true;
      this.ImagesWrittenLabel.Location = new System.Drawing.Point (519, 60);
      this.ImagesWrittenLabel.Name = "ImagesWrittenLabel";
      this.ImagesWrittenLabel.Size = new System.Drawing.Size (78, 13);
      this.ImagesWrittenLabel.TabIndex = 22;
      this.ImagesWrittenLabel.Text = "Images Written";
      this.ImagesWrittenLabel.TextAlign = System.Drawing.ContentAlignment.TopCenter;
      // 
      // ImagesFilteredOut
      // 
      this.ImagesFilteredOut.CausesValidation = false;
      this.ImagesFilteredOut.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ImagesFilteredOut.Location = new System.Drawing.Point (256, 76);
      this.ImagesFilteredOut.Name = "ImagesFilteredOut";
      this.ImagesFilteredOut.ReadOnly = true;
      this.ImagesFilteredOut.Size = new System.Drawing.Size (111, 22);
      this.ImagesFilteredOut.TabIndex = 21;
      this.ImagesFilteredOut.TabStop = false;
      this.ImagesFilteredOut.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // ImagesFilteredOutLabel
      // 
      this.ImagesFilteredOutLabel.AutoSize = true;
      this.ImagesFilteredOutLabel.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
      this.ImagesFilteredOutLabel.Location = new System.Drawing.Point (253, 60);
      this.ImagesFilteredOutLabel.Name = "ImagesFilteredOutLabel";
      this.ImagesFilteredOutLabel.Size = new System.Drawing.Size (98, 13);
      this.ImagesFilteredOutLabel.TabIndex = 20;
      this.ImagesFilteredOutLabel.Text = "Images Filtered Out";
      this.ImagesFilteredOutLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // SaveProgress
      // 
      this.SaveProgress.Location = new System.Drawing.Point (12, 117);
      this.SaveProgress.Name = "SaveProgress";
      this.SaveProgress.Size = new System.Drawing.Size (633, 17);
      this.SaveProgress.TabIndex = 19;
      // 
      // BackGroundSatus
      // 
      this.BackGroundSatus.CausesValidation = false;
      this.BackGroundSatus.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.BackGroundSatus.Location = new System.Drawing.Point (9, 22);
      this.BackGroundSatus.Name = "BackGroundSatus";
      this.BackGroundSatus.ReadOnly = true;
      this.BackGroundSatus.Size = new System.Drawing.Size (631, 22);
      this.BackGroundSatus.TabIndex = 18;
      this.BackGroundSatus.TabStop = false;
      // 
      // BackGroundStatusLabel
      // 
      this.BackGroundStatusLabel.AutoSize = true;
      this.BackGroundStatusLabel.Location = new System.Drawing.Point (9, 6);
      this.BackGroundStatusLabel.Name = "BackGroundStatusLabel";
      this.BackGroundStatusLabel.Size = new System.Drawing.Size (37, 13);
      this.BackGroundStatusLabel.TabIndex = 17;
      this.BackGroundStatusLabel.Text = "Status";
      this.BackGroundStatusLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // CruiseLabel
      // 
      this.CruiseLabel.AutoSize = true;
      this.CruiseLabel.Location = new System.Drawing.Point (7, 13);
      this.CruiseLabel.Name = "CruiseLabel";
      this.CruiseLabel.Size = new System.Drawing.Size (36, 13);
      this.CruiseLabel.TabIndex = 19;
      this.CruiseLabel.Text = "Cruise";
      this.CruiseLabel.TextAlign = System.Drawing.ContentAlignment.BottomLeft;
      // 
      // SipperFileLabel
      // 
      this.SipperFileLabel.AutoSize = true;
      this.SipperFileLabel.Location = new System.Drawing.Point (7, 61);
      this.SipperFileLabel.Name = "SipperFileLabel";
      this.SipperFileLabel.Size = new System.Drawing.Size (53, 13);
      this.SipperFileLabel.TabIndex = 20;
      this.SipperFileLabel.Text = "SipperFile";
      this.SipperFileLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // DeploymentLabel
      // 
      this.DeploymentLabel.AutoSize = true;
      this.DeploymentLabel.Location = new System.Drawing.Point (328, 13);
      this.DeploymentLabel.Name = "DeploymentLabel";
      this.DeploymentLabel.Size = new System.Drawing.Size (63, 13);
      this.DeploymentLabel.TabIndex = 21;
      this.DeploymentLabel.Text = "Deployment";
      this.DeploymentLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // StationsLabel
      // 
      this.StationsLabel.AutoSize = true;
      this.StationsLabel.Location = new System.Drawing.Point (166, 13);
      this.StationsLabel.Name = "StationsLabel";
      this.StationsLabel.Size = new System.Drawing.Size (40, 13);
      this.StationsLabel.TabIndex = 22;
      this.StationsLabel.Text = "Station";
      this.StationsLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // CruiseName
      // 
      this.CruiseName.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.CruiseName.Location = new System.Drawing.Point (10, 28);
      this.CruiseName.Name = "CruiseName";
      this.CruiseName.ReadOnly = true;
      this.CruiseName.Size = new System.Drawing.Size (140, 22);
      this.CruiseName.TabIndex = 11;
      this.CruiseName.TabStop = false;
      // 
      // StationName
      // 
      this.StationName.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.StationName.Location = new System.Drawing.Point (169, 28);
      this.StationName.Name = "StationName";
      this.StationName.ReadOnly = true;
      this.StationName.Size = new System.Drawing.Size (140, 22);
      this.StationName.TabIndex = 23;
      this.StationName.TabStop = false;
      // 
      // DeploymentNum
      // 
      this.DeploymentNum.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.DeploymentNum.Location = new System.Drawing.Point (328, 29);
      this.DeploymentNum.Name = "DeploymentNum";
      this.DeploymentNum.ReadOnly = true;
      this.DeploymentNum.Size = new System.Drawing.Size (84, 22);
      this.DeploymentNum.TabIndex = 24;
      this.DeploymentNum.TabStop = false;
      // 
      // SipperFile
      // 
      this.SipperFile.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.SipperFile.Location = new System.Drawing.Point (10, 76);
      this.SipperFile.Name = "SipperFile";
      this.SipperFile.ReadOnly = true;
      this.SipperFile.Size = new System.Drawing.Size (402, 22);
      this.SipperFile.TabIndex = 25;
      this.SipperFile.TabStop = false;
      // 
      // SelectionCriteria
      // 
      this.SelectionCriteria.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.SelectionCriteria.Controls.Add (this.ClassName);
      this.SelectionCriteria.Controls.Add (this.ClassNameLabel);
      this.SelectionCriteria.Controls.Add (this.DepthLabel);
      this.SelectionCriteria.Controls.Add (this.DepthMax);
      this.SelectionCriteria.Controls.Add (this.DepthMin);
      this.SelectionCriteria.Controls.Add (this.SizeMax);
      this.SelectionCriteria.Controls.Add (this.SizeMin);
      this.SelectionCriteria.Controls.Add (this.SizeLabel);
      this.SelectionCriteria.Controls.Add (this.ProbMax);
      this.SelectionCriteria.Controls.Add (this.ProbMin);
      this.SelectionCriteria.Controls.Add (this.ProbabilityLabel);
      this.SelectionCriteria.Controls.Add (this.CruiseName);
      this.SelectionCriteria.Controls.Add (this.StationName);
      this.SelectionCriteria.Controls.Add (this.CruiseLabel);
      this.SelectionCriteria.Controls.Add (this.DeploymentNum);
      this.SelectionCriteria.Controls.Add (this.GroupName);
      this.SelectionCriteria.Controls.Add (this.StationsLabel);
      this.SelectionCriteria.Controls.Add (this.GroupNameLabel);
      this.SelectionCriteria.Controls.Add (this.DeploymentLabel);
      this.SelectionCriteria.Controls.Add (this.SipperFile);
      this.SelectionCriteria.Controls.Add (this.SipperFileLabel);
      this.SelectionCriteria.Location = new System.Drawing.Point (23, 73);
      this.SelectionCriteria.Name = "SelectionCriteria";
      this.SelectionCriteria.Size = new System.Drawing.Size (657, 207);
      this.SelectionCriteria.TabIndex = 26;
      // 
      // ClassName
      // 
      this.ClassName.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ClassName.Location = new System.Drawing.Point (10, 172);
      this.ClassName.Name = "ClassName";
      this.ClassName.ReadOnly = true;
      this.ClassName.Size = new System.Drawing.Size (402, 22);
      this.ClassName.TabIndex = 36;
      this.ClassName.TabStop = false;
      // 
      // ClassNameLabel
      // 
      this.ClassNameLabel.AutoSize = true;
      this.ClassNameLabel.Location = new System.Drawing.Point (7, 157);
      this.ClassNameLabel.Name = "ClassNameLabel";
      this.ClassNameLabel.Size = new System.Drawing.Size (63, 13);
      this.ClassNameLabel.TabIndex = 37;
      this.ClassNameLabel.Text = "Class Name";
      this.ClassNameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // DepthLabel
      // 
      this.DepthLabel.AutoSize = true;
      this.DepthLabel.Location = new System.Drawing.Point (513, 109);
      this.DepthLabel.Name = "DepthLabel";
      this.DepthLabel.Size = new System.Drawing.Size (36, 13);
      this.DepthLabel.TabIndex = 36;
      this.DepthLabel.Text = "Depth";
      this.DepthLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // DepthMax
      // 
      this.DepthMax.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.DepthMax.Location = new System.Drawing.Point (538, 125);
      this.DepthMax.Name = "DepthMax";
      this.DepthMax.ReadOnly = true;
      this.DepthMax.Size = new System.Drawing.Size (57, 22);
      this.DepthMax.TabIndex = 35;
      this.DepthMax.TabStop = false;
      this.DepthMax.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // DepthMin
      // 
      this.DepthMin.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.DepthMin.Location = new System.Drawing.Point (465, 125);
      this.DepthMin.Name = "DepthMin";
      this.DepthMin.ReadOnly = true;
      this.DepthMin.Size = new System.Drawing.Size (57, 22);
      this.DepthMin.TabIndex = 34;
      this.DepthMin.TabStop = false;
      this.DepthMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // SizeMax
      // 
      this.SizeMax.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.SizeMax.Location = new System.Drawing.Point (538, 76);
      this.SizeMax.Name = "SizeMax";
      this.SizeMax.ReadOnly = true;
      this.SizeMax.Size = new System.Drawing.Size (57, 22);
      this.SizeMax.TabIndex = 33;
      this.SizeMax.TabStop = false;
      this.SizeMax.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // SizeMin
      // 
      this.SizeMin.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.SizeMin.Location = new System.Drawing.Point (465, 76);
      this.SizeMin.Name = "SizeMin";
      this.SizeMin.ReadOnly = true;
      this.SizeMin.Size = new System.Drawing.Size (57, 22);
      this.SizeMin.TabIndex = 32;
      this.SizeMin.TabStop = false;
      this.SizeMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // SizeLabel
      // 
      this.SizeLabel.AutoSize = true;
      this.SizeLabel.Location = new System.Drawing.Point (516, 61);
      this.SizeLabel.Name = "SizeLabel";
      this.SizeLabel.Size = new System.Drawing.Size (27, 13);
      this.SizeLabel.TabIndex = 31;
      this.SizeLabel.Text = "Size";
      this.SizeLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // ProbMax
      // 
      this.ProbMax.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ProbMax.Location = new System.Drawing.Point (538, 28);
      this.ProbMax.Name = "ProbMax";
      this.ProbMax.ReadOnly = true;
      this.ProbMax.Size = new System.Drawing.Size (57, 22);
      this.ProbMax.TabIndex = 30;
      this.ProbMax.TabStop = false;
      this.ProbMax.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // ProbMin
      // 
      this.ProbMin.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ProbMin.Location = new System.Drawing.Point (465, 28);
      this.ProbMin.Name = "ProbMin";
      this.ProbMin.ReadOnly = true;
      this.ProbMin.Size = new System.Drawing.Size (57, 22);
      this.ProbMin.TabIndex = 29;
      this.ProbMin.TabStop = false;
      this.ProbMin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
      // 
      // ProbabilityLabel
      // 
      this.ProbabilityLabel.AutoSize = true;
      this.ProbabilityLabel.Location = new System.Drawing.Point (501, 12);
      this.ProbabilityLabel.Name = "ProbabilityLabel";
      this.ProbabilityLabel.Size = new System.Drawing.Size (55, 13);
      this.ProbabilityLabel.TabIndex = 28;
      this.ProbabilityLabel.Text = "Probability";
      this.ProbabilityLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // GroupName
      // 
      this.GroupName.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.GroupName.Location = new System.Drawing.Point (10, 125);
      this.GroupName.Name = "GroupName";
      this.GroupName.ReadOnly = true;
      this.GroupName.Size = new System.Drawing.Size (402, 22);
      this.GroupName.TabIndex = 27;
      this.GroupName.TabStop = false;
      // 
      // GroupNameLabel
      // 
      this.GroupNameLabel.AutoSize = true;
      this.GroupNameLabel.Location = new System.Drawing.Point (7, 109);
      this.GroupNameLabel.Name = "GroupNameLabel";
      this.GroupNameLabel.Size = new System.Drawing.Size (36, 13);
      this.GroupNameLabel.TabIndex = 26;
      this.GroupNameLabel.Text = "Group";
      this.GroupNameLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // SelectionCriteriaLabel
      // 
      this.SelectionCriteriaLabel.AutoSize = true;
      this.SelectionCriteriaLabel.Location = new System.Drawing.Point (20, 57);
      this.SelectionCriteriaLabel.Name = "SelectionCriteriaLabel";
      this.SelectionCriteriaLabel.Size = new System.Drawing.Size (86, 13);
      this.SelectionCriteriaLabel.TabIndex = 27;
      this.SelectionCriteriaLabel.Text = "Selection Criteria";
      // 
      // RunTimeParametersLabel
      // 
      this.RunTimeParametersLabel.AutoSize = true;
      this.RunTimeParametersLabel.Location = new System.Drawing.Point (20, 300);
      this.RunTimeParametersLabel.Name = "RunTimeParametersLabel";
      this.RunTimeParametersLabel.Size = new System.Drawing.Size (109, 13);
      this.RunTimeParametersLabel.TabIndex = 28;
      this.RunTimeParametersLabel.Text = "Run Time Parameters";
      // 
      // RunTimeStatusLabel
      // 
      this.RunTimeStatusLabel.AutoSize = true;
      this.RunTimeStatusLabel.Location = new System.Drawing.Point (20, 436);
      this.RunTimeStatusLabel.Name = "RunTimeStatusLabel";
      this.RunTimeStatusLabel.Size = new System.Drawing.Size (86, 13);
      this.RunTimeStatusLabel.TabIndex = 29;
      this.RunTimeStatusLabel.Text = "Run Time Status";
      // 
      // StatsTimer
      // 
      this.StatsTimer.Interval = 300;
      this.StatsTimer.Tick += new System.EventHandler (this.StatsTimer_Tick);
      // 
      // IncludeSampleImages
      // 
      this.IncludeSampleImages.AutoSize = true;
      this.IncludeSampleImages.Location = new System.Drawing.Point (304, 68);
      this.IncludeSampleImages.Name = "IncludeSampleImages";
      this.IncludeSampleImages.Size = new System.Drawing.Size (136, 17);
      this.IncludeSampleImages.TabIndex = 11;
      this.IncludeSampleImages.Text = "Include Sample Images";
      this.IncludeSampleImages.UseVisualStyleBackColor = true;
      // 
      // IncludeSampleImagesNumPerClass
      // 
      this.IncludeSampleImagesNumPerClass.FormattingEnabled = true;
      this.IncludeSampleImagesNumPerClass.Items.AddRange (new object[] {
            "1",
            "2",
            "5",
            "10",
            "20",
            "50",
            "100"});
      this.IncludeSampleImagesNumPerClass.Location = new System.Drawing.Point (455, 66);
      this.IncludeSampleImagesNumPerClass.Name = "IncludeSampleImagesNumPerClass";
      this.IncludeSampleImagesNumPerClass.Size = new System.Drawing.Size (44, 21);
      this.IncludeSampleImagesNumPerClass.TabIndex = 12;
      // 
      // IncludeSampleImagesNumPerClassLabel
      // 
      this.IncludeSampleImagesNumPerClassLabel.AutoSize = true;
      this.IncludeSampleImagesNumPerClassLabel.Location = new System.Drawing.Point (452, 52);
      this.IncludeSampleImagesNumPerClassLabel.Name = "IncludeSampleImagesNumPerClassLabel";
      this.IncludeSampleImagesNumPerClassLabel.Size = new System.Drawing.Size (51, 13);
      this.IncludeSampleImagesNumPerClassLabel.TabIndex = 13;
      this.IncludeSampleImagesNumPerClassLabel.Text = "Per Class";
      this.IncludeSampleImagesNumPerClassLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
      // 
      // SaveFeatureData
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF (6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size (702, 642);
      this.Controls.Add (this.RunTimeStatusLabel);
      this.Controls.Add (this.RunTimeParametersLabel);
      this.Controls.Add (this.SelectionCriteriaLabel);
      this.Controls.Add (this.RunTimeStatus);
      this.Controls.Add (this.RunTimeParameters);
      this.Controls.Add (this.CancelSaveButton);
      this.Controls.Add (this.StartButton);
      this.Controls.Add (this.TitleLabel);
      this.Controls.Add (this.SelectionCriteria);
      this.MaximumSize = new System.Drawing.Size (718, 680);
      this.MinimumSize = new System.Drawing.Size (718, 680);
      this.Name = "SaveFeatureData";
      this.Text = "SaveFeatureData";
      this.Load += new System.EventHandler (this.SaveFeatureData_Load);
      this.FormClosing += new System.Windows.Forms.FormClosingEventHandler (this.SaveFeatureData_FormClosing);
      ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit ();
      this.RunTimeParameters.ResumeLayout (false);
      this.RunTimeParameters.PerformLayout ();
      this.RunTimeStatus.ResumeLayout (false);
      this.RunTimeStatus.PerformLayout ();
      this.SelectionCriteria.ResumeLayout (false);
      this.SelectionCriteria.PerformLayout ();
      this.ResumeLayout (false);
      this.PerformLayout ();

    }

    #endregion

    private System.Windows.Forms.Label TitleLabel;
    private System.Windows.Forms.Label ImageCountlabel;
    private System.Windows.Forms.TextBox ImageCount;
    private System.Windows.Forms.Label FeatureFileNameLabel;
    private System.Windows.Forms.TextBox FeatureFileName;
    private System.Windows.Forms.Button FeatureFileNameBrowseButton;
    private System.Windows.Forms.ErrorProvider errorProvider1;
    private System.Windows.Forms.Button CancelSaveButton;
    private System.Windows.Forms.Button StartButton;
    private System.Windows.Forms.Label ImagesLoadedLabel;
    private System.Windows.Forms.TextBox ImagesLoaded;
    private System.Windows.Forms.Timer backGroundTimer;
    private System.Windows.Forms.Label MissingFeatureDataLabel;
    private System.Windows.Forms.TextBox ImagesMissingFeatureData;
    private System.Windows.Forms.Panel RunTimeParameters;
    private System.Windows.Forms.Panel RunTimeStatus;
    private System.Windows.Forms.Label StationsLabel;
    private System.Windows.Forms.Label DeploymentLabel;
    private System.Windows.Forms.Label SipperFileLabel;
    private System.Windows.Forms.Label CruiseLabel;
    private System.Windows.Forms.TextBox SipperFile;
    private System.Windows.Forms.TextBox DeploymentNum;
    private System.Windows.Forms.TextBox StationName;
    private System.Windows.Forms.TextBox CruiseName;
    private System.Windows.Forms.Panel SelectionCriteria;
    private System.Windows.Forms.TextBox GroupName;
    private System.Windows.Forms.Label GroupNameLabel;
    private System.Windows.Forms.Label SelectionCriteriaLabel;
    private System.Windows.Forms.Label RunTimeStatusLabel;
    private System.Windows.Forms.Label RunTimeParametersLabel;
    private System.Windows.Forms.TextBox BackGroundSatus;
    private System.Windows.Forms.Label BackGroundStatusLabel;
    private System.Windows.Forms.Timer StatsTimer;
    private System.Windows.Forms.ProgressBar SaveProgress;
    private System.Windows.Forms.TextBox ProbMin;
    private System.Windows.Forms.Label ProbabilityLabel;
    private System.Windows.Forms.TextBox ProbMax;
    private System.Windows.Forms.Label DepthLabel;
    private System.Windows.Forms.TextBox DepthMax;
    private System.Windows.Forms.TextBox DepthMin;
    private System.Windows.Forms.TextBox SizeMax;
    private System.Windows.Forms.TextBox SizeMin;
    private System.Windows.Forms.Label SizeLabel;
    private System.Windows.Forms.TextBox ImagesFilteredOut;
    private System.Windows.Forms.Label ImagesFilteredOutLabel;
    private System.Windows.Forms.TextBox ImagesWritten;
    private System.Windows.Forms.Label ImagesWrittenLabel;
    private System.Windows.Forms.Label FileFrmatLabel;
    private System.Windows.Forms.ComboBox FileFormat;
    private System.Windows.Forms.Label ClassNameLabel;
    private System.Windows.Forms.TextBox ClassName;
    private System.Windows.Forms.CheckBox NormalizeData;
    private System.Windows.Forms.CheckBox IncludeSampleImages;
    private System.Windows.Forms.ComboBox IncludeSampleImagesNumPerClass;
    private System.Windows.Forms.Label IncludeSampleImagesNumPerClassLabel;
  }
}