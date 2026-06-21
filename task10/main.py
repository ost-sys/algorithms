# Вариант с файлом:
# with open("input.txt") as f:
#     arr = list(map(int, f.read().split()))

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - 1, i, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
    return arr

arr = list(map(int, input("Введите элементы через пробел: ").split()))
print(bubble_sort(arr))