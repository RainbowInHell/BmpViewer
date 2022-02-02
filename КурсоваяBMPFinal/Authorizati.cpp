//Authorizati.cpp
#include <Windows.h>
#include "Authorizati.h"
#include "Errors.h"
#include <sys/types.h>
#include <sys/stat.h>

using namespace ��������BMPFinal;
struct stat info;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Authorizati());
	return 0;
}

System::Void ��������BMPFinal::Authorizati::Enter_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		User prof1;

		String^ log = textBox1->Text;
		String^ pas = textBox2->Text;
		string log1, pas1;
		
		//����������� �� String^ � string
		MarshalString(log, log1);
		MarshalString(pas, pas1);

		//������ get � set � ������� prof1 ������ User
		prof1.SetLogin(log1);
		prof1.SetPassword(pas1);

		if (log == "") throw freelog(); //�������� ������ �� ������� � ����� �� ����� ������
		else if (pas == "") throw freepass(); //�������� ������ �� ������� � ����� �� ����� ������
		else if (textBox2->TextLength < 5 || textBox2->TextLength > 13) throw badlenght(); //�������� ����� ���������� ������ � ����� �� ����� ������

		//���� ������� ����.������ ��� ������, �� ������� ����� ��� �������������
		else if (log == "adminyshka" && pas == "matvich3585")
		{

			this->Hide();
			f2->Show();
		}

		else if (prof1.Chek() == true)
		//���� ����� ������������������ ������������
		{
			if (stat("D:\\Results", &info) != 0)
			{
				//�������� �������� Results �� ����� D ���� ��� ��� ���
				std::wstring name(L"D:\\Results");
				const wchar_t* szName = name.c_str();
				_wmkdir(szName);
			}

			//����������� ������������
			MessageBox::Show(rm->GetString(L"Welcome") + " " + log + "!");

			this->Hide();
			f1->Show();


		}
		else
		{
			//��������� �� ������
			MessageBox::Show(rm->GetString(L"Smth"));
		}
	}

	catch (freelog e)
	{
		//��������� � ������� ������ ��� ������
		MessageBox::Show(rm->GetString(L"LoginFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (freepass e)
	{
		//��������� � ������� ������ ��� �����
		MessageBox::Show(rm->GetString(L"PassFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (badlenght e)
	{
		//��������� � ������������ ������ ��������
		MessageBox::Show(rm->GetString(L"PassLenght"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (...)
	{
		//������������� ����� ������ �� ������ ������
		MessageBox::Show(rm->GetString(L"GG"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void ��������BMPFinal::Authorizati::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� �� ����������
	Application::Exit();
}

System::Void ��������BMPFinal::Authorizati::Registration_Click(System::Object^ sender, System::EventArgs^ e)
{
	//������ ������ ����� � ������� � ����� �����������
	this->Hide();
	f->Show();
}

System::Void ��������BMPFinal::Authorizati::Authorizati_Load(System::Object^ sender, System::EventArgs^ e)
{
	//�������� �������� ������ � textBox2
	textBox2->PasswordChar = '*';
}

System::Void ��������BMPFinal::Authorizati::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	//���� ������� �����, �� ��������� ������ �����
	if (checkBox1->Checked)
		textBox2->PasswordChar = false;
	//����� ������ �������� *
	else
		textBox2->PasswordChar = '*';
}

System::Void ��������BMPFinal::Authorizati::RusLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//���������� �������� ��� ��������� �������� �����
	changeLng->UpdateConfig("language", "");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void ��������BMPFinal::Authorizati::EngLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//���������� �������� ��� ��������� ����������� �����
	changeLng->UpdateConfig("language", "en-US");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void ��������BMPFinal::Authorizati::BelLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//���������� �������� ��� ��������� ������������ �����
	changeLng->UpdateConfig("language", "be-BY");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void ��������BMPFinal::Authorizati::Restart_Click(System::Object^ sender, System::EventArgs^ e)
{
	//������������ ����������
	Application::Restart();
}

System::Void ��������BMPFinal::Authorizati::Color_Click(System::Object^ sender, System::EventArgs^ e)
{
	//���� ����� ������� ��
	if (MyDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//��������������� ���������� ����� � String
		String^ a = Convert::ToString(MyDialog->Color);
		//���� ���� ������, �� �� ���� ������ ���������� ����� �����
		if (a == "Color [Black]")
		{
			buttonWasClicked1 = true;
			this->BackColor = MyDialog->Color;
			this->ForeColor = Color::White;
			f->UpdateFormColor(MyDialog);
			f->ForeColor = Color::White;

			f1->UpdateFormColor(MyDialog);
			f1->ForeColor = Color::White;

			f2->UpdateFormColor(MyDialog);
			f2->ForeColor = Color::White;
		
		}
		//���� ���� �����, �� �� ���� ������ ���������� ����� ������
		else if (a == "Color [White]")
		{
			buttonWasClicked2 = true;
			this->BackColor = MyDialog->Color;
			this->ForeColor = Color::Black;

			f->UpdateFormColor(MyDialog);
			f->ForeColor = Color::Black;

			f1->UpdateFormColor(MyDialog);
			f1->ForeColor = Color::Black;

			f2->UpdateFormColor(MyDialog);
			f2->ForeColor = Color::Black;
		}
		//������� ���������� ����� UpdateFormColor ��� ��������� ���������� ����� �� ��� �����
		else
		{

			this->BackColor = MyDialog->Color;

			f->UpdateFormColor(MyDialog);
			f1->UpdateFormColor(MyDialog);
			f2->UpdateFormColor(MyDialog);
		}
	}
	// �������� ������� ���� �����
	else
	{
		return;
	}
}