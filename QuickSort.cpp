#include "FunctionsPrototypes.h"


template<typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(vector<T>& array, int low, int high) {
    T pivot = array[high]; 
    int i = low - 1;        

    for (int j = low; j <= high - 1; j++) {
        quick_sort_comparisons++;

        if (array[j] < pivot) {
            i++;
            Swap(array[i], array[j]);
            quick_sort_swaps++;
        }
        quick_sort_iterations++;
    }

    Swap(array[i + 1], array[high]);

    quick_sort_swaps++;

    return i + 1;
}

// Quick Sort function
template<typename T>
void QuickSort(vector<T>& array, int low, int high) {
    if (low < high) {
   
        int pivotIndex = partition(array, low, high);

      
        QuickSort(array, low, pivotIndex - 1);
        QuickSort(array, pivotIndex + 1, high);
    }
}