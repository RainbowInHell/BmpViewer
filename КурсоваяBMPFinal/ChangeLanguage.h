//ChangeLanguage.h
#pragma once

using namespace System::Globalization;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Xml;

namespace ��������BMPFinal
{
	public ref class ChangeLanguage
	{
	public:
		//������� ��� ���������� �������� ����������
		void UpdateConfig(String^ key, String^ value)
		{
			XmlDocument^ xmlDoc = gcnew XmlDocument();
			//�������� xml ��������� �� ���������� URL-������
			xmlDoc->Load(AppDomain::CurrentDomain->SetupInformation->ConfigurationFile);

			for each (XmlElement ^ xmlElement in xmlDoc->DocumentElement)
			{
				if (xmlElement->Name->Equals("appSettings"))
				{
					//������������� ���������� ���� � XML-���������
					for each (XmlNode ^ xNode in xmlElement->ChildNodes)
					{
						//��������� ��������� ������� ����(���� - ��������)
						if (xNode->Attributes[0]->Value->Equals(key))
						{
							xNode->Attributes[1]->Value = value;
						}
					}
				}
			}
			//���������� ��������
			System::Configuration::ConfigurationManager::RefreshSection("appSettings");
			xmlDoc->Save(AppDomain::CurrentDomain->SetupInformation->ConfigurationFile);
		}
	};
}
