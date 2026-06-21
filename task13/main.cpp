#include <iostream>
#include <vector>
// Вариант с файлом:
// #include <fstream>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Введите количество элементов (отсортированный массив): ";
    cin >> n;

    // Вариант с файлом:
    // ifstream f("input.txt");
    // f >> n;
    // vector<int> arr(n);
    // for (int& x : arr) f >> x;
    // int target; f >> target;

    vector<int> arr(n);
    cout << "Введите элементы: ";
    for (int& x : arr) cin >> x;

    int target;
    cout << "Введите искомый элемент: ";
    cin >> target;

    cout << binarySearch(arr, target) << endl;
    return 0;
}