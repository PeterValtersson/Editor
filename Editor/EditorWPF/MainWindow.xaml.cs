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
using System.Windows.Interop;
using Newtonsoft.Json;

namespace EditorWPF
{
   
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private EditorInterop.Engine engine;
        private RenderView render_view;
        public MainWindow()
        {
            InitializeComponent();
            engine = new EditorInterop.Engine();
            render_view = new RenderView(this, engine);
            render_view.HorizontalAlignment = HorizontalAlignment.Stretch;
            render_view.VerticalAlignment = VerticalAlignment.Stretch;
            Grid.SetColumn(render_view, 2);
            content_grid.Children.Add(render_view);
            engine.init(render_view.get_HWND(), render_view.get_resoulution());

            var c = engine.get_component_reflections();
            ComponentSingleton.Initialize(c);
            //var r = c.get_reflection_meta_data(); 
            //var json = JsonConvert.DeserializeObject<Reflection> (r);
            var scene_view = new SceneView(engine);
            left_tab_panel.add_tab(scene_view);
            right_tab_panel.add_tab(new ComponentView.ComponentView(scene_view, c));
        }

    }
}
