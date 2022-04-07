#include "Func.h"

void Text::add_text(string& str)
{
	text.push_back(str); // ������ ����� �� ������
}

vector<string>& Text::get_text()
{
	return text; // ��������� �����
}

float& Text::percent()
{
	int numberofall = 0; // ʳ������ ��� ����
	int numberofpr = 0; // ʳ������ ����������� ����
	for (int i = 0; i < text.size(); i++) // ��������� �� ������ ������
	{
		for (int j = 0; j < text[i].size(); j++) // ��������� �� �������� �����
		{
			if (litera(text[i][j], Alphabet)) // ����������, �� � ������ ������
			{
				if (litera(text[i][j], Litery)) // ����������, �� � ������ ����������� ������
				{
					numberofpr++; // �������� ������� ����������� ����
				}
				numberofall++; // �������� ������� ����
			}
		}
	}
	float v = (float)numberofpr / numberofall; // ³������ ����������� ���� �� ��� ����
	return v;
}

bool Text::litera(char& l, string alphabet)
{
	bool flag; // ��������� ��������
	int pos = alphabet.find(l); // �������� ������� � ������
	if (pos >= 0)
	{
		flag = true; // ������ � ������
	}
	else
	{
		flag = false; // ������ �� � ������
	}
	return flag;
}

void input_text(vector<Text>& text)
{
	string str; // �������� �����
	bool flag1 = true; // ��� ���������� ����� ������
	bool flag2 = true; // ��� ���������� ����� ������
	int i = 0; // ����� ������
	do
	{
		Text buffer; // �����
		cout << "����� " << i + 1 << ":" << endl;
		do
		{
			getline(cin, str); // ������� �����
			if (!str.empty()) // ����������, �� �� ������ �����
			{
				buffer.add_text(str); // ������ ����� � �����
			}
			else
			{
				flag2 = false;
			}
		} while (flag2);

		if ((buffer.get_text()).size() == 0) // ����������, �� �� ������ �����
		{
			flag1 = false;
		}
		else
		{
			text.push_back(buffer);
		}
		flag2 = true;
		i++;
	} while (flag1);
}

void add(vector<Text>& text)
{
	string num; // ����� � �������� ������
	string str; // �������� �����
	bool flag = true; // ��� ���������� ����� ������
	cout << "������ �������� ������ ������, �� ������ ���������, � ������ \"1 3 5\". ���� �� ������ ����������� �����, ������ �������� \"Enter\": ";
	getline(cin, num); // ������� ����� � �������
	while (!num.empty()) // ���������� �� �� ������
	{
		int pos = num.find(' '); // ��������� ������ �����
		int number; // ����� ������
		if (pos > -1)
		{
			number = stoi(num.substr(0, pos)); // ������������ ������� � �����
			num.erase(0, pos + 1); // ��������� �������
		}
		else
		{
			number = stoi(num); // ������������ ����� � �����
			num.clear();
		}
		cout << "��� ���������� ���������� ������ �������� ���� \"Enter\"" << endl;

		cout << "����� " << number << ":" << endl;
		flag = true;
		do
		{
			getline(cin, str);
			if (!str.empty())
			{
				text[number - 1].add_text(str); // ������ ����� �� ������
			}
			else
			{
				flag = false;
			}
		} while (flag);
	}
}

void output_text(vector<Text>& text) // �������� �� ������
{
	cout << "�� ������:" << endl;
	for (int i = 0; i < text.size(); i++)
	{
		cout << "\n����� " << i + 1 << ":\n";
		for (int j = 0; j < text[i].get_text().size(); j++)
		{
			cout << text[i].get_text()[j] << endl;
		}
	}
}

void out_percent(vector<Text>& text)
{
	float max = -1; // ������������ �������
	int numb = 0; // ����� �����
	for (int i = 0; i < text.size(); i++)
	{
		cout << "\n³������ ����������� ( " << text[i].percent() * 100 << " % ) � ����� " << i + 1 << endl;
		if (max < text[i].percent())
		{
			max = text[i].percent();
			numb = i;
		}
	}
	cout << "\n��������� ������� ����������� ( " << max * 100 << " % ) � ����� " << numb + 1 << endl;
}