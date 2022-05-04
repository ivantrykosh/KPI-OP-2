from classes import *

def input_number(): # Вводимо загальну кількість фігур та кількість куль
	n = int(input("Кількість фігур = "))
	n_ball = int(input("Кількість куль = "))
	print("Кількість прямокутних паралелепіпедів =", n - n_ball, end = "\n\n")
	return n, n_ball

def input_ball(n_ball): # Вводимо кулі
	listofballs = [] # Список куль
	for i in range(n_ball):
		print("Радіус ", i + 1, "-ї кулі = ", sep = "", end = "")
		r = float(input()) # Вводимо радіус
		temp = TBall(r) # Створюємо об'єкт
		listofballs += [temp] # Додаємо об'єкт у список
	return listofballs

def input_parallelepiped(n_parallelepiped): # Вводимо прямокутні паралелепіпеди
	listofparallelepipeds = [] # Список прямокутних параледепіпедів
	print()
	for i in range(n_parallelepiped):
		print("Сторони ", i + 1, "-го паралелепіпеда:", sep = "")
		# Вводимо сторони прямокутного паралелепіпеда
		a = float(input("	Перша сторона = "))
		b = float(input("	Друга сторона = "))
		c = float(input("	Третя сторона = "))

		temp = TParallelepiped(a, b, c) # Створюємо об'єкт
		listofparallelepipeds += [temp] # Додаємо об'єкт до списку
	return listofparallelepipeds

def find_area_volume(listofballs, listofparallelepipeds, n_ball, n_parallelepiped):
	sum_volume = 0.0 # Сума об'ємів куль
	sum_area = 0.0 # Сума площ поверхонь прямокутних паралелепіпедів

	for i in range(n_ball):
		sum_volume += listofballs[i].get_volume() # Отримуємо об'єм кулі та додаємо його до суми

	for i in range(n_parallelepiped):
		sum_area += listofparallelepipeds[i].get_area() # Отримуємо площу поверхні прямокутного паралелепіпеда та додаємо її до суми

	# Виводимо результат
	print("\nСумарний об'єм куль =", sum_volume)
	print("Сума площ поверхонь прямокутних паралелепіпедів =", sum_area, end = "\n\n")