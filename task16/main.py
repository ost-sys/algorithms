# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     text = lines[0]
#     pattern = lines[1]

def bm_search(text, pattern):
    n = len(text)
    m = len(pattern)
    results = []

    d = [m] * 256
    for i in range(m):
        d[ord(pattern[i])] = m - i - 1

    i = m - 1
    while i < n:
        j = m - 1
        k = i
        while j >= 0 and pattern[j] == text[k]:
            j -= 1
            k -= 1
        if j == -1:
            results.append(i - m + 1)
            i += 1
        else:
            i += d[ord(text[i])]

    return results

text = input("Введите текст: ")
pattern = input("Введите образец: ")
print("Вхождения на позициях:", bm_search(text, pattern))