#include"MyString.h"

MyString::MyString() // конструктор по умолчанию (создаёт пустую строку)
{
	size = 0;
	str = new char[size + 1];
	str[0] = 0;
}
MyString::MyString(const string & _s) // конструктор по умолчанию (создаёт строку с переданным текстом)
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
MyString::MyString(const MyString & _ms) // конструктор копирования
{
	size = _ms.size;
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = _ms.str[i];
	}
	str[size] = 0;
}
MyString::~MyString() // деструктор
{
	delete[] str;
	size = 0;
	str = nullptr;
}

void MyString::printStr() // вывод строки на экран консоли
{
	for (size_t i = 0; str[i] != 0; i++)
	{
		cout << str[i];
	}
}
int MyString::getSizeStr() // возращает размер строки (без учёта нольтерминатора)
{
	return size;
}
void MyString::clearStr() // очистка строки
{
	delete[] str;
	size = 0;
	str = new char[size + 1];
	str[0] = 0;
}

MyString MyString::operator=(const string & _s) // оператор присваивания (принимает строку)
{
	delete[] str; // чистим память от старого  масива чаров
	size = 0;
	while (_s[size] != 0) // считаем размер нового масива чаров
	{
		size++;
	}
	str = new char[size + 1]; // выделяем память под новый масив чаров
	for (size_t i = 0; i < size; i++) // копируем переданную строку в массив
	{
		str[i] = _s[i];
	}
	str[size] = 0; // в конец записываем нольтерминаторы
	return *this;
}
MyString MyString::operator=(const MyString & _ms) // оператор присваивания (принимает объект MyString)
{
	delete[] str; // чистим память от старого  масива чаров
	size = _ms.size;
	str = new char[size + 1]; // выделяем память под новый масив чаров
	for (size_t i = 0; i < size; i++) // копируем переданную строку в массив
	{
		str[i] = _ms.str[i];
	}
	str[size] = 0; // в конец записываем нольтерминаторы
	return *this;
}
MyString MyString::operator+(const string & _s) // оператор сложения (принимает строку)
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
MyString MyString::operator+(const MyString & _ms) // оператор сложения (принимает объект MyString)
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
MyString MyString::operator+=(const string & _s) // конкатенация объекта со строкой
{
	int size_s = 0;
	while (_s[size_s] != 0) // считаем размер масива чаров
	{
		size_s++;
	}
	char * newStr = new char[size + size_s + 1]; // новый масив размером текущий + размер строки которую присоеденяем
	for (size_t i = 0; i < size + size_s; i++) // переписываем в новый массив строки
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
	size += size_s; // меняем размер текущего объекта
	newStr[size] = 0; // в последний элемент масива записываем нольтерминатор
	delete[] str; // удаление старого масива
	str = newStr; // переставляем указатель на новый массив
	return *this;
}
MyString MyString::operator+=(const MyString & _ms) // конкатенация объекта с объектом
{
	char * newStr = new char[size + _ms.size + 1];
	for (size_t i = 0; i < size + _ms.size; i++) // переписываем в новый массив строки
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
	size += _ms.size; // меняем размер текущего объекта
	newStr[size] = 0; // в последний элемент масива записываем нольтерминатор
	delete[] str; // удаление старого масива
	str = newStr; // переставляем указатель на новый массив
	return *this;
}
bool MyString::operator==(const string & _s) // оператор стравнения объекта со строкой
{
	int size_s = 0;
	while (_s[size_s] != 0) // считаем размер масива чаров
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
bool MyString::operator==(const MyString & _ms) // оператор стравнения объекта с объектом типа MyString
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
bool MyString::operator!=(const string & _s) // оператор стравнения объекта со строкой
{
	int size_s = 0;
	while (_s[size_s] != 0) // считаем размер масива чаров
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
bool MyString::operator!=(const MyString & _ms) // оператор стравнения объекта с объектом типа MyString
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
