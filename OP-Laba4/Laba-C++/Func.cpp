#include "Func.h"

void input(string& str1, string& str2, string& str3) // Вводимо множини символів як рядки
{
	cout << "Input the first set (Example: akhsgjd,1n23 6): ";
	getline(cin, str1);
	cout << "Input the second set (Example: akhsg jd,1n236): ";
	getline(cin, str2);
	cout << "Input the third set (Example: ak hsgjd,1n236): ";
	getline(cin, str3);
}

void check(Multiset& A, Multiset& B, Multiset& C, Multiset& D)
{
	int n; // Номер множини
	char m; // Символ для перевірки
	cout << "\nInput the set number: ";
	cin >> n;
	cout << "Input the symbol: ";
	cin >> m;

	// Перевірка символу на наявність у множині
	if (n == 1)
	{
		if (A.inset(&m))
		{
			cout << "The symbol is in the set!" << endl;
		}
		else
		{
			cout << "The symbol is not in the set!" << endl;
		}
	}
	else if (n == 2)
	{
		if (B.inset(&m))
		{
			cout << "The symbol is in the set!" << endl;
		}
		else
		{
			cout << "The symbol is not in the set!" << endl;
		}
	}
	else if (n == 3)
	{
		if (C.inset(&m))
		{
			cout << "The symbol is in the set!" << endl;
		}
		else
		{
			cout << "The symbol is not in the set!" << endl;
		}
	}
	else if (n == 4)
	{
		if (D.inset(&m))
		{
			cout << "The symbol is in the set!" << endl;
		}
		else
		{
			cout << "The symbol is not in the set!" << endl;
		}
	}
	else
	{
		cout << "The incorrect number!" << endl;
	}
}

Multiset::Multiset()
{
	array = ""; // Пуста множина
}

Multiset::Multiset(const char* array)
{
	this->array = array; // Присвоюємо рядку масив символів
}

Multiset::Multiset(string& array)
{
	this->array = array; // Приствоюємо рядок рядку
}

string& Multiset::get_multiset()
{
	return array; // Повертаємо множину
}

bool Multiset::inset(char* symbol) // Перевірка, чи належить символ множині
{
	bool flag = false;
	for (int i = 0; i < array.size(); i++)
	{
		if (*symbol == array[i])
		{
			flag = true;
		}
	}
	return flag;
}

void Multiset::print() // Виведення множини символів
{
	cout << "{ '";
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i];
		if (i == array.size() - 1)
		{
			cout << "' }\n";
		}
		else
		{
			cout << "', '";
		}
	}
}

void Multiset::operator = (const Multiset& operand) // Приствоювання множини
{
	this->array = operand.array;
}

Multiset Multiset::operator + (Multiset& operand)
{
	Multiset temp; // Тимчасовий об'єкт класу
	temp.array += operand.array; // Присвоюємо атрибуту тимчасового об'єкту множину
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) == -1) // Якщо символу немає в множині, то додаємо його в тимчасову множину
		{
			temp.array += this->array[i];
		}
	}
	return temp; // Повертаємо тимчасовий об'єкт
}

Multiset Multiset::operator * (Multiset& operand)
{
	Multiset temp; // Тимчасовий об'єкт класу
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) != -1) // Якщо символ є у двох множинах, то присвоюємо його тимчасовій множині
		{
			temp.array += this->array[i];
		}
	}
	return temp; // Повертаємо тимчасовий об'єкт
}

Multiset Multiset::operator - (Multiset& operand)
{
	Multiset temp; // Тимчасовий об'єкт класу
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) == -1) // Якщо символ є у першій множині і відсутній у другій множині, то присвоюємо його тимчасовій множині
		{
			temp.array += this->array[i];
		}
	}
	return temp; // Повертаємо тимчасовий об'єкт
}