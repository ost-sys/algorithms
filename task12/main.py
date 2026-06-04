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

arr = [10, 23, 5, 7, 42, 18]
print("1D поиск:", linear_search_1d(arr, 7))

matrix = [
    [1,  2,  3],
    [4,  5,  6],
    [7,  8,  9]
]
print("2D поиск:", linear_search_2d(matrix, 5))