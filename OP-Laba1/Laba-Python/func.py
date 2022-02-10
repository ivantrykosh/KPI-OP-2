def inputtext(name1):
    print("Input the text to the file", name1,". Press \"Ctrl\" + \"Q\" to exit")
    flag = True # Прапорець для циклу
    text = [] # Створюємо список
    while flag:
        line = input() # Вводимо рядок
        i = 0 # Лічильний циклу
        while i < len(line):
            if (line[i] == chr(17)): # Перевіряємо, чи є поточний символ символом "Ctrl" + "Q"
                flag = False # Змінюємо прапорець для виходу із циклу
                line = line[:i:] # Робимо зріз до символу "Ctrl" + "Q"
            i += 1 # Збільшуємо лічильний
        if len(line) > 0: # Перевіряємо, чи не пустий рядок
            text += [line + "\n"] # Додаємо його до тексту
    return text

def recordtext(text, name1, name2):
    #Відкриваємо для читання файли
    file1 = open(name1, "w")
    file2 = open(name2, "w")

    for i in range(len(text)):
        file1.write(text[i]) # Записуємо введений рядок у файл
        file2.write(str(len(text[i])-1) + " " + text[i][:-1:] + " " + str(i+1) + "\n") # Записуємо форматований рядок у файл

    #Закриваємо файли
    file1.close()
    file2.close()

def outputtext(text, name2):
    print("\nThe modified text from the file", name2, ".")
    # Виводимо форматований текст в консоль
    for i in range(len(text)):
        print(len(text[i])-1, text[i][:-1:], i+1)