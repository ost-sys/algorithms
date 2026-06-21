#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
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
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // f >> n;
    // vector<int> arr(n);
    // for (int& x : arr) f >> x;
    // int target_1d; f >> target_1d;
    // int rows, cols; f >> rows >> cols;
    // vector<vector<int>> matrix(rows, vector<int>(cols));
    // for (auto& row : matrix) for (int& x : row) f >> x;
    // int target_2d; f >> target_2d;

    vector<int> arr(n);
    cout << "Введите элементы: ";
    for (int& x : arr) cin >> x;

    int target_1d;
    cout << "Введите искомый элемент (1D): ";
    cin >> target_1d;
    cout << "1D поиск: " << linearSearch1D(arr, target_1d) << endl;

    int rows, cols;
    cout << "Введите размеры матрицы (строки столбцы): ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введите элементы матрицы построчно:" << endl;
    for (auto& row : matrix)
        for (int& x : row) cin >> x;

    int target_2d;
    cout << "Введите искомый элемент (2D): ";
    cin >> target_2d;

    auto [row, col] = linearSearch2D(matrix, target_2d);
    cout << "2D поиск: (" << row << ", " << col << ")" << endl;

    return 0;
}