import sys
import time
from container import Container

if __name__ == '__main__':
    start = time.time()
    if len(sys.argv) != 5:
        print("Incorrect command line!\n"
              "  Waited:\n"
              "     command -f infile outfile01 outfile02\n"
              "  Or:\n"
              "     command -n number outfile01 outfile02\n")
        exit()
    print('==> Start')
    # Создание контейнера.
    container = Container()
    if sys.argv[1] == "-f":
        input = sys.argv[2]

        try:
            # Открытие файла.
            infile = open(input)
        except IOError:
            # Если файла нет, то создаем его.
            infile = open(input, 'w')
        input_line = infile.read()
        infile.close()
        str_array = input_line.replace("\n", " ").split(" ")
        figNum = container.fill_from_array(str_array)
        # Открытие потока для записи данных.
        out_file = open(sys.argv[3], 'w+')
        container.write(out_file)
        out_file.close()
        print("Time when objects were written to the file: ",
              round(time.time() - start, 5), " seconds")
        # Открытие потока для записи отсортированных данных.
        outfile_two = open(sys.argv[4], 'w+')
        # Сортируем объект по данной в задании функции.
        container.insertion_sort(container.store)
        container.write(outfile_two)
        outfile_two.close()
        print("Time when the sorting occurred and the result was written to the file: ",
              round(time.time() - start, 5), " seconds")
    elif sys.argv[1] == "-n":
        length = int(sys.argv[2])
        # Проверка на корректность данных.
        if length < 1 or length > 10000:
            print("Incorrect number of matrixs = {}. Set 0 < number <= 10000\n", length)
            exit()
        container.random_fill(length)
        out_file = open(sys.argv[3], 'w+')
        container.write(out_file)
        out_file.close()
        outfile_two = open(sys.argv[4], 'w+')
        # Сортируем объект по данной в задании функции.
        container.insertion_sort(container.store)
        container.write(outfile_two)
        # Выводим время работы программы.
        print("The time it took to run the program: ",
              round(time.time() - start, 5), " seconds")
        outfile_two.close()
    else:
        print("Incorrect qualifier value!\n"
              "  Waited:\n"
              "     command -f <infile> <outfile01> <outfile02>\n"
              "  Or:\n"
              "     command -n <number> <outfile01> <outfile02>\n")
        exit()
print('==> Finish')
