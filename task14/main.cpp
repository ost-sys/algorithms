#include <iostream>
#include <vector>
#include <string>
// Вариант с файлом:
// #include <fstream>
using namespace std;

vector<int> naiveSearch(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> results;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match)
            results.push_back(i);
    }

    return results;
}

int main() {
    // Вариант с файлом:
    // ifstream f("input.txt");
    // string text, pattern;
    // getline(f, text);
    // getline(f, pattern);

    string text, pattern;
    cout << "Введите текст: ";
    getline(cin, text);
    cout << "Введите образец: ";
    getline(cin, pattern);

    vector<int> positions = naiveSearch(text, pattern);

    cout << "Вхождения на позициях: ";
    for (int pos : positions)
        cout << pos << " ";

    return 0;
}