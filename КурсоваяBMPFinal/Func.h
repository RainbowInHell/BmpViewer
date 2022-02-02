//Func.h
#pragma once
#include "BMP.h"
#include <Windows.h>
#include <iostream>
#include <msclr/marshal.h>



//структура для маршалирования, хранит поле типа String^
value struct ManagedEmp 
{
	System::String^ name;
};
//структура для маршалирования, хранит поле типа const char*
struct NativeEmp {
	const char* name;
};
//готовая структура, поскольку формат БМП разработали не мы. Эта структура для установки и хранения цвета одного пикселя
struct Pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

//готовый код для маршалирования, взятый на оффициаельном сайте microsoft
namespace msclr {
	namespace interop {
		template<>
		ref class context_node<NativeEmp*, ManagedEmp^> : public context_node_base
		{
		private:
			NativeEmp* toPtr;
			marshal_context context;
		public:
			context_node(NativeEmp*& toObject, ManagedEmp^ fromObject)
			{
				// Conversion logic starts here
				toPtr = NULL;

				const char* nativeName;
				const char* nativeAddress;

				// Convert the name from String^ to const char*.
				System::String^ tempValue = fromObject->name;
				nativeName = context.marshal_as<const char*>(tempValue);

				toPtr = new NativeEmp();
				toPtr->name = nativeName;

				toObject = toPtr;
			}
			~context_node()
			{
				this->!context_node();
			}
		protected:
			!context_node()
			{
				// When the context is deleted, it will free the memory
				// allocated for toPtr->name and toPtr->address, so toPtr
				// is the only memory that needs to be freed.
				if (toPtr != NULL) {
					delete toPtr;
					toPtr = NULL;
				}
			}
		};
	}
}
using namespace System;
using namespace msclr::interop;
using namespace КурсоваяBMPFinal;

//функция для получения расширения файла
std::string GetFileExtension(const std::string& FileName)
{
	if (FileName.find_last_of(".") != std::string::npos)
		return FileName.substr(FileName.find_last_of(".") + 1);
	return "";
}

