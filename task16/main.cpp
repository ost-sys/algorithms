#include <iostream>
#include <vector>
#include <string>
// Вариант с файлом:
// #include <fstream>
using namespace std;

vector<int> bmSearch(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> results;

    vector<int> d(256, m);
    for (int i = 0; i < m; i++)
        d[(unsigned char)pattern[i]] = m - i - 1;

    int i = m - 1;
    while (i < n) {
        int j = m - 1;
        int k = i;
        while (j >= 0 && pattern[j] == text[k]) {
            j--;
            k--;
        }
        if (j == -1) {
            results.push_back(i - m + 1);
            i++;
        } else {
            i += d[(unsigned char)text[i]];
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

    vector<int> positions = bmSearch(text, pattern);

    cout << "Вхождения на позициях: ";
    for (int pos : positions)
        cout << pos << " ";

    return 0;
}