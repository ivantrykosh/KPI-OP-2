#include "Function.h"

// Методи класу TBody
TBody::TBody() // У цьому конструкторі ініціалізуємо атрибути за умовчуванням
{
	name = "Без імені";
	arrayofsides = nullptr;
}

TBody::TBody(string name, double* arrayofsides) // Ініціалізуємо атрибути за параметрами
{
	this->name = name;
	this->arrayofsides = arrayofsides;
}

double TBody::get_area()
{
	double area; // Площа поверхні фігури

	// Для фігури визначаємо площу поверхні за відповідною формулою
	if (name == "Прямокутний паралелепіпед")
	{
		area = 2 * (arrayofsides[0] * arrayofsides[1] + arrayofsides[1] * arrayofsides[2] + arrayofsides[0] * arrayofsides[2]);
	}
	else if (name == "Куля")
	{
		area = 4 * M_PI * pow(arrayofsides[0], 2);
	}
	else if (name == "Куб")
	{
		area = 6 * pow(arrayofsides[0], 2);
	}
	else if (name == "Циліндр")
	{
		area = 2 * M_PI * arrayofsides[0] * (arrayofsides[0] + arrayofsides[1]);
	}
	else if (name == "Конус")
	{
		area = M_PI * arrayofsides[0] * (arrayofsides[0] + sqrt(pow(arrayofsides[0], 2) + pow(arrayofsides[1], 2)));
	}
	else
	{
		area = -1;
	}

	return area;
}

double TBody::get_volume()
{
	double volume; // Об'єм фігури

	// Для фігури визначаємо об'єм за відповідною формулою
	if (name == "Прямокутний паралелепіпед")
	{
		volume = arrayofsides[0] * arrayofsides[1] * arrayofsides[2];
	}
	else if (name == "Куля")
	{
		volume = 4. / 3 * M_PI * pow(arrayofsides[0], 3);
	}
	else if (name == "Куб")
	{
		volume = pow(arrayofsides[0], 3);
	}
	else if (name == "Циліндр")
	{
		volume = M_PI * pow(arrayofsides[0], 2) * arrayofsides[1];
	}
	else if (name == "Конус")
	{
		volume = 1. / 3 * M_PI * pow(arrayofsides[0], 2) * arrayofsides[1];
	}
	else
	{
		volume = -1;
	}

	return volume;
}

string TBody::get_name()
{
	return name;
}

// Методи класу TParallelepiped
TParallelepiped::TParallelepiped() : TBody() // У цьому конструкторі ініціалізуємо лише назву фігури та атрибути за умовчуванням (0)
{
	name = "Прямокутний паралелепіпед";
	a = b = c = 0;
}

TParallelepiped::TParallelepiped(double a, double b, double c) : TBody() // Ініціалізуємо атрибути за параметрами
{
	name = "Прямокутний паралелепіпед";
	this->a = a;
	this->b = b;
	this->c = c;
}

void TParallelepiped::operator = (const TParallelepiped& value) // Копіємо довжини сторін фігури
{
	a = value.a;
	b = value.b;
	c = value.c;
}

double TParallelepiped::get_area() // Обчислюємо площу поверхні за формулою
{
	return 2 * (a * b + b * c + a * c);
}

double TParallelepiped::get_volume() // Обчислюємо об'єм за формулою
{
	return a * b * c;
}

// Методи класу TBall
TBall::TBall() : TBody() // У цьому конструкторі ініціалізуємо лише назву фігури та атрибут за умовчуванням (0)
{
	name = "Куля";
	r = 0;
}

TBall::TBall(double r) : TBody() // Ініціалізуємо атрибут за параметром
{
	name = "Куля";
	this->r = r;
}

void TBall::operator = (const TBall& value) // Копіюємо радіус кулі
{
	r = value.r;
}

double TBall::get_area() // Обчислюємо площу поверхні за формулою
{
	return 4 * M_PI * pow(r, 2);
}

double TBall::get_volume() // Обчислюємо об'єм за формулою
{
	return 4. / 3 * M_PI * pow(r, 3);
}

// Функції
void input_number(int& n, int& n_ball) // Вводимо загальну кількість фігур та кількість куль
{
	cout << "Кількість фігур = ";
	cin >> n;
	cout << "Кількість куль = ";
	cin >> n_ball;
	cout << "Кількість прямокутних паралелепіпедів = " << n - n_ball << endl;
}

TBall* input_ball(int& n_ball) // Вводимо кулі
{
	TBall* arrayofballs = new TBall[n_ball]; // Створюємо масив об'єктів
	cout << endl;
	for (int i = 0; i < n_ball; i++)
	{
		double r; // Радіус кулі
		cout << "Радіус " << i + 1 << "-ї кулі = ";
		cin >> r; // Вводимо радіус кожної кулі
		TBall temp(r); // Створюємо тимчасовий об'єкт
		arrayofballs[i] = temp; // Зберігаємо радіус в елемент масиву
	}
	return arrayofballs;
}

TParallelepiped* input_parallelepiped(int n_parallelepiped) // Вводимо прямокутні паралелепіпеди
{
	TParallelepiped* arrayofparallelepipeds = new TParallelepiped[n_parallelepiped]; // Створюємо масив об'єктів
	cout << endl;
	for (int i = 0; i < n_parallelepiped; i++)
	{
		double a, b, c; // Сторони прямокутного паралелепіпеда
		cout << "Сторони " << i + 1 << "-го паралелепіпеда = ";
		cin >> a >> b >> c; // Вводимо сторони
		TParallelepiped temp(a, b, c); // Створюємо тимчасовий об'єкт
		arrayofparallelepipeds[i] = temp; // Зберігаємо сторони в елемент масиву
	}
	return arrayofparallelepipeds;
}

void find_area_volume(TBall* arrayofballs, TParallelepiped* arrayofparallelepipeds, int n_balls, int n_parallelepipeds)
{
	double sum_volume = 0; // Сума об'ємів куль
	double sum_area = 0; // Сума площ поверхонь прямокутних паралелепіпедів

	// Знаходимо суму об'ємів куль
	for (int i = 0; i < n_balls; i++)
	{
		sum_volume += arrayofballs[i].get_volume();
	}

	// Знаходимо суму площ поверхонь прямокутних паралелепіпедів
	for (int i = 0; i < n_parallelepipeds; i++)
	{
		sum_area += arrayofparallelepipeds[i].get_area();
	}

	// Виводимо результат
	cout << "\nСумарний об'єм куль = " << sum_volume << endl;
	cout << "Сума площ поверхонь прямокутних паралелепіпедів = " << sum_area << endl;
}