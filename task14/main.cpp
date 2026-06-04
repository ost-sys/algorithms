#include <iostream>
#include <vector>
#include <string>
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
    string text = "АВАВАВАВАС";
    string pattern = "АВАВАС";
    vector<int> positions = naiveSearch(text, pattern);

    cout << "Вхождения на позициях: ";
    for (int pos : positions)
        cout << pos << " ";

    return 0;
}