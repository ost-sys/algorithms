#include <iostream>
#include <vector>
using namespace std;

int linearSearch1D(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

pair<int,int> linearSearch2D(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {10, 23, 5, 7, 42, 18};
    int idx = linearSearch1D(arr, 7);
    cout << "1D поиск: " << idx << endl;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto [row, col] = linearSearch2D(matrix, 5);
    cout << "2D поиск: (" << row << ", " << col << ")" << endl;

    return 0;
}