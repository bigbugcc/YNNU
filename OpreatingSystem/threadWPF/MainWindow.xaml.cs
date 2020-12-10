using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
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
using System.Windows.Threading;

namespace threadWPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btn_One_Click(object sender, RoutedEventArgs e)
        {
            btn_One.IsEnabled = false;
            for (int i = 0; i < 10000000; i++)
            {
                updataText(i.ToString());
                //ModifyUI(i.ToString());
            }
            
            btn_One.IsEnabled = true;
        }

        private void updataText(string i) {
            txt_show.Dispatcher.Invoke(() => {
                txt_show.Text = i;
            });
        }

        private void ModifyUI(string i)
        {
           
            this.Dispatcher.Invoke(DispatcherPriority.Normal, (ThreadStart)delegate ()
            {
                txt_show.Text = i;
            });

        }


        private void btn_More_Click(object sender, RoutedEventArgs e)
        {
            Thread thread = new Thread(ThreadMore);
            thread.Start();
            btn_More.IsEnabled = false;
        }

        private void ThreadMore()
        {
            
            for (int i = 0; i < 100000; i++)
            {
                this.Dispatcher.Invoke(DispatcherPriority.Normal, (ThreadStart)delegate {
                    txt_show.Text = i.ToString();
                });
            }
            this.Dispatcher.BeginInvoke(DispatcherPriority.Normal, (ThreadStart)delegate {
                btn_More.IsEnabled = true;
            });
        }
    }
}
