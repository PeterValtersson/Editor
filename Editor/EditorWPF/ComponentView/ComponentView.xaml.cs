﻿using EditorInterop;
using Newtonsoft.Json;
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
    /// Interaction logic for ComponentView.xaml
    /// </summary>
    public partial class ComponentView : UserControl
    {
        private Entity selected_entity;
        private List<ComponentReflection> components;
        private ContextMenu contextMenu;
        public ComponentView(OnSelectedEntityChanged onSelectedEntityChanged, List<ComponentReflection> components)
        {
            InitializeComponent();
            onSelectedEntityChanged.OnSelectedEntityChanged += OnSelectedEntityChanged_OnSelectedEntityChanged;
            this.components = components;

            foreach (var component in components)
            {
                var json = component.get_reflection_meta_data();
                var data = JsonConvert.DeserializeObject<Reflection>(json);
                
                Button btn = new Button();
                btn.Width = Double.NaN;
                btn.Content = data.Name;
               // add_component_btn.ContextMenu.Items.Add(btn);
               // contextMenu.Template;
                //add_component_btn.ContextMenu.Items.Add(btn);
            }
            //add_component_btn.ContextMenu.Items;
        }

        private void OnSelectedEntityChanged_OnSelectedEntityChanged(Entity entity)
        {
            if (selected_entity is not null)
                entity.OnNameChanged -= Entity_OnNameChanged;
            selected_entity = entity;
            entity_name.Text = entity.Name;
            entity.OnNameChanged += Entity_OnNameChanged;
         
        }

        private void Entity_OnNameChanged(string name)
        {
            entity_name.Text = name;
        }

        private void entity_name_TextChanged(object sender, TextChangedEventArgs e)
        {
            selected_entity.Name = entity_name.Text;
        }

        private void add_component_btn_Click(object sender, RoutedEventArgs e)
        {

            ContextMenu contextMenu = add_component_btn.ContextMenu;
            contextMenu.Width = add_component_btn.ActualWidth;
            contextMenu.PlacementTarget = add_component_btn;
            contextMenu.Placement = System.Windows.Controls.Primitives.PlacementMode.Bottom;
            contextMenu.IsOpen = true;
            e.Handled = true;

        }
    }
}
