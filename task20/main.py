def find_runs(data):
    runs = []
    i = 0
    while i < len(data):
        j = i + 1
        while j < len(data) and data[j] >= data[j - 1]:
            j += 1
        runs.append(data[i:j])
        i = j
    return runs

def merge_two(a, b):
    result = []
    ia, ib = 0, 0
    while ia < len(a) and ib < len(b):
        if a[ia] <= b[ib]:
            result.append(a[ia]); ia += 1
        else:
            result.append(b[ib]); ib += 1
    result.extend(a[ia:])
    result.extend(b[ib:])
    return result

def natural_merge_sort(data):
    data = data[:]
    while True:
        runs = find_runs(data)
        if len(runs) == 1:
            return runs[0]
        merged = []
        i = 0
        while i < len(runs):
            if i + 1 < len(runs):
                merged.append(merge_two(runs[i], runs[i + 1]))
                i += 2
            else:
                merged.append(runs[i])
                i += 1
        data = []
        for r in merged:
            data.extend(r)
    return data

if __name__ == '__main__':
    # Ручной ввод массива
    raw = input("Введите числа через пробел: ")
    arr = list(map(int, raw.split()))

    # Вариант чтения из файла:
    # with open('input.txt', 'r') as f:
    #     arr = list(map(int, f.read().split()))

    print("До:    ", arr)
    print("После: ", natural_merge_sort(arr))