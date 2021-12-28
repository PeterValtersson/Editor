#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Editor {

	/// <summary>
	/// Summary for PoperContainer
	/// </summary>
	public ref class PoperContainer : public System::Windows::Forms::ToolStripDropDown
	{
	public:
		PoperContainer(Control^ content)
		{
			InitializeComponent();
			
			if (content == nullptr)
				throw gcnew ArgumentNullException("Content");

			this->content = content;

			host = gcnew ToolStripControlHost(content);
			host->AutoSize = false;
			Padding = Windows::Forms::Padding::Empty;
			Margin = Windows::Forms::Padding::Empty;
			host->Padding = Windows::Forms::Padding::Empty;
			host->Margin = Windows::Forms::Padding::Empty;

			content->Location = Point::Empty;

			Items->Add(host);
		}

		void show(Control^ control)
		{
			if (control == nullptr)
				throw gcnew ArgumentNullException("Control");
			show(control, control->ClientRectangle);
		}
		void show(Form^ f, Point p)
		{
			show(f, Rectangle(p, Drawing::Size(0,0)));
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PoperContainer()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Control^ content;
		ToolStripControlHost^ host;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		}
#pragma endregion

		void show(Control^ control, Rectangle area)
		{
			if (control == nullptr)
				throw gcnew ArgumentNullException("Control");

			auto location = control->PointToScreen(Point(area.Left, area.Top + area.Height));
			auto screen = Screen::FromControl(control)->WorkingArea;

			if (location.X + Size.Width > (screen.Left + screen.Width))
				location.X = (screen.Left + screen.Width) - Size.Width;

			if (location.Y + Size.Height > (screen.Top + screen.Height))
				location.Y -= Size.Height + area.Height;

			location = control->PointToClient(location);

			Show(control, location, ToolStripDropDownDirection::BelowRight);
		}
	};
}
