#include "MyForm.h"
#include "Inputs.h"
#include "Outputs.h"
#include "Vehicle.h"
#include "Tire.h"
#include "YMD.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(% form);
}