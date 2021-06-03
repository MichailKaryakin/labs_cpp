#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "src/utils.h"

#define N1 10000
#define N2 18000
#define N3 30000
#define N4 60000

using namespace std;

void fill_arrays(int* array1, int* array2, int* array3, int* array4) {
    ifstream fin("test_numbers.txt");
    string temp;
    int symbol_count = 0;
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 48 && symbol_count != N1) {
                array1[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N1) {
            puts("первый массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 48 && symbol_count != N2) {
                array2[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N2) {
            puts("второй массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 48 && symbol_count != N3) {
                array3[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N3) {
            puts("третий массив заполнен");
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    while (getline(fin, temp)) {
        for (char i : temp) {
            if (i != 48 && symbol_count != N4) {
                array4[symbol_count] = i - 48;
                ++symbol_count;
            }
        }
        if (symbol_count == N4) {
            puts("четвёртый массив заполнен");
            break;
        }
        temp.clear();
    }
    fin.close();
}

void array1_sort(int* array) {
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА ВЫБОРОМ");
    int temp_array[N1];
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N1);
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА ВСТАВКАМИ");
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N1);
    puts("СОРТИРОВКА ШЕЛЛА ПЕРВОГО МАССИВА");
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N1);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N1);
    puts("СОРТИРОВКА ПЕРВОГО МАССИВА СЛИЯНИЕМ");
    for (int i = 0; i < N1; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, 0, N1 - 1);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, 0, N1 - 1);
    sort(temp_array, temp_array + N1);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, 0, N1 - 1);
}

void array2_sort(int* array) {
    puts("СОРТИРОВКА ВТОРОГО МАССИВА ВЫБОРОМ");
    int temp_array[N2];
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N2);
    puts("СОРТИРОВКА ВТОРОГО МАССИВА ВСТАВКАМИ");
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N2);
    puts("СОРТИРОВКА ШЕЛЛА ВТОРОГО МАССИВА");
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N2);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N2);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N2);
    puts("СОРТИРОВКА ВТОРОГО МАССИВА СЛИЯНИЕМ");
    for (int i = 0; i < N2; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, 0, N2 - 1);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, 0, N2 - 1);
    sort(temp_array, temp_array + N2);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, 0, N2 - 1);
}

void array3_sort(int* array) {
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА ВЫБОРОМ");
    int temp_array[N3];
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N3);
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА ВСТАВКАМИ");
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N3);
    puts("СОРТИРОВКА ШЕЛЛА ТРЕТЬЕГО МАССИВА");
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N3);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N3);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N3);
    puts("СОРТИРОВКА ТРЕТЬЕГО МАССИВА СЛИЯНИЕМ");
    for (int i = 0; i < N3; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, 0, N3 - 1);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, 0, N3 - 1);
    sort(temp_array, temp_array + N3);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, 0, N3 - 1);
}

void array4_sort(int* array) {
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА ВЫБОРОМ");
    int temp_array[N4];
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    choicesSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    choicesSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    choicesSort(temp_array, N4);
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА ВСТАВКАМИ");
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    insertionSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    insertionSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    insertionSort(temp_array, N4);
    puts("СОРТИРОВКА ШЕЛЛА ЧЕТВЁРТОГО МАССИВА");
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    shellSort(temp_array, N4);
    puts("сортировка упорядоченного массива");
    shellSort(temp_array, N4);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    shellSort(temp_array, N4);
    puts("СОРТИРОВКА ЧЕТВЁРТОГО МАССИВА СЛИЯНИЕМ");
    for (int i = 0; i < N4; ++i) {
        temp_array[i] = array[i];
    }
    puts("сортировка неупорядоченного массива");
    mergeSort(temp_array, 0, N4 - 1);
    puts("сортировка упорядоченного массива");
    mergeSort(temp_array, 0, N4 - 1);
    sort(temp_array, temp_array + N4);
    puts("сортировка упорядоченного в обратном порядке массива");
    mergeSort(temp_array, 0, N4 - 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int array1[N1], array2[N2], array3[N3], array4[N4];
    fill_arrays(array1, array2, array3, array4);
    array1_sort(array1);
    array2_sort(array2);
    array3_sort(array3);
    array4_sort(array4);
}
