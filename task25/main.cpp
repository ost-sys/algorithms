#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    // возвращает true и записывает значение в outValue, если ключ найден
    bool search(int key, string& outValue) const {
        int start = hash(key);
        for (int i = 0; i < size; ++i) {
            int idx = (start + i) % size;
            if (table[idx].state == SlotState::EMPTY)
                return false;
            if (table[idx].state == SlotState::OCCUPIED &&
                table[idx].key == key) {
                outValue = table[idx].value;
                return true;
            }
        }
        return false;
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
    int size;
    cout << "Введите размер таблицы: ";
    cin >> size;
    HashTable ht(size);

    // Вариант чтения из файла (пары key value, одна на строку):
    // #include <fstream>
    // ifstream fin("input.txt");
    // int k; string v;
    // while (fin >> k >> v) ht.insert(k, v);

    cin.ignore(); // съесть остаток строки после числа
    cout << "Команды: insert <key> <value> | search <key> | delete <key> | display | exit\n";

    string line;
    while (true) {
        cout << "> ";
        if (!getline(cin, line)) break;
        istringstream iss(line);
        string action;
        iss >> action;
        if (action.empty()) continue;

        if (action == "insert") {
            int key; string value;
            if (iss >> key >> value) ht.insert(key, value);
        } else if (action == "search") {
            int key;
            if (iss >> key) {
                string value;
                bool found = ht.search(key, value);
                cout << "Найдено: " << (found ? value : "не найдено") << '\n';
            }
        } else if (action == "delete") {
            int key;
            if (iss >> key) {
                bool ok = ht.remove(key);
                cout << (ok ? "Удалено" : "Ключ не найден") << '\n';
            }
        } else if (action == "display") {
            ht.display();
        } else if (action == "exit") {
            break;
        } else {
            cout << "Неизвестная команда\n";
        }
    }
    return 0;
}