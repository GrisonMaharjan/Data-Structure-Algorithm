#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    for (int n = 1000; n <= 10000; n += 1000) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000; // Random numbers between 0 and 9999
        }

        auto start = high_resolution_clock::now();
        bubbleSort(arr, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Input size: " << n << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}