//Admin.cpp
#include <Windows.h>
#include "Admin.h"
#include "Authorizati.h"

using namespace КурсоваяBMPFinal;


System::Void КурсоваяBMPFinal::Admin::GetUsers_Click(System::Object^ sender, System::EventArgs^ e)
{
	//чтение из файла в richTextBox1
	auto f = System::IO::File::OpenText("records.txt");
	//если файл пустой, то сообщить это админу
	if (f->Peek() == EOF)
	{
		MessageBox::Show(rm->GetString(L"FreeFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	//читать файл до конца
	auto s = f->ReadToEnd();
	//прочитанную информацию помещаем в richTextBox1
	richTextBox1->Text = s;
	f->Close();
}

System::Void КурсоваяBMPFinal::Admin::SaveNewInfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	//проверяем richTextBox1 на пустоту
	if (richTextBox1->Text == "")
	{
		//если пустой, то выводим сообщение об этом
		MessageBox::Show(rm->GetString(L"FreeRich"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else
	{
		//если не пусто
		System::IO::File::WriteAllText("records.txt", richTextBox1->Text);
	}
}

System::Void КурсоваяBMPFinal::Admin::Back_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Hide();               // Скрываем Форму2
	Form^ form = this->Owner;  // Получаем указатель на владельца 
	form->Show();  //  Показываем владельца
}

