# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     arr = list(map(int, lines[0].split()))
#     target = int(lines[1])

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

arr = list(map(int, input("Введите отсортированный массив через пробел: ").split()))
target = int(input("Введите искомый элемент: "))
print(binary_search(arr, target))