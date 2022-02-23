#include "Func.h"

void inputfile1(string& namefile1)
{
	cout << "Input universities to the file " << namefile1 << " . Press \"Ctrl\" + \"Q\" to exit" << endl;
	cout << "Example: �������� ����������� ��������, ���, IV, 2, Բ�� - 1500, ��� - 500" << endl;

	cout << "You wanna delete the previous contents of the file " << namefile1 << "?(Y/N):";
	char choice; // ������, �� ��� ����������
	cin >> choice;
	ofstream outfile;
	if (choice == 'Y' || choice == 'y')
	{
		outfile.open(namefile1, ios::binary); // ³������� ����, ���������� ��������� ����
	}
	else
	{
		outfile.open(namefile1, ios::binary | ios::app); // ³�������� ���� �� �������
	}

	string value; // �������� �����
	bool flag = true; // ��� ������ �� �����
	while (flag)
	{
		getline(cin, value);

		for (int i = 0; i < value.size(); i++) // ����������, �� � � ����� ������ � ����� 17 ("Ctrl" + "Q")
		{
			if (value[i] == 17)
			{
				flag = false; // ��� ������ �� �����
				value.erase(i); // ��������� ������ "Ctrl" + "Q" � ���, �� ��� �� ���
			}
		}

		if (!value.empty()) // ����������, �� �� ������ �����
		{
			// ��������� ������ �� ������� �� � ���� �����
			while (value[0] == ' ')
			{
				value.erase(0, 1);
			}
			while (value[value.size() - 1] == ' ')
			{
				value.erase(value.size() - 1, 1);
			}

			value += "\n";
			for (int i = 0; i < value.size(); i++)
			{
				outfile.write((char*)(&value[i]), sizeof(value[i])); // ����������� �������� ���������� � ����
			}
		}
	}

	outfile.close();
}

void outputfile(string& namefile)
{
	cout << "\nFile " << namefile << endl;

	ifstream file(namefile, ios::binary); // ³�������� ���� �� �������
	char s; // �������� ������

	do
	{
		string value; // �������� �����
		int i = 0; // ˳������� �����
		do
		{
			file.read((char*)&s, sizeof(s)); // ������� ������
			value += s;
			i++;
		} while (value[i - 1] != '\n'); // �������, ���� �� ���� ���������� �����
		if (value != "")
		{
			cout << value; // �������� ����� � �������
		}
	} while (!file.eof()); // ������� �� ���� �����

	file.close();
}

void universities(vector<University>& universities, string& namefile1)
{
	ifstream file1(namefile1, ios::binary); // ³�������� ��� ������� ����
	
	do
	{
		int i = 0; // ˳������� �����
		char s; // �������� ������
		string value; // ����� � ������ ��� ����������
		do
		{
			file1.read((char*)&s, sizeof(s)); // ����������� ������� ����������
			value += s;
			i++;
		} while (value[i - 1] != '\n'); // ������� �� ���� �����
		value.erase(value.size() - 1); // ��������� ������� ������ "\n"

		int pos = 0; // ������� ����� ����
		int counter = 0; // ����� ����������
		University univer; // ����������

		while (value != "")
		{
			pos = value.find(",", 0); // ��������� ������� ����� ����
			switch (counter)
			{
			case 0: univer.name = value.substr(0, pos); // ��������� ����� �����������
				break;
			case 1: univer.city = value.substr(0, pos); // ��������� ����
				break;
			case 2: univer.level = value.substr(0, pos); // ��������� �����������
				break;
			case 3: univer.amountF = stoi(value.substr(0, pos)); // ��������� ������� ����������
				break;
			}
			value.erase(0, pos + 2); // �������� ������� ����������
			counter++; // ���������� �� ��������� �����
			if (counter == 4) // ���� ����� �� ������� ����������, �� ������� ��� ��
			{
				int position; // ������� ���� �� ����
				for (int i = 0; i < univer.amountF; i++)
				{
					Faculty faculty; // ���������
					position = value.find("-", 0); // ������� ������� ����
					faculty.nameF = value.substr(0, position - 1); // ����� ����������
					value.erase(0, position + 2); // ��������� ����� � �����
					position = value.find(",", 0); // ��������� ����� ����
					faculty.amount = stoi(value.substr(0, position)); // ʳ������ ��������
					if (i != univer.amountF - 1) // ����������, �� �� ������� ���������
					{
						value.erase(0, position + 2); // ��������� ������� ��������
					}
					else
					{
						value.erase(0); // ��������� �����
					}
					univer.amountf.push_back(faculty); // ������ ��������� � ���������� �����������
				}
			}
		}
		universities.push_back(univer); // ������ � ������ ����������� ���������� ��� ����������
	} while (!file1.eof());
	file1.close();
}

void findfaculty(vector<University>& list)
{
	string town; // ������� ����
	cout << "\nInput city: ";
	getline(cin, town);

	// ��������� ������ �� ������� �� � ���� �����
	while (town[0] == ' ')
	{
		town.erase(0, 1);
	}
	while (town[town.size() - 1] == ' ')
	{
		town.erase(town.size() - 1, 1);
	}

	string facultet = "error"; // ���������
	string univer = "error"; // ����� �����������
	int maxamount = 0; // ����������� ������� ��������
	for (int i = 0; i < list.size(); i++)
	{
		if (town == list[i].city) // ����������, �� ������� ���� � �������
		{
			for (int j = 0; j < list[i].amountF; j++)
			{
				if (maxamount < list[i].amountf[j].amount) // ���������� ������� �������� �� ������� ���������
				{
					maxamount = list[i].amountf[j].amount; // ����������� ������� ��������
					univer = list[i].name; // ����� �����������
					facultet = list[i].amountf[j].nameF; // ����� ����������
				}
			}
		}
	}
	cout << "Maxamount:\n" << univer << ", " << facultet << " - " << maxamount << endl;
}

void inputfile2(vector<University>& list, string& namefile2)
{
	cout << "\nYou wanna delete the previous contents of the file " << namefile2 << "?(Y/N):";
	char choice; // ������, �� ��� ����������
	cin >> choice;
	ofstream outfile;
	if (choice == 'Y' || choice == 'y')
	{
		outfile.open(namefile2, ios::binary); // ³������� ����, ����������� ��������� ����
	}
	else
	{
		outfile.open(namefile2, ios::binary | ios::app); // ³�������� ���� �� �������
	}

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].level == "III" || list[i].level == "IV") // ���������� ����� �����������
		{
			string value = list[i].name + ", " + list[i].city + ", " + list[i].level + "\n"; // �������� ���������� � ����
			for (int j = 0; j < value.size(); j++)
			{
				outfile.write((char*)(&value[j]), sizeof(value[j])); //  �������� ���������� ����� � ����
			}
		}
	}
	outfile.close(); // ��������� ����
}