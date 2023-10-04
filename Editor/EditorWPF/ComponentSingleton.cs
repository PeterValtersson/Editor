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
    public delegate void ComponentAddedToEntity(Entity entity);
    public delegate void ComponentDataUpdated();

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
        public static event ComponentAddedToEntity OnComponentAddedToEntity;
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
        private static EditorInterop.ComponentReflection _FindComponentReflection(string component_name)
        {
            foreach (var component in _components)
                if (component.get_name() == component_name) return component;
            throw new Exception("Component " + component_name + " not found");
        }
        private static Reflection GetReflection(EditorInterop.ComponentReflection component)
        {
            var jsonString = component.get_reflection_meta_data();
            return JsonConvert.DeserializeObject<Reflection>(jsonString);
        }
        private static Reflection GetEntityReflection(EditorInterop.ComponentReflection component)
        {
            var jsonString = component.get_reflection_data(CurrentEntity);
            return JsonConvert.DeserializeObject<Reflection>(jsonString);
        }
        public static Reflection FindComponentReflection(string component_name)
        {
            return GetReflection(_FindComponentReflection(component_name));
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
        public static List<Reflection> GetEntityComponents()
        {
            if (_components == null)
                throw new Exception("Not initialized");

            var componentReflections = new List<Reflection>();
            foreach (var component in _components)
                if (component.is_registered_re(CurrentEntity))
                    componentReflections.Add(GetEntityReflection(component));
            return componentReflections;
        }
        public static void SetComponentDataOfCurrentEntity(Reflection component_data)
        {
            var component = _FindComponentReflection(component_data.Name);
            var new_component = component.is_registered_re(CurrentEntity);
            component.set_data_from_json(CurrentEntity, JsonConvert.SerializeObject(component_data));
            if (OnComponentAddedToEntity is not null && !new_component)
                OnComponentAddedToEntity(CurrentEntity);
        }
    }

    public class DummyClass
    {
        public int ID { get; set; }
        public string Text { get; set; }
    }
    public static class ComponentControlBuilder
    {
        public static UIElement BuildComponentFields(Reflection component_data, ComponentDataUpdated updateCallback = null)
        {
            var stackpanel = new StackPanel();
            foreach (var field in component_data.Fields)
            {
                try 
                { 
                    stackpanel.Children.Add(BuildComponentField(field, updateCallback)); 
                }
                catch(Exception e)
                {
                    MessageBox.Show(e.Message);
                }

                
                
            }
            return stackpanel;
        }
        public static UIElement BuildComponentField(Field field, ComponentDataUpdated updateCallback)
        {
            
            switch (field.Type)
            {
                case "Flag":
                    {
                        return BuildFlagField(field, updateCallback);
                    }
                case "float3":
                    {
                        return BuildFloat3Field(field, updateCallback);
                    }
                case "float":
                    {
                        return BuildVerticalFloatField(field, updateCallback);
                    }
                case "GUID":
                    {
                        return BuildGUIDField(field, updateCallback);
                    }
                default:
                    throw new Exception("Unknown field type \""+ field.Type + "\"");
            }
        }

        private static UIElement BuildFloat3Field(Field field, ComponentDataUpdated updateCallback)
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
                var child = BuildHorizontalFloatField(field2, updateCallback);
                Grid.SetColumn(child, c);
                grid2.Children.Add(child);
                c++;
            }
            return grid;
        }

        private static UIElement BuildHorizontalFloatField(Field field, ComponentDataUpdated updateCallback)
        {
            var grid = new Grid();
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            var name = new Label();
            name.Content = field.Name;
            var value = new TextBox();
            if (field.Value is not null)
                value.Text = field.Value;
            else
                value.Text = field.Value = "0.0";
            value.TextChanged += (s, e) => { field.Value = value.Text; if (updateCallback is not null) updateCallback(); };
            Grid.SetColumn(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }

        private static UIElement BuildVerticalFloatField(Field field, ComponentDataUpdated updateCallback)
        {
            var grid = new Grid();
            grid.RowDefinitions.Add(new RowDefinition());
            grid.RowDefinitions.Add(new RowDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            var name = new Label();
            name.Content = field.Name;
            Grid.SetRow(name, 0);
            var value = new TextBox();
            if (field.Value is not null)
                value.Text = field.Value;
            else
                value.Text = field.Value = "0.0";
            value.TextChanged += (s, e) => { field.Value = value.Text; if (updateCallback is not null) updateCallback(); };
            Grid.SetRow(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }
        private static UIElement BuildFlagField(Field field, ComponentDataUpdated updateCallback)
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
                var o = new DummyClass { ID = 1 << c, Text = value_string };
                value.Items.Add(o);
                if ((Byte.Parse(field.Value) & o.ID) > 0)
                    value.SelectedItems.Add(o);
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
                if (updateCallback is not null) updateCallback();
            };

            Grid.SetRow(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }
        private static UIElement BuildGUIDField(Field field, ComponentDataUpdated updateCallback)
        {
            var grid = new Grid();
            grid.RowDefinitions.Add(new RowDefinition());
            grid.RowDefinitions.Add(new RowDefinition());
            var name = new Label();
            name.Content = field.Name;
            var value = new TextBox();
            if (field.Value is not null)
                value.Text = field.Value;
            else
                value.Text = field.Value = "";
            value.TextChanged += (s, e) => { field.Value = value.Text; if (updateCallback is not null) updateCallback(); };
            value.MouseDown += (s, e) => { /* Open browse mesh library */ };
            value.IsEnabled = false;
            Grid.SetRow(value, 1);
            grid.Children.Add(name);
            grid.Children.Add(value);
            return grid;
        }
    }

}