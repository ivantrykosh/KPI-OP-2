#include "Func.h"

Tree::Tree(string name) // ���������� ����� ������ ������� �� ����������� ����������
{
	this->name = name;
	this->number = 1;
	this->left = nullptr;
	this->right = nullptr;
}

void Tree::insert_name(Tree* node, string name) // ���������� ������� � ������
{
	if (name < node->name) // ���� ������� ����� ������ �� ��������, �� �������� ����
	{
		if (node->left == nullptr) // ���� ��� ���� ����
		{
			node->left = new Tree(name); // ��������� ��� ����
		}
		else
		{
			insert_name(node->left, name); // ������ ���������� ��������� �������
		}
	}
	else if (name > node->name) // ���� �������� ���� ����� ������ �� ��������, �� �������
	{
		if (node->right == nullptr) // ���� ����� ���� ����
		{
			node->right = new Tree(name); // ��������� ����� ����
		}
		else
		{
			insert_name(node->right, name); // ������ ���������� ��������� �������
		}
	}
	else
	{
		node->number++; // ������ �������� ������� �������� � ����� ��������
	}
}

void Tree::Output_tree(Tree* node) // �������� ���������� ������
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
Tree::~Tree() // ��������� ������
{
	delete this->left;
	delete this->right;
}

void readfile(vector <string>& identificators, string& filename)
{
	ifstream file(filename); // ³�������� ��� ������� ����
	string temp; // �������� �����
	const int n = 84; // ����� ������ �� ��������������
	string notidentificators[n] = {"asm", "auto", "bool", "break", "case", "catch", "char", "class", "const", "const_class", "continue",
	"default", "delete", "double", "do", "dinamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend",
	"goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "operator", "private", "protected", "public", "register",
	"reinterpret_cast", "return", "short", "unsigned", "signed", "sizeof", "static", "static_cast", "struct", "switch", "template", "this", "throw",
	"true", "try", "typedef", "typeid", "typename", "union", "using", "virtual", "void", "volatile", "wchar_t", "while", "{",
	"}", "[", "]", "&", "+", "-", "*", "/", "->", "%", ">>", "<<", "++", "--", "#", "(", ")", ";", ",", "="}; // ����� �� ��������������

	while (!file.eof()) // ��������� �� ���� �����
	{
		getline(file, temp); // ������� �������� �����
		if (temp[0] != '#') // ���������� ����� �� ������ "#" � �� ������� ���������� ����
		{
			int pos; // ������� ��������
			pos = temp.find('\''); // ��������� ������ "'" � ���, �� �� ������
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
			pos = temp.find('\"'); // ��������� ������ '"' � ���, �� �� ������
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
			for (int i = 0; i < n; i++) // ��������� �� �� �������������� � �����
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
			while (temp.size() != 0) // �������� �������������� � ������
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