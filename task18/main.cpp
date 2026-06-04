#include <iostream>
#include <vector>
#include <list>
#include <string>
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
    HashTable ht;
    ht.insert(10, "Alice");
    ht.insert(20, "Bob");
    ht.insert(30, "Charlie");
    cout << ht.search(20) << endl;
    ht.remove(20);
    cout << ht.search(20) << endl;
    return 0;
}