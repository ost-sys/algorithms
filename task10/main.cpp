#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
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

    bubbleSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}