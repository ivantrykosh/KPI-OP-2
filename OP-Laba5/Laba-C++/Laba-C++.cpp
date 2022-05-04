#include "Function.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*double array[] = { 1.91 };
	TBody ball("Куля", array);
	cout << ball.get_name() << ball.get_area() << ball.get_volume() << endl;

	double array1[] = { 1.93 };
	TBody cube("Куб", array1);
	cout << cube.get_name() << cube.get_area() << cube.get_volume() << endl;

	double array2[] = { 1.91, 2.5, 6 };
	TBody parallelepiped("Прямокутний паралелепіпед", array2);
	cout << parallelepiped.get_name() << parallelepiped.get_area() << parallelepiped.get_volume() << endl;

	double array3[] = { 1.91, 8 };
	TBody cilindr("Циліндр", array3);
	cout << cilindr.get_name() << cilindr.get_area() << cilindr.get_volume() << endl;

	double array4[] = { 1.91, 2 };
	TBody konus("Конус", array4);
	cout << konus.get_name() << konus.get_area() << konus.get_volume() << endl;

	TParallelepiped parallelepiped1(3.2, 2.7, 6.1);
	cout << parallelepiped1.get_name() << parallelepiped1.get_area() << parallelepiped1.get_volume() << endl;

	TBall ball1(6.6);
	cout << ball1.get_name() << ball1.get_area() << ball1.get_volume() << endl;*/

	int n; // Кількість фігур
	int n_ball; // Кількість куль
	input_number(n, n_ball); // Вводимо кількість фігур
	TBall* arrayofballs = input_ball(n_ball); // Вводимо кулі
	TParallelepiped* arrayofparallelepiped = input_parallelepiped(n - n_ball); // Вводимо прямокутні паралелепіпеди
	find_area_volume(arrayofballs, arrayofparallelepiped, n_ball, n - n_ball); // Знаходимо суму об'ємів та площ поверхонь фігур

	// Очищуємо пам'ять
	delete[] arrayofballs;
	delete[] arrayofparallelepiped;

	return 0;
}