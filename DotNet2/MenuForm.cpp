#include "MenuForm.h"
#include "FormSampleData.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//запуск основного цикла сообщений с запуском формы. Закрывается форма - завершается цикл - завершается процесс
	DotNet2::MenuForm form;
	Application::Run(% form);
}

System::Void DotNet2::MenuForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	FormSampleData^ formSample = gcnew FormSampleData();
	this->Hide();
	formSample->Show();
}

System::Void DotNet2::MenuForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}
