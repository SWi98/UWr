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
    class DataForListView
    {
        public string Name { get; set; }
        public string Surname { get; set; }
    }
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            DataForListView temp = new DataForListView();
            temp.Name = textBox.Text;
            temp.Surname = textBox1.Text;
            listView.Items.Add(temp);
            //listView.ItemsSource = test;
        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
       

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            TreeViewItem node = new TreeViewItem();
            node.Header = textBox2.Text;
            treeView.Items.Add(node);
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
        }

        private void textBox2_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void ProgressBar_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {

        }
    }
}