Pixel** Mas(BITMAPINFOHEADER a)
{
	//выделение памяти для двумерного динамического массива
	Pixel** arr = new Pixel * [a.biHeight];
	BMP^ gg = gcnew BMP();
	//если нет памяти
	if (arr == NULL)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	for (int i = 0; i < a.biHeight; i++)
	{
		arr[i] = new Pixel[a.biWidth];
		if (arr[i] == NULL)
		{
			Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
			MessageBox::Show(rm->GetString(L"NoMemory"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	return arr;
}

//функция для порчи изображения черными пикселями
Pixel** Shit_Cl(Pixel** arr, BITMAPINFOHEADER a, Pixel* ras, int x, int c)
{
	//используем рандомный шаг
	for (int i = 0; i < a.biHeight; i += x + rand() % c)
	{
		for (int j = 0; j < a.biWidth; j += x + rand() % c)
		{
			//для работы с цветами, создадим указатель типа p
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].r = 0;
			arr[i][j].g = 0;
			arr[i][j].b = 0;
			*p = arr[i][j];
		}
	}
	return arr;
}
//функция для порчи изображения белыми пикселями
Pixel** Shit_Cl1(Pixel** arr, BITMAPINFOHEADER a, Pixel* ras, int x, int c)
{
	for (int i = 0; i < a.biHeight; i += x + rand() % c)
	{
		for (int j = 0; j < a.biWidth; j += x + rand() % c)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].r = 255;
			arr[i][j].g = 255;
			arr[i][j].b = 255;
			*p = arr[i][j];
		}
	}
	return arr;
}
//функция для исправления изображения
Pixel** Fix_(Pixel** arr, BITMAPINFOHEADER a, Pixel* ras)
{
	//по углам
	for (int i = 0; i < a.biHeight; i++)
	{
		for (int j = 0; j < a.biWidth; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			if (i == 0 && j == a.biWidth - 1)
			{
				arr[i][j].b = (arr[i][j - 1].b + arr[i + 1][j - 1].b + arr[i + 1][j].b) / 3.0;
				arr[i][j].g = (arr[i][j - 1].g + arr[i + 1][j - 1].g + arr[i + 1][j].g) / 3.0;
				arr[i][j].r = (arr[i][j - 1].r + arr[i + 1][j - 1].r + arr[i + 1][j].r) / 3.0;
				*p = arr[i][j];
			}
			if (i == 0 && j == 0)
			{
				arr[i][j].b = (arr[i][j + 1].b + arr[i + 1][j + 1].b + arr[i + 1][j].b) / 3.0;
				arr[i][j].g = (arr[i][j + 1].g + arr[i + 1][j + 1].g + arr[i + 1][j].g) / 3.0;
				arr[i][j].r = (arr[i][j + 1].r + arr[i + 1][j + 1].r + arr[i + 1][j].r) / 3.0;
				*p = arr[i][j];
			}
			if (i == a.biHeight - 1 && j == a.biWidth - 1)
			{
				arr[i][j].b = (arr[i - 1][j].b + arr[i - 1][j - 1].b + arr[i][j - 1].b) / 3.0;
				arr[i][j].g = (arr[i - 1][j].g + arr[i - 1][j - 1].g + arr[i][j - 1].g) / 3.0;
				arr[i][j].r = (arr[i - 1][j].r + arr[i - 1][j - 1].r + arr[i][j - 1].r) / 3.0;
				*p = arr[i][j];
			}
			if (i == a.biHeight - 1 && j == 0)
			{
				arr[i][j].b = (arr[i - 1][j].b + arr[i - 1][j + 1].b + arr[i][j + 1].b) / 3.0;
				arr[i][j].g = (arr[i - 1][j].g + arr[i - 1][j + 1].g + arr[i][j + 1].g) / 3.0;
				arr[i][j].r = (arr[i - 1][j].r + arr[i - 1][j + 1].r + arr[i][j + 1].r) / 3.0;
				*p = arr[i][j];
			}
		}
	}

	//по бокам
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j < a.biWidth - 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].b = (arr[i][j - 1].b + arr[i + 1][j - 1].b + arr[i + 1][j].b + arr[i + 1][j + 1].b + arr[i][j + 1].b) / 5.0;
			arr[i][j].g = (arr[i][j - 1].g + arr[i + 1][j - 1].g + arr[i + 1][j].g + arr[i + 1][j + 1].g + arr[i][j + 1].g) / 5.0;
			arr[i][j].r = (arr[i][j - 1].r + arr[i + 1][j - 1].r + arr[i + 1][j].r + arr[i + 1][j + 1].r + arr[i][j + 1].r) / 5.0;
			*p = arr[i][j];
		}
	}
	for (int i = 1; i < a.biHeight - 1; i++)
	{
		for (int j = a.biWidth - 1; j < a.biWidth; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].b = (arr[i - 1][j].b + arr[i - 1][j - 1].b + arr[i][j - 1].b + arr[i + 1][j - 1].b + arr[i + 1][j].b) / 5.0;
			arr[i][j].g = (arr[i - 1][j].g + arr[i - 1][j - 1].g + arr[i][j - 1].g + arr[i + 1][j - 1].g + arr[i + 1][j].g) / 5.0;
			arr[i][j].r = (arr[i - 1][j].r + arr[i - 1][j - 1].r + arr[i][j - 1].r + arr[i + 1][j - 1].r + arr[i + 1][j].r) / 5.0;
			*p = arr[i][j];
		}
	}

	for (int i = a.biHeight - 1; i < a.biHeight; i++)
	{
		for (int j = 1; j < a.biWidth - 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].b = (arr[i][j - 1].b + arr[i - 1][j - 1].b + arr[i - 1][j].b + arr[i - 1][j + 1].b + arr[i][j + 1].b) / 5.0;
			arr[i][j].g = (arr[i][j - 1].g + arr[i - 1][j - 1].g + arr[i - 1][j].g + arr[i - 1][j + 1].g + arr[i][j + 1].g) / 5.0;
			arr[i][j].r = (arr[i][j - 1].r + arr[i - 1][j - 1].r + arr[i - 1][j].r + arr[i - 1][j + 1].r + arr[i][j + 1].r) / 5.0;
			*p = arr[i][j];
		}
	}

	for (int i = 1; i < a.biHeight - 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			arr[i][j].b = (arr[i - 1][j].b + arr[i - 1][j + 1].b + arr[i][j + 1].b + arr[i - 1][j - 1].b + arr[i + 1][j].b) / 5.0;
			arr[i][j].g = (arr[i - 1][j].g + arr[i - 1][j + 1].g + arr[i][j + 1].g + arr[i - 1][j - 1].g + arr[i + 1][j].g) / 5.0;
			arr[i][j].r = (arr[i - 1][j].r + arr[i - 1][j + 1].r + arr[i][j + 1].r + arr[i - 1][j - 1].r + arr[i + 1][j].r) / 5.0;
			*p = arr[i][j];
		}
	}

	//внутри
	for (int i = 1; i < a.biHeight - 1; i++)
	{
		for (int j = 1; j < a.biWidth - 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			if ((arr[i][j].b == 0 & arr[i][j].g == 0 & arr[i][j].r == 0) || (arr[i][j].b == 255 & arr[i][j].g == 255 & arr[i][j].r == 255))
			{
				arr[i][j].b = (arr[i - 1][j - 1].b + arr[i - 1][j].b + arr[i - 1][j + 1].b + arr[i][j + 1].b + arr[i + 1][j + 1].b + arr[i + 1][j].b + arr[i + 1][j - 1].b + arr[i][j - 1].b) / 8.0;
				arr[i][j].g = (arr[i - 1][j - 1].g + arr[i - 1][j].g + arr[i - 1][j + 1].g + arr[i][j + 1].g + arr[i + 1][j + 1].g + arr[i + 1][j].g + arr[i + 1][j - 1].g + arr[i][j - 1].g) / 8.0;
				arr[i][j].r = (arr[i - 1][j - 1].r + arr[i - 1][j].r + arr[i - 1][j + 1].r + arr[i][j + 1].r + arr[i + 1][j + 1].r + arr[i + 1][j].r + arr[i + 1][j - 1].r + arr[i][j - 1].r) / 8.0;
				*p = arr[i][j];
			}
		}
	}

	return arr;
}
//функция для применения фильтра негатив
Pixel** Negative_(Pixel** arr, BITMAPINFOHEADER a, Pixel* ras)
{
	for (int i = 1; i < a.biHeight - 1; i++)
	{
		for (int j = 1; j < a.biWidth - 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			//присваиваем пикселю его обратный цвет
			arr[i][j].r = 255 - arr[i][j].r;
			arr[i][j].g = 255 - arr[i][j].g;
			arr[i][j].b = 255 - arr[i][j].b;
			*p = arr[i][j];
		}
	}
	return arr;
}
//функция для применения фильтра сепия
Pixel** Sepia_(Pixel** arr, BITMAPINFOHEADER a, Pixel* ras)
{
	int tr, tg, tb;
	for (int i = 1; i < a.biHeight - 1; i++)
	{
		for (int j = 1; j < a.biWidth - 1; j++)
		{
			Pixel* p = ras + a.biWidth * i + j;
			arr[i][j] = *p;
			tr = (int)(0.259 * arr[i][j].r + 0.259 * arr[i][j].g + 0.259 * arr[i][j].b);
			tg = (int)(0.359 * arr[i][j].r + 0.359 * arr[i][j].g + 0.359 * arr[i][j].b);
			tb = (int)(0.459 * arr[i][j].r + 0.459 * arr[i][j].g + 0.459 * arr[i][j].b);
			if (tr > 255 || tg > 255 || tb > 255)
			{
				tr = 255;
				tg = 255;
				tb = 255;
			}
			arr[i][j].r = (tr);
			arr[i][j].g = (tg);
			arr[i][j].b = (tb);
			*p = arr[i][j];
		}
	}
	return arr;
}
//функция для открытия файла
FILE* OpenF(NativeEmp* a)
{
	//создаем поток
	FILE* file = fopen(a->name, "rb");
	BMP^ gg = gcnew BMP();
	if (file == nullptr)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"BadFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	return file;
}
//функция сохранения обработанного файла
FILE* Savef_(const char a[], const char b[], FILE* f, Pixel* ras, BITMAPFILEHEADER c, BITMAPINFOHEADER d, Pixel* temp, size_t pad)
{
	FILE* new_file;
	fopen_s(&new_file, a, b);
	BMP^ gg = gcnew BMP();
	if (new_file == nullptr)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"BadFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		fclose(f);
		free(ras);
	}
	else
	{
		c.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		size_t fieles_count = fwrite(&c, sizeof(c), 1, new_file);
		fieles_count = fwrite(&d, sizeof(d), 1, new_file);
		temp = ras;
		for (int row = 0; row < d.biHeight; row++)
		{
			size_t count = fwrite(temp, sizeof(Pixel), d.biWidth, new_file);
			unsigned char zero = 0;
			fwrite(&zero, 1, pad, new_file);
			temp += count;
		}
		fclose(new_file);
		return new_file;
	}
}

