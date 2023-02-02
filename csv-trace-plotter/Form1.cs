namespace csv_trace_plotter
{
	public partial class Form1 : Form
	{
		struct entry
		{
			public string name;
			public List<txy> data;
			public bool show;
			public ScottPlot.Plottable.IPlottable assocplot;
		}
		struct txy
		{
			public float t;
			public float x;
			public float y;
		}
		List<entry> datas;

		double[] rollasarray(entry e, int index)
		{
			double[] ar = new double[e.data.Count];
			for (int i = 0; i < e.data.Count; i++)
			{
				switch (index)
				{
					case 0:
						ar[i] = e.data[i].x;
						break;
					case 1:
						ar[i] = e.data[i].y;
						break;
					default:
						break;
				}
			}
			return ar;
		}

		entry parsecsv(string[] src, string name = "")
		{
			//time, x, y order is assumed!
			entry c = new entry();
			c.name = (name != "") ? name : ("entry" + " " + (datas.Count + 1));
			c.data = new List<txy>();
			for (int i = 1; i < src.Length; i++)
			{
				txy x = new txy();
				string[] a = src[i].Trim().Split(',');
				x.t = int.Parse(a[0]);
				x.x = int.Parse(a[1]);
				x.y = int.Parse(a[2]);
				c.data.Add(x);
			}
			datas.Add(c);
			return c;
		}


		public Form1()
		{
			InitializeComponent();
			formsPlot1.Refresh();
			comboBox1.SelectedIndex = 0;
			datas = new();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			openFileDialog1.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
			if (openFileDialog1.ShowDialog(this) == DialogResult.OK) textBox1.Text = openFileDialog1.FileName;
		}

		static int c = 1;
		private void button2_Click(object sender, EventArgs e)
		{
			if (true)
			{
				var parsed = parsecsv(new string[]
					{
						"time, x, y",
						"1 , 0, 0",
						"2 , 10, 10",
						"3 , 10, 20",
						"4 , 20, 20",
						"5,"+(c*5+20)+","+(10*(c++)),
				});
				parsed.assocplot = new ScottPlot.Plottable.ScatterPlot(rollasarray(datas.Last(), 0), rollasarray(datas.Last(), 1));
				formsPlot1.Plot.Add(parsed.assocplot); //workaround...
				formsPlot1.Refresh();
				checkedListBox1.SetItemChecked(checkedListBox1.Items.Add(parsed.name), true);
			}

			if (File.Exists(textBox1.Text))
			{
				parsecsv(File.ReadAllLines(textBox1.Text));
				formsPlot1.Plot.AddScatter(rollasarray(datas.Last(), 0), rollasarray(datas.Last(), 1));
			}
			else MessageBox.Show(this, "No File", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}

		private void checkedListBox1_ItemCheck(object sender, ItemCheckEventArgs e)
		{
			/*
			if (e.NewValue == CheckState.Checked)
			{
				formsPlot1.Plot.Add(datas[e.Index].assocplot);
				formsPlot1.Refresh();
			}
			if (e.NewValue == CheckState.Unchecked)
			{
				formsPlot1.Plot.Remove(datas[e.Index].assocplot);
				formsPlot1.Refresh();
			}
			*/
		}

		private void button3_Click(object sender, EventArgs e)
		{
			datas.Clear();
			checkedListBox1.Items.Clear();
			formsPlot1.Plot.Clear();
			formsPlot1.Refresh();
		}
	}
}