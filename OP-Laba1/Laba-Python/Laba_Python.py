import func

def main():
    namefile1 = "C:/Ivan/OP-Laba1/firstFile.txt"  # Шлях та назва першого файлу
    namefile2 = "C:/Ivan/OP-Laba1/secondFile.txt" # Шлях та назва другого файлу

    text = func.inputtext(namefile1) # Вводимо текст
    if len(text) == 0: # Перевіряємо, чи не порожній текст
        print("The text is empty")
    else:
        func.recordtext(text, namefile1, namefile2) # Записуємо у файл початковий текст
        func.outputtext(text, namefile2) # Записуємо у файл форматований текст

main()