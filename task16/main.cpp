#include <iostream>
#include <vector>
#include <string>
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
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABC";
    vector<int> positions = bmSearch(text, pattern);

    cout << "Вхождения на позициях: ";
    for (int pos : positions)
        cout << pos << " ";

    return 0;
}