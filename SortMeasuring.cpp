#include "FunctionsPrototypes.h"


template<typename T>
void CompareSortAlgorithms() {
    vector<T> generated_array;
    ChooseFillArrayOption<T>(generated_array);
    cout << string(95, '-') << "\n";

    PrintMetricsHeader();

    vector<T> array_quick_sort = generated_array;
    vector<T> array_shell_sort = generated_array;
    vector<T> array_merge_sort = generated_array;
    vector<T> array_heap_sort = generated_array;

    clock_t start_time, end_time;
    double elapsed_time;

    // Quick Sort
    start_time = clock();
    QuickSort(array_quick_sort, 0, array_quick_sort.size() - 1);
    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    PrintMetrics("Quick Sort", quick_sort_comparisons, quick_sort_swaps, quick_sort_iterations, elapsed_time, "O(n log n)");
    ResetMetrics(quick_sort_comparisons, quick_sort_swaps, quick_sort_iterations, elapsed_time);

    //// Heap Sort
    start_time = clock();
    HeapSort(array_heap_sort);
    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    PrintMetrics("Heap Sort", heap_sort_comparisons, heap_sort_swaps, heap_sort_iterations, elapsed_time, "O(n log n)");
    ResetMetrics(heap_sort_comparisons, heap_sort_swaps, heap_sort_iterations, elapsed_time);
    
    //// Merge Sort
    start_time = clock();
    MergeSort(array_merge_sort, 0, array_merge_sort.size() - 1);
    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    PrintMetrics("Merge Sort", merge_sort_comparisons, merge_sort_swaps, merge_sort_iterations, elapsed_time, "O(n log n)");
    ResetMetrics(merge_sort_comparisons, merge_sort_swaps, merge_sort_iterations, elapsed_time);
    
    //// Shell Sort
    start_time = clock();
    ShellSort(array_shell_sort);
    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    PrintMetrics("Shell Sort", shell_sort_comparisons, shell_sort_swaps, shell_sort_iterations, elapsed_time, "O(n log^2 n)");
    ResetMetrics(shell_sort_comparisons, shell_sort_swaps, shell_sort_iterations, elapsed_time);
     
    cout << string(95, '-') << "\n";
    
    generated_array.clear();
    array_quick_sort.clear();
    array_shell_sort.clear();
    array_merge_sort.clear();
    array_heap_sort.clear();
}

template<typename T>
void SortAndMeasureTimeOfSorting(void(*sorting_function)(vector<T>&, int, int), const string& sortingMethodName) {
    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    vector<T> array;

    cout << "Sorting array using " << sortingMethodName << "...\n";
    ChooseFillArrayOption(array);
    cout << "Original array: \n";
    ShowArray(array);
    start_time = clock();
    sorting_function(array, 0, array.size() - 1);

    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "\n Sorted array:\n";
    ShowArray(array);
    cout << "\nSorted array in " << elapsed_time << " seconds.\n";
    
    array.clear();

}
template<typename T>
void SortAndMeasureTimeOfSorting(void(*sorting_function)(vector<T>&), const string& function_name) {
    clock_t start_time;
    clock_t end_time;
    double elapsed_time;
    vector<T> array;

    cout << "Sorting array using " << function_name << "...\n";
    ChooseFillArrayOption(array);
    cout << "Original array: \n";
    ShowArray(array);
    start_time = clock();

    sorting_function(array);

    end_time = clock();
    elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "\n Sorted array:\n";
    ShowArray(array);

    cout << "\nSorted array in " << elapsed_time << " seconds.\n";

    array.clear();
}


