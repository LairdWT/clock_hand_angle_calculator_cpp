/// Laird Shingleton - 2022
/// Written in Visual Studio 2022 as an exercise

#include "main_form.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CPPClockAngleApp::main_form form;
	Application::Run(% form);
}