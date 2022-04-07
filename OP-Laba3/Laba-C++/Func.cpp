#include "Func.h"

void Text::add_text(string& str)
{
	text.push_back(str); // Додаємо рядок до тексту
}

vector<string>& Text::get_text()
{
	return text; // Повертаємо текст
}

float& Text::percent()
{
	int numberofall = 0; // Кількість усіх літер
	int numberofpr = 0; // Кількість приголосних літер
	for (int i = 0; i < text.size(); i++) // Проходимо по рядках тексту
	{
		for (int j = 0; j < text[i].size(); j++) // Проходимо по символах рядка
		{
			if (litera(text[i][j], Alphabet)) // Перевіряємо, чи є символ літерою
			{
				if (litera(text[i][j], Litery)) // Перевіряємо, чи є символ приголосною літерою
				{
					numberofpr++; // Збільшуємо кількість приголосних літер
				}
				numberofall++; // Збільшуємо кількість літер
			}
		}
	}
	float v = (float)numberofpr / numberofall; // Відсоток приголосних літер від усіх літер
	return v;
}

bool Text::litera(char& l, string alphabet)
{
	bool flag; // Результат перевірки
	int pos = alphabet.find(l); // Перевірка символу в алфавіті
	if (pos >= 0)
	{
		flag = true; // Символ є літерою
	}
	else
	{
		flag = false; // Символ не є літерою
	}
	return flag;
}

void input_text(vector<Text>& text)
{
	string str; // Введений рядок
	bool flag1 = true; // Для завершення вводу текстів
	bool flag2 = true; // Для завершення вводу тексту
	int i = 0; // Номер тексту
	do
	{
		Text buffer; // Текст
		cout << "Текст " << i + 1 << ":" << endl;
		do
		{
			getline(cin, str); // Зчитуємо рядок
			if (!str.empty()) // Перевіряємо, чи не пустий рядок
			{
				buffer.add_text(str); // Додаємо рядок в текст
			}
			else
			{
				flag2 = false;
			}
		} while (flag2);

		if ((buffer.get_text()).size() == 0) // Перевіряємо, чи не пустий текст
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
	string num; // Рядок з номерами текстів
	string str; // Введений рядок
	bool flag = true; // Для завершення вводу тексту
	cout << "Введіть порядкові номера тексту, які хочете доповнити, у форматі \"1 3 5\". Якщо не хочете доповнювати текст, просто натисніть \"Enter\": ";
	getline(cin, num); // Зчитуємо рядок з числами
	while (!num.empty()) // Перевіряємо чи не пустий
	{
		int pos = num.find(' '); // Знаходимо перший пробіл
		int number; // Номер тексту
		if (pos > -1)
		{
			number = stoi(num.substr(0, pos)); // Перетворюємо підрядок в число
			num.erase(0, pos + 1); // Видаляємо підрядок
		}
		else
		{
			number = stoi(num); // Перетворюємо рядок в число
			num.clear();
		}
		cout << "Для завершення доповнення тексту натисніть двічі \"Enter\"" << endl;

		cout << "Текст " << number << ":" << endl;
		flag = true;
		do
		{
			getline(cin, str);
			if (!str.empty())
			{
				text[number - 1].add_text(str); // Додаємо рядок до тексту
			}
			else
			{
				flag = false;
			}
		} while (flag);
	}
}

void output_text(vector<Text>& text) // Виводимо усі тексти
{
	cout << "Всі тексти:" << endl;
	for (int i = 0; i < text.size(); i++)
	{
		cout << "\nТекст " << i + 1 << ":\n";
		for (int j = 0; j < text[i].get_text().size(); j++)
		{
			cout << text[i].get_text()[j] << endl;
		}
	}
}

void out_percent(vector<Text>& text)
{
	float max = -1; // Максимальний відсоток
	int numb = 0; // Номер рядка
	for (int i = 0; i < text.size(); i++)
	{
		cout << "\nВідсоток приголосних ( " << text[i].percent() * 100 << " % ) у тексті " << i + 1 << endl;
		if (max < text[i].percent())
		{
			max = text[i].percent();
			numb = i;
		}
	}
	cout << "\nНайбільший відсоток приголосних ( " << max * 100 << " % ) у тексті " << numb + 1 << endl;
}