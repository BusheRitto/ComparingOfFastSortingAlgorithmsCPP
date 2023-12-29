#pragma once
#ifndef UNTITLED_FUNCTIONSPROTOTYPES_H
#define UNTITLED_FUNCTIONSPROTOTYPES_H
#include <vector>
#include <iostream>
#include <string>
#include <iomanip> 
#include <ios>  
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Actions on array
template<typename T>
void FillArrayByKeyboard(vector<T>& array);
template<typename T>
void FillArrayByRandomValues(vector<T>& array);
template<typename T>
void FillArrayByRandomValues(vector<T>& array, int count_of_elements);
template<typename T>
void ChooseFillArrayOption(vector<T>& array);
template void ChooseFillArrayOption<int>(vector<int>& array);
template<typename T>
void ShowArray(const vector<T>& array);
template void ShowArray<int>(const std::vector<int>& array);
template void ShowArray<double>(const std::vector<double>& array);

// Menu
void PrintLine(int n);
void Menu();

// Sort prototypes

// Quick Sort
template<typename T>
void QuickSort(vector<T>& array, int low, int high);

template<typename T>
int partition(vector<T>& array, int low, int high);

template<typename T>
void Swap(T& a, T& b);


// Shell Sort

template<typename T>
vector<T> DistanceMethod(int n);


template<typename T>
void ShellSort(vector<T>& arr);

// Merge Sort

template<typename T>
void merge(vector<T>& arr, int l, int m, int r);
template<typename T>
void MergeSort(vector<T>& arr, int l, int r);

// Heap Sort
template<typename T>
void HeapSort(vector<T>& arr);

template<typename T>
void heapify(vector<T>& arr, int n, int i);

// Testing Sort Algorithms
template<typename T>
void SortAndMeasureTimeOfSorting(void(*sorting_function)(vector<T>&, int, int), const string& sortingMethodName);

template<typename T>
void SortAndMeasureTimeOfSorting(void(*sorting_function)(vector<T>&), const string& function_name);

template<typename T>
void CompareSortAlgorithms();

void ResetMetrics(int& comparisons, int& swaps, int& iterations, double& elapsed_time);
void PrintMetrics(const string& algorithm_name, int comparisons, int swaps, int iterations, double elapsed_time, const string& notation);
void PrintMetricsHeader();

// Build graph
void BuildGraph();
template<typename T>
void BuildGraph(void(*sorting_function)(vector<T>&), const string& function_name);
template<typename T>
void ChooseAlgorithmForBuildingGraph();
template<typename T>
void BuildGraph(void(*sorting_function)(vector<T>&, int, int), const string& function_name);

// Global variables for testing sort algorithms
static int quick_sort_comparisons = 0;
static int quick_sort_swaps = 0;
static int quick_sort_iterations = 0;

static int shell_sort_comparisons = 0;
static int shell_sort_swaps = 0;
static int shell_sort_iterations = 0;

static int merge_sort_comparisons = 0;
static int merge_sort_swaps = 0;
static int merge_sort_iterations = 0;

static int heap_sort_comparisons = 0;
static int heap_sort_swaps = 0;
static int heap_sort_iterations = 0;

#endif 
