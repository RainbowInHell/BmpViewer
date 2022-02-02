//Authorizati.cpp
#include <Windows.h>
#include "Authorizati.h"
#include "Errors.h"
#include <sys/types.h>
#include <sys/stat.h>

using namespace КурсоваяBMPFinal;
struct stat info;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Authorizati());
	return 0;
}

System::Void КурсоваяBMPFinal::Authorizati::Enter_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		User prof1;

		String^ log = textBox1->Text;
		String^ pas = textBox2->Text;
		string log1, pas1;
		
		//Преобразуем из String^ в string
		MarshalString(log, log1);
		MarshalString(pas, pas1);

		//Методы get и set у объекта prof1 класса User
		prof1.SetLogin(log1);
		prof1.SetPassword(pas1);

		if (log == "") throw freelog(); //проверка логина на пустоту и сразу же отлов ошибки
		else if (pas == "") throw freepass(); //проверка пароля на пустоту и сразу же отлов ошибки
		else if (textBox2->TextLength < 5 || textBox2->TextLength > 13) throw badlenght(); //проверка ввода допустимой длинны и сразу же отлов ошибки

		//если введены спец.данные для админа, то открыть форму для администрации
		else if (log == "adminyshka" && pas == "matvich3585")
		{

			this->Hide();
			f2->Show();
		}

		else if (prof1.Chek() == true)
		//если вошел зарегистрированный пользователь
		{
			if (stat("D:\\Results", &info) != 0)
			{
				//создание каталога Results на диске D если его там нет
				std::wstring name(L"D:\\Results");
				const wchar_t* szName = name.c_str();
				_wmkdir(szName);
			}

			//приветствие пользователя
			MessageBox::Show(rm->GetString(L"Welcome") + " " + log + "!");

			this->Hide();
			f1->Show();


		}
		else
		{
			//сообщение об ошибке
			MessageBox::Show(rm->GetString(L"Smth"));
		}
	}

	catch (freelog e)
	{
		//сообщение о пустоте строки для логина
		MessageBox::Show(rm->GetString(L"LoginFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (freepass e)
	{
		//сообщение о пустоте строки для проля
		MessageBox::Show(rm->GetString(L"PassFree"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (badlenght e)
	{
		//сообщение о недопустимой длинне символов
		MessageBox::Show(rm->GetString(L"PassLenght"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	catch (...)
	{
		//Универсальный отлов ошибок на всякий случай
		MessageBox::Show(rm->GetString(L"GG"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void КурсоваяBMPFinal::Authorizati::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	//выход из приложения
	Application::Exit();
}

System::Void КурсоваяBMPFinal::Authorizati::Registration_Click(System::Object^ sender, System::EventArgs^ e)
{
	//скрыть данную форму и перейти к форме регистрации
	this->Hide();
	f->Show();
}

System::Void КурсоваяBMPFinal::Authorizati::Authorizati_Load(System::Object^ sender, System::EventArgs^ e)
{
	//скрывает вводимые данные в textBox2
	textBox2->PasswordChar = '*';
}

System::Void КурсоваяBMPFinal::Authorizati::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	//если галочка стоит, то введенные данные видны
	if (checkBox1->Checked)
		textBox2->PasswordChar = false;
	//иначе скрыть символом *
	else
		textBox2->PasswordChar = '*';
}

System::Void КурсоваяBMPFinal::Authorizati::RusLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//обновление настроек для установки русского языка
	changeLng->UpdateConfig("language", "");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void КурсоваяBMPFinal::Authorizati::EngLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//обновление настроек для установки английского языка
	changeLng->UpdateConfig("language", "en-US");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void КурсоваяBMPFinal::Authorizati::BelLang_Click(System::Object^ sender, System::EventArgs^ e)
{
	//обновление настроек для установки белорусского языка
	changeLng->UpdateConfig("language", "be-BY");
	MessageBox::Show(rm->GetString(L"Lang"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void КурсоваяBMPFinal::Authorizati::Restart_Click(System::Object^ sender, System::EventArgs^ e)
{
	//перезагрузка приложения
	Application::Restart();
}

System::Void КурсоваяBMPFinal::Authorizati::Color_Click(System::Object^ sender, System::EventArgs^ e)
{
	//если ответ диалога ОК
	if (MyDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//конвертирование выбранного цвета в String
		String^ a = Convert::ToString(MyDialog->Color);
		//если цвет черный, то на всех формах установить шрифт белый
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
		//если цвет белый, то на всех формах установить шрифт черный
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
		//вызвать глобальный метод UpdateFormColor для установки выбранного цвета на все формы
		else
		{

			this->BackColor = MyDialog->Color;

			f->UpdateFormColor(MyDialog);
			f1->UpdateFormColor(MyDialog);
			f2->UpdateFormColor(MyDialog);
		}
	}
	// оставить обычный цвет формы
	else
	{
		return;
	}
}