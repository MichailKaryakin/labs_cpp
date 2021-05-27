#include "cstdlib"
#include "cmath"
#include "sortings.h"

void choicesSort(int* array, int length) {
    for (int repeat_counter = 0; repeat_counter < length; repeat_counter++) {
        int temp; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < length; element_counter++) {
            if (array[repeat_counter] < array[element_counter]) {
                temp = array[repeat_counter];
                array[repeat_counter] = array[element_counter];
                array[element_counter] = temp;
            }
        }
    }
}

void insertionSort(int* array, int length) {
    int temp, item;
    for (int counter = 1; counter < length; counter++) {
        temp = array[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter - 1; // запоминаем индекс предыдущего элемента массива
        while (item >= 0 && array[item] < temp) // пока индекс не равен 0 и предыдущий элемент массива меньше текущего
        {
            array[item + 1] = array[item]; // перестановка элементов массива
            array[item] = temp;
            item--;
        }
    }
}

void shellSort(int* array, int length) {
    const int t = (int) ((log(length) / log(3)) - 1);
    int i, j, k, m, x;
    int* h = (int*) malloc(t * sizeof(int));
    h[t - 1] = 1;
    for (m = t - 2; m >= 0; m--)
        h[m] = h[m + 1] * 3 + 1;
    for (m = 0; m < t; m++) /*последовательно перебираем все расстояния*/
    {
        k = h[m];
        for (i = k; i < length; i++) /*до конца цикла метод вставки с учетом шага h[m]*/
        {
            x = array[i];
            j = i - k;
            while (j >= 0 && x > array[j]) {
                array[j + k] = array[j];
                j -= k;
            }
            array[j + k] = x;
        }
    }
    free(h);
}

void Merge(int* array, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[100];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++) { //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (array[start] > array[final]))) {
            mas[j] = array[start];
            start++;
        } else {
            mas[j] = array[final];
            final++;
        }
    }
    for (j = first; j <= last; j++) { //возвращение результата в список
        array[j] = mas[j];
    }
    delete[] mas;
}

void mergeSort(int* array, int first, int last) { //рекурсивная процедура сортировки
    if (first < last) {
        mergeSort(array, first, (first + last) / 2);  //сортировка левой части
        mergeSort(array, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(array, first, last);  //слияние двух частей
    }
}


