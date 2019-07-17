#pragma once
#include<iostream>

using namespace std;

class MyString
{
public:
	MyString(); // конструктор по умолчанию (создаёт пустую строку)
	MyString(const string & _s); // конструктор по умолчанию (создаёт строку с переданным текстом)
	MyString(const MyString & _ms); // конструктор копирования
	~MyString(); // деструктор
	void printStr(); // вывод строки на экран консоли
	int getSizeStr(); // получение размера строки (без учёта нольтерминатора)
	void clearStr(); // очистка строки
	MyString operator=(const string & _s); // оператор присваивания (принимает строку)
	MyString operator=(const MyString & _ms); // оператор присваивания (принимает объект MyString)
	MyString operator+(const string & _s); // оператор сложения (принимает строку)
	MyString operator+(const MyString & _ms); // оператор сложения (принимает объект MyString)
	MyString operator+=(const string & _s); // конкатенация объекта со строкой
	MyString operator+=(const MyString & _ms); // конкатенация объекта с объектом

	bool operator==(const string & _s); // оператор стравнения объекта со строкой
	bool operator==(const MyString & _ms); // оператор стравнения объекта с объектом типа MyString
	bool operator!=(const string & _s); // оператор стравнения объекта со строкой
	bool operator!=(const MyString & _ms); // оператор стравнения объекта с объектом типа MyString


private:
	char * str;
	unsigned int size;
};