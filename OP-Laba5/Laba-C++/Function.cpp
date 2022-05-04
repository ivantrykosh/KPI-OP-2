#include "Function.h"

// ������ ����� TBody
TBody::TBody() // � ����� ����������� ���������� �������� �� ������������
{
	name = "��� ����";
	arrayofsides = nullptr;
}

TBody::TBody(string name, double* arrayofsides) // ���������� �������� �� �����������
{
	this->name = name;
	this->arrayofsides = arrayofsides;
}

double TBody::get_area()
{
	double area; // ����� ������� ������

	// ��� ������ ��������� ����� ������� �� ��������� ��������
	if (name == "����������� ������������")
	{
		area = 2 * (arrayofsides[0] * arrayofsides[1] + arrayofsides[1] * arrayofsides[2] + arrayofsides[0] * arrayofsides[2]);
	}
	else if (name == "����")
	{
		area = 4 * M_PI * pow(arrayofsides[0], 2);
	}
	else if (name == "���")
	{
		area = 6 * pow(arrayofsides[0], 2);
	}
	else if (name == "������")
	{
		area = 2 * M_PI * arrayofsides[0] * (arrayofsides[0] + arrayofsides[1]);
	}
	else if (name == "�����")
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
	double volume; // ��'�� ������

	// ��� ������ ��������� ��'�� �� ��������� ��������
	if (name == "����������� ������������")
	{
		volume = arrayofsides[0] * arrayofsides[1] * arrayofsides[2];
	}
	else if (name == "����")
	{
		volume = 4. / 3 * M_PI * pow(arrayofsides[0], 3);
	}
	else if (name == "���")
	{
		volume = pow(arrayofsides[0], 3);
	}
	else if (name == "������")
	{
		volume = M_PI * pow(arrayofsides[0], 2) * arrayofsides[1];
	}
	else if (name == "�����")
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

// ������ ����� TParallelepiped
TParallelepiped::TParallelepiped() : TBody() // � ����� ����������� ���������� ���� ����� ������ �� �������� �� ������������ (0)
{
	name = "����������� ������������";
	a = b = c = 0;
}

TParallelepiped::TParallelepiped(double a, double b, double c) : TBody() // ���������� �������� �� �����������
{
	name = "����������� ������������";
	this->a = a;
	this->b = b;
	this->c = c;
}

void TParallelepiped::operator = (const TParallelepiped& value) // ��ﳺ�� ������� ����� ������
{
	a = value.a;
	b = value.b;
	c = value.c;
}

double TParallelepiped::get_area() // ���������� ����� ������� �� ��������
{
	return 2 * (a * b + b * c + a * c);
}

double TParallelepiped::get_volume() // ���������� ��'�� �� ��������
{
	return a * b * c;
}

// ������ ����� TBall
TBall::TBall() : TBody() // � ����� ����������� ���������� ���� ����� ������ �� ������� �� ������������ (0)
{
	name = "����";
	r = 0;
}

TBall::TBall(double r) : TBody() // ���������� ������� �� ����������
{
	name = "����";
	this->r = r;
}

void TBall::operator = (const TBall& value) // ������� ����� ���
{
	r = value.r;
}

double TBall::get_area() // ���������� ����� ������� �� ��������
{
	return 4 * M_PI * pow(r, 2);
}

double TBall::get_volume() // ���������� ��'�� �� ��������
{
	return 4. / 3 * M_PI * pow(r, 3);
}

// �������
void input_number(int& n, int& n_ball) // ������� �������� ������� ����� �� ������� ����
{
	cout << "ʳ������ ����� = ";
	cin >> n;
	cout << "ʳ������ ���� = ";
	cin >> n_ball;
	cout << "ʳ������ ����������� ������������� = " << n - n_ball << endl;
}

TBall* input_ball(int& n_ball) // ������� ���
{
	TBall* arrayofballs = new TBall[n_ball]; // ��������� ����� ��'����
	cout << endl;
	for (int i = 0; i < n_ball; i++)
	{
		double r; // ����� ���
		cout << "����� " << i + 1 << "-� ��� = ";
		cin >> r; // ������� ����� ����� ���
		TBall temp(r); // ��������� ���������� ��'���
		arrayofballs[i] = temp; // �������� ����� � ������� ������
	}
	return arrayofballs;
}

TParallelepiped* input_parallelepiped(int n_parallelepiped) // ������� ��������� �������������
{
	TParallelepiped* arrayofparallelepipeds = new TParallelepiped[n_parallelepiped]; // ��������� ����� ��'����
	cout << endl;
	for (int i = 0; i < n_parallelepiped; i++)
	{
		double a, b, c; // ������� ������������ �������������
		cout << "������� " << i + 1 << "-�� ������������� = ";
		cin >> a >> b >> c; // ������� �������
		TParallelepiped temp(a, b, c); // ��������� ���������� ��'���
		arrayofparallelepipeds[i] = temp; // �������� ������� � ������� ������
	}
	return arrayofparallelepipeds;
}

void find_area_volume(TBall* arrayofballs, TParallelepiped* arrayofparallelepipeds, int n_balls, int n_parallelepipeds)
{
	double sum_volume = 0; // ���� ��'��� ����
	double sum_area = 0; // ���� ���� ��������� ����������� �������������

	// ��������� ���� ��'��� ����
	for (int i = 0; i < n_balls; i++)
	{
		sum_volume += arrayofballs[i].get_volume();
	}

	// ��������� ���� ���� ��������� ����������� �������������
	for (int i = 0; i < n_parallelepipeds; i++)
	{
		sum_area += arrayofparallelepipeds[i].get_area();
	}

	// �������� ���������
	cout << "\n�������� ��'�� ���� = " << sum_volume << endl;
	cout << "���� ���� ��������� ����������� ������������� = " << sum_area << endl;
}