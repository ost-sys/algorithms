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
ht.insert(10, "Alice")
ht.insert(20, "Bob")
ht.insert(30, "Charlie")
print(ht.search(20))
ht.delete(20)
print(ht.search(20))