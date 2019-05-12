using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie1
{
    public partial class Form1 : Form
    {
        private string textToPass;
        public Form1()
        {
            InitializeComponent();
            textToPass = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            if (!(checkBox1.Checked && checkBox2.Checked)){
                textToPass = textBox1.Text + "\r\n" + textBox2.Text
                    + "\r\n" + comboBox1.Text;
                if (checkBox1.Checked)
                    textToPass += "\r\n" + checkBox1.Text;
                else if (checkBox2.Checked)
                    textToPass += "\r\n" + checkBox2.Text;
                this.Hide();
                Form2 f2 = new Form2(textToPass);
                f2.Show();
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
