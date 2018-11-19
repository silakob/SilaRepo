using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Accord.Math;
using Accord.Controls;
using Accord.Math.Decompositions;
using Accord.Statistics;
using Accord.Statistics.Analysis;


namespace PCAApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            computeMeanAndSD();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        public void computeMeanAndSD()
        {
            double[] x1 = { 0, 8, 12, 20 };
            double[] x2 = { 8, 9, 11, 12 };

            //Find Means
            double meanX1 = x1.Mean();
            double meanX2 = x2.Mean();

            //Find SD
            double sdX1 = x1.StandardDeviation();
            double sdX2 = x2.StandardDeviation();

            Console.WriteLine("x1 = " + x1.ToString("G"));
            Console.WriteLine("x2 = " + x2.ToString("G"));
        }
    }
}
