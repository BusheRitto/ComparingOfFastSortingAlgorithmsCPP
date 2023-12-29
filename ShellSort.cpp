#include "FunctionsPrototypes.h"


template<typename T>
vector<T> DistanceMethod(int n) {
    vector<T> distances;
    int gap = 1;

    while (gap <= n / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        distances.push_back(gap);
        gap /= 3;
    }

    return distances;
}

template<typename T>
void ShellSort(vector<T>& arr) {
    int n = arr.size();

    vector<T> distances = DistanceMethod<T>(n);

    for (int p = 0; p < distances.size(); p++) {
        int gap = distances[p];

        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            shell_sort_iterations++;
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                shell_sort_comparisons++;
         
                shell_sort_swaps++;

                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
