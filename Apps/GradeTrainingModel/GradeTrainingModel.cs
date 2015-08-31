using System;
using System.Collections.Generic;
using System.Windows.Forms;
using PicesInterface;

namespace GradeTrainingModel
{
  static class GradeTrainingModel
  {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
      PicesSipperVariables.InitializeEnvironment ();
      Application.EnableVisualStyles();
      Application.SetCompatibleTextRenderingDefault(false);
      Application.Run(new GetRunTimeParameters());
    }
  }
}