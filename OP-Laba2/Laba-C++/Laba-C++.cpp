#include "Func.h"

int main()
{
    SetConsoleCP(1251); // Для вводу кирилиці
    SetConsoleOutputCP(1251); // Для виводу кирилиці

    vector<University> Universities; // Список університетів

    // Шлях до файлів та їх назва
    string namefile1 = "C:/Ivan/OP-Laba2/firstfile.dat";
    string namefile2 = "C:/Ivan/OP-Laba2/secondfile.dat";

    inputfile1(namefile1); // Вводимо список університетів
    outputfile(namefile1); // Виводимо перший файл в консоль
    universities(Universities, namefile1); // Зчитуємо університети з файлу
    findfaculty(Universities); // Знаходимо факультет з найб. кількістю студентів в заданому місті
    inputfile2(Universities, namefile2); // Записуємо інформацію в другий файл
    outputfile(namefile2); // Виводимо другий файл в консоль

    return 0;
}