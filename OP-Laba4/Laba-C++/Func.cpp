#include "Func.h"

void input(string& str1, string& str2, string& str3) // ������� ������� ������� �� �����
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
	int n; // ����� �������
	char m; // ������ ��� ��������
	cout << "\nInput the set number: ";
	cin >> n;
	cout << "Input the symbol: ";
	cin >> m;

	// �������� ������� �� �������� � ������
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
	array = ""; // ����� �������
}

Multiset::Multiset(const char* array)
{
	this->array = array; // ���������� ����� ����� �������
}

Multiset::Multiset(string& array)
{
	this->array = array; // ����������� ����� �����
}

string& Multiset::get_multiset()
{
	return array; // ��������� �������
}

bool Multiset::inset(char* symbol) // ��������, �� �������� ������ ������
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

void Multiset::print() // ��������� ������� �������
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

void Multiset::operator = (const Multiset& operand) // ������������� �������
{
	this->array = operand.array;
}

Multiset Multiset::operator + (Multiset& operand)
{
	Multiset temp; // ���������� ��'��� �����
	temp.array += operand.array; // ���������� �������� ����������� ��'���� �������
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) == -1) // ���� ������� ���� � ������, �� ������ ���� � ��������� �������
		{
			temp.array += this->array[i];
		}
	}
	return temp; // ��������� ���������� ��'���
}

Multiset Multiset::operator * (Multiset& operand)
{
	Multiset temp; // ���������� ��'��� �����
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) != -1) // ���� ������ � � ���� ��������, �� ���������� ���� ��������� ������
		{
			temp.array += this->array[i];
		}
	}
	return temp; // ��������� ���������� ��'���
}

Multiset Multiset::operator - (Multiset& operand)
{
	Multiset temp; // ���������� ��'��� �����
	for (int i = 0; i < this->array.size(); i++)
	{
		if (operand.get_multiset().find(this->array[i]) == -1) // ���� ������ � � ������ ������ � ������� � ����� ������, �� ���������� ���� ��������� ������
		{
			temp.array += this->array[i];
		}
	}
	return temp; // ��������� ���������� ��'���
}