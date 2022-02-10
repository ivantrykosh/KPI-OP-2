#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

void input(vector<string>&, string&); // Ввід тексту
void record(vector<string>&, string&, string&); // Запис тексту у файли
void output(vector<string>&, string&); // Вивід форматованого тексту в консоль