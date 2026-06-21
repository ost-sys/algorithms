#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
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

    shellSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}