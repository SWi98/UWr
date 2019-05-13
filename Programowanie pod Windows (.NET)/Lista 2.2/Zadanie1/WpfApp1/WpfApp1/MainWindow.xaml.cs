using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string textToPass;
        public MainWindow()
        {
            InitializeComponent();
            textToPass = "";
        }

        private void textBox1_TextChanged(object sender, TextChangedEventArgs e)
        {
        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void checkBox1_Checked(object sender, RoutedEventArgs e)
        {

        }

        private void checkBox_Checked(object sender, RoutedEventArgs e)
        {

        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            bool cond = checkBox.IsChecked.Value && checkBox1.IsChecked.Value;
            if (!cond)
            {
                textToPass = textBox.Text + "\r\n" + textBox1.Text
                    + "\r\n" + comboBox.Text;
                if (checkBox.IsChecked.Value)
                    textToPass += "\r\n" + checkBox.Content;
                else if (checkBox1.IsChecked.Value)
                    textToPass += "\r\n" + checkBox1.Content;
                Window1 win2 = new Window1(textToPass);
                win2.Show();
                this.Close();
            }
            
            
        }

        private void comboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            /*comboBox.Items.Add("3-letnie");
            comboBox.Items.Add("5-letnie");*/
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
