from matrix import Matrix
from usual_matrix import UsualMatrix
from triangular_matrix import TriangularMatrix
from diagonal_matrix import DiagonalMatrix
import random

# Класс Container представаляет простой контейнер с данными (в данном случае матрицами).
class Container:

    def __init__(self):
        self.store = []
        self.eps = 1e-8

    def fill_from_array(self, str_array):
        """
        Заполняет контейнер матрицами трех типов.
        :param str_array: массив, из которого берутся данные
        :return:
        """
        # Переменная-итератор, необходимая для проверки того,
        # что все элементы массива сохранены в контейнере
        i = 0
        while i < len(str_array):
            matrix = Matrix()
            # Ключ-идентификатор базовой альтернативы
            key = int(str_array[i])
            if key == 0:
                i += 1
                matrix = UsualMatrix()
                i = matrix.initialize(str_array, i)
                self.store.append(matrix)
            elif key == 1:
                i += 1
                matrix = DiagonalMatrix()
                i = matrix.initialize(str_array, i)
                self.store.append(matrix)
            elif key == 2:
                i += 1
                matrix = TriangularMatrix()
                i = matrix.initialize(str_array, i)
                self.store.append(matrix)
            else:
                pass
        if i == 0:
            pass

    def random_fill(self, size):
        """
        Заполнение контейнера матрицами трех типов, сгенерированными  из рандомных данных.
        :param size:
        :return:
        """
        for i in range(size):
            matrix = Matrix()
            key = random.randint(0, 2)
            if key == 0:
                matrix = UsualMatrix()
                matrix.generate_matrix()
                self.store.append(matrix)
            elif key == 1:
                matrix = DiagonalMatrix()
                matrix.generate_matrix()
                self.store.append(matrix)
            elif key == 2:
                matrix = TriangularMatrix()
                matrix.generate_matrix()
                self.store.append(matrix)

    def write(self, ostream):
        """
        Запись содержимого контейнера в файл.
        :param ostream: файл, в который запитсываается информация
        :return:
        """
        i = 0
        for matrix in self.store:
            ostream.write(f"{i}: ")
            matrix.write(ostream)
            i+=1

    def binary_search(self, arr, mean, low, high):
        if high <= low:
            if mean + self.eps < arr[low].get_average():
                return low + 1
            return low
        mid = (low + high) // 2
        mid_value = arr[mid].get_average()
        if abs(mean - mid_value) < self.eps:
            return mid + 1
        if mean + self.eps < mid_value:
            return self.binary_search(arr, mean, mid + 1, high)
        return self.binary_search(arr, mean, low, mid - 1)

    def insertion_sort(self, arr):
        """
        Бинарная сортировка элементов контейнера по среднему арифметическому их элементов.
        :param arr:
        :return:
        """
        for i in range(1, len(arr)):
            j = i - 1
            selected_mean = arr[i].get_average()
            index = self.binary_search(arr, selected_mean, 0, j)
            selected = arr[i]
            while j >= index:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = selected
        return arr
