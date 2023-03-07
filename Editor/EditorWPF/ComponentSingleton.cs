using EditorWPF.ComponentView;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace EditorWPF
{
    public class Field
    {
        public string Type;
        public string Name;
        public string Value;
        public List<string> Values;
        public List<Field> Fields;
    }
    public class Fields
    {
        public List<Field> Flags;
    }
    public class Reflection
    {
        public List<Field> Fields;
        public string Name;
    }
    public static class ComponentSingleton
    {
        public static List<EditorInterop.ComponentReflection> _components;
        public static void Initialize(List<EditorInterop.ComponentReflection> components)
        {
            _components = components;
        }
        public static List<Button> GetAddComponentContextMenuContent()
        {
            if (_components == null)
                throw new Exception("Not initialized");
            var component_buttons = new List<Button>();
            foreach (var component in _components)
            {
                var button = new Button();
                button.Content = component.get_name();

                var jsonData = component.get_reflection_meta_data();
                var json = JsonConvert.DeserializeObject<Reflection>(jsonData);
                var stackpanel = new StackPanel();
                foreach (var field in json.Fields)
                {
                    if (field.Fields == null)
                    {
                        var grid = new Grid();
                        grid.RowDefinitions.Add(new RowDefinition());
                        grid.RowDefinitions.Add(new RowDefinition());
                        grid.ColumnDefinitions.Add(new ColumnDefinition());
                        var name = new Label();
                        name.Content = field.Name;
                        Grid.SetRow(name, 0);
                        var value = new TextBox();
                        //value.Text = field.Value;
                        Grid.SetRow(value, 1);
                        grid.Children.Add(name);
                        grid.Children.Add(value);
                        stackpanel.Children.Add(grid);
                    }
                    else
                    {
                        var grid = new Grid();
                        grid.RowDefinitions.Add(new RowDefinition());
                        grid.RowDefinitions.Add(new RowDefinition());
                        var name = new Label();
                        name.Content = field.Name;
                        Grid.SetRow(name, 0);
                        var grid2 = new Grid();
                        grid2.RowDefinitions.Add(new RowDefinition());
                        Grid.SetRow(grid2, 1);
                        grid.Children.Add(name);
                        grid.Children.Add(grid2);
                        int c = 0;
                        foreach (var field2 in field.Fields)
                        {
                            grid2.ColumnDefinitions.Add(new ColumnDefinition());
                            grid2.ColumnDefinitions.Add(new ColumnDefinition());
                            var name2 = new Label();
                            name2.Content = field2.Name;
                            Grid.SetColumn(name2, c*2);
                            var value = new TextBox();
                            //value.Text = field2.Value;
                            Grid.SetColumn(value, c*2+1);
                            grid2.Children.Add(name2);
                            grid2.Children.Add(value);
                            c++;
                        }
                        stackpanel.Children.Add(grid);
                    }
                }
                button.Tag = stackpanel;
                component_buttons.Add(button);
            }
            return component_buttons;
        }
    }
}