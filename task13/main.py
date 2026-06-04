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

arr = [3, 7, 11, 18, 25, 42, 56, 78]
print(binary_search(arr, 25))
print(binary_search(arr, 10))