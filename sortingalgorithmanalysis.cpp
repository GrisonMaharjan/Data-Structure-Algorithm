#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to generate N random numbers
vector<int> generateRandomNumbers(int N, int minVal = 1, int maxVal = 1000) {
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % (maxVal - minVal + 1) + minVal;
    }
    return numbers;
}

// Selection Sort Algorithm
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// Merge Sort Algorithm
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to measure sorting time (Selection Sort)
void measureSortingTime(vector<int>& numbers, void (*sortFunction)(vector<int>&), const string& sortName) {
    vector<int> tempNumbers = numbers;  // Copy original array

    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortFunction(tempNumbers);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    milliseconds duration = duration_cast<milliseconds>(end - start);
    cout << sortName << " Time: " << duration.count() << " ms" << endl;
}

// Function to measure Merge Sort time
void measureMergeSortTime(vector<int>& numbers) {
    vector<int> tempNumbers = numbers;  // Copy original array

    high_resolution_clock::time_point start = high_resolution_clock::now();
    mergeSort(tempNumbers, 0, tempNumbers.size() - 1);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    milliseconds duration = duration_cast<milliseconds>(end - start);
    cout << "Merge Sort Time: " << duration.count() << " ms" << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    // Different input sizes to test
    int inputSizes[] = {100, 500, 1000, 5000};
    int numSizes = sizeof(inputSizes) / sizeof(inputSizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int N = inputSizes[i];
        cout << "\nSorting " << N << " random elements...\n";
        vector<int> numbers = generateRandomNumbers(N);

        // Measure time for Selection Sort
        measureSortingTime(numbers, selectionSort, "Selection Sort");

        // Measure time for Merge Sort
        measureMergeSortTime(numbers);
    }

    return 0;
}


