#pragma once
#include <iostream>
#include <string>

using namespace std;

class Multiset
{
private:
	string array; // ������� �������
public:
	Multiset(); // ��������� ����� �������
	Multiset(const char*); // ��������� ������� �� ���������� �� ����� �������
	Multiset(string&); // ��������� ������� �� ������

	string& get_multiset(); // �������� �������
	bool inset(char*); // ��������, �� �������� ������ ������
	void print(); // ���� �������

	void operator = (const Multiset&); // ������������ ���� ������� �����
	Multiset operator + (Multiset&); // ��'������� ������
	Multiset operator * (Multiset&); // ������ ������
	Multiset operator - (Multiset&); // г����� ������
};

void input(string&, string&, string&); // �������� ������
void check(Multiset&, Multiset&, Multiset&, Multiset&); // �������� ������� � ������