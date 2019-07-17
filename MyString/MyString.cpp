#include"MyString.h"

MyString::MyString() // ����������� �� ��������� (������ ������ ������)
{
	size = 0;
	str = new char[size + 1];
	str[0] = 0;
}
MyString::MyString(const string & _s) // ����������� �� ��������� (������ ������ � ���������� �������)
{
	size = 0;
	while (_s[size] != 0)
	{
		size++;
	}
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = _s[i];
	}
	str[size] = 0;
}
MyString::MyString(const MyString & _ms) // ����������� �����������
{
	size = _ms.size;
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = _ms.str[i];
	}
	str[size] = 0;
}
MyString::~MyString() // ����������
{
	delete[] str;
	size = 0;
	str = nullptr;
}

void MyString::printStr() // ����� ������ �� ����� �������
{
	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i];
	}
}
int MyString::getSizeStr() // ��������� ������ ������ (��� ����� ���������������)
{
	return size;
}
void MyString::clearStr() // ������� ������
{
	delete[] str;
	size = 0;
	str = new char[size + 1];
	str[0] = 0;
}

MyString MyString::operator=(const string & _s) // �������� ������������ (��������� ������)
{
	delete[] str; // ������ ������ �� �������  ������ �����
	size = 0;
	while (_s[size] != 0) // ������� ������ ������ ������ �����
	{
		size++;
	}
	str = new char[size + 1]; // �������� ������ ��� ����� ����� �����
	for (size_t i = 0; i < size; i++) // �������� ���������� ������ � ������
	{
		str[i] = _s[i];
	}
	str[size] = 0; // � ����� ���������� ���������������
	return *this;
}
MyString MyString::operator=(const MyString & _ms) // �������� ������������ (��������� ������ MyString)
{
	delete[] str; // ������ ������ �� �������  ������ �����
	size = _ms.size;
	str = new char[size + 1]; // �������� ������ ��� ����� ����� �����
	for (size_t i = 0; i < size; i++) // �������� ���������� ������ � ������
	{
		str[i] = _ms.str[i];
	}
	str[size] = 0; // � ����� ���������� ���������������
	return *this;
}
MyString MyString::operator+(const string & _s) // �������� �������� (��������� ������)
{
	int sizeNew = 0;
	while (_s[sizeNew] != 0)
	{
		sizeNew++;
	}
	sizeNew += size;
	MyString newStr;
	newStr.size = sizeNew;
	delete[] newStr.str;
	newStr.str = new char[newStr.size + 1];
	for (size_t i = 0; i < newStr.size; i++)
	{
		if (i < size)
		{
			newStr.str[i] = str[i];
		}
		else
		{
			newStr.str[i] = _s[i - size];
		}
	}
	newStr.str[newStr.size] = 0;
	return newStr;
}
MyString MyString::operator+(const MyString & _ms) // �������� �������� (��������� ������ MyString)
{
	MyString newStr;
	newStr.size = size + _ms.size;
	delete[] newStr.str;
	newStr.str = new char[newStr.size + 1];
	for (size_t i = 0; i < newStr.size; i++)
	{
		if (i < size)
		{
			newStr.str[i] = str[i];
		}
		else
		{
			newStr.str[i] = _ms.str[i - size];
		}
	}
	newStr.str[newStr.size] = 0;
	return newStr;
}
MyString MyString::operator+=(const string & _s) // ������������ ������� �� �������
{
	int size_s = 0;
	while (_s[size_s] != 0) // ������� ������ ������ �����
	{
		size_s++;
	}
	char * newStr = new char[size + size_s + 1]; // ����� ����� �������� ������� + ������ ������ ������� ������������
	for (size_t i = 0; i < size + size_s; i++) // ������������ � ����� ������ ������
	{
		if (i < size)
		{
			newStr[i] = str[i];
		}
		else
		{
			newStr[i] = _s[i - size];
		}
	}
	size += size_s; // ������ ������ �������� �������
	newStr[size] = 0; // � ��������� ������� ������ ���������� ��������������
	delete[] str; // �������� ������� ������
	str = newStr; // ������������ ��������� �� ����� ������
	return *this;
}
MyString MyString::operator+=(const MyString & _ms) // ������������ ������� � ��������
{
	char * newStr = new char[size + _ms.size + 1];
	for (size_t i = 0; i < size + _ms.size; i++) // ������������ � ����� ������ ������
	{
		if (i < size)
		{
			newStr[i] = str[i];
		}
		else
		{
			newStr[i] = _ms.str[i - size];
		}
	}
	size += _ms.size; // ������ ������ �������� �������
	newStr[size] = 0; // � ��������� ������� ������ ���������� ��������������
	delete[] str; // �������� ������� ������
	str = newStr; // ������������ ��������� �� ����� ������
	return *this;
}
bool MyString::operator==(const string & _s) // �������� ���������� ������� �� �������
{
	int size_s = 0;
	while (_s[size_s] != 0) // ������� ������ ������ �����
	{
		size_s++;
	}
	if (size == size_s)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != _s[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool MyString::operator==(const MyString & _ms) // �������� ���������� ������� � �������� ���� MyString
{
	if (size == _ms.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != _ms.str[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool MyString::operator!=(const string & _s) // �������� ���������� ������� �� �������
{
	int size_s = 0;
	while (_s[size_s] != 0) // ������� ������ ������ �����
	{
		size_s++;
	}
	if (size == size_s)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != _s[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}
bool MyString::operator!=(const MyString & _ms) // �������� ���������� ������� � �������� ���� MyString
{
	if (size == _ms.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] != _ms.str[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}
