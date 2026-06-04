#include <iostream>
#include <vector>
#include <algorithm>

void shakerSort(std::vector<int>& arr) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        for (int i = left; i < right; ++i)
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
        --right;

        for (int i = right; i > left; --i)
            if (arr[i] < arr[i - 1])
                std::swap(arr[i], arr[i - 1]);
        ++left;
    }
}

int main() {
    std::vector<int> arr = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    std::cout << "До:    ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';

    shakerSort(arr);

    std::cout << "После: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}