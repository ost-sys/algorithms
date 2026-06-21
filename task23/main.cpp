#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

    shellSort(arr);

    std::cout << "После: ";
    for (int v : arr) std::cout << v << ' ';
    std::cout << '\n';
    return 0;
}