#include "Func.h"

void inputfile1(string& namefile1)
{
	cout << "Input universities to the file " << namefile1 << " . Press \"Ctrl\" + \"Q\" to exit" << endl;
	cout << "Example: Київський політехнічний інститут, Київ, IV, 2, ФІОТ - 1500, ІАТ - 500" << endl;

	cout << "You wanna delete the previous contents of the file " << namefile1 << "?(Y/N):";
	char choice; // Символ, що ввів користувач
	cin >> choice;
	ofstream outfile;
	if (choice == 'Y' || choice == 'y')
	{
		outfile.open(namefile1, ios::binary); // Вікриваємо файл, попередньо очистивши його
	}
	else
	{
		outfile.open(namefile1, ios::binary | ios::app); // Відкриваємо файл на дозапис
	}

	string value; // Поточний рядок
	bool flag = true; // Для виходу із циклу
	while (flag)
	{
		getline(cin, value);

		for (int i = 0; i < value.size(); i++) // Перевіряємо, чи є в рядку символ з кодом 17 ("Ctrl" + "Q")
		{
			if (value[i] == 17)
			{
				flag = false; // Для виходу із циклу
				value.erase(i); // Видаляємо символ "Ctrl" + "Q" і все, що іде за ним
			}
		}

		if (!value.empty()) // Перевіряємо, чи не пустий рядок
		{
			// Видаляємо пробіли на початку та в кінці рядка
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
				outfile.write((char*)(&value[i]), sizeof(value[i])); // Посимвольно записуємо інформацію у файл
			}
		}
	}

	outfile.close();
}

void outputfile(string& namefile)
{
	cout << "\nFile " << namefile << endl;

	ifstream file(namefile, ios::binary); // Відкриваємо файл як бінарний
	char s; // Поточний символ

	do
	{
		string value; // Поточний рядок
		int i = 0; // Лічильник циклу
		do
		{
			file.read((char*)&s, sizeof(s)); // Зчитуємо символ
			value += s;
			i++;
		} while (value[i - 1] != '\n'); // Зчитуємо, поки не буде наступного рядка
		if (value != "")
		{
			cout << value; // Виводимо рядок в консоль
		}
	} while (!file.eof()); // Зчитуємо до кінця файлу

	file.close();
}

void universities(vector<University>& universities, string& namefile1)
{
	ifstream file1(namefile1, ios::binary); // Відкриваємо для читання файл
	
	do
	{
		int i = 0; // Лічильник циклу
		char s; // Поточний символ
		string value; // Рядок з даними про університет
		do
		{
			file1.read((char*)&s, sizeof(s)); // Посимвольно зчитуємо інформацію
			value += s;
			i++;
		} while (value[i - 1] != '\n'); // Зчитуємо до кінця рядка
		value.erase(value.size() - 1); // Видаляємо останній символ "\n"

		int pos = 0; // Позиція першої коми
		int counter = 0; // Номер інформації
		University univer; // Університет

		while (value != "")
		{
			pos = value.find(",", 0); // Знаходимо позицію першої коми
			switch (counter)
			{
			case 0: univer.name = value.substr(0, pos); // Знаходимо назву університету
				break;
			case 1: univer.city = value.substr(0, pos); // Знаходимо місто
				break;
			case 2: univer.level = value.substr(0, pos); // Знаходимо акредитацію
				break;
			case 3: univer.amountF = stoi(value.substr(0, pos)); // Знаходимо кількість факультетів
				break;
			}
			value.erase(0, pos + 2); // Виаляємо поточну інформацію
			counter++; // Переходимо до наступних даних
			if (counter == 4) // Якщо дійшли до кількості факультетів, то зчитуємо вже їх
			{
				int position; // Позиція коми та тире
				for (int i = 0; i < univer.amountF; i++)
				{
					Faculty faculty; // Факультет
					position = value.find("-", 0); // Позиція першого тире
					faculty.nameF = value.substr(0, position - 1); // Назва факультету
					value.erase(0, position + 2); // Видалення назви з рядка
					position = value.find(",", 0); // Знаходимо першу кому
					faculty.amount = stoi(value.substr(0, position)); // Кількість студентів
					if (i != univer.amountF - 1) // Перевіряємо, чи це останній факультет
					{
						value.erase(0, position + 2); // Видаляємо кількість студентів
					}
					else
					{
						value.erase(0); // Видаляємо рядок
					}
					univer.amountf.push_back(faculty); // Додаємо факультет в факультети університету
				}
			}
		}
		universities.push_back(univer); // Додаємо у список університетів інформацію про університет
	} while (!file1.eof());
	file1.close();
}

void findfaculty(vector<University>& list)
{
	string town; // Введене місто
	cout << "\nInput city: ";
	getline(cin, town);

	// Видаляємо пробіли на початку на в кінці рядка
	while (town[0] == ' ')
	{
		town.erase(0, 1);
	}
	while (town[town.size() - 1] == ' ')
	{
		town.erase(town.size() - 1, 1);
	}

	string facultet = "error"; // Факультет
	string univer = "error"; // Назва університету
	int maxamount = 0; // Максимальна кількість студентів
	for (int i = 0; i < list.size(); i++)
	{
		if (town == list[i].city) // Перевіряємо, чи поточне місто є шуканим
		{
			for (int j = 0; j < list[i].amountF; j++)
			{
				if (maxamount < list[i].amountf[j].amount) // Перевіряємо кількість студентів на кожному факультеті
				{
					maxamount = list[i].amountf[j].amount; // Максимальна кількість студентів
					univer = list[i].name; // Назва університету
					facultet = list[i].amountf[j].nameF; // Назва факультету
				}
			}
		}
	}
	cout << "Maxamount:\n" << univer << ", " << facultet << " - " << maxamount << endl;
}

void inputfile2(vector<University>& list, string& namefile2)
{
	cout << "\nYou wanna delete the previous contents of the file " << namefile2 << "?(Y/N):";
	char choice; // Символ, що ввів користувач
	cin >> choice;
	ofstream outfile;
	if (choice == 'Y' || choice == 'y')
	{
		outfile.open(namefile2, ios::binary); // Вікриваємо файл, поперредньо очистивши його
	}
	else
	{
		outfile.open(namefile2, ios::binary | ios::app); // Відкриваємо файл на дозапис
	}

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].level == "III" || list[i].level == "IV") // Перевіряємо рівень акредитації
		{
			string value = list[i].name + ", " + list[i].city + ", " + list[i].level + "\n"; // Записуємо інформацію у файл
			for (int j = 0; j < value.size(); j++)
			{
				outfile.write((char*)(&value[j]), sizeof(value[j])); //  Записуємо посивольно рядок у файл
			}
		}
	}
	outfile.close(); // Закриваємо файл
}