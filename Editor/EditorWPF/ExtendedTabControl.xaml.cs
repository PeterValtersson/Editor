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

namespace EditorWPF
{
    /// <summary>
    /// Interaction logic for ExtendedTabControl.xaml
    /// </summary>
    public partial class ExtendedTabControl : UserControl
    {
        public ExtendedTabControl()
        {
            InitializeComponent();
            var view = CollectionViewSource.GetDefaultView(tab_panel.Items);
            view.CollectionChanged += View_CollectionChanged;
        }

        private void View_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
            if(tab_panel.Items.Count > 1)
            {
                foreach (TabItem tab in tab_panel.Items)
                {
                    tab.Visibility = Visibility.Visible;
                }
            }
            else
            {
                foreach (TabItem tab in tab_panel.Items)
                {
                    tab.Visibility = Visibility.Collapsed;
                }
            }
        }

        public void add_tab(Control control)
        {
            var tab_item = new TabItem();
            tab_item.Header = control.Name;
            tab_item.Tag = control;
            tab_item.Content = new TabView(control);
            tab_panel.Items.Add(tab_item);
        }

    }
}
