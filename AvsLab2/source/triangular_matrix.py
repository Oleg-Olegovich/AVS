from matrix import Matrix
import random

# Класс TriangularMatr описывает нижнюю треугольную квадратную матрицу как базовую альтернативу.
class TriangularMatrix(Matrix):
    def __init__(self):
        super().__init__()
        self.dim = 0
        self.nums_arr = None

    def generate_matrix(self):
        """
        Генерация нижней треугольной матрицы рандомной размерности из рандомных чисел.
        :return:
        """
        self.dim = random.randint(1, 20)
        self.nums_arr = [0.0] * self.dim
        for k in range(0, self.dim):
            self.nums_arr[k] = round(random.uniform(-20, 20), 5)
        pass

    def initialize(self, str_array, i):
        """
        Инициализация матрицы данными из массива.
        :param str_array: массив с данными
        :param i: итератор
        :return: измененный итератор
        """
        self.dim = int(str_array[i])
        i += 1
        self.nums_arr = [0.0] * self.dim
        for k in range(0, self.dim):
            self.nums_arr[k] = float(str_array[i])
            i += 1
        return i

    def get_average(self):
        """
        Нахождение среднего арифметического элементов квадратной матрицы.
        :return: среднее арифметическое
        """
        summa = 0
        for i in range(0, self.dim):
            summa += self.nums_arr[i]
        return float(summa) / (self.dim * self.dim)

    def write(self, ostream):
        ostream.write(f"It is triangular matrix. ")
        ostream.write(f"Dimension = {self.dim}; ")
        ostream.write(f"Arithmetic average of the matrix elements = {self.get_average():.{3}f}\n")
