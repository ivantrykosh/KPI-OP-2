#include "Func.h"

Tree::Tree(string name) // Ініціалізуємо корінь дерева заданим та початковими значеннями
{
	this->name = name;
	this->number = 1;
	this->left = nullptr;
	this->right = nullptr;
}

void Tree::insert_name(Tree* node, string name) // Вставляємо елемент у дерево
{
	if (name < node->name) // Якщо елемент стоїть першим за алфавітом, ніж поточний ключ
	{
		if (node->left == nullptr) // Якщо лівої гілки нема
		{
			node->left = new Tree(name); // Створюємо ліву гілку
		}
		else
		{
			insert_name(node->left, name); // Інакше рекурсивно викликаємо функцію
		}
	}
	else if (name > node->name) // Якщо поточний ключ стоїть першим за алфавітом, ніж елемент
	{
		if (node->right == nullptr) // Якщо правої гілки нема
		{
			node->right = new Tree(name); // Створюємо праву гілку
		}
		else
		{
			insert_name(node->right, name); // Інакше рекурсивно викликаємо функцію
		}
	}
	else
	{
		node->number++; // Інакше збільшуємо кількість входжень у текст програми
	}
}

void Tree::Output_tree(Tree* node) // Виводимо центровано дерево
{
	if (node->left != nullptr)
	{
		Output_tree(node->left);
	}
	cout << node->name << " - " << node->number << endl;
	if (node->right != nullptr)
	{
		Output_tree(node->right);
	}
	
}
Tree::~Tree() // Видаляємо дерево
{
	delete this->left;
	delete this->right;
}

void readfile(vector <string>& identificators, string& filename)
{
	ifstream file(filename); // Відкриваємо для читання файл
	string temp; // Поточний рядок
	const int n = 84; // Розмір масиву не ідентифікаторів
	string notidentificators[n] = {"asm", "auto", "bool", "break", "case", "catch", "char", "class", "const", "const_class", "continue",
	"default", "delete", "double", "do", "dinamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend",
	"goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "operator", "private", "protected", "public", "register",
	"reinterpret_cast", "return", "short", "unsigned", "signed", "sizeof", "static", "static_cast", "struct", "switch", "template", "this", "throw",
	"true", "try", "typedef", "typeid", "typename", "union", "using", "virtual", "void", "volatile", "wchar_t", "while", "{",
	"}", "[", "]", "&", "+", "-", "*", "/", "->", "%", ">>", "<<", "++", "--", "#", "(", ")", ";", ",", "="}; // Масив не ідентифікаторів

	while (!file.eof()) // Проходимо до кінця файлу
	{
		getline(file, temp); // Зчитуємо поточний рядок
		if (temp[0] != '#') // Перевіряємо рядок на символ "#" і за потреби пропускаємо його
		{
			int pos; // Позиція елемента
			pos = temp.find('\''); // Видаляємо символ "'" і все, що він означує
			while (pos != -1)
			{
				temp.erase(pos, 3);
				if (pos == 0 && temp.size() != 0)
				{
					temp.erase(pos, 1);
				}
				else if (pos != 0 && pos == temp.size())
				{
					temp.erase(pos - 1, 1);
				}
				else if (pos != 0)
				{
					temp.erase(pos - 1, 1);
				}
				pos = temp.find('\'');
			}
			pos = temp.find('\"'); // Видаляємо символ '"' і все, що він означує
			while (pos != -1)
			{
				int pos2 = temp.find('\"', pos + 1);
				temp.erase(pos, pos2 - pos + 1);
				if (pos == 0 && temp.size() != 0)
				{
					temp.erase(pos, 1);
				}
				else if (pos != 0 && pos == temp.size())
				{
					temp.erase(pos - 1, 1);
				}
				else if (pos != 0)
				{
					temp.erase(pos - 1, 1);
				}
				pos = temp.find('\"');
			}
			for (int i = 0; i < n; i++) // Видаляємо всі не ідентифікатори з рядка
			{
				int pos = temp.find(notidentificators[i]);
				while (pos != -1)
				{
					temp.erase(pos, notidentificators[i].size());
					if (pos == 0 && temp.size() != 0)
					{
						temp.erase(pos, 1);
					}
					else if (pos != 0 && pos == temp.size())
					{
						temp.erase(pos - 1, 1);
					}
					else if (pos != 0)
					{
						temp.erase(pos - 1, 1);
					}
					pos = temp.find(notidentificators[i]);
				}
			}
			while (temp.size() != 0) // Записуємо ідентифікатори у вектор
			{
				int pos1 = temp.find(' ');
				int pos2 = temp.find(' ', pos1 + 1);

				if (pos1 != -1 && pos2 != -1)
				{
					string t = temp.substr(pos1 + 1, pos2 - pos1 - 1);
					bool flag = false;
					for (int j = 0; j < t.size(); j++)
					{
						if (isalpha(t[j]))
						{
							flag = true;
						}
					}
					if (flag)
					{
						identificators.push_back(t);
					}
					temp.erase(pos1, pos2 - pos1);
				}
				else if (pos1 != -1)
				{
					string t = temp.substr(pos1 + 1, temp.size() - pos1 - 1);
					bool flag = false;
					for (int j = 0; j < t.size(); j++)
					{
						if (isalpha(t[j]))
						{
							flag = true;
						}
					}
					if (flag)
					{
						identificators.push_back(t);
					}
					temp.erase(pos1);
				}
				else
				{
					bool flag = false;
					for (int j = 0; j < temp.size(); j++)
					{
						if (isalpha(temp[j]))
						{
							flag = true;
						}
					}
					int k = 0;
					while (temp[k] == '\t')
					{
						temp.erase(k, 1);
						k++;
					}
					k = temp.size() - 1;
					if (flag)
					{
						identificators.push_back(temp);
					}
					temp.clear();
				}
			}
		}
	}
	file.close();
}