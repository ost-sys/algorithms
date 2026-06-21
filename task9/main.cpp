#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // vector<int> arr(n);
    // for (int& x : arr) f >> x;

    vector<int> arr(n);
    cout << "Введите элементы: ";
    for (int& x : arr) cin >> x;

    selectionSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}