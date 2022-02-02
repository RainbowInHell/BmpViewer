//Registr.cpp
#include "Registr.h"
#include "Errors.h"
System::Void КурсоваяBMPFinal::Registr::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		User profi;

		String^ logg = textBox1->Text;
		String^ pass = textBox2->Text;

		string logg1, pass1;

		MarshalString(logg, logg1);
		MarshalString(pass, pass1);

		profi.SetLogin(logg1);
		profi.SetPassword(pass1);

		if (logg == "") throw freelog();
		else if (pass == "") throw freepass();
		else if (textBox2->TextLength < 5 || textBox2->TextLength > 13) throw badlenght();
		else if (profi.writer() == true)
		{
			MessageBox::Show(rm->GetString(L"SamePerson"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else
		{
			MessageBox::Show(rm->GetString(L"Reg"));
		}
	}
	catch (freelog e)
	{
		MessageBox::Show(rm->GetString(L"LoginFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (freepass e)
	{
		MessageBox::Show(rm->GetString(L"PassFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (badlenght e)
	{
		MessageBox::Show(rm->GetString(L"PassLenght"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (...)
	{
		MessageBox::Show(rm->GetString(L"GG"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void КурсоваяBMPFinal::Registr::Registr_Load(System::Object^ sender, System::EventArgs^ e)
{
	textBox2->PasswordChar = '*';
}

System::Void КурсоваяBMPFinal::Registr::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked)
		textBox2->PasswordChar = false;
	else
		textBox2->PasswordChar = '*';
}

System::Void КурсоваяBMPFinal::Registr::Back_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();               // Скрываем Форму2
	Form^ form = this->Owner;  // Получаем указатель на владельца 
	form->Show();  //  Показываем владельца
}
	