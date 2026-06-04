#include <iostream>
#include <vector>
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
    vector<int> arr = {3, 7, 11, 18, 25, 42, 56, 78};
    cout << binarySearch(arr, 25) << endl;
    cout << binarySearch(arr, 10) << endl;
    return 0;
}