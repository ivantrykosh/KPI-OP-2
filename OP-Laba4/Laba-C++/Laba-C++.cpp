#include "Func.h"

int main()
{
	string array1; // Перша множина елементів
	string array2; // Друга множина елементів
	string array3; // Третя множина елементів
	input(array1, array2, array3); // Вводимо множини

	Multiset A(array1); // Перша множина
	Multiset B = array2; // Друга множина
	Multiset C(array3); // Третя множина

	cout << "\nMultiset A:\n";
	A.print(); // Виводимо множину
	cout << "\nMultiset B:\n";
	B.print(); // Виводимо множину
	cout << "\nMultiset C:\n";
	C.print(); // Виводимо множину

	Multiset D("");

	D = (A + B - C) * B; // Остаточна множина

	cout << "\nMultiset D:\n";
	D.print(); // Виводимо множину

	check(A, B, C, D); // Перевірка символу
}