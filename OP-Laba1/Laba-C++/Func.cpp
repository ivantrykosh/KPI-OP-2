#include "Func.h"

void input(vector<string>& text, string& name1)
{
    cout << "Input the text to the file " << name1 <<" . Press \"Ctrl\" + \"Q\" to exit\n";
    string str; // Поточний рядок
    bool flag = true; // Для виходу з циклу
    while (flag)
    {
        getline(cin, str); // Зчитуємо рядок
        for (int i = 0; i < str.size(); i++) // Перевіряємо, чи є в рядку символ з кодом 17 ("Ctrl" + "Q")
        {
            if (str[i] == 17)
            {
                flag = false; // Для виходу із циклу
                str.erase(i); // Видаляємо символ "Ctrl" + "Q" і все, що іде за ним
            }
        }
        if (str.size() > 0) // Перевіряємо, чи не пустий рядок
        {
            text.push_back(str); // Вставляємо рядок у вектор
        }
    }
}

void record(vector<string>& text, string& name1, string& name2)
{
    // Відкриваємо для запису файли
    ofstream file1(name1);
    ofstream file2(name2);

    for (int i = 0; i < text.size(); i++)
    {
        file1 << text[i] << endl; // Записуємо у перший файл поточний рядок
        file2 << text[i].size() << " " << text[i] << " " << i + 1 << endl; // Записуємо у другий файл поточний форматований рядок
    }

    // Закриваємо файли
    file1.close();
    file2.close();
}

void output(vector<string>& text, string& name2)
{
    cout << "\nThe modified text from the file " << name2 << " .\n";

    // Виводимо текст в консоль
    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i].size() << " " << text[i] << " " << i + 1 << endl;
    }
}