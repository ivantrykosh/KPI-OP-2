#include "Func.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Для завершення введення тексту натисніть двічі \"Enter\"" << endl;
    cout << "Для завершення введення текстів натисніть тричі \"Enter\"" << endl;

    vector<Text> text; // Масив текстів
    input_text(text); // Вводимо текст
    add(text); // Додаємо рядки
    output_text(text); // Виводимо тексти
    out_percent(text); // Виводимо найбільший відсоток
    
    return 0;
}