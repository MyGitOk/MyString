#pragma once
#include<iostream>

using namespace std;

class MyString
{
public:
	MyString(); // ����������� �� ��������� (������ ������ ������)
	MyString(const string & _s); // ����������� �� ��������� (������ ������ � ���������� �������)
	MyString(const MyString & _ms); // ����������� �����������
	~MyString(); // ����������
	void printStr(); // ����� ������ �� ����� �������
	int getSizeStr(); // ��������� ������� ������ (��� ����� ���������������)
	void clearStr(); // ������� ������
	MyString operator=(const string & _s); // �������� ������������ (��������� ������)
	MyString operator=(const MyString & _ms); // �������� ������������ (��������� ������ MyString)
	MyString operator+(const string & _s); // �������� �������� (��������� ������)
	MyString operator+(const MyString & _ms); // �������� �������� (��������� ������ MyString)
	MyString operator+=(const string & _s); // ������������ ������� �� �������
	MyString operator+=(const MyString & _ms); // ������������ ������� � ��������

	bool operator==(const string & _s); // �������� ���������� ������� �� �������
	bool operator==(const MyString & _ms); // �������� ���������� ������� � �������� ���� MyString
	bool operator!=(const string & _s); // �������� ���������� ������� �� �������
	bool operator!=(const MyString & _ms); // �������� ���������� ������� � �������� ���� MyString


private:
	char * str;
	unsigned int size;
};