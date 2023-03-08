﻿using System;
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
            var components = ComponentSingleton.GetComponentNameList();
            component_list.Children.Clear();
            foreach (var component in components)
            {
                var btn = new Button();
                btn.Content = component;
                btn.Click += Component_Click;
                component_list.Children.Add(btn);
            }

        }

        private void Component_Click(object sender, RoutedEventArgs e)
        {
            component_hide.Visibility = Visibility.Visible;
            component_list.Visibility = Visibility.Hidden;
            add_component_page.Children.Clear();
            component_name.Content = (sender as Button).Content;

            add_component_page.Children.Add(ComponentControlBuilder.BuildComponentFieldsWithAddButton(ComponentSingleton.FindComponentReflection(component_name.Content as string)));
            add_component_page.Visibility = Visibility.Visible;
        }
        private void component_hide_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ReturnToComponentList();
        }

        private void Border_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ReturnToComponentList();
        }

        private void component_name_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ReturnToComponentList();
        }
        private void UserControl_Unloaded(object sender, RoutedEventArgs e)
        {
            ReturnToComponentList();
        }
        private void ReturnToComponentList()
        {
            component_name.Content = "Component";
            component_list.Visibility = Visibility.Visible;
            component_hide.Visibility = Visibility.Hidden;
            add_component_page.Children.Clear();
        }

    }
}
