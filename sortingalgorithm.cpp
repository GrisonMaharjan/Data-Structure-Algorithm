#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate N random numbers within a given range
vector<int> generateRandomNumbers(int N, int minVal = 1, int maxVal = 100) {
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

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation
    int N;

    // Ask for the number of elements to sort
    cout << "Enter the number of elements to sort: ";
    cin >> N;

    // Generate random numbers for the array
    vector<int> numbers = generateRandomNumbers(N);

    // Display the randomly generated array
    cout << "\nOriginal Array:\n";
    displayArray(numbers);

    // Run Selection Sort
    vector<int> selectionSortedArray = numbers; // Copy original array
    cout << "\nApplying Selection Sort...\n";
    selectionSort(selectionSortedArray);
    cout << "\nSelection Sorted Array:\n";
    displayArray(selectionSortedArray);

    // Run Merge Sort
    vector<int> mergeSortedArray = numbers; // Copy original array
    cout << "\nApplying Merge Sort...\n";
    mergeSort(mergeSortedArray, 0, mergeSortedArray.size() - 1);
    cout << "\nMerge Sorted Array:\n";
    displayArray(mergeSortedArray);

    return 0;
}
