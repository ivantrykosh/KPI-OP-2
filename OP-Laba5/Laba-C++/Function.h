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
	TBody(); // ����������� ��� ���������
	TBody(string, double*); // ����������� ��� ��������� �� ����������� ��'����
	virtual double get_area(); // ����� ��������� ����� ������� ������
	virtual double get_volume(); // ����� ��������� ��'��� ������
	string get_name(); // ����� ��������� ����� ������
protected:
	string name; // ����� ������
private:
	double* arrayofsides; // �������� �� ����� ����� ������
};

class TParallelepiped : public TBody
{
public:
	TParallelepiped(); // ����������� ��� ���������
	TParallelepiped(double, double, double); // ����������� ��� ��������� �� ����������� ��'����
	void operator = (const TParallelepiped&); // ������������� "="
	double get_area() override; // ����� ��������� ����� ������� ������������ �������������
	double get_volume() override; // ����� ��������� ��'��� ������������ �������������
private:
	double a, b, c; // ������� �������������
};

class TBall : public TBody
{
public:
	TBall(); // ����������� ��� ���������
	TBall(double); // ����������� ��� ��������� �� ����������� ��'����
	void operator = (const TBall&); // ������������� "="
	double get_area() override; // ����� ��������� ����� ������� ���
	double get_volume() override; // ����� ��������� ��'��� ���
private:
	double r; // ����� ���
};

void input_number(int&, int&); // ������� ������� �����
TBall* input_ball(int&); // ������� ���
TParallelepiped* input_parallelepiped(int); // ������� ��������� �������������
void find_area_volume(TBall*, TParallelepiped*, int, int); // ��������� �� �������� ���� ��'��� �� ���� ��������� �����