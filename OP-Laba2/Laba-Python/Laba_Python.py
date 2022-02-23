import func

def main():
    namefile1 = "C:/Ivan/OP-Laba2/firstfile.dat" # Шлях до першого файлу
    namefile2 = "C:/Ivan/OP-Laba2/secondfile.dat" # Шлях до другого файлу

    func.inputfile1(namefile1) # Вводимо університети
    func.outputfile(namefile1) # Вводимо університети
    list_universities = func.universities(namefile1) # Зчитуємо університети з файлу
    func.findfaculty(list_universities) # Знаходимо факультет з найб. кількістю студентів в заданому місті
    func.inputfile2(list_universities, namefile2) # Записуємо інформацію в другий файл
    func.outputfile(namefile2) # Виводимо другий файл в консоль
    
main()