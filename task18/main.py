# Вариант с файлом:
# with open("input.txt") as f:
#     lines = f.read().splitlines()
#     for line in lines:
#         parts = line.split()
#         if parts[0] == "insert": ht.insert(int(parts[1]), parts[2])
#         elif parts[0] == "search": print(ht.search(int(parts[1])))
#         elif parts[0] == "delete": ht.delete(int(parts[1]))

class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return key % self.size

    def insert(self, key, value):
        idx = self._hash(key)
        for pair in self.table[idx]:
            if pair[0] == key:
                pair[1] = value
                return
        self.table[idx].append([key, value])

    def search(self, key):
        idx = self._hash(key)
        for pair in self.table[idx]:
            if pair[0] == key:
                return pair[1]
        return None

    def delete(self, key):
        idx = self._hash(key)
        self.table[idx] = [p for p in self.table[idx] if p[0] != key]

ht = HashTable()
while True:
    cmd = input("Команда (insert/search/delete/exit): ").strip()
    if cmd == "exit":
        break
    elif cmd == "insert":
        key = int(input("Ключ (число): "))
        value = input("Значение: ")
        ht.insert(key, value)
    elif cmd == "search":
        key = int(input("Ключ (число): "))
        print(ht.search(key))
    elif cmd == "delete":
        key = int(input("Ключ (число): "))
        ht.delete(key)