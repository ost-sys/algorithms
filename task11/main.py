# Вариант с файлом:
# with open("input.txt") as f:
#     arr = list(map(int, f.read().split()))

def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            key = arr[i]
            j = i
            while j >= gap and arr[j - gap] > key:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = key
        gap //= 2

    return arr

arr = list(map(int, input("Введите элементы через пробел: ").split()))
print(shell_sort(arr))