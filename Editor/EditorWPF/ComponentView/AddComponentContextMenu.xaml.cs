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

namespace EditorWPF.ComponentView
{
   
    /// <summary>
    /// Interaction logic for AddComponentContextMenu.xaml
    /// </summary>
    public partial class AddComponentContextMenu : UserControl
    {
        public AddComponentContextMenu()
        {
            InitializeComponent();
        }
        private void component_list_Loaded(object sender, RoutedEventArgs e)
        {
            var components = ComponentSingleton.GetAddComponentContextMenuContent();
            foreach (var component in components)
            {
                component.Click += Component_Click;
                component_list.Children.Add(component);
            }

        }

        private void Component_Click(object sender, RoutedEventArgs e)
        {
            component_hide.Visibility = Visibility.Visible;
            component_list.Visibility = Visibility.Hidden;
            add_component_page.Children.Clear();
            component_name.Content = (sender as Button).Content;
            var content = (sender as Button).Tag as StackPanel;
            add_component_page.Children.Add(content);
            add_component_page.Visibility = Visibility.Visible;
        }

        private void component_hide_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            component_list.Visibility = Visibility.Visible;
            component_hide.Visibility = Visibility.Hidden;
            add_component_page.Children.Clear();
        }
    }
}
