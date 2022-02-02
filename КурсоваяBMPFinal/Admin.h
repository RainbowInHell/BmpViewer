#pragma once

namespace  урсова€BMPFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L" урсова€BMPFinal.MyString", this->GetType()->Assembly);
	public:
		Admin(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	public:
		void UpdateFormColor(ColorDialog^ a)
		{
			this->BackColor = a->Color;
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ GetUsers;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ SaveNewInfo;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ Back;






	private: System::ComponentModel::IContainer^ components;

	protected:
	protected:
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin::typeid));
			this->GetUsers = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SaveNewInfo = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->Back = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// GetUsers
			// 
			resources->ApplyResources(this->GetUsers, L"GetUsers");
			this->GetUsers->Name = L"GetUsers";
			this->GetUsers->UseVisualStyleBackColor = true;
			this->GetUsers->Click += gcnew System::EventHandler(this, &Admin::GetUsers_Click);
			// 
			// richTextBox1
			// 
			resources->ApplyResources(this->richTextBox1, L"richTextBox1");
			this->richTextBox1->Name = L"richTextBox1";
			// 
			// SaveNewInfo
			// 
			resources->ApplyResources(this->SaveNewInfo, L"SaveNewInfo");
			this->SaveNewInfo->Name = L"SaveNewInfo";
			this->SaveNewInfo->UseVisualStyleBackColor = true;
			this->SaveNewInfo->Click += gcnew System::EventHandler(this, &Admin::SaveNewInfo_Click);
			// 
			// Back
			// 
			resources->ApplyResources(this->Back, L"Back");
			this->Back->Name = L"Back";
			this->Back->UseVisualStyleBackColor = true;
			this->Back->Click += gcnew System::EventHandler(this, &Admin::Back_Click);
			// 
			// Admin
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->Back);
			this->Controls->Add(this->SaveNewInfo);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->GetUsers);
			this->Name = L"Admin";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GetUsers_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SaveNewInfo_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Back_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
