# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     text = lines[0]
#     pattern = lines[1]

def compute_prefix(pattern):
    m = len(pattern)
    d = [0] * m
    d[0] = -1
    k = -1

    for i in range(1, m):
        while k >= 0 and pattern[k + 1] != pattern[i]:
            k = d[k]
        if pattern[k + 1] == pattern[i]:
            k += 1
        d[i] = k

    return d

def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    d = compute_prefix(pattern)
    results = []
    k = -1

    for i in range(n):
        while k >= 0 and pattern[k + 1] != text[i]:
            k = d[k]
        if pattern[k + 1] == text[i]:
            k += 1
        if k == m - 1:
            results.append(i - m + 1)
            k = d[k]

    return results

text = input("Введите текст: ")
pattern = input("Введите образец: ")
print("Вхождения на позициях:", kmp_search(text, pattern))