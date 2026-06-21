# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     arr = list(map(int, lines[0].split()))
#     target_1d = int(lines[1])
#     rows, cols = map(int, lines[2].split())
#     matrix = [list(map(int, lines[3 + i].split())) for i in range(rows)]
#     target_2d = int(lines[3 + rows])

def linear_search_1d(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def linear_search_2d(matrix, target):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] == target:
                return (i, j)
    return (-1, -1)

arr = list(map(int, input("Введите элементы массива через пробел: ").split()))
target_1d = int(input("Введите искомый элемент (1D): "))
print("1D поиск:", linear_search_1d(arr, target_1d))

rows, cols = map(int, input("Введите размеры матрицы (строки столбцы): ").split())
matrix = []
for i in range(rows):
    row = list(map(int, input(f"Введите строку {i + 1}: ").split()))
    matrix.append(row)
target_2d = int(input("Введите искомый элемент (2D): "))
print("2D поиск:", linear_search_2d(matrix, target_2d))