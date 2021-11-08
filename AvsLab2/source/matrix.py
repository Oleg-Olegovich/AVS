# Класс Matrix описывает представляет матрицу как артефакт.
class Matrix:
    def __init__(self):
        """
         Инициализация.
         :argument self.dim: диаметр
         :argument self.nums_arr: матриц
        """
        self.dim = 0
        self.nums_arr = list()

    def initialize(self, str_array, i):
        """
         Инициализирует матрицу по введенным данным из массива
         """
        pass

    def generate_matrix(self):
        """
         Генерация матрицы рнадомной размерности из рандомных чисел.
        :return: сгенерированная матрица
        """
        pass

    def write(self, ostream):
        """
        Запись данных в файл.
        :param ostream: стрим
        :return:
        """
        pass

    def get_average(self):
        """
        Функция, которая вычисляет среднее арифметическое от элементов массива
        :return:
        """
        pass
