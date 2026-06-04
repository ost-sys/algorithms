#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findRuns(const vector<int>& data) {
    vector<vector<int>> runs;
    int n = (int)data.size();
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && data[j] >= data[j - 1]) ++j;
        runs.push_back(vector<int>(data.begin() + i, data.begin() + j));
        i = j;
    }
    return runs;
}

vector<int> mergeTwo(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    result.reserve(a.size() + b.size());
    int ia = 0, ib = 0;
    while (ia < (int)a.size() && ib < (int)b.size()) {
        if (a[ia] <= b[ib]) result.push_back(a[ia++]);
        else                 result.push_back(b[ib++]);
    }
    while (ia < (int)a.size()) result.push_back(a[ia++]);
    while (ib < (int)b.size()) result.push_back(b[ib++]);
    return result;
}

vector<int> naturalMergeSort(vector<int> data) {
    while (true) {
        vector<vector<int>> runs = findRuns(data);
        if ((int)runs.size() == 1) return runs[0];

        vector<vector<int>> merged;
        for (int i = 0; i < (int)runs.size(); i += 2) {
            if (i + 1 < (int)runs.size())
                merged.push_back(mergeTwo(runs[i], runs[i + 1]));
            else
                merged.push_back(runs[i]);
        }

        data.clear();
        for (auto& r : merged)
            data.insert(data.end(), r.begin(), r.end());
    }
}

int main() {
    vector<int> arr = {3, 5, 1, 2, 8, 6, 7, 4};
    cout << "До:    ";
    for (int x : arr) cout << x << ' ';
    cout << '\n';

    vector<int> sorted = naturalMergeSort(arr);
    cout << "После: ";
    for (int x : sorted) cout << x << ' ';
    cout << '\n';
    return 0;
}