#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Faculty // Факультет
{
    string nameF; // Назва факультету
    int amount; // кількість студентів факультету
};

struct University // Університет
{
    string name; // Назва університету
    string city; // Місто
    string level; // Рівень акредитації
    int amountF; // Кількість факультетів
    vector<Faculty> amountf; // Факультети
};

void inputfile1(string&);
void outputfile(string&);
void universities(vector<University>&, string&);
void findfaculty(vector<University>&);
void inputfile2(vector<University>&, string&);