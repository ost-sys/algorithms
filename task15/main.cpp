#include <iostream>
#include <vector>
#include <string>
// Вариант с файлом:
// #include <fstream>
using namespace std;

vector<int> computePrefix(string& pattern) {
    int m = pattern.size();
    vector<int> d(m, 0);
    d[0] = -1;
    int k = -1;

    for (int i = 1; i < m; i++) {
        while (k >= 0 && pattern[k + 1] != pattern[i])
            k = d[k];
        if (pattern[k + 1] == pattern[i])
            k++;
        d[i] = k;
    }

    return d;
}

vector<int> kmpSearch(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> d = computePrefix(pattern);
    vector<int> results;
    int k = -1;

    for (int i = 0; i < n; i++) {
        while (k >= 0 && pattern[k + 1] != text[i])
            k = d[k];
        if (pattern[k + 1] == text[i])
            k++;
        if (k == m - 1) {
            results.push_back(i - m + 1);
            k = d[k];
        }
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

    vector<int> positions = kmpSearch(text, pattern);

    cout << "Вхождения на позициях: ";
    for (int pos : positions)
        cout << pos << " ";

    return 0;
}