//Admin.cpp
#include <Windows.h>
#include "Admin.h"
#include "Authorizati.h"

using namespace ��������BMPFinal;


System::Void ��������BMPFinal::Admin::GetUsers_Click(System::Object^ sender, System::EventArgs^ e)
{
	//������ �� ����� � richTextBox1
	auto f = System::IO::File::OpenText("records.txt");
	//���� ���� ������, �� �������� ��� ������
	if (f->Peek() == EOF)
	{
		MessageBox::Show(rm->GetString(L"FreeFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	//������ ���� �� �����
	auto s = f->ReadToEnd();
	//����������� ���������� �������� � richTextBox1
	richTextBox1->Text = s;
	f->Close();
}

System::Void ��������BMPFinal::Admin::SaveNewInfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	//��������� richTextBox1 �� �������
	if (richTextBox1->Text == "")
	{
		//���� ������, �� ������� ��������� �� ����
		MessageBox::Show(rm->GetString(L"FreeRich"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else
	{
		//���� �� �����
		System::IO::File::WriteAllText("records.txt", richTextBox1->Text);
	}
}

System::Void ��������BMPFinal::Admin::Back_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Hide();               // �������� �����2
	Form^ form = this->Owner;  // �������� ��������� �� ��������� 
	form->Show();  //  ���������� ���������
}

