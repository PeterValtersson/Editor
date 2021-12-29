#include "TabLayout.h"

void Editor::TabLayout::add_view(Control^ control)
{
    if (content_tabs->Find(x => x == control))
        return;
    content_tabs->Add(control);
    auto tab_lbl = gcnew Label();
    tab_lbl->Text = control->Name;
    tab_lbl->Tag = control;
    tab_lbl->Click += gcnew System::EventHandler(this, &Editor::TabLayout::on_tab_button_click);
    tab_list->Controls->Add(tab_lbl);
}

System::Void Editor::TabLayout::TabLayout_Resize(System::Object^ sender, System::EventArgs^ e)
{
    tableLayoutPanel1->RowStyles[0]->Height = Height - 25;
    tableLayoutPanel1->RowStyles[1]->Height = 25;
}


void Editor::TabLayout::on_tab_button_click(System::Object^ sender, System::EventArgs^ e)
{
    throw gcnew System::NotImplementedException();
}
