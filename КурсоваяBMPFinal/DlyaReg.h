//DlyaReg.h
#pragma once
#include <fstream>
#include <string>
using namespace std;
//����� ��� ����������� � ����������� �������������
class User
{
private:
	//���� ����� � ������ ���� string
	string login;
	string password;
public:
	//����������� ��� ����������
	User() {}
	User(string login_, string password_)
	{
		SetLogin(login_);
		SetPassword(password_);
	}
	//������ ��� ������
	string SetLogin(string login_)
	{
		login = login_;
		return login;
	}
	//������ ��� ������
	string SetPassword(string password_)
	{
		password = password_;
		return password;
	}
	//����� ��� ������ ������ ������������
	bool writer()
	{

		bool h;
		fstream file("records.txt", ios::in);
		fstream file2("records.txt", ios::app);
		string a;
		while (!file.eof())
		{
			//������ � ��������� ���������� �
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
		//���� ���������� ��� �� ���������� ������ ������������
		if (h == false)
		{
			file2 << login << " " << password << endl;
			return false;
		}
	}

	//����� ��� �������� ���� �� ��� ����� ������������
	bool Chek()
	{
		bool h;
		string log_pas = login + " " + password;
		string temp;
		//������� ����� ��� ������
		fstream file("records.txt", ios::in);
		//������ �� �����
		while (!file.eof())
		{
			//������ �� ������
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
