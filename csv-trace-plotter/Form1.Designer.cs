namespace csv_trace_plotter
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		///  Clean up any resources being used.
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
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.panel1 = new System.Windows.Forms.Panel();
			this.formsPlot1 = new ScottPlot.FormsPlot();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
			this.panel1.Location = new System.Drawing.Point(1000, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(280, 720);
			this.panel1.TabIndex = 0;
			// 
			// formsPlot1
			// 
			this.formsPlot1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.formsPlot1.Location = new System.Drawing.Point(0, 0);
			this.formsPlot1.Margin = new System.Windows.Forms.Padding(7, 6, 7, 6);
			this.formsPlot1.Name = "formsPlot1";
			this.formsPlot1.Size = new System.Drawing.Size(1000, 720);
			this.formsPlot1.TabIndex = 1;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(13F, 32F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1280, 720);
			this.Controls.Add(this.formsPlot1);
			this.Controls.Add(this.panel1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private Panel panel1;
		private ScottPlot.FormsPlot formsPlot1;
	}
}