#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Tree
{
private:
	string name; // ��'� ��������������
	int number; // ʳ������ ��������
	Tree* left; // ����� ���� ������
	Tree* right; // ˳�� ���� ������
public:
	Tree(string); // ��������� ������ � ����� ������
	void Output_tree(Tree*); // �������� ������
	void insert_name(Tree*, string); // ���������� ������� � ������
	~Tree(); // ��������� ������
};

void readfile(vector <string>&, string&); // ������� ��������������