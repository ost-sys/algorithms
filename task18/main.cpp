#include <iostream>
#include <vector>
#include <list>
#include <string>
// Вариант с файлом:
// #include <fstream>
using namespace std;

class HashTable {
    int size;
    vector<list<pair<int, string>>> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int size = 10) : size(size), table(size) {}

    void insert(int key, string value) {
        int idx = hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[idx].push_back({key, value});
    }

    string search(int key) {
        int idx = hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key)
                return pair.second;
        }
        return "Not found";
    }

    void remove(int key) {
        int idx = hash(key);
        table[idx].remove_if([key](pair<int,string>& p) {
            return p.first == key;
        });
    }
};

int main() {
    // Вариант с файлом:
    // ifstream f("input.txt");
    // string cmd;
    // while (f >> cmd) {
    //     if (cmd == "insert") { int k; string v; f >> k >> v; ht.insert(k, v); }
    //     else if (cmd == "search") { int k; f >> k; cout << ht.search(k) << endl; }
    //     else if (cmd == "delete") { int k; f >> k; ht.remove(k); }
    // }

    HashTable ht;
    string cmd;
    while (true) {
        cout << "Команда (insert/search/delete/exit): ";
        cin >> cmd;
        if (cmd == "exit") break;
        else if (cmd == "insert") {
            int key; string value;
            cout << "Ключ (число): "; cin >> key;
            cout << "Значение: "; cin >> value;
            ht.insert(key, value);
        } else if (cmd == "search") {
            int key;
            cout << "Ключ (число): "; cin >> key;
            cout << ht.search(key) << endl;
        } else if (cmd == "delete") {
            int key;
            cout << "Ключ (число): "; cin >> key;
            ht.remove(key);
        }
    }
    return 0;
}