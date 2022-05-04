from classes import *
from functions import *

def main():
    n, n_ball = input_number() # Вводимо кількість фігур
    listofballs = input_ball(n_ball) # Вводимо радіуси кіл
    listofparallelepipeds = input_parallelepiped(n - n_ball) # Вводимо сторони паралелепіпедів
    find_area_volume(listofballs, listofparallelepipeds, n_ball, n - n_ball) # Знаходимо та виводимо суму об'ємів та площ поверхонь

if __name__ == "__main__":
    main()