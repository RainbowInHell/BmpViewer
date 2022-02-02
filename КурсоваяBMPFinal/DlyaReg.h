//DlyaReg.h
#pragma once
#include <fstream>
#include <string>
using namespace std;
//класс для авторизации и регистрации пользователей
class User
{
private:
	//поля логин и пароль типа string
	string login;
	string password;
public:
	//конструктор без параметров
	User() {}
	User(string login_, string password_)
	{
		SetLogin(login_);
		SetPassword(password_);
	}
	//сеттер для логина
	string SetLogin(string login_)
	{
		login = login_;
		return login;
	}
	//сеттер для пароля
	string SetPassword(string password_)
	{
		password = password_;
		return password;
	}
	//метод для записи нового пользователя
	bool writer()
	{

		bool h;
		fstream file("records.txt", ios::in);
		fstream file2("records.txt", ios::app);
		string a;
		while (!file.eof())
		{
			//читаем в временную переменную а
			file >> a;
			if (login != a)
			{
				h = false;
			}
			else
			{
				h = true;
				return true;
				break;
			}
		}
		//если пвоторений нет то записываем нового пользователя
		if (h == false)
		{
			file2 << login << " " << password << endl;
			return false;
		}
	}

	//метод для проверки есть ли уже такой пользователь
	bool Chek()
	{
		bool h;
		string log_pas = login + " " + password;
		string temp;
		//создаем поток для чтения
		fstream file("records.txt", ios::in);
		//читаем до конца
		while (!file.eof())
		{
			//читаем по линиям
			getline(file, temp);
			if (log_pas == temp)
			{
				h = true;
				break;
			}
			else
			{
				h = false;
			}
		}
		if (h == true)
		{
			return true;
		}

		file.close();
	}
};
