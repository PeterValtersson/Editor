using EditorWPF.ComponentView;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Net.Http.Headers;

namespace EditorWPF
{
    public delegate void SelectedEntityChanged(Entity entity);
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
        public static event SelectedEntityChanged OnSelectedEntityChanged;
        private static List<EditorInterop.ComponentReflection> _components;
        public static Entity CurrentEntity;
        public static void Initialize(List<EditorInterop.ComponentReflection> components)
        {
            _components = components;
        }
        public static void SetCurrentEntity(Entity entity)
        {
            CurrentEntity = entity;
            if (OnSelectedEntityChanged is not null)
                OnSelectedEntityChanged(CurrentEntity);
        }
        public static Reflection FindComponentReflection(string component_name)
        {
            foreach (var component in _components)
            {
                var jsonString = component.get_reflection_meta_data();
                if (component.get_name() == component_name) return JsonConvert.DeserializeObject<Reflection>(jsonString);
            }
            throw new Exception("Component " + component_name + " not found");
        }
        public static List<string> GetComponentNameList()
        {
            if (_components == null)
                throw new Exception("Not initialized");

            var componentNames = new List<string>();
            foreach (var component in _components)
                componentNames.Add(component.get_name());
            return componentNames;
        }

        public static void AddComponentToCurrentEntity(Reflection component_data)
        {

        }
    }

    public class DummyClass
    {
        public int ID { get; set; }
        public string Text { get; set; }
    }
    public static class ComponentControlBuilder
    {
        public static UIElement BuildComponentFieldsWithAddButton(Reflection component)
        {
            var grid = new Grid();
            grid.RowDefinitions.Add(new RowDefinition());
            var row = new RowDefinition();
            row.Height = new GridLength(25, GridUnitType.Pixel);
            var addButton = new Button();
            addButton.Content = "Add component";
            addButton.Click += (s, e) => { ComponentSingleton.AddComponentToCurrentEntity(component); };
            Grid.SetRow(addButton, 1);
            grid.Children.Add(BuildComponentFields(component));
            grid.Children.Add(addButton);
            grid.RowDefinitions.Add(row);
            return grid;
        }
     
        public static UIElement BuildComponentFields(Reflection component_data)
        {
            var stackpanel = new StackPanel();
            foreach (var field in component_data.Fields)
            {
                stackpanel.Children.Add(BuildComponentField(field));
            }
            return stackpanel;
        }
        public static UIElement BuildComponentField(Field field)
        {
            
            switch (field.Type)
            {
                case "Flag":
                    {
                        return BuildFlagField(field);
                    }
                case "float3":
                    {
                        return BuildFloat3Field(field);
                    }
                case "float":
                    {
                        return BuildVerticalFloatField(field);
                    }
                default:
                    throw new Exception("Unknown field type \""+ field.Type + "\"");
            }
        }

        private static UIElement BuildFloat3Field(Field field)
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
                var child = BuildHorizontalFloatField(field2);
                Grid.SetColumn(child, c);
                grid2.Children.Add(child);
                c++;
            }
            return grid;
        }

        private static UIElement BuildHorizontalFloatField(Field field)
        {
            var grid = new Grid();
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            var name = new Label();
            name.Content = field.Name;
            var value = new TextBox();
            value.Text = "0.0";
            value.TextChanged += (s, e) => { field.Value = value.Text; };
            Grid.SetColumn(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }

        private static UIElement BuildVerticalFloatField(Field field)
        {
            var grid = new Grid();
            grid.RowDefinitions.Add(new RowDefinition());
            grid.RowDefinitions.Add(new RowDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            var name = new Label();
            name.Content = field.Name;
            Grid.SetRow(name, 0);
            var value = new TextBox();
            value.Text = "0.0";
            value.TextChanged += (s, e) => { field.Value = value.Text; };
            Grid.SetRow(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }
        private static UIElement BuildFlagField(Field field)
        {
            var grid = new Grid();
            grid.RowDefinitions.Add(new RowDefinition());
            grid.RowDefinitions.Add(new RowDefinition());
            var name = new Label();
            name.Content = field.Name;
            Grid.SetRow(name, 0);
            var value = new Xceed.Wpf.Toolkit.CheckComboBox();
            int c = 0;
            foreach (var value_string in field.Values)
            {
                object o = new DummyClass { ID = 1 << c, Text = value_string } ;
                value.Items.Add(o);
                c++;
            }
            value.ValueMemberPath = "ID";
            value.DisplayMemberPath = "Text"; 
            value.ItemSelectionChanged += (s, e) => 
            {
                int sum = 0;
                foreach (var item in value.SelectedItems)
                {
                    sum += (item as DummyClass).ID;
                }
                field.Value = sum.ToString();
            };
         
            Grid.SetRow(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }
    }

}