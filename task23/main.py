def shell_sort(arr):
    arr = arr[:]
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

if __name__ == '__main__':
    # Ручной ввод массива
    raw = input("Введите числа через пробел: ")
    arr = list(map(int, raw.split()))

    # Вариант чтения из файла:
    # with open('input.txt', 'r') as f:
    #     arr = list(map(int, f.read().split()))

    print("До:    ", arr)
    print("После: ", shell_sort(arr))