#include "cstdlib"
#include "cmath"
#include "ctime"
#include "utils.h"
#include "iostream"

using namespace std;

void choicesSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++) {
        ++compare_count;
        int temp; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++) {
            ++compare_count;
            if (array[repeat_counter] < array[element_counter]) {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
            ++basic_operations;
        }
        ++compare_count;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество выделенной дополнительной памяти = " << sizeof(int) << " байт" << "\n";
}

void insertionSort(int* array, int length) {
    clock_t start = clock();
    long long compare_count = 0;
    long long basic_operations = 0;
    int temp, j, i;
    for (i = 1; i < length; i++) {
        ++compare_count;
        temp = array[i];
        for (j = i; j >= 0 && temp > array[j - 1]; j--) {/* находим место вставки, попутно сдвигая элементы */
            ++compare_count;
            ++basic_operations;
            array[j] = array[j - 1];
        }
        ++compare_count;
        ++basic_operations;
        array[j] = temp;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество выделенной дополнительной памяти = " << sizeof(int) * 3 << " байт" << "\n";
}

void shellSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    const int num_of_gaps = (int) ((log(length) / log(3)) - 1);
    int i, m;
    int current_gap, temp, replace_index;
    int gaps[num_of_gaps];
    gaps[num_of_gaps] = 1;
    for (m = num_of_gaps - 1; m >= 0; m--) {
        ++compare_count;
        gaps[m] = gaps[m + 1] * 3 + 1;
    }
    ++compare_count;
    for (m = 0; m < num_of_gaps; m++) /*последовательно перебираем все расстояния*/
    {
        ++compare_count;
        current_gap = gaps[m];
        for (i = current_gap; i < length; i++) /*до конца цикла метод вставки с учетом шага gaps[m]*/
        {
            ++compare_count;
            temp = array[i];
            replace_index = i - current_gap;
            while (replace_index >= 0 && temp > array[replace_index]) {
                ++basic_operations;
                ++compare_count;
                array[replace_index + current_gap] = array[replace_index];
                replace_index -= current_gap;
            }
            ++basic_operations;
            ++compare_count;
            array[replace_index + current_gap] = temp;
        }
        ++compare_count;
    }
    ++compare_count;
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество дополнительно выделенной памяти = "
         << sizeof(const int) * 1 + sizeof(int) * 5 + sizeof(int) * num_of_gaps << " байт" << "\n";
}

void mergeSort(int* array, int length) {
    clock_t start = clock();
    long int compare_count = 0;
    long int basic_operations = 0;
    int* temp = (int*) malloc(sizeof(int) * length);    /* вспомогательный массив */
    int* p1,    /* адрес элемента в одной серии */
    * p2,    /* адрес элемента в другой серии */
    * p3,    /* адрес элемента в формируемом массиве */
    len = 1,        /* длина серии */
    len1 = 0, len2 = 0,    /* текущие длины серий */
    * end_a,                /* адрес конца массива array */
    * end_temp;            /* адрес конца массива temp */
    char flag = 0;            /* признак того, откуда куда идет перезапись: 0 - из сортируемого массива во вспомогательный, 1 - из вспомогательного в исходный */
    while (len < length)    /* пока длина серии меньше длины массива */
    {
        ++compare_count;
        p1 = array;
        p2 = array + len;
        p3 = temp;
        end_a = array + length;
        end_temp = temp + length; /* указатели ставим на стартовые позиции */
        while (p3 < end_temp)            /* пока переписаны не все элементы массива */
        {
            ++compare_count;
            len1 = 0;            /* в первой серии всегда будут элементы, устанавливаем счетчик в 0 */
            if (p2 < end_a) {   /* если на вторую серию элементов в массиве хватает, */
                len2 = 0;        /* то счетчик тоже устанавливаем в 0 */
            } else {
                len2 = len;    /* а если элементов не хватает, то серия не будет принимать участие в переписывании */
            }
            ++compare_count;
            while (len1 < len && len2 < len && p2 < end_a)   /* пока в обеих сериях есть элементы */
            {
                compare_count += 3;
                if (*p1 <= *p2) {                   /* если значение в первой серии не больше, чем во второй, */
                    *p3++ = *p1++, len1++;            /* то переписываем его в другой массив, увеличиваем счетчик изъятых элементов */
                } else {
                    *p3++ = *p2++, len2++;            /* иначе переписываем значение из второй серии */
                }
                ++compare_count;
            }
            compare_count += 3;
            while (len1 < len && p3 < end_temp) {  /* пока первая серия не пуста */
                compare_count += 2;
                *p3++ = *p1++, len1++;                    /* переписываем ее до конца во второй массив */
            }
            compare_count += 2;
            while (len2 < len && p3 < end_temp) {   /* пока вторая серия не пуста */
                compare_count += 2;
                *p3++ = *p2++, len2++;                    /* переписываем ее до конца во второй массив */
            }
            compare_count += 2;
            p1 += len;            /* переставляем указатели на первые элементы следующих серий */
            p2 += len;
        }
        ++compare_count;
        len *= 2;            /* увеличиваем длину серии вдвое */
        p3 = array;            /* меняем местами входной и выходной массивы */
        array = temp;
        temp = p3;
        flag = !flag;    /* меняем значение флага */
    }
    ++compare_count;
    if (flag)    /* если флаг установлен, то упорядоченная последовательность находится во вспомогательном массиве */
    {
        for (p1 = temp, p2 = array; p1 < temp + length; *p1++ = *p2++) { /* переписываем ее в исходный */
            ++compare_count;
        }
        ++compare_count;
        free(array);                                                /* освобождаем память от вспомогательного массива */
    } else {
        free(temp);    /* иначе на вспомогательный массив указыает temp, освобождаем память от вспомогательного массива */
    }
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start) / (double) CLOCKS_PER_SEC;
    cout << "количество основных операций: " << basic_operations << "\n";
    cout << "количество сравнений: " << compare_count << "\n";
    cout << "время: " << time_elapsed_in_seconds << "\n";
    cout << "количество дополнительно выделенной памяти = "
         << sizeof(int) * length + sizeof(int*) * 5 + sizeof(int) * 3 + sizeof(int) * 3 + sizeof(char) << " байт"
         << "\n";
}


