#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

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
    // Ручной ввод массива
    std::cout << "Введите числа через пробел: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> arr;
    int x;
    while (iss >> x) arr.push_back(x);

    // Вариант чтения из файла:
    // #include <fstream>
    // std::ifstream fin("input.txt");
    // std::vector<int> arr;
    // int x;
    // while (fin >> x) arr.push_back(x);

    std::cout << "До:    ";
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';

    shakerSort(arr);

    std::cout << "После: ";
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';
    return 0;
}