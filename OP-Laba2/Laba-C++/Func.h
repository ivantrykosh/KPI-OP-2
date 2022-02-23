#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Faculty // ���������
{
    string nameF; // ����� ����������
    int amount; // ������� �������� ����������
};

struct University // ����������
{
    string name; // ����� �����������
    string city; // ̳���
    string level; // г���� �����������
    int amountF; // ʳ������ ����������
    vector<Faculty> amountf; // ����������
};

void inputfile1(string&);
void outputfile(string&);
void universities(vector<University>&, string&);
void findfaculty(vector<University>&);
void inputfile2(vector<University>&, string&);