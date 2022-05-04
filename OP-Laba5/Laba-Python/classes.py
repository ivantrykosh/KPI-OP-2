import math

class TBody:
	def __init__(self, name, listofsides):
		self._name = name # Ім'я фігури
		self.__sides = listofsides # Сторони фігури

	def get_area(self): # Для фігури знаходимо площу поверхні за окремою формулою
		area = 0.0
		if self._name == "Прямокутний паралелепіпед":
			area = 2 * (self.__sides[0] * self.__sides[1] + self.__sides[1] * self.__sides[2] + self.__sides[0] * self.__sides[2])
		elif self._name == "Куля":
			area = 4 * math.pi * self.__sides[0] ** 2
		elif self._name == "Куб":
			area = 6 * self.__sides[0] ** 2
		elif self._name == "Циліндр":
			area = 2 * math.pi * self.__sides[0] * (self.__sides[0] + self.__sides[1])
		elif self._name == "Конус":
			area = math.pi * self.__sides[0] * (self.__sides[0] + math.sqrt(self.__sides[0] ** 2 + self.__sides[1] ** 2))
		else:
			area = -1.0
		return area

	def get_volume(self): # Для фігури знаходимо об'єм за оркемою формулою
		volume = 0.0
		if self._name == "Прямокутний паралелепіпед":
			volume = self.__sides[0] * self.__sides[1] * self.__sides[2]
		elif self._name == "Куля":
			volume = 4 / 3 * math.pi * self.__sides[0] ** 3
		elif self._name == "Куб":
			volume = self.__sides[0] ** 3
		elif self._name == "Циліндр":
			volume = 2 * math.pi * self.__sides[0] * (self.__sides[0] + self.__sides[1])
		elif self._name == "Конус":
			volume = math.pi * self.__sides[0] * (self.__sides[0] + math.sqrt(self.__sides[0] ** 2 + self.__sides[1] ** 2))
		else:
			volume = -1.0
		return volume
	
	def get_name(self): #  Повертаємо ім'я фігури
		return self._name


class TBall(TBody):
	def __init__(self, r):
		self._name = "Куля" # Ім'я фігури ("Куля" за умовчуванням)
		self.__r = r # Радіус кулі
		
	def get_area(self): # Знаходимо площу поверхні за формулою
		return 4 * math.pi * self.__r ** 2

	def get_volume(self): # Знаходимо об'єм за формулою
		return 4 / 3 * math.pi * self.__r ** 3

class TParallelepiped(TBody):
	def __init__(self, a, b, c):
		self._name = "Прямокутний паралелепіпед" # Ім'я фігури ("Прямокутний паралелепіпед" за умовчуванням)
		self.__a = a # Перша сторона
		self.__b = b # Друга сторона
		self.__c = c # Третя сторона

	def get_area(self): # Знаходимо площу поверхні за формулою
		return 2 * (self.__a * self.__b + self.__b * self.__c + self.__a * self.__c)

	def get_volume(self): # Знаходимо об'єм за формулою
		return self.__a * self.__b * self.__c