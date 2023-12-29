#include "FunctionsPrototypes.h"

template<typename T>
void ShowArray(const vector<T>& array) {
    for (const T el : array) {
        cout << el << ' ';
    }
}

template<typename T>
void ChooseFillArrayOption(vector<T>& array) {
    int option;
    while (true) {
        cout << "Choose fill option: Random or OwnInputData.\n";
        cout << "Enter 1 if you want Random Filling: \n";
        cout << "Enter 2 if you want Own Input Data: \n";
        cin >> option;

        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Incorrect input! Please enter a valid option.\n";
        }
        else {
            switch (option) {
            case 1:
                FillArrayByRandomValues(array);
                return;
            case 2:
                FillArrayByKeyboard(array);
                return;
            default:
                cout << "Incorrect input! Please enter 1 or 2.\n";
                break;
            }
        }
    }
}
template void ChooseFillArrayOption<int>(vector<int>& array);
template void ChooseFillArrayOption<double>(vector<double>& array);
template<typename T>
void FillArrayByKeyboard(std::vector<T>& array) {
    int size;

    while (true) {
        std::cout << "Enter the number of elements in the array: ";
        std::cin >> size;

        if (std::cin.fail() || size <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
        else {
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        T element;
        while (true) {
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> element;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid value.\n";
            }
            else {
                break;
            }
        }
        array.push_back(element);
    }
}

template<typename T>
void FillArrayByRandomValues(std::vector<T>& array) {
    int size;
    T min_value, max_value;

    while (true) {
        std::cout << "Enter count of elements you want to generate randomly: ";
        std::cin >> size;

        if (std::cin.fail() || size <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter the range for random values:\n";
        std::cout << "Min value: ";
        std::cin >> min_value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid value.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Max value: ";
        std::cin >> max_value;

        if (std::cin.fail() || max_value <= min_value) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a value greater than the min value.\n";
        }
        else {
            break;
        }
    }

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++) {
        T random_value = static_cast<T>(min_value + rand() % static_cast<int>(max_value - min_value + 1));
        array.push_back(random_value);
    }
}

template<typename T>
void FillArrayByRandomValues(vector<T>& array, int count_of_elements) {


    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < count_of_elements; i++) {

        T random_value = static_cast<T>(1 + rand() % static_cast<int>(count_of_elements - 1 + 1));
        array.push_back(random_value);
    }
}
