#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

class Text
{
private:
    vector<string> text; // Масив рядків
    string Litery = "йцкнгґшщзхфвпрлджчсмтьб"; // Приголосні літери
    string Alphabet = "йцукенгґшщзхїфівапролджєячсмитьбю"; // Усі літери
    bool litera(char&, string); // Для перевірки символу на літеру
public:
    void add_text(string&); // Додавання рядку до тексту
    vector<string>& get_text(); // Отримання масиву рядків
    float& percent(); // Відсоток приголосних літер
};

void input_text(vector<Text>&); // Вводимо текст
void add(vector<Text>&); // Додаємо рядки
void output_text(vector<Text>&); // Виводимо тексти
void out_percent(vector<Text>&); // Виводимо найбільший відсоток