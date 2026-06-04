#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    vector<int> results;
    if (m > n) return results;

    const int BASE = 256;
    const int MOD  = 101;

    // h = BASE^(m-1) mod MOD
    int h = 1;
    for (int i = 0; i < m - 1; ++i)
        h = (h * BASE) % MOD;

    int patternHash = 0;
    int windowHash  = 0;
    for (int i = 0; i < m; ++i) {
        patternHash = (BASE * patternHash + pattern[i]) % MOD;
        windowHash  = (BASE * windowHash  + text[i])   % MOD;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (windowHash == patternHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) results.push_back(i);
        }

        if (i < n - m) {
            windowHash = (BASE * (windowHash - (unsigned char)text[i] * h)
                          + (unsigned char)text[i + m]) % MOD;
            if (windowHash < 0)
                windowHash += MOD;
        }
    }

    return results;
}

int main() {
    string text    = "ABCABCDABABCDABCDABDE";
    string pattern = "ABCD";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Текст:   " << text    << '\n';
    cout << "Образец: " << pattern << '\n';
    cout << "Найдено на позициях: ";
    for (int pos : result) cout << pos << ' ';
    cout << '\n';
    return 0;
}