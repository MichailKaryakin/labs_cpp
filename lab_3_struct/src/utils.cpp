#include "cstdlib"
#include "cmath"
#include "ctime"
#include "utils.h"

void choicesSort(int* array, int length) {
    unsigned int start_time = clock();
    int compare_count = 0;
    int basic_actions = 0;
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++) {
        ++compare_count;
        int temp; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++) {
            ++compare_count;
            if (array[repeat_counter] < array[element_counter]) {
                ++compare_count;
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                ++basic_actions;
                array[element_counter] = temp;
                ++basic_actions;
            }
        }
    }
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
}

void insertionSort(int* array, int length) {
    unsigned int start_time = clock();
    int temp, item;
    int compare_count = 0;
    int basic_actions = 0;
    for (int counter = 1; counter < length; counter++) {
        ++compare_count;
        temp = array[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter - 1; // запоминаем индекс предыдущего элемента массива
        while (item >= 0 && array[item] < temp) // пока индекс не равен 0 и предыдущий элемент массива меньше текущего
        {
            compare_count += 2;
            array[item + 1] = array[item]; // перестановка элементов массива
            ++basic_actions;
            array[item] = temp;
            ++basic_actions;
            item--;
        }
    }
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
}

void shellSort(int* array, int length) {
    unsigned int start_time = clock();
    int compare_count = 0;
    int basic_actions = 0;
    const int t = (int) ((log(length) / log(3)) - 1);
    int i, j, k, m, x;
    int* h = (int*) malloc(t * sizeof(int));
    h[t - 1] = 1;
    for (m = t - 2; m >= 0; m--)
        ++compare_count;
    h[m] = h[m + 1] * 3 + 1;
    for (m = 0; m < t; m++) /*последовательно перебираем все расстояния*/
    {
        ++compare_count;
        k = h[m];
        for (i = k; i < length; i++) /*до конца цикла метод вставки с учетом шага h[m]*/
        {
            ++compare_count;
            x = array[i];
            j = i - k;
            while (j >= 0 && x > array[j]) {
                compare_count += 2;
                array[j + k] = array[j];
                ++basic_actions;
                j -= k;
            }
            array[j + k] = x;
            ++basic_actions;
        }
    }
    free(h);
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
}

static int basic_actions = 0;
static int compare_count = 0;

void Merge(int* array, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++)  //выполнять от начала до конца
    {
        ++compare_count;
        if ((start <= middle) && ((final > last) || (array[start] < array[final]))) {
            compare_count += 3;
            mas[j] = array[start];
            start++;
        } else {
            mas[j] = array[final];
            final++;
        }
    }
    //возвращение результата в список
    for (j = first; j <= last; j++) {
        ++basic_actions;
        array[j] = mas[j];
    }
    delete[] mas;
}

void mergeSort(int* array, int first, int last) {
    unsigned int start_time = clock();
    if (first < last) {
        ++compare_count;
        mergeSort(array, first, (first + last) / 2);  //сортировка левой части
        mergeSort(array, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(array, first, last);  //слияние двух частей
    }
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
    basic_actions = 0;
    compare_count = 0;
}


