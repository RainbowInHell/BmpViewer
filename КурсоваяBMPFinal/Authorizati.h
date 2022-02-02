#pragma once
#include "BMP.h"
#include "Registr.h"
#include "ChangeLanguage.h"
#include "Admin.h"


namespace КурсоваяBMPFinal
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Authorizati
	/// </summary>
	public ref class Authorizati : public System::Windows::Forms::Form
	{
	public:
		ColorDialog^ MyDialog = gcnew ColorDialog;
		ChangeLanguage^ changeLng = gcnew ChangeLanguage();

	public:
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", this->GetType()->Assembly);
	public:
		Authorizati(void)
		{
			String^ language = System::Configuration::ConfigurationManager::AppSettings["language"];
			Thread::CurrentThread->CurrentUICulture = gcnew System::Globalization::CultureInfo(language);
			InitializeComponent();

			MyDialog->Color = this->BackColor;

			f = gcnew Registr();
			f->Owner = this;
			f->Hide();

			f1 = gcnew BMP();
			f1->Owner = this;
			f1->Hide();

			f2 = gcnew Admin();
			f2->Owner = this;
			f2->Hide();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Authorizati()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Registr^ f;
	private: BMP^ f1;
	private: Admin^ f2;
	private: bool buttonWasClicked1 = false;
	private: bool buttonWasClicked2 = false;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ Exit;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Button^ Registration;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ EngLang;
	private: System::Windows::Forms::Button^ RusLang;
	private: System::Windows::Forms::Button^ Restart;
	private: System::Windows::Forms::Button^ BelLang;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ Color;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Authorizati::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->Registration = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->BelLang = (gcnew System::Windows::Forms::Button());
			this->EngLang = (gcnew System::Windows::Forms::Button());
			this->RusLang = (gcnew System::Windows::Forms::Button());
			this->Restart = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->Color = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// textBox1
			// 
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			// 
			// textBox2
			// 
			resources->ApplyResources(this->textBox2, L"textBox2");
			this->textBox2->Name = L"textBox2";
			// 
			// Exit
			// 
			resources->ApplyResources(this->Exit, L"Exit");
			this->Exit->Name = L"Exit";
			this->Exit->UseVisualStyleBackColor = true;
			this->Exit->Click += gcnew System::EventHandler(this, &Authorizati::Exit_Click);
			// 
			// Enter
			// 
			resources->ApplyResources(this->Enter, L"Enter");
			this->Enter->Name = L"Enter";
			this->Enter->UseVisualStyleBackColor = true;
			this->Enter->Click += gcnew System::EventHandler(this, &Authorizati::Enter_Click);
			// 
			// Registration
			// 
			resources->ApplyResources(this->Registration, L"Registration");
			this->Registration->Name = L"Registration";
			this->Registration->UseVisualStyleBackColor = true;
			this->Registration->Click += gcnew System::EventHandler(this, &Authorizati::Registration_Click);
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Authorizati::checkBox1_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->BelLang);
			this->groupBox1->Controls->Add(this->EngLang);
			this->groupBox1->Controls->Add(this->RusLang);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// BelLang
			// 
			resources->ApplyResources(this->BelLang, L"BelLang");
			this->BelLang->Name = L"BelLang";
			this->BelLang->UseVisualStyleBackColor = true;
			this->BelLang->Click += gcnew System::EventHandler(this, &Authorizati::BelLang_Click);
			// 
			// EngLang
			// 
			resources->ApplyResources(this->EngLang, L"EngLang");
			this->EngLang->Name = L"EngLang";
			this->EngLang->UseVisualStyleBackColor = true;
			this->EngLang->Click += gcnew System::EventHandler(this, &Authorizati::EngLang_Click);
			// 
			// RusLang
			// 
			resources->ApplyResources(this->RusLang, L"RusLang");
			this->RusLang->Name = L"RusLang";
			this->RusLang->UseVisualStyleBackColor = true;
			this->RusLang->Click += gcnew System::EventHandler(this, &Authorizati::RusLang_Click);
			// 
			// Restart
			// 
			resources->ApplyResources(this->Restart, L"Restart");
			this->Restart->Name = L"Restart";
			this->Restart->UseVisualStyleBackColor = true;
			this->Restart->Click += gcnew System::EventHandler(this, &Authorizati::Restart_Click);
			// 
			// Color
			// 
			resources->ApplyResources(this->Color, L"Color");
			this->Color->Name = L"Color";
			this->Color->UseVisualStyleBackColor = true;
			this->Color->Click += gcnew System::EventHandler(this, &Authorizati::Color_Click);
			// 
			// Authorizati
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->Color);
			this->Controls->Add(this->Restart);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Registration);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"Authorizati";
			this->Load += gcnew System::EventHandler(this, &Authorizati::Authorizati_Load);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void MarshalString(String^ s, string& os) // метод Маршала. Для конвертации из String^ в string.
		{
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Registration_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Authorizati_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RusLang_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EngLang_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Restart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BelLang_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Color_Click(System::Object^ sender, System::EventArgs^ e);
	};
}