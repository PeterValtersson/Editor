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
    /// Interaction logic for SceneView.xaml
    /// </summary>
    public partial class SceneView : UserControl
    {
        private TreeViewItem selected_item;
        public SceneView()
        {
            InitializeComponent();
        }

        private void MenuItem_Click(object sender, RoutedEventArgs e)
        {
            var text = new TreeViewItem();
            text.Header = "Test";
            if (selected_item is not null)
            {
                selected_item.Items.Add(text);
                selected_item.ExpandSubtree();
            }
            else
                scene_tree.Items.Add(text);
        }   

        private void scene_tree_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.RightButton == MouseButtonState.Pressed)
            {
                var item = VisualUpwardSearch(e.OriginalSource as DependencyObject);
                if(item is not null)
                {
                    item.Focus();
                    e.Handled = true;
                }
            }
        }

        private static TreeViewItem VisualUpwardSearch(DependencyObject source)
        {
            while (source != null && !(source is TreeViewItem))
                source = VisualTreeHelper.GetParent(source);

            return source as TreeViewItem;
        }

        private void scene_tree_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            selected_item = e.NewValue as TreeViewItem;
            e.Handled = true;
        }
    }

}
