#include "FunctionsPrototypes.h"

#include "QuickSort.cpp"
#include "ShellSort.cpp"
#include "MergeSort.cpp"
#include "HeapSort.cpp"
#include "SortMeasuring.cpp"
#include "BuildGraph.cpp"
#include "ActionsOnArray.cpp"
#include <ctime>

void PrintMetricsHeader() {
    cout << setw(15) << left << "Algorithm";
    cout << setw(15) << right << "Comparisons";
    cout << setw(15) << "Swaps";
    cout << setw(15) << "Iterations";
    cout << setw(15) << "Time";
    cout << setw(17) << "O-Notation\n";
    cout << string(95, '-') << "\n";  
}

void PrintMetrics(const string& algorithm_name, int comparisons, int swaps, int iterations, double elapsed_time, const string& notation) {
    cout << setw(15) << left << algorithm_name;
    cout << setw(15) << right << comparisons;
    cout << setw(15) << swaps;
    cout << setw(15) << iterations;
    cout << setw(15) << fixed << setprecision(6) << elapsed_time << " sec.";
    cout << setw(15) << notation << "\n";
}

void ResetMetrics(int& comparisons, int& swaps, int& iterations, double& elapsed_time) {
    comparisons = 0;
    swaps = 0;
    iterations = 0;
    elapsed_time = 0;
}

void Menu() {
    int option = 0;

    while (true) {
        PrintLine(60);
        cout << "\t\tFAST SORTING ALGORITHMS\n";
        PrintLine(60);
        cout << "\t\t\tMenu\n";
        cout << "1. Sort array using Shell Sort.\n";
        cout << "2. Sort array using Quick Sort.\n";
        cout << "3. Sort array using Heap Sort.\n";
        cout << "4. Sort array using Merge Sort.\n";
        cout << "5. Comparison of sorting algorithms.\n";
        cout << "6. Plotting graph of sort function.\n";
        cout << "0. Exit the program.\n";
        PrintLine(60);
        cout << "Choose an option: ";

        cin >> option;

        if (cin.fail() || option < 0 || option > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option.\n";
        }
        else {
            switch (option) {
            case 1:
                SortAndMeasureTimeOfSorting<double>(ShellSort, "ShellSort");
                break;

            case 2:
                SortAndMeasureTimeOfSorting<int>(QuickSort, "QuickSort");
                break;

            case 3:
                SortAndMeasureTimeOfSorting<int>(HeapSort, "QuickSort");
                break;

            case 4:
                SortAndMeasureTimeOfSorting<int>(MergeSort, "MergeSort");
                break;

            case 5:
                CompareSortAlgorithms<int>();
                break;
            case 6:
                ChooseAlgorithmForBuildingGraph<int>();
                break;
            case 0:
                cout << "Program successfully terminated!\n";
                return;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
}

void PrintLine(int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << "=";
    }
    cout << "\n";
}