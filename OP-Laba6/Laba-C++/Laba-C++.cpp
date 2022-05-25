#include "Func.h"

int main()
{
	vector <string> identificators; // Масив ідентифікаторів
	string filename = "file.txt"; // Ім'я файлу
	readfile(identificators, filename); // Зчитуємо ідентифікатори
	if (identificators.size() == 0) // Перевіряємо, чи є ідентифікатори
	{
		cout << "There are no identificators" << endl;
	}
	Tree tree(identificators[0]); // Стоворюємо дерево з першим іденфікатором
	for (int i = 1; i < identificators.size(); i++) // Додаємо ідентифікатори у дерево
	{
		tree.insert_name(&tree, identificators[i]);
	}
	tree.Output_tree(&tree); // Виводимо дерево
	return 0;
}