void BIT1(FILE* f, BITMAPFILEHEADER* a, BITMAPINFOHEADER* b)
{
	fread(&(*a), sizeof(BITMAPFILEHEADER), 1, f);
	BMP^ gg = gcnew BMP();
	if ((*a).bfType != 19778)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"BadFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	fread(&(*b), sizeof(BITMAPINFOHEADER), 1, f);
	if ((*a).bfType != 19778)
	{
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
		MessageBox::Show(rm->GetString(L"BadFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

void BIT2(FILE* f, BITMAPFILEHEADER a, BITMAPINFOHEADER b, size_t* pad, size_t* pixc, Pixel* (*ras), Pixel* (*tmp))
{
	(*pad) = b.biWidth % 4;
	(*pixc) = b.biWidth * b.biHeight;

	fseek(f, a.bfOffBits, SEEK_SET); //функция может сдвигать, ставить курсор работы с файлом (чтения/записи) в конкретную позицию отсносительно начала файла

	(*ras) = (Pixel*)malloc(sizeof(Pixel) * (*pixc));//хардкорное выделение памяти как на C
	(*tmp) = (*ras);
	BMP^ gg = gcnew BMP();
	for (int row = 0; row < b.biHeight; row++)
	{
		size_t count = fread((*tmp), sizeof(Pixel), b.biWidth, f);
		fseek(f, (*pad), SEEK_CUR);
		(*tmp) += count;
		if (count != b.biWidth)
		{
			Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"КурсоваяBMPFinal.MyString", gg->GetType()->Assembly);
			MessageBox::Show(rm->GetString(L"BadFile"), rm->GetString(L"Er"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
			fclose(f);
			free((*ras));//освобождение ДООП
			return;
		}
	}

}



