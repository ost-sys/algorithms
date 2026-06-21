def rabin_karp(text, pattern):
    n, m = len(text), len(pattern)
    if m > n:
        return []

    BASE = 256
    MOD  = 101

    # h = BASE^(m-1) mod MOD
    h = 1
    for _ in range(m - 1):
        h = (h * BASE) % MOD

    pattern_hash = 0
    window_hash  = 0
    for i in range(m):
        pattern_hash = (BASE * pattern_hash + ord(pattern[i])) % MOD
        window_hash  = (BASE * window_hash  + ord(text[i]))    % MOD

    results = []
    for i in range(n - m + 1):
        if window_hash == pattern_hash:
            # проверка посимвольно (защита от коллизий)
            if text[i:i + m] == pattern:
                results.append(i)

        if i < n - m:
            window_hash = (BASE * (window_hash - ord(text[i]) * h)
                           + ord(text[i + m])) % MOD
            if window_hash < 0:
                window_hash += MOD

    return results

if __name__ == '__main__':
    # Ручной ввод текста и образца
    text    = input("Введите текст: ")
    pattern = input("Введите образец: ")

    # Вариант чтения из файла (первая строка — текст, вторая — образец):
    # with open('input.txt', 'r') as f:
    #     text = f.readline().strip()
    #     pattern = f.readline().strip()

    result = rabin_karp(text, pattern)
    print(f"Текст:   {text}")
    print(f"Образец: {pattern}")
    print(f"Найдено на позициях: {result}")