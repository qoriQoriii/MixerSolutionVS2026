#include "pch.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ::View::MyForm^ form = gcnew ::View::MyForm();
    Application::Run(form);

    return 0;
}