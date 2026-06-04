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
    arr = [5, 3, 8, 1, 9, 2, 7, 4, 6]
    print("До:    ", arr)
    print("После: ", shell_sort(arr))