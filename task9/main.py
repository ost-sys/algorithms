# Вариант с файлом:
# with open("input.txt") as f:
#     arr = list(map(int, f.read().split()))

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

arr = list(map(int, input("Введите элементы через пробел: ").split()))
print(selection_sort(arr))