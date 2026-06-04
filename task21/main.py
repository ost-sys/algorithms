class HashTable:
    DELETED = object()  # маркер удалённого слота

    def __init__(self, size=11):
        self.size = size
        self.table = [None] * size
        self.count = 0

    def _hash(self, key):
        return key % self.size

    def _probe(self, key):
        idx = self._hash(key)
        for i in range(self.size):
            yield (idx + i) % self.size

    def insert(self, key, value):
        if self.count >= self.size * 0.7:
            print("Предупреждение: таблица заполнена более чем на 70%")
        first_deleted = None
        for idx in self._probe(key):
            slot = self.table[idx]
            if slot is None:
                pos = first_deleted if first_deleted is not None else idx
                self.table[pos] = (key, value)
                self.count += 1
                return
            if slot is self.DELETED:
                if first_deleted is None:
                    first_deleted = idx
            elif slot[0] == key:
                self.table[idx] = (key, value)
                return

    def search(self, key):
        for idx in self._probe(key):
            slot = self.table[idx]
            if slot is None:
                return None
            if slot is not self.DELETED and slot[0] == key:
                return slot[1]
        return None

    def delete(self, key):
        for idx in self._probe(key):
            slot = self.table[idx]
            if slot is None:
                return False
            if slot is not self.DELETED and slot[0] == key:
                self.table[idx] = self.DELETED
                self.count -= 1
                return True
        return False

    def display(self):
        for i, slot in enumerate(self.table):
            if slot is None:
                print(f"  [{i}] пусто")
            elif slot is self.DELETED:
                print(f"  [{i}] удалено")
            else:
                print(f"  [{i}] ключ={slot[0]}, значение={slot[1]}")

if __name__ == '__main__':
    ht = HashTable(size=11)
    for k, v in [(5, 'a'), (16, 'b'), (27, 'c'), (3, 'd'), (14, 'e')]:
        ht.insert(k, v)
    ht.display()
    print("Поиск 16:", ht.search(16))
    ht.delete(16)
    print("После удаления 16, поиск 27:", ht.search(27))