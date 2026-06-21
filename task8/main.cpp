#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}