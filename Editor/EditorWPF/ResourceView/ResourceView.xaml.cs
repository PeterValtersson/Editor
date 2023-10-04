using EditorWPF.Properties;
using Microsoft.Win32;
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

namespace EditorWPF.ResourceView
{
    /// <summary>
    /// Interaction logic for ResourceView.xaml
    /// </summary>
    public partial class ResourceView : UserControl
    {
        public ResourceView()
        {
            InitializeComponent();

            _resources = ResourceHandlerI.GetAllResources();

           FillResourceList();

        }
        private string? _filterType;
        private List<ResourceMetaInfo> _resources;

        public string FilterType
        {
            get { return _filterType; }
            set
            {
                _filterType = value;
                FillResourceList();
            }
        }

        private void ImportMesh(object sender, RoutedEventArgs e)
        {
            var fd = new OpenFileDialog();
            if (Settings.Default.import_mesh_last_used_path != "")
                fd.InitialDirectory = Settings.Default.import_mesh_last_used_path;
            if (fd.ShowDialog() == true)
            {
                var file = fd.FileName;
                Settings.Default.import_mesh_last_used_path = file;
                AssimpImporterI.Import(file);
                _resources = ResourceHandlerI.GetAllResources();

                FillResourceList();

            }
        }

        private void FillResourceList()
        {
            if (_filterType != null && _filterType != "")
            {
                resource_list.Children.Clear();
                foreach (var resource in _resources)
                {
                    var mesh = ResourceHandlerI.MakeGUID("Mesh");
                    if (resource.type == mesh)
                    {
                        var label = new Label();
                        label.Content = resource.name;
                        resource_list.Children.Add(label);
                    }
                }
            }
            else
            {
                foreach (var resource in _resources)
                {
                    var label = new Label();
                    label.Content = resource.name;
                    resource_list.Children.Add(label);

                }
            }
        }
    }
}
