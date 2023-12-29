#include "FunctionsPrototypes.h"


template<typename T>
void heapify(vector<T>& arr, int n, int i) {
    int largest = i;   // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    heap_sort_iterations++;

    if (left < n) {
        // Increment comparisons counter
        heap_sort_comparisons++;

        if (arr[left] > arr[largest])
            largest = left;
    }

    // If right child is larger than largest so far
    if (right < n) {
        // Increment comparisons counter
        heap_sort_comparisons++;

        if (arr[right] > arr[largest])
            largest = right;
    }
    // If largest is not root
    if (largest != i) {
        heap_sort_swaps++;
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
template<typename T>
void HeapSort(vector<T>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
