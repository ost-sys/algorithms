# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     text = lines[0]
#     pattern = lines[1]

def naive_search(text, pattern):
    n = len(text)
    m = len(pattern)
    results = []

    for i in range(n - m + 1):
        match = True
        for j in range(m):
            if text[i + j] != pattern[j]:
                match = False
                break
        if match:
            results.append(i)

    return results

text = input("Введите текст: ")
pattern = input("Введите образец: ")
positions = naive_search(text, pattern)
print("Вхождения на позициях:", positions)