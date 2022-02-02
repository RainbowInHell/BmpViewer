#pragma once

namespace ÊóğñîâàÿBMPFinal
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ BMP
	/// </summary>
	public ref class BMP : public System::Windows::Forms::Form
	{
	public:
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"ÊóğñîâàÿBMPFinal.MyString", this->GetType()->Assembly);
	public:
		BMP(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}
	public:
		void UpdateFormColor(ColorDialog^ a)
		{
			this->BackColor = a->Color;
		}
	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~BMP()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::OpenFileDialog^ ofd;

	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ èíôîğìàöèÿToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ Shit;

	private: System::Windows::Forms::Button^ Fix;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ Negativ;
	private: System::Windows::Forms::Button^ Sepia;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Form^ home_form2;
	private: System::Windows::Forms::ToolStripMenuItem^ èíñòğóêöèÿToolStripMenuItem;


	private: System::Windows::Forms::Button^ ShitCl1;
	private: System::Windows::Forms::Button^ Fix1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ ToRight;
	private: System::Windows::Forms::Button^ Open_Res;
	private: System::Windows::Forms::Button^ ToBack;
	private: System::Windows::Forms::Button^ Close;
	private: System::Windows::Forms::Button^ Reset_All;
	private: System::Windows::Forms::Button^ Open;
	private: System::Windows::Forms::Button^ Close1;
	private: System::Windows::Forms::Panel^ panel1;









	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BMP::typeid));
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èíôîğìàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èíñòğóêöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Shit = (gcnew System::Windows::Forms::Button());
			this->Fix = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Sepia = (gcnew System::Windows::Forms::Button());
			this->Negativ = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->ShitCl1 = (gcnew System::Windows::Forms::Button());
			this->Fix1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ToRight = (gcnew System::Windows::Forms::Button());
			this->Open_Res = (gcnew System::Windows::Forms::Button());
			this->ToBack = (gcnew System::Windows::Forms::Button());
			this->Close = (gcnew System::Windows::Forms::Button());
			this->Reset_All = (gcnew System::Windows::Forms::Button());
			this->Open = (gcnew System::Windows::Forms::Button());
			this->Close1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ofd
			// 
			this->ofd->FileName = L"ofd";
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->âûõîäToolStripMenuItem,
					this->èíôîğìàöèÿToolStripMenuItem, this->èíñòğóêöèÿToolStripMenuItem
			});
			resources->ApplyResources(this->menuStrip2, L"menuStrip2");
			this->menuStrip2->Name = L"menuStrip2";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			resources->ApplyResources(this->âûõîäToolStripMenuItem, L"âûõîäToolStripMenuItem");
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &BMP::âûõîäToolStripMenuItem_Click);
			// 
			// èíôîğìàöèÿToolStripMenuItem
			// 
			this->èíôîğìàöèÿToolStripMenuItem->Name = L"èíôîğìàöèÿToolStripMenuItem";
			resources->ApplyResources(this->èíôîğìàöèÿToolStripMenuItem, L"èíôîğìàöèÿToolStripMenuItem");
			this->èíôîğìàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &BMP::èíôîğìàöèÿToolStripMenuItem_Click);
			// 
			// èíñòğóêöèÿToolStripMenuItem
			// 
			this->èíñòğóêöèÿToolStripMenuItem->Name = L"èíñòğóêöèÿToolStripMenuItem";
			resources->ApplyResources(this->èíñòğóêöèÿToolStripMenuItem, L"èíñòğóêöèÿToolStripMenuItem");
			this->èíñòğóêöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &BMP::èíñòğóêöèÿToolStripMenuItem_Click);
			// 
			// pictureBox2
			// 
			resources->ApplyResources(this->pictureBox2, L"pictureBox2");
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->TabStop = false;
			// 
			// Shit
			// 
			resources->ApplyResources(this->Shit, L"Shit");
			this->Shit->Name = L"Shit";
			this->Shit->UseVisualStyleBackColor = true;
			this->Shit->Click += gcnew System::EventHandler(this, &BMP::Shit_Click);
			// 
			// Fix
			// 
			resources->ApplyResources(this->Fix, L"Fix");
			this->Fix->Name = L"Fix";
			this->Fix->UseVisualStyleBackColor = true;
			this->Fix->Click += gcnew System::EventHandler(this, &BMP::Fix_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Sepia);
			this->groupBox1->Controls->Add(this->Negativ);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// Sepia
			// 
			resources->ApplyResources(this->Sepia, L"Sepia");
			this->Sepia->Name = L"Sepia";
			this->Sepia->UseVisualStyleBackColor = true;
			this->Sepia->Click += gcnew System::EventHandler(this, &BMP::Sepia_Click);
			// 
			// Negativ
			// 
			resources->ApplyResources(this->Negativ, L"Negativ");
			this->Negativ->Name = L"Negativ";
			this->Negativ->UseVisualStyleBackColor = true;
			this->Negativ->Click += gcnew System::EventHandler(this, &BMP::Negativ_Click);
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
			// ShitCl1
			// 
			resources->ApplyResources(this->ShitCl1, L"ShitCl1");
			this->ShitCl1->Name = L"ShitCl1";
			this->ShitCl1->UseVisualStyleBackColor = true;
			this->ShitCl1->Click += gcnew System::EventHandler(this, &BMP::ShitCl1_Click);
			// 
			// Fix1
			// 
			resources->ApplyResources(this->Fix1, L"Fix1");
			this->Fix1->Name = L"Fix1";
			this->Fix1->UseVisualStyleBackColor = true;
			this->Fix1->Click += gcnew System::EventHandler(this, &BMP::Fix1_Click);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// ToRight
			// 
			resources->ApplyResources(this->ToRight, L"ToRight");
			this->ToRight->Name = L"ToRight";
			this->ToRight->UseVisualStyleBackColor = true;
			this->ToRight->Click += gcnew System::EventHandler(this, &BMP::ToRight_Click);
			// 
			// Open_Res
			// 
			resources->ApplyResources(this->Open_Res, L"Open_Res");
			this->Open_Res->Name = L"Open_Res";
			this->Open_Res->UseVisualStyleBackColor = true;
			this->Open_Res->Click += gcnew System::EventHandler(this, &BMP::Open_Res_Click);
			// 
			// ToBack
			// 
			resources->ApplyResources(this->ToBack, L"ToBack");
			this->ToBack->Name = L"ToBack";
			this->ToBack->UseVisualStyleBackColor = true;
			this->ToBack->Click += gcnew System::EventHandler(this, &BMP::ToBack_Click);
			// 
			// Close
			// 
			resources->ApplyResources(this->Close, L"Close");
			this->Close->Name = L"Close";
			this->Close->UseVisualStyleBackColor = true;
			this->Close->Click += gcnew System::EventHandler(this, &BMP::Close_Click);
			// 
			// Reset_All
			// 
			resources->ApplyResources(this->Reset_All, L"Reset_All");
			this->Reset_All->Name = L"Reset_All";
			this->Reset_All->UseVisualStyleBackColor = true;
			this->Reset_All->Click += gcnew System::EventHandler(this, &BMP::Reset_All_Click);
			// 
			// Open
			// 
			resources->ApplyResources(this->Open, L"Open");
			this->Open->Name = L"Open";
			this->Open->UseVisualStyleBackColor = true;
			this->Open->Click += gcnew System::EventHandler(this, &BMP::Open_Click);
			// 
			// Close1
			// 
			resources->ApplyResources(this->Close1, L"Close1");
			this->Close1->Name = L"Close1";
			this->Close1->UseVisualStyleBackColor = true;
			this->Close1->Click += gcnew System::EventHandler(this, &BMP::Close1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Close1);
			this->panel1->Controls->Add(this->Open);
			this->panel1->Controls->Add(this->Reset_All);
			this->panel1->Controls->Add(this->Close);
			this->panel1->Controls->Add(this->ToBack);
			this->panel1->Controls->Add(this->Open_Res);
			this->panel1->Controls->Add(this->ToRight);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// BMP
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Shit);
			this->Controls->Add(this->Fix1);
			this->Controls->Add(this->Fix);
			this->Controls->Add(this->ShitCl1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"BMP";
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::String^ way1;
		System::String^ path;
		array<String^>^ files;
		array<String^>^ files1;
		int currentIndex = 0;
		const int zoomLevel = 100;
		int Zooms = 0;

#pragma endregion

	private: System::Void Reset_All_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Close_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Open_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Shit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Open_Res_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Fix_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Negativ_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Sepia_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void èíñòğóêöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToRight_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToBack_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ShitCl1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Fix1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Close1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void èíôîğìàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}