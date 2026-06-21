import os

def write_sequence(filename, data):
    with open(filename, 'w') as f:
        f.write(' '.join(map(str, data)))

def read_sequence(filename):
    with open(filename, 'r') as f:
        content = f.read().strip()
        if not content:
            return []
        return list(map(int, content.split()))

def split_to_files(src, file_b, file_c, step):
    data = read_sequence(src)
    n = len(data)
    b_data, c_data = [], []
    i = 0
    toggle = True
    while i < n:
        chunk = data[i:i + step]
        if toggle:
            b_data.extend(chunk)
        else:
            c_data.extend(chunk)
        toggle = not toggle
        i += step
    write_sequence(file_b, b_data)
    write_sequence(file_c, c_data)

def merge_files(file_b, file_c, dst, step):
    b = read_sequence(file_b)
    c = read_sequence(file_c)
    result = []
    ib, ic = 0, 0
    while ib < len(b) or ic < len(c):
        b_chunk = b[ib:ib + step]
        c_chunk = c[ic:ic + step]
        bi, ci = 0, 0
        while bi < len(b_chunk) and ci < len(c_chunk):
            if b_chunk[bi] <= c_chunk[ci]:
                result.append(b_chunk[bi]); bi += 1
            else:
                result.append(c_chunk[ci]); ci += 1
        result.extend(b_chunk[bi:])
        result.extend(c_chunk[ci:])
        ib += step
        ic += step
    write_sequence(dst, result)

def straight_merge_sort_external(input_file, output_file):
    data = read_sequence(input_file)
    n = len(data)
    write_sequence(output_file, data)

    file_b = 'temp_b.txt'
    file_c = 'temp_c.txt'
    step = 1

    while step < n:
        split_to_files(output_file, file_b, file_c, step)
        merge_files(file_b, file_c, output_file, step)
        step *= 2

    for f in [file_b, file_c]:
        if os.path.exists(f):
            os.remove(f)

if __name__ == '__main__':
    # Ручной ввод последовательности
    raw = input("Введите числа через пробел: ")
    data = list(map(int, raw.split()))

    # Вариант чтения из файла:
    # data = read_sequence('input.txt')

    write_sequence('input.txt', data)
    straight_merge_sort_external('input.txt', 'output.txt')
    print("Результат:", read_sequence('output.txt'))