def inputfile1(namefile1):
	print("Input universities to the file", namefile1, ". Press \"Ctrl\" + \"Q\" to exit")
	print("Example: Київський політехнічний інститут, Київ, IV, 2, ФІОТ - 1500, ІАТ - 500")

	choice = input("You wanna delete the previous contents of the file " + namefile1 + " ? (Y / N): ")

	if (choice == 'Y' or choice == 'y'):
		outfile = open(namefile1, "wb") # Вікриваємо файл, попередньо очистивши його
	else:
		outfile = open(namefile1, "ab") # Відкриваємо файл на дозапис

	flag = True # Для виходу із циклу
	while (flag):
		value = input()
		i = 0
		while(i < len(value)): # Перевіряємо, чи є в рядку символ з кодом 17 ("Ctrl" + "Q")
			if (value[i] == chr(17)):
				flag = False # Для виходу із циклу
				value = value[:i:] # Видаляємо символ "Ctrl" + "Q" і все, що іде за ним
			i += 1

		if (not(len(value) == 0)): # Перевіряємо, чи не пустий рядок
			# Видаляємо пробіли на початку та в кінці рядка
			value.lstrip()
			value.rstrip()
			value += "\n"
			# Записуємо рядок у файл
			outfile.write(value.encode())
	outfile.close()

def outputfile(namefile):
	print("\nFile", namefile)

	file = open(namefile, "rb") # Відкриваємо файл як бінарний

	for value in file:
		print(value.decode(encoding = 'UTF-8'), end = "")
	print()
	file.close()

def universities(namefile1):
	file = open(namefile1, "rb") # Відкриваємо файл як бінарний
	l = []
	number = 0
	for value in file:
		if (len(value) > 0):
			value = value.decode(encoding = 'UTF-8')
			l += [value.split(", ")] # Розбиваємо рядок на список
			for i in range(int(l[number][3])): # Розбиваємо елементи списку на факультети та кількість студентів
				faculty = l[number][4 + i]
				l[number][4 + i] = faculty.split(" - ")
			number += 1 # Збільшуємо порядковий номер факультету
	file.close()
	return l

def findfaculty(l):

	# Вводимо місто та видаляємо пробіли на початку і в кінці рядка
	city = input("\nInput city: ")
	city.lstrip()
	city.rstrip()

	facultet = "error"
	university = "error"
	maxnumber = 0

	# Знаходимо максимальну кількість студентів у заданому місті
	for i in range(len(l)):
		if l[i][1] == city:
			for j in range(int(l[i][3])):
				if maxnumber < int(l[i][4 + j][1]):
					maxnumber = int(l[i][4 + j][1])
					university = l[i][0]
					facultet = l[i][4 + j][0]

	print("Maxamount:\n", university, ", ", facultet, " - ", maxnumber, sep = "")

def inputfile2(l, namefile2):
	choice = input("\nYou wanna delete the previous contents of the file " + namefile2 + " ? (Y / N): ")

	if (choice == 'Y' or choice == 'y'):
		outfile = open(namefile2, "wb") # Вікриваємо файл, попередньо очистивши його
	else:
		outfile = open(namefile2, "ab") # Відкриваємо файл на дозапис

	# Записуємо інформацію про університети з III та IV рівнем акредитації у файл та виводимо її в консоль
	for i in range(len(l)):
		if l[i][2] == "III" or l[i][2] == "IV":
			value = l[i][0] + ", " + l[i][1] + ", " + l[i][2] + "\n"
			outfile.write(value.encode())

	outfile.close() # Закриваємо файл