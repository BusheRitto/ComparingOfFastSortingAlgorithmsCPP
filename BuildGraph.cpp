#include "FunctionsPrototypes.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

template<typename T>
void ChooseAlgorithmForBuildingGraph() {
    PrintLine(60);
    cout << "Building a graph that shows the count of elements and the time taken to sort these elements.\n";

    int option = 0;
    while (true) {
        cout << "Choose an algorithm to visualize on the graph:\n";
        cout << "1. Shell Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Heap Sort\n";
        cout << "4. Merge Sort\n";
        cout << "0. Exit from this point.\n";
        PrintLine(60);
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            BuildGraph<T>(ShellSort, "Shell Sort");
            break;
        case 2:
            BuildGraph<T>(QuickSort, "Quick Sort");
            break;
        case 3:
            BuildGraph<T>(HeapSort, "Heap Sort");
            break;
        case 4:
            BuildGraph<T>(MergeSort, "Merge Sort");
            break;
        case 0:
            cout << "You successfully went from this point!\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}

template<typename T>
void BuildGraph(void(*sorting_function)(vector<T>&), const string& function_name) {
    vector<int> elements = { 100, 1000, 10000, 100000, 1000000, 10000000 };
    vector<double> sortingTimes;

    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    plt::figure();

    for (int numElements : elements) {
        vector<T> array;
        FillArrayByRandomValues<T>(array, numElements);
        
        start_time = clock();
       
        sorting_function(array);
        end_time = clock();
        elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
     
        sortingTimes.push_back(elapsed_time);
        array.clear();
    }

    plt::plot(elements, sortingTimes);
    
    plt::title(function_name + " Sorting Time vs Number of Elements");
    plt::xlabel("Number of Elements");
    plt::ylabel("Time (s)");
    plt::show();
}

template<typename T>
void BuildGraph(void(*sorting_function)(vector<T>&, int,int), const string& function_name) {
    vector<int> elements = { 100, 1000, 10000, 100000, 1000000, 10000000 };
    vector<double> sortingTimes;

    clock_t start_time;
    clock_t end_time;
    double elapsed_time;

    plt::figure();

    for (int numElements : elements) {
        vector<T> array;
        FillArrayByRandomValues<T>(array, numElements);

        start_time = clock();

        sorting_function(array, 0, array.size() - 1);
        end_time = clock();
        elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        sortingTimes.push_back(elapsed_time);
        array.clear();
    }

    plt::plot(elements, sortingTimes);
    plt::title(function_name + " Sorting Time vs Number of Elements");
    plt::xlabel("Number of Elements");
    plt::ylabel("Time (s)");

    plt::show();
}

