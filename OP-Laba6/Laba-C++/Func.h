#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Tree
{
private:
	string name; // Ім'я ідентифікатора
	int number; // Кількість входжень
	Tree* left; // Права гілка дерева
	Tree* right; // Ліва гілка дерева
public:
	Tree(string); // Створюємо дерево з одним ключем
	void Output_tree(Tree*); // Виводимо дерево
	void insert_name(Tree*, string); // Всатвляємо елемент у дерево
	~Tree(); // Видаляємо дерево
};

void readfile(vector <string>&, string&); // Зчитуємо ідентифікатори