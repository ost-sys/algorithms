#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class SlotState { EMPTY, OCCUPIED, DELETED };

struct Slot {
    int key;
    string value;
    SlotState state = SlotState::EMPTY;
};

class HashTable {
    int size;
    vector<Slot> table;

    int hash(int key) const { return key % size; }

public:
    HashTable(int size = 11) : size(size), table(size) {}

    void insert(int key, const string& value) {
        int start = hash(key);
        int firstDeleted = -1;
        for (int i = 0; i < size; ++i) {
            int idx = (start + i) % size;
            if (table[idx].state == SlotState::EMPTY) {
                int pos = (firstDeleted != -1) ? firstDeleted : idx;
                table[pos] = {key, value, SlotState::OCCUPIED};
                return;
            }
            if (table[idx].state == SlotState::DELETED) {
                if (firstDeleted == -1) firstDeleted = idx;
            } else if (table[idx].key == key) {
                table[idx].value = value;
                return;
            }
        }
        if (firstDeleted != -1)
            table[firstDeleted] = {key, value, SlotState::OCCUPIED};
    }

    // возвращает "" если не найдено, иначе значение
    string search(int key) const {
        int start = hash(key);
        for (int i = 0; i < size; ++i) {
            int idx = (start + i) % size;
            if (table[idx].state == SlotState::EMPTY)
                return "";
            if (table[idx].state == SlotState::OCCUPIED &&
                table[idx].key == key)
                return table[idx].value;
        }
        return "";
    }

    bool remove(int key) {
        int start = hash(key);
        for (int i = 0; i < size; ++i) {
            int idx = (start + i) % size;
            if (table[idx].state == SlotState::EMPTY)
                return false;
            if (table[idx].state == SlotState::OCCUPIED &&
                table[idx].key == key) {
                table[idx].state = SlotState::DELETED;
                return true;
            }
        }
        return false;
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            if (table[i].state == SlotState::EMPTY)
                cout << "  [" << i << "] пусто\n";
            else if (table[i].state == SlotState::DELETED)
                cout << "  [" << i << "] удалено\n";
            else
                cout << "  [" << i << "] ключ=" << table[i].key
                     << ", значение=" << table[i].value << '\n';
        }
    }
};

int main() {
    HashTable ht(11);
    ht.insert(5, "a"); ht.insert(16, "b"); ht.insert(27, "c");
    ht.insert(3, "d"); ht.insert(14, "e");
    ht.display();

    string res = ht.search(16);
    cout << "Поиск 16: " << (res != "" ? res : "не найдено") << '\n';
    ht.remove(16);
    res = ht.search(27);
    cout << "После удаления 16, поиск 27: " << (res != "" ? res : "не найдено") << '\n';
    return 0;
}