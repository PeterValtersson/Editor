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
        private TextBox editing_textbox;
        private String editing_name_backup;
        private EditorInterop.Engine engine;

        public SceneView(EditorInterop.Engine engine)
        {
            InitializeComponent();
            this.engine = engine;
        }

        private void NewScene_Click(object sender, RoutedEventArgs e)
        {
            var tree_view_item = new TreeViewItem();
            tree_view_item.Header = "New Scene";
            var entity = new Entity(engine.entity_factory().create());
            entity.Name = "New Scene";
            entity.OnNameChanged += (n) =>
            {
                selected_item.Header = n;
            };
            tree_view_item.Tag = entity;
            engine.scene().create(entity, "New Scene");
            if (selected_item is not null)
            {
                selected_item.Items.Add(tree_view_item);
                selected_item.ExpandSubtree();
            }
            else
                scene_tree.Items.Add(tree_view_item);

            tree_view_item.IsSelected = true;

        }

        private void Tree_view_item_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            var tvi = sender as TreeViewItem;
            var tb = new TextBox { Text = tvi.Header as string };
            tvi.Header = tb;

            tb.LostFocus += (o, e) =>
            {
                tvi.Header = tb.Text;
                (tvi.Tag as Entity).Name = tb.Text;
            };
        }

        private void scene_tree_MouseDown(object sender, MouseButtonEventArgs e)
        {
           
            if (e.RightButton == MouseButtonState.Pressed)
            {
                var item = VisualUpwardSearch(e.OriginalSource as DependencyObject);
                if (item is not null)
                {
                    item.Focus();
                    e.Handled = true;
                }
            }
            if (selected_item is not null && selected_item.Header is TextBox)
            {
                if (editing_textbox.Text == "")
                {
                    selected_item.Header = editing_name_backup;
                    e.Handled = true;
                }
                selected_item.Header = editing_textbox.Text;
                (selected_item.Tag as Entity).Name = editing_textbox.Text;
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
            ComponentSingleton.SetCurrentEntity(selected_item.Tag as Entity);
            e.Handled = true;
        }

        private void Rename_Click(object sender, RoutedEventArgs e)
        {
            editing_name_backup = selected_item.Header as string;
            editing_textbox = new TextBox { Text = new string(editing_name_backup) };
            editing_textbox.Height = selected_item.Height;
            editing_textbox.Loaded += (o, e) =>
            {
                editing_textbox.Focus();
            };
            editing_textbox.SelectAll();
            selected_item.Header = editing_textbox;
            editing_textbox.Loaded += delegate { 
                var c = Mouse.Capture(editing_textbox);
            };
            editing_textbox.PreviewMouseDown += Editing_textbox_PreviewMouseDown;
            editing_textbox.LostFocus += Editing_textbox_LostFocus;

            editing_textbox.KeyUp += Editing_textbox_KeyUp;
            e.Handled = true;
        }

        private void Editing_textbox_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            if(VisualTreeHelper.HitTest(editing_textbox, e.GetPosition(this)) == null)
            {
                if (selected_item.Header != editing_textbox)
                    return;
                if (editing_textbox.Text == "")
                {
                    selected_item.Header = editing_name_backup;
                    e.Handled = true;
                    return;
                }
                selected_item.Header = editing_textbox.Text;
                (selected_item.Tag as Entity).Name = editing_textbox.Text;
                e.Handled = true;
            }
        }

        private void Editing_textbox_LostFocus(object sender, RoutedEventArgs e)
        {
            if (selected_item.Header != editing_textbox)
                return;
            if (editing_textbox.Text == "")
            {
                selected_item.Header = editing_name_backup;
                e.Handled = true;
                return;
            }
            selected_item.Header = editing_textbox.Text;
            (selected_item.Tag as Entity).Name = editing_textbox.Text;
            e.Handled = true;
        }
        private void Editing_textbox_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                if (editing_textbox.Text == "")
                {
                    selected_item.Header = editing_name_backup;
                    e.Handled = true;
                    return;
                }
                selected_item.Header = editing_textbox.Text;
                (selected_item.Tag as Entity).Name = editing_textbox.Text;
                e.Handled = true;
            }
            else if (e.Key == Key.Escape)
            {
                selected_item.Header = editing_name_backup;
                e.Handled = true;
            }
        }

    }

}
