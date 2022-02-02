//ChangeLanguage.h
#pragma once

using namespace System::Globalization;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Xml;

namespace КурсоваяBMPFinal
{
	public ref class ChangeLanguage
	{
	public:
		//функция для обновления настроек приложения
		void UpdateConfig(String^ key, String^ value)
		{
			XmlDocument^ xmlDoc = gcnew XmlDocument();
			//загрузка xml документа из указанного URL-адреса
			xmlDoc->Load(AppDomain::CurrentDomain->SetupInformation->ConfigurationFile);

			for each (XmlElement ^ xmlElement in xmlDoc->DocumentElement)
			{
				if (xmlElement->Name->Equals("appSettings"))
				{
					//представление отдельного узла в XML-документе
					for each (XmlNode ^ xNode in xmlElement->ChildNodes)
					{
						//получение атрибутов данного узла(ключ - значение)
						if (xNode->Attributes[0]->Value->Equals(key))
						{
							xNode->Attributes[1]->Value = value;
						}
					}
				}
			}
			//сохранение настроек
			System::Configuration::ConfigurationManager::RefreshSection("appSettings");
			xmlDoc->Save(AppDomain::CurrentDomain->SetupInformation->ConfigurationFile);
		}
	};
}
