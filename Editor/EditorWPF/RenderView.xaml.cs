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
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace EditorWPF
{
    /// <summary>
    /// Interaction logic for RenderView.xaml
    /// </summary>
    public partial class RenderView : UserControl
    {
        private RenderWindow render_window;
        private Window parent;
        private EditorInterop.Engine engine;
        public RenderView(Window parent, EditorInterop.Engine engine)
        {
            InitializeComponent();
            this.parent = parent;
            this.engine = engine;
            render_window = new RenderWindow();


            parent.LocationChanged += Window_LocationChanged;
            parent.ContentRendered += Window_ContentRendered;

            WindowInteropHelper Helper = new WindowInteropHelper(render_window);
            IntPtr hWnd = Helper.EnsureHandle();
            Helper.Owner = hWnd;
            
            

        }

        public IntPtr get_HWND()
        {
            WindowInteropHelper Helper = new WindowInteropHelper(render_window);
            return Helper.EnsureHandle();
        }
        public System.Drawing.Size get_resoulution()
        {
            var resolution = new System.Drawing.Size();
            resolution.Width = Convert.ToInt32(render_window.ActualWidth);
            resolution.Height = Convert.ToInt32(render_window.ActualHeight);
            return resolution;
        }

        public void Window_ContentRendered(object sender, EventArgs e)
        {

            render_window.Owner = parent;
            var pos = parent.PointToScreen(TranslatePoint(new Point(0, 0), parent));
            render_window.Left = pos.X;
            render_window.Top = pos.Y;
            render_window.Width = ActualWidth;
            render_window.Height = ActualHeight;
            render_window.Show();
        }

        public void Window_LocationChanged(object sender, EventArgs e)
        {
            var pos = parent.PointToScreen(TranslatePoint(new Point(0, 0), parent));
            render_window.Left = pos.X;
            render_window.Top = pos.Y;
        }

        private void UserControl_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            var pos = parent.PointToScreen(TranslatePoint(new Point(0, 0), parent));
            render_window.Left = pos.X;
            render_window.Top = pos.Y;
            render_window.Width = ActualWidth;
            render_window.Height = ActualHeight;
        }
    }
}
