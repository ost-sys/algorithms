#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = (int)arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
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
    std::vector<int> arr = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    std::cout << "До:    ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';

    shellSort(arr);

    std::cout << "После: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}