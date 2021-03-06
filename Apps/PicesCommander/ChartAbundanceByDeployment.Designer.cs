﻿namespace PicesCommander
{
  partial class ChartAbundanceByDeployment
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose (bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose ();
      }
      base.Dispose (disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent ()
    {
      this.components = new System.ComponentModel.Container ();
      System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea ();
      System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend ();
      System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title ();
      this.PlotButton = new System.Windows.Forms.Button ();
      this.CancelPlotButton = new System.Windows.Forms.Button ();
      this.ProfileChart = new System.Windows.Forms.DataVisualization.Charting.Chart ();
      this.DepthIncr = new System.Windows.Forms.NumericUpDown ();
      this.timer1 = new System.Windows.Forms.Timer (this.components);
      this.DepthIncrLabel = new System.Windows.Forms.Label ();
      this.Status = new System.Windows.Forms.TextBox ();
      this.DeploymentsToPlot = new System.Windows.Forms.CheckedListBox ();
      this.ClearAllButton = new System.Windows.Forms.Button ();
      this.SelectAllButton = new System.Windows.Forms.Button ();
      this.ClassToPlot = new System.Windows.Forms.TextBox ();
      this.SelectClassButton = new System.Windows.Forms.Button ();
      this.ClassToPlotLabel = new System.Windows.Forms.Label ();
      this.IncludeSubClasses = new System.Windows.Forms.CheckBox ();
      this.WeightByVolume = new System.Windows.Forms.CheckBox ();
      this.SelectionCriteriaPanel = new System.Windows.Forms.Panel ();
      this.CriteriaLabel = new System.Windows.Forms.Label ();
      this.Criteria_ = new System.Windows.Forms.TextBox ();
      this.Deployment_ = new System.Windows.Forms.TextBox ();
      this.Station_ = new System.Windows.Forms.TextBox ();
      this.Cruise_ = new System.Windows.Forms.TextBox ();
      this.DeploymentLabel = new System.Windows.Forms.Label ();
      this.CruiseLabel = new System.Windows.Forms.Label ();
      this.StationLabel = new System.Windows.Forms.Label ();
      this.DepthIncrementLabel = new System.Windows.Forms.Label ();
      this.DepthAxisInterval = new System.Windows.Forms.NumericUpDown ();
      this.MaxDepthLabel = new System.Windows.Forms.Label ();
      this.DepthAxisMax = new System.Windows.Forms.NumericUpDown ();
      this.MinDepthLabel = new System.Windows.Forms.Label ();
      this.DepthAxisAuto = new System.Windows.Forms.CheckBox ();
      this.DepthAxisMin = new System.Windows.Forms.NumericUpDown ();
      ((System.ComponentModel.ISupportInitialize)(this.ProfileChart)).BeginInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthIncr)).BeginInit ();
      this.SelectionCriteriaPanel.SuspendLayout ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisInterval)).BeginInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisMax)).BeginInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisMin)).BeginInit ();
      this.SuspendLayout ();
      // 
      // PlotButton
      // 
      this.PlotButton.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.PlotButton.Location = new System.Drawing.Point (12, 623);
      this.PlotButton.Name = "PlotButton";
      this.PlotButton.Size = new System.Drawing.Size (75, 23);
      this.PlotButton.TabIndex = 28;
      this.PlotButton.Text = "Plot";
      this.PlotButton.UseVisualStyleBackColor = true;
      this.PlotButton.Click += new System.EventHandler (this.PlotButton_Click);
      // 
      // CancelPlotButton
      // 
      this.CancelPlotButton.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.CancelPlotButton.Location = new System.Drawing.Point (353, 623);
      this.CancelPlotButton.Name = "CancelPlotButton";
      this.CancelPlotButton.Size = new System.Drawing.Size (75, 23);
      this.CancelPlotButton.TabIndex = 29;
      this.CancelPlotButton.Text = "Cancel";
      this.CancelPlotButton.UseVisualStyleBackColor = true;
      this.CancelPlotButton.Click += new System.EventHandler (this.CancelPlotButton_Click);
      // 
      // ProfileChart
      // 
      this.ProfileChart.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid;
      this.ProfileChart.CausesValidation = false;
      chartArea1.AlignmentOrientation = ((System.Windows.Forms.DataVisualization.Charting.AreaAlignmentOrientations)((System.Windows.Forms.DataVisualization.Charting.AreaAlignmentOrientations.Vertical | System.Windows.Forms.DataVisualization.Charting.AreaAlignmentOrientations.Horizontal)));
      chartArea1.AlignWithChartArea = "ChartArea1";
      chartArea1.AxisX.LabelAutoFitMaxFontSize = 12;
      chartArea1.AxisX.LabelAutoFitMinFontSize = 10;
      chartArea1.AxisX.LabelStyle.Format = "##0.000";
      chartArea1.AxisX.MajorGrid.Enabled = false;
      chartArea1.AxisX.Title = "Count/m_3";
      chartArea1.AxisX2.LabelStyle.Format = "##0.00";
      chartArea1.AxisX2.MajorGrid.Enabled = false;
      chartArea1.AxisY.IsStartedFromZero = false;
      chartArea1.AxisY.LabelAutoFitMaxFontSize = 12;
      chartArea1.AxisY.LabelAutoFitMinFontSize = 10;
      chartArea1.AxisY.LabelStyle.Format = "#0.000";
      chartArea1.AxisY.MajorGrid.Enabled = false;
      chartArea1.AxisY.MajorTickMark.Interval = 0;
      chartArea1.AxisY.MajorTickMark.IntervalOffset = 0;
      chartArea1.AxisY.MajorTickMark.IntervalOffsetType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
      chartArea1.AxisY.MajorTickMark.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Number;
      chartArea1.AxisY.Title = "Depth (m)";
      chartArea1.AxisY2.MajorGrid.Enabled = false;
      chartArea1.BorderDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid;
      chartArea1.Name = "ChartArea1";
      this.ProfileChart.ChartAreas.Add (chartArea1);
      legend1.Alignment = System.Drawing.StringAlignment.Far;
      legend1.DockedToChartArea = "ChartArea1";
      legend1.Docking = System.Windows.Forms.DataVisualization.Charting.Docking.Bottom;
      legend1.IsDockedInsideChartArea = false;
      legend1.Name = "Legend1";
      this.ProfileChart.Legends.Add (legend1);
      this.ProfileChart.Location = new System.Drawing.Point (447, 12);
      this.ProfileChart.Name = "ProfileChart";
      this.ProfileChart.Size = new System.Drawing.Size (521, 600);
      this.ProfileChart.TabIndex = 30;
      this.ProfileChart.Text = "Abundance/Deployment";
      title1.Name = "Title1";
      this.ProfileChart.Titles.Add (title1);
      // 
      // DepthIncr
      // 
      this.DepthIncr.Font = new System.Drawing.Font ("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.DepthIncr.Location = new System.Drawing.Point (355, 498);
      this.DepthIncr.Minimum = new decimal (new int[] {
            5,
            0,
            0,
            65536});
      this.DepthIncr.Name = "DepthIncr";
      this.DepthIncr.Size = new System.Drawing.Size (73, 23);
      this.DepthIncr.TabIndex = 31;
      this.DepthIncr.Value = new decimal (new int[] {
            10,
            0,
            0,
            65536});
      // 
      // timer1
      // 
      this.timer1.Interval = 50;
      this.timer1.Tick += new System.EventHandler (this.timer1_Tick);
      // 
      // DepthIncrLabel
      // 
      this.DepthIncrLabel.AutoSize = true;
      this.DepthIncrLabel.Location = new System.Drawing.Point (346, 482);
      this.DepthIncrLabel.Name = "DepthIncrLabel";
      this.DepthIncrLabel.Size = new System.Drawing.Size (86, 13);
      this.DepthIncrLabel.TabIndex = 32;
      this.DepthIncrLabel.Text = "Depth Increment";
      // 
      // Status
      // 
      this.Status.Font = new System.Drawing.Font ("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.Status.Location = new System.Drawing.Point (12, 594);
      this.Status.Name = "Status";
      this.Status.ReadOnly = true;
      this.Status.Size = new System.Drawing.Size (416, 23);
      this.Status.TabIndex = 35;
      this.Status.TabStop = false;
      // 
      // DeploymentsToPlot
      // 
      this.DeploymentsToPlot.CheckOnClick = true;
      this.DeploymentsToPlot.Font = new System.Drawing.Font ("Courier New", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.DeploymentsToPlot.FormattingEnabled = true;
      this.DeploymentsToPlot.Location = new System.Drawing.Point (12, 181);
      this.DeploymentsToPlot.Name = "DeploymentsToPlot";
      this.DeploymentsToPlot.Size = new System.Drawing.Size (416, 232);
      this.DeploymentsToPlot.TabIndex = 46;
      this.DeploymentsToPlot.Format += new System.Windows.Forms.ListControlConvertEventHandler (this.DeploymentsToPlot_Format);
      // 
      // ClearAllButton
      // 
      this.ClearAllButton.Font = new System.Drawing.Font ("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.ClearAllButton.Location = new System.Drawing.Point (12, 149);
      this.ClearAllButton.Name = "ClearAllButton";
      this.ClearAllButton.Size = new System.Drawing.Size (75, 22);
      this.ClearAllButton.TabIndex = 50;
      this.ClearAllButton.Text = "Clear All";
      this.ClearAllButton.UseVisualStyleBackColor = true;
      this.ClearAllButton.Click += new System.EventHandler (this.ClearAllButton_Click);
      // 
      // SelectAllButton
      // 
      this.SelectAllButton.Font = new System.Drawing.Font ("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.SelectAllButton.Location = new System.Drawing.Point (93, 149);
      this.SelectAllButton.Name = "SelectAllButton";
      this.SelectAllButton.Size = new System.Drawing.Size (75, 22);
      this.SelectAllButton.TabIndex = 51;
      this.SelectAllButton.Text = "Select All";
      this.SelectAllButton.UseVisualStyleBackColor = true;
      this.SelectAllButton.Click += new System.EventHandler (this.SelectAllButton_Click);
      // 
      // ClassToPlot
      // 
      this.ClassToPlot.Location = new System.Drawing.Point (12, 442);
      this.ClassToPlot.Name = "ClassToPlot";
      this.ClassToPlot.ReadOnly = true;
      this.ClassToPlot.Size = new System.Drawing.Size (343, 20);
      this.ClassToPlot.TabIndex = 52;
      // 
      // SelectClassButton
      // 
      this.SelectClassButton.Font = new System.Drawing.Font ("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.SelectClassButton.Location = new System.Drawing.Point (361, 439);
      this.SelectClassButton.Name = "SelectClassButton";
      this.SelectClassButton.Size = new System.Drawing.Size (67, 23);
      this.SelectClassButton.TabIndex = 53;
      this.SelectClassButton.Text = "Browse";
      this.SelectClassButton.UseVisualStyleBackColor = true;
      this.SelectClassButton.Click += new System.EventHandler (this.SelectClassButton_Click);
      // 
      // ClassToPlotLabel
      // 
      this.ClassToPlotLabel.AutoSize = true;
      this.ClassToPlotLabel.Location = new System.Drawing.Point (9, 426);
      this.ClassToPlotLabel.Name = "ClassToPlotLabel";
      this.ClassToPlotLabel.Size = new System.Drawing.Size (32, 13);
      this.ClassToPlotLabel.TabIndex = 54;
      this.ClassToPlotLabel.Text = "Class";
      // 
      // IncludeSubClasses
      // 
      this.IncludeSubClasses.AutoSize = true;
      this.IncludeSubClasses.Checked = true;
      this.IncludeSubClasses.CheckState = System.Windows.Forms.CheckState.Checked;
      this.IncludeSubClasses.Font = new System.Drawing.Font ("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.IncludeSubClasses.Location = new System.Drawing.Point (12, 499);
      this.IncludeSubClasses.Name = "IncludeSubClasses";
      this.IncludeSubClasses.Size = new System.Drawing.Size (155, 21);
      this.IncludeSubClasses.TabIndex = 55;
      this.IncludeSubClasses.Text = "Include Sub-Classes";
      this.IncludeSubClasses.UseVisualStyleBackColor = true;
      // 
      // WeightByVolume
      // 
      this.WeightByVolume.AutoSize = true;
      this.WeightByVolume.Checked = true;
      this.WeightByVolume.CheckState = System.Windows.Forms.CheckState.Checked;
      this.WeightByVolume.Font = new System.Drawing.Font ("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
      this.WeightByVolume.Location = new System.Drawing.Point (187, 499);
      this.WeightByVolume.Name = "WeightByVolume";
      this.WeightByVolume.Size = new System.Drawing.Size (141, 21);
      this.WeightByVolume.TabIndex = 56;
      this.WeightByVolume.Text = "Weight by Volume";
      this.WeightByVolume.UseVisualStyleBackColor = true;
      // 
      // SelectionCriteriaPanel
      // 
      this.SelectionCriteriaPanel.BackColor = System.Drawing.Color.FromArgb (((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
      this.SelectionCriteriaPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
      this.SelectionCriteriaPanel.Controls.Add (this.CriteriaLabel);
      this.SelectionCriteriaPanel.Controls.Add (this.Criteria_);
      this.SelectionCriteriaPanel.Controls.Add (this.Deployment_);
      this.SelectionCriteriaPanel.Controls.Add (this.Station_);
      this.SelectionCriteriaPanel.Controls.Add (this.Cruise_);
      this.SelectionCriteriaPanel.Controls.Add (this.DeploymentLabel);
      this.SelectionCriteriaPanel.Controls.Add (this.CruiseLabel);
      this.SelectionCriteriaPanel.Controls.Add (this.StationLabel);
      this.SelectionCriteriaPanel.Location = new System.Drawing.Point (12, 12);
      this.SelectionCriteriaPanel.Name = "SelectionCriteriaPanel";
      this.SelectionCriteriaPanel.Size = new System.Drawing.Size (416, 117);
      this.SelectionCriteriaPanel.TabIndex = 57;
      // 
      // CriteriaLabel
      // 
      this.CriteriaLabel.AutoSize = true;
      this.CriteriaLabel.Location = new System.Drawing.Point (3, 63);
      this.CriteriaLabel.Name = "CriteriaLabel";
      this.CriteriaLabel.Size = new System.Drawing.Size (39, 13);
      this.CriteriaLabel.TabIndex = 12;
      this.CriteriaLabel.Text = "Criteria";
      // 
      // Criteria_
      // 
      this.Criteria_.Location = new System.Drawing.Point (3, 79);
      this.Criteria_.Name = "Criteria_";
      this.Criteria_.ReadOnly = true;
      this.Criteria_.Size = new System.Drawing.Size (408, 20);
      this.Criteria_.TabIndex = 11;
      // 
      // Deployment_
      // 
      this.Deployment_.Location = new System.Drawing.Point (323, 30);
      this.Deployment_.Name = "Deployment_";
      this.Deployment_.ReadOnly = true;
      this.Deployment_.Size = new System.Drawing.Size (88, 20);
      this.Deployment_.TabIndex = 10;
      // 
      // Station_
      // 
      this.Station_.Location = new System.Drawing.Point (210, 30);
      this.Station_.Name = "Station_";
      this.Station_.ReadOnly = true;
      this.Station_.Size = new System.Drawing.Size (88, 20);
      this.Station_.TabIndex = 9;
      // 
      // Cruise_
      // 
      this.Cruise_.Location = new System.Drawing.Point (3, 30);
      this.Cruise_.Name = "Cruise_";
      this.Cruise_.ReadOnly = true;
      this.Cruise_.Size = new System.Drawing.Size (173, 20);
      this.Cruise_.TabIndex = 8;
      // 
      // DeploymentLabel
      // 
      this.DeploymentLabel.AutoSize = true;
      this.DeploymentLabel.Location = new System.Drawing.Point (320, 14);
      this.DeploymentLabel.Name = "DeploymentLabel";
      this.DeploymentLabel.Size = new System.Drawing.Size (63, 13);
      this.DeploymentLabel.TabIndex = 7;
      this.DeploymentLabel.Text = "Deployment";
      // 
      // CruiseLabel
      // 
      this.CruiseLabel.AutoSize = true;
      this.CruiseLabel.Location = new System.Drawing.Point (3, 14);
      this.CruiseLabel.Name = "CruiseLabel";
      this.CruiseLabel.Size = new System.Drawing.Size (36, 13);
      this.CruiseLabel.TabIndex = 3;
      this.CruiseLabel.Text = "Cruise";
      // 
      // StationLabel
      // 
      this.StationLabel.AutoSize = true;
      this.StationLabel.Location = new System.Drawing.Point (207, 14);
      this.StationLabel.Name = "StationLabel";
      this.StationLabel.Size = new System.Drawing.Size (40, 13);
      this.StationLabel.TabIndex = 5;
      this.StationLabel.Text = "Station";
      // 
      // DepthIncrementLabel
      // 
      this.DepthIncrementLabel.AutoSize = true;
      this.DepthIncrementLabel.Location = new System.Drawing.Point (323, 540);
      this.DepthIncrementLabel.Name = "DepthIncrementLabel";
      this.DepthIncrementLabel.Size = new System.Drawing.Size (42, 13);
      this.DepthIncrementLabel.TabIndex = 64;
      this.DepthIncrementLabel.Text = "Interval";
      // 
      // DepthAxisInterval
      // 
      this.DepthAxisInterval.DecimalPlaces = 1;
      this.DepthAxisInterval.Increment = new decimal (new int[] {
            5,
            0,
            0,
            65536});
      this.DepthAxisInterval.Location = new System.Drawing.Point (324, 556);
      this.DepthAxisInterval.Name = "DepthAxisInterval";
      this.DepthAxisInterval.Size = new System.Drawing.Size (63, 20);
      this.DepthAxisInterval.TabIndex = 63;
      this.DepthAxisInterval.Value = new decimal (new int[] {
            5,
            0,
            0,
            0});
      // 
      // MaxDepthLabel
      // 
      this.MaxDepthLabel.AutoSize = true;
      this.MaxDepthLabel.Location = new System.Drawing.Point (233, 540);
      this.MaxDepthLabel.Name = "MaxDepthLabel";
      this.MaxDepthLabel.Size = new System.Drawing.Size (59, 13);
      this.MaxDepthLabel.TabIndex = 62;
      this.MaxDepthLabel.Text = "Max Depth";
      // 
      // DepthAxisMax
      // 
      this.DepthAxisMax.Location = new System.Drawing.Point (234, 556);
      this.DepthAxisMax.Maximum = new decimal (new int[] {
            500,
            0,
            0,
            0});
      this.DepthAxisMax.Name = "DepthAxisMax";
      this.DepthAxisMax.Size = new System.Drawing.Size (63, 20);
      this.DepthAxisMax.TabIndex = 61;
      this.DepthAxisMax.Value = new decimal (new int[] {
            100,
            0,
            0,
            0});
      // 
      // MinDepthLabel
      // 
      this.MinDepthLabel.AutoSize = true;
      this.MinDepthLabel.Location = new System.Drawing.Point (143, 540);
      this.MinDepthLabel.Name = "MinDepthLabel";
      this.MinDepthLabel.Size = new System.Drawing.Size (56, 13);
      this.MinDepthLabel.TabIndex = 60;
      this.MinDepthLabel.Text = "Min Depth";
      // 
      // DepthAxisAuto
      // 
      this.DepthAxisAuto.AutoSize = true;
      this.DepthAxisAuto.Checked = true;
      this.DepthAxisAuto.CheckState = System.Windows.Forms.CheckState.Checked;
      this.DepthAxisAuto.Location = new System.Drawing.Point (12, 557);
      this.DepthAxisAuto.Name = "DepthAxisAuto";
      this.DepthAxisAuto.Size = new System.Drawing.Size (102, 17);
      this.DepthAxisAuto.TabIndex = 59;
      this.DepthAxisAuto.Text = "Auto Depth Axis";
      this.DepthAxisAuto.UseVisualStyleBackColor = true;
      // 
      // DepthAxisMin
      // 
      this.DepthAxisMin.Location = new System.Drawing.Point (144, 556);
      this.DepthAxisMin.Maximum = new decimal (new int[] {
            300,
            0,
            0,
            0});
      this.DepthAxisMin.Name = "DepthAxisMin";
      this.DepthAxisMin.Size = new System.Drawing.Size (63, 20);
      this.DepthAxisMin.TabIndex = 58;
      // 
      // ChartAbundanceByDeployment
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF (6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size (981, 658);
      this.Controls.Add (this.DepthIncrementLabel);
      this.Controls.Add (this.DepthAxisInterval);
      this.Controls.Add (this.MaxDepthLabel);
      this.Controls.Add (this.DepthAxisMax);
      this.Controls.Add (this.MinDepthLabel);
      this.Controls.Add (this.DepthAxisAuto);
      this.Controls.Add (this.DepthAxisMin);
      this.Controls.Add (this.SelectionCriteriaPanel);
      this.Controls.Add (this.WeightByVolume);
      this.Controls.Add (this.IncludeSubClasses);
      this.Controls.Add (this.ClassToPlotLabel);
      this.Controls.Add (this.SelectClassButton);
      this.Controls.Add (this.ClassToPlot);
      this.Controls.Add (this.SelectAllButton);
      this.Controls.Add (this.ClearAllButton);
      this.Controls.Add (this.DeploymentsToPlot);
      this.Controls.Add (this.Status);
      this.Controls.Add (this.DepthIncrLabel);
      this.Controls.Add (this.DepthIncr);
      this.Controls.Add (this.ProfileChart);
      this.Controls.Add (this.CancelPlotButton);
      this.Controls.Add (this.PlotButton);
      this.Name = "ChartAbundanceByDeployment";
      this.Text = "Chart Abundance by Deployment";
      this.Load += new System.EventHandler (this.ChartAbundanceByDeployment_Load);
      this.SizeChanged += new System.EventHandler (this.ChartAbundanceByDeployment_SizeChanged);
      this.FormClosing += new System.Windows.Forms.FormClosingEventHandler (this.ChartAbundanceByDeployment_FormClosing);
      this.Resize += new System.EventHandler (this.ChartAbundanceByDeployment_Resize);
      ((System.ComponentModel.ISupportInitialize)(this.ProfileChart)).EndInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthIncr)).EndInit ();
      this.SelectionCriteriaPanel.ResumeLayout (false);
      this.SelectionCriteriaPanel.PerformLayout ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisInterval)).EndInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisMax)).EndInit ();
      ((System.ComponentModel.ISupportInitialize)(this.DepthAxisMin)).EndInit ();
      this.ResumeLayout (false);
      this.PerformLayout ();

    }

    #endregion

    private System.Windows.Forms.Button PlotButton;
    private System.Windows.Forms.Button CancelPlotButton;
    private System.Windows.Forms.DataVisualization.Charting.Chart ProfileChart;
    private System.Windows.Forms.NumericUpDown DepthIncr;
    private System.Windows.Forms.Timer timer1;
    private System.Windows.Forms.Label DepthIncrLabel;
    private System.Windows.Forms.TextBox Status;
    private System.Windows.Forms.CheckedListBox DeploymentsToPlot;
    private System.Windows.Forms.Button ClearAllButton;
    private System.Windows.Forms.Button SelectAllButton;
    private System.Windows.Forms.TextBox ClassToPlot;
    private System.Windows.Forms.Button SelectClassButton;
    private System.Windows.Forms.Label ClassToPlotLabel;
    private System.Windows.Forms.CheckBox IncludeSubClasses;
    private System.Windows.Forms.CheckBox WeightByVolume;
    private System.Windows.Forms.Panel SelectionCriteriaPanel;
    private System.Windows.Forms.Label DeploymentLabel;
    private System.Windows.Forms.Label CruiseLabel;
    private System.Windows.Forms.Label StationLabel;
    private System.Windows.Forms.Label CriteriaLabel;
    private System.Windows.Forms.TextBox Criteria_;
    private System.Windows.Forms.TextBox Deployment_;
    private System.Windows.Forms.TextBox Station_;
    private System.Windows.Forms.TextBox Cruise_;
    private System.Windows.Forms.Label DepthIncrementLabel;
    private System.Windows.Forms.NumericUpDown DepthAxisInterval;
    private System.Windows.Forms.Label MaxDepthLabel;
    private System.Windows.Forms.NumericUpDown DepthAxisMax;
    private System.Windows.Forms.Label MinDepthLabel;
    private System.Windows.Forms.CheckBox DepthAxisAuto;
    private System.Windows.Forms.NumericUpDown DepthAxisMin;


  }
}