#include "Func.h"

int main()
{
    SetConsoleCP(1251); // Для вводу кирилиці
    SetConsoleOutputCP(1251); // Для виводу кирилиці
    string filename1 = "C:/Ivan/OP-Laba1/firstFile.txt"; // Назва файлу та шлях до нього
    string filename2 = "C:/Ivan/OP-Laba1/secondFile.txt"; // Назва файлу та шлях до нього
    vector<string> text; // Введений текст

    input(text, filename1); // Вводимо текст
    if (text.empty()) // Перевіряємо, чи не пустий він
    {
        cout << "The text is empty";
    }
    else
    {
        record(text, filename1, filename2); // Записуємо у файли
        output(text, filename2); // Виводимо в консоль
    }

    return 0;
}