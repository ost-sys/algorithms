#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    heapSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}