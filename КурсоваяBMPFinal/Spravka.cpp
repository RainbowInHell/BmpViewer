//Spravka.cpp
#include "Spravka.h"

System::Void ��������BMPFinal::Spravka::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Resources::ResourceManager^ rm = gcnew Resources::ResourceManager(L"��������BMPFinal.MyString", this->GetType()->Assembly);
	MessageBox::Show(rm->GetString(L"Spravka"), rm->GetString(L"Info"), MessageBoxButtons::OK, MessageBoxIcon::Information);
}
