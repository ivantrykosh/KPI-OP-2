#pragma once
#include <iostream>
#include <string>

using namespace std;

class Multiset
{
private:
	string array; // Множина символів
public:
	Multiset(); // Створення пустої множини
	Multiset(const char*); // Створення множини за покажчиком на масив символів
	Multiset(string&); // Створення множини за рядком

	string& get_multiset(); // Отимання множини
	bool inset(char*); // Перевірка, чи належить символ множині
	void print(); // Вивід множини

	void operator = (const Multiset&); // Присвоювання однієї множини іншій
	Multiset operator + (Multiset&); // Об'єднання множин
	Multiset operator * (Multiset&); // Переріз множин
	Multiset operator - (Multiset&); // Різниця множин
};

void input(string&, string&, string&); // Введення множин
void check(Multiset&, Multiset&, Multiset&, Multiset&); // Перевірка символу в множині