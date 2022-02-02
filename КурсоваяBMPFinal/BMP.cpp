//BMP.cpp
#include "Func.h"
#include "BMP.h"
#include "Spravka.h"

System::Void ��������BMPFinal::BMP::Close1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pictureBox2->Image != nullptr)
	{
		pictureBox2->Image = nullptr;
		pictureBox2->Invalidate();
	}
}
System::Void ��������BMPFinal::BMP::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(rm->GetString(L"Info1"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}



System::Void ��������BMPFinal::BMP::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����� �� ���������
	Application::Exit();
}
System::Void ��������BMPFinal::BMP::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Spravka^ s = gcnew Spravka(); //������� ����� ������� ����� ���� ������ Spravka
	s->Show();//���������� ���� s �� ������ ��, ��� ���� ������� ���� �������� ��������
}



System::Void ��������BMPFinal::BMP::Reset_All_Click(System::Object^ sender, System::EventArgs^ e)
{
	//������������ ����������
	Application::Restart();
}
System::Void ��������BMPFinal::BMP::Open_Click(System::Object^ sender, System::EventArgs^ e)
{
	//���� � ������� ��� ������ ������� ������� ��
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		pictureBox1->ImageLocation = ofd->FileName;
		//� way1 �������� ��� ���������� �����
		way1 = ofd->FileName;
		//� path �������� ���� � ���������� �����
		path = System::IO::Path::GetDirectoryName(ofd->FileName);
		files = System::IO::Directory::GetFiles(path);

		for (int i = 0; i < files->Length; i++)
		{
			if (files[i] == ofd->FileName)
			{
				currentIndex = i;
				break;
			}
		}
	}
}
System::Void ��������BMPFinal::BMP::Close_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pictureBox1->Image != nullptr)
	{
		pictureBox1->Image = nullptr;
		pictureBox1->Invalidate();
	}
}



System::Void ��������BMPFinal::BMP::Shit_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{	
		//���������� ��������� ������ �� textBox1 � textBox2
		String^ S1 = textBox1->Text;
		String^ S2 = textBox2->Text;
		//������������� � ��� ������ ���
		int x = Convert::ToInt32(S1);
		int y = Convert::ToInt32(S2);
		//�������� ���������� ��������
		if (x < 1 && y < 2)
		{
			MessageBox::Show(rm->GetString(L"Invalid"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (x > y)
		{
			MessageBox::Show(rm->GetString(L"Invalid"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else
		{
			//�������� �� �� ������� pictureBox1
			if (pictureBox1->Image != nullptr)
			{
				//��������������� �� String^ � const chat* ����� ��������������
				ManagedEmp^ employee = gcnew ManagedEmp();
				employee->name = gcnew String(way1);
				marshal_context context;
				NativeEmp* result = context.marshal_as<NativeEmp*>(employee);
				//�������� �� ������ ����������
				if (GetFileExtension(result->name) == "bmp")
				{
					//�������� �� ������ ������
					if (String::Format("Pixel format: {0}", pictureBox1->Image->PixelFormat) == "Pixel format: Format24bppRgb")
					{
						//�������� ������
						FILE* f = OpenF(result);
						BITMAPFILEHEADER header1;
						BITMAPINFOHEADER header2;
						//��������� ������
						BIT1(f, &header1, &header2);


						//�������� ���������� ��� ��������� �������� �� �������
						size_t padding;
						size_t pixel_count;
						Pixel* raster;
						Pixel* temp;
						BIT2(f, header1, header2, &padding, &pixel_count, &raster, &temp);
						//��������� ������ ��� ���������� �������
						Pixel** arrr = Mas(header2);
						Pixel** a;
						//������� ����� �����������
						a = Shit_Cl(arrr, header2, raster, x, y);

						const char cc[] = "D:\\Results\\DirtyBlack.bmp";
						const char vv[] = "w+b";
						//������� ���������� �����
						if (Savef_(cc, vv, f, raster, header1, header2, temp, padding))
						{
							MessageBox::Show("D:\\Results\\DirtyBlack.bmp", rm->GetString(L"Path"), MessageBoxButtons::OK, MessageBoxIcon::Information);
							_fcloseall();
						}
					}
					else
					{
						MessageBox::Show(rm->GetString(L"Format"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
				}
				else
				{
					MessageBox::Show(rm->GetString(L"Expansion"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else
			{
				MessageBox::Show(rm->GetString(L"PhotoChoose"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}

	catch (System::FormatException^ e)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"��������BMPFinal.MyString", this->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"FromTo"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
System::Void ��������BMPFinal::BMP::ShitCl1_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		String^ S1 = textBox1->Text;
		String^ S2 = textBox2->Text;
		int x = Convert::ToInt32(S1);
		int y = Convert::ToInt32(S2);
		if (x <= 0 && y <= 0)
		{
			MessageBox::Show(rm->GetString(L"Invalid"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (x > y)
		{
			MessageBox::Show(rm->GetString(L"Invalid"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else
		{
			if (pictureBox1->Image != nullptr)
			{
				ManagedEmp^ employee = gcnew ManagedEmp();
				employee->name = gcnew String(way1);
				marshal_context context;
				NativeEmp* result = context.marshal_as<NativeEmp*>(employee);
				if (GetFileExtension(result->name) == "bmp")
				{
					if (String::Format("Pixel format: {0}", pictureBox1->Image->PixelFormat) == "Pixel format: Format24bppRgb")
					{
						FILE* f = OpenF(result);

						BITMAPFILEHEADER header1;
						BITMAPINFOHEADER header2;
						BIT1(f, &header1, &header2);

						size_t padding;
						size_t pixel_count;
						Pixel* raster;
						Pixel* temp;
						BIT2(f, header1, header2, &padding, &pixel_count, &raster, &temp);

						Pixel** arrr = Mas(header2);
						Pixel** a;
						if (arrr == NULL)
						{
							MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
						a = Shit_Cl1(arrr, header2, raster, x, y);

						const char cc[] = "D:\\Results\\DirtyWhite.bmp";
						const char vv[] = "w+b";
						if (Savef_(cc, vv, f, raster, header1, header2, temp, padding))
						{
							MessageBox::Show("D:\\Results\\DirtyWhite.bmp", rm->GetString(L"Path"), MessageBoxButtons::OK, MessageBoxIcon::Information);
							_fcloseall();
						}
					}
					else
					{
						MessageBox::Show(rm->GetString(L"Format"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
				}
				else
				{
					MessageBox::Show(rm->GetString(L"Expansion"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else
			{
				Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"��������BMPFinal.MyString", this->GetType()->Assembly);
				MessageBox::Show(rm->GetString(L"PhotoChoose"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}

	catch (System::FormatException^ e)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"��������BMPFinal.MyString", this->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"FromTo"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
System::Void ��������BMPFinal::BMP::Fix_Click(System::Object^ sender, System::EventArgs^ e)
{
	FILE* f1 = fopen("D:\\Results\\DirtyBlack.bmp", "rb");
	if (f1 == nullptr)
	{
		MessageBox::Show(rm->GetString(L"NoDirty"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else
	{
		BITMAPFILEHEADER header1;
		BITMAPINFOHEADER header2;
		BIT1(f1, &header1, &header2);

		size_t padding;
		size_t pixel_count;
		Pixel* raster;
		Pixel* temp;
		BIT2(f1, header1, header2, &padding, &pixel_count, &raster, &temp);

		Pixel** arrrr = Mas(header2);
		if (arrrr == NULL)
		{
			MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		Pixel** b;
		b = Fix_(arrrr, header2, raster);
		const char cc[] = "D:\\Results\\FixedBlack.bmp";
		const char vv[] = "w+b";
		Savef_(cc, vv, f1, raster, header1, header2, temp, padding);
		_fcloseall();
		MessageBox::Show("D:\\Results\\FixedBlack.bmp", rm->GetString(L"Path"), MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}
System::Void ��������BMPFinal::BMP::Fix1_Click(System::Object^ sender, System::EventArgs^ e)
{
	FILE* f2 = fopen("D:\\Results\\DirtyWhite.bmp", "rb");
	if (f2 == nullptr)
	{
		MessageBox::Show(rm->GetString(L"NoDirty"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else
	{
		BITMAPFILEHEADER header1;
		BITMAPINFOHEADER header2;
		BIT1(f2, &header1, &header2);

		size_t padding;
		size_t pixel_count;
		Pixel* raster;
		Pixel* temp;
		BIT2(f2, header1, header2, &padding, &pixel_count, &raster, &temp);

		Pixel** arrrr = Mas(header2);
		if (arrrr == NULL)
		{
			MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		Pixel** b;
		b = Fix_(arrrr, header2, raster);
		const char cc[] = "D:\\Results\\FixedWhite.bmp";
		const char vv[] = "w+b";
		Savef_(cc, vv, f2, raster, header1, header2, temp, padding);
		_fcloseall();

		MessageBox::Show("D:\\Results\\FixedWhite.bmp", rm->GetString(L"Path"));
	}
}
System::Void ��������BMPFinal::BMP::Sepia_Click(System::Object^ sender, System::EventArgs^ e)
{
	ManagedEmp^ employee = gcnew ManagedEmp();
	employee->name = gcnew String(pictureBox1->ImageLocation);
	marshal_context context;
	NativeEmp* result = context.marshal_as<NativeEmp*>(employee);
	if (pictureBox1->Image != nullptr)
	{
		if (GetFileExtension(result->name) == "bmp")
		{
			if (String::Format("Pixel format: {0}", pictureBox1->Image->PixelFormat) == "Pixel format: Format24bppRgb")
			{
				FILE* f3 = OpenF(result);

				BITMAPFILEHEADER header1;
				BITMAPINFOHEADER header2;
				BIT1(f3, &header1, &header2);

				size_t padding;
				size_t pixel_count;
				Pixel* raster;
				Pixel* temp;
				BIT2(f3, header1, header2, &padding, &pixel_count, &raster, &temp);

				Pixel** arrrrrr = Mas(header2);
				if (arrrrrr == NULL)
				{
					MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				Pixel** d;
				d = Sepia_(arrrrrr, header2, raster);
				const char cc[] = "D:\\Results\\Sepia.bmp";
				const char vv[] = "w+b";
				Savef_(cc, vv, f3, raster, header1, header2, temp, padding);
				_fcloseall();

				MessageBox::Show("D:\\Results\\Sepia.bmp", rm->GetString(L"Path"));
			}
			else
			{
				MessageBox::Show(rm->GetString(L"Format"), rm->GetString(L"Er"));
			}
		}
		else
		{
			MessageBox::Show(rm->GetString(L"Expansion"), rm->GetString(L"Er"));
		}
	}
	else
	{
		MessageBox::Show(rm->GetString(L"PhotoChoose"), rm->GetString(L"Er"));
	}
}
System::Void ��������BMPFinal::BMP::Negativ_Click(System::Object^ sender, System::EventArgs^ e)
{
	ManagedEmp^ employee = gcnew ManagedEmp();
	employee->name = gcnew String(pictureBox1->ImageLocation);
	marshal_context context;
	NativeEmp* result = context.marshal_as<NativeEmp*>(employee);
	if (pictureBox1->Image != nullptr)
	{
		if (GetFileExtension(result->name) == "bmp")
		{
			if (String::Format("Pixel format: {0}", pictureBox1->Image->PixelFormat) == "Pixel format: Format24bppRgb")
			{
				FILE* f2 = OpenF(result);

				BITMAPFILEHEADER header1;
				BITMAPINFOHEADER header2;
				BIT1(f2, &header1, &header2);

				size_t padding;
				size_t pixel_count;
				Pixel* raster;
				Pixel* temp;
				BIT2(f2, header1, header2, &padding, &pixel_count, &raster, &temp);

				Pixel** arrrrr = Mas(header2);
				Pixel** c;
				if (arrrrr == NULL)
				{
					MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				c = Negative_(arrrrr, header2, raster);
				const char cc[] = "D:\\Results\\Negative.bmp";
				const char vv[] = "w+b";
				Savef_(cc, vv, f2, raster, header1, header2, temp, padding);
				_fcloseall();

				MessageBox::Show("D:\\Results\\Negative.bmp", rm->GetString(L"Path"));
			}
			else
			{
				MessageBox::Show(rm->GetString(L"Format"), rm->GetString(L"Er"));
			}
		}
		else
		{
			MessageBox::Show(rm->GetString(L"Expansion"), rm->GetString(L"Er"));
		}
	}
	else
	{
		MessageBox::Show(rm->GetString(L"PhotoChoose"), rm->GetString(L"Er"));
	}
}



System::Void ��������BMPFinal::BMP::Open_Res_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		pictureBox2->ImageLocation = ofd->FileName;
		way1 = ofd->FileName;
		path = System::IO::Path::GetDirectoryName(ofd->FileName);
		files = System::IO::Directory::GetFiles(path);

		for (int i = 0; i < files->Length; i++)
		{
			if (files[i] == ofd->FileName)
			{
				currentIndex = i;
				break;
			}
		}
	}
}
System::Void ��������BMPFinal::BMP::ToBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� � ��������� ���������� ����������� �����
	if (currentIndex != 0)
	{
		currentIndex--;
	}
	pictureBox2->ImageLocation = files[currentIndex];
}
System::Void ��������BMPFinal::BMP::ToRight_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������� � ��������� ���������� ����������� ������
	if (currentIndex != files->Length - 1)
	{
		currentIndex++;
	}
	pictureBox2->ImageLocation = files[currentIndex];
}


