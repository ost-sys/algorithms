def shaker_sort(arr):
    arr = arr[:]
    left, right = 0, len(arr) - 1
    while left < right:
        for i in range(left, right):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        right -= 1
        for i in range(right, left, -1):
            if arr[i] < arr[i - 1]:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
        left += 1
    return arr

if __name__ == '__main__':
    # Ручной ввод массива
    raw = input("Введите числа через пробел: ")
    arr = list(map(int, raw.split()))

    # Вариант чтения из файла:
    # with open('input.txt', 'r') as f:
    #     arr = list(map(int, f.read().split()))

    print("До:    ", arr)
    print("После: ", shaker_sort(arr))