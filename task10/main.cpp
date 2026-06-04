#include <iostream>
#include <vector>
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
    vector<int> arr = {64, 25, 12, 22, 11};
    bubbleSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}