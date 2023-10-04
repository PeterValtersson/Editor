using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
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
    /// Interaction logic for ComponentList.xaml
    /// </summary>
    public partial class ComponentList : UserControl
    {
        public ComponentList()
        {
            InitializeComponent();
            ComponentSingleton.OnSelectedEntityChanged += OnSelectedEntityChanged;
            ComponentSingleton.OnComponentAddedToEntity += OnSelectedEntityChanged;
            //ComponentControlBuilder.OnComponentDataUpdated += OnComponentDataUpdated;
        }

        private void OnComponentDataUpdated(Reflection component_data)
        {
            ComponentSingleton.SetComponentDataOfCurrentEntity(component_data);
        }

        private void OnSelectedEntityChanged(Entity entity)
        {
            component_list.Children.Clear();
            var components = ComponentSingleton.GetEntityComponents();
            foreach (var component in components)
            {
                var expander = new Expander();
                expander.Header = component.Name;
                expander.IsExpanded = true;
                var component_fields = ComponentControlBuilder.BuildComponentFields(component, () => { OnComponentDataUpdated(component); });
                expander.Content = component_fields;
                component_list.Children.Add(expander);
            }
        }
    }
}
