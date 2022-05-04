#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <string>
#include <cmath>

using namespace std;

class TBody
{
public:
	TBody(); // Конструктор без параметрів
	TBody(string, double*); // Конструктор для створення та ініціалізації об'єктів
	virtual double get_area(); // Метод отримання площі поверхні фігури
	virtual double get_volume(); // Метод отримання об'єму фігури
	string get_name(); // Метод отримання назви фігури
protected:
	string name; // Назва фігури
private:
	double* arrayofsides; // Покажчик на масив сторін фігури
};

class TParallelepiped : public TBody
{
public:
	TParallelepiped(); // Конструктор без параметрів
	TParallelepiped(double, double, double); // Конструктор для створення та ініціалізації об'єктів
	void operator = (const TParallelepiped&); // Перевантажуємо "="
	double get_area() override; // Метод отримання площі поверхні прямокутного паралелепіпеда
	double get_volume() override; // Метод отримання об'єму прямокутного паралелепіпеда
private:
	double a, b, c; // Сторони паралелепіпеда
};

class TBall : public TBody
{
public:
	TBall(); // Конструктор без параметрів
	TBall(double); // Конструктор для створення та ініціалізації об'єктів
	void operator = (const TBall&); // Перевантажуємо "="
	double get_area() override; // Метод отримання площі поверхні кулі
	double get_volume() override; // Метод отримання об'єму кулі
private:
	double r; // Радіус кулі
};

void input_number(int&, int&); // Вводимо кількість фігур
TBall* input_ball(int&); // Вводимо кулі
TParallelepiped* input_parallelepiped(int); // Вводимо прямокутні паралелепіпеди
void find_area_volume(TBall*, TParallelepiped*, int, int); // Знаходимо та виводимо суму об'ємів та площ поверхонь фігур