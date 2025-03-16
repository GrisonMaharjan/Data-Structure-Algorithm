#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 5, 5, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}