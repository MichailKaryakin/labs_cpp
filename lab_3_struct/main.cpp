#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "src/sortings.h"
#include "src/data.h"

#define N1 10000
#define N2 18000
#define N3 30000
#define N4 60000

using namespace std;

struct array_data {
    data data1;
    data data2;
    data data3;
    data data4;
    data data5;
    data data6;
    data data7;
    data data8;
    data data9;
    data data10;
    data data11;
    data data12;
};

struct total_data {
    array_data data1;
    array_data data2;
    array_data data3;
    array_data data4;
};

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
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    fin.close();
}

total_data
sort_arrays(const int* array1, const int* array2, const int* array3, const int* array4, total_data totalData) {
    bool exit = false;
    bool sorted1 = false, sorted2 = false, sorted3 = false, sorted4 = false;
    while (!exit) {
        int user_choice;
        puts("1 - сортировка N1, 2 - сортировка N2, 3 - сортировка N3, 4 - сортировка N4");
        cin >> user_choice;
        if (user_choice == 1 && !sorted1) {
            bool exit_1 = false;
            bool sorted1_1 = false, sorted2_1 = false, sorted3_1 = false, sorted4_1 = false;
            array_data arrayData{};
            while (!exit_1) {
                int user_choice_1;
                puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
                cin >> user_choice_1;
                if (user_choice_1 == 1 && !sorted1_1) {
                    int temp_array[N1];
                    for (int i : temp_array) {
                        temp_array[i] = array1[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data1 = choicesSort(temp_array, N1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data2 = choicesSort(temp_array, N1);
                    sort(temp_array[0], temp_array[N1 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data3 = choicesSort(temp_array, N1);
                    sorted1_1 = true;
                } else if (user_choice_1 == 2 && !sorted2_1) {
                    int temp_array[N1];
                    for (int i : temp_array) {
                        temp_array[i] = array1[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data4 = insertionSort(temp_array, N1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data5 = insertionSort(temp_array, N1);
                    sort(temp_array[0], temp_array[N1 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data6 = insertionSort(temp_array, N1);
                    sorted2_1 = true;
                } else if (user_choice_1 == 3 && !sorted3_1) {
                    int temp_array[N1];
                    for (int i : temp_array) {
                        temp_array[i] = array1[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data7 = shellSort(temp_array, N1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data8 = shellSort(temp_array, N1);
                    sort(temp_array[0], temp_array[N1 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data9 = shellSort(temp_array, N1);
                    sorted3_1 = true;
                } else if (user_choice_1 == 4 && !sorted4_1) {
                    int temp_array[N1];
                    for (int i : temp_array) {
                        temp_array[i] = array1[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data10 = mergeSort(temp_array, 0, N1 - 1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data11 = mergeSort(temp_array, 0, N1 - 1);
                    sort(temp_array[0], temp_array[N1 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data12 = mergeSort(temp_array, 0, N1 - 1);
                    sorted4_1 = true;
                } else if (sorted1_1 && sorted2_1 && sorted3_1 && sorted4_1) {
                    exit_1 = true;
                }
            }
            sorted1 = true;
            totalData.data1 = arrayData;
        } else puts("сортировка N1 уже была протестирована");
        if (user_choice == 2 && !sorted2) {
            bool exit_2 = false;
            bool sorted1_2 = false, sorted2_2 = false, sorted3_2 = false, sorted4_2 = false;
            array_data arrayData{};
            while (!exit_2) {
                int user_choice_2;
                puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
                cin >> user_choice_2;
                if (user_choice_2 == 1 && !sorted1_2) {
                    int temp_array[N2];
                    for (int i : temp_array) {
                        temp_array[i] = array2[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data1 = choicesSort(temp_array, N2);
                    puts("сортировка упорядоченного массива");
                    arrayData.data2 = choicesSort(temp_array, N2);
                    sort(temp_array[0], temp_array[N2 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data3 = choicesSort(temp_array, N2);
                    sorted1_2 = true;
                } else if (user_choice_2 == 2 && !sorted2_2) {
                    int temp_array[N2];
                    for (int i : temp_array) {
                        temp_array[i] = array2[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data4 = insertionSort(temp_array, N2);
                    puts("сортировка упорядоченного массива");
                    arrayData.data5 = insertionSort(temp_array, N2);
                    sort(temp_array[0], temp_array[N2 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data6 = insertionSort(temp_array, N2);
                    sorted2_2 = true;
                } else if (user_choice_2 == 3 && !sorted3_2) {
                    int temp_array[N2];
                    for (int i : temp_array) {
                        temp_array[i] = array2[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data7 = shellSort(temp_array, N2);
                    puts("сортировка упорядоченного массива");
                    arrayData.data8 = shellSort(temp_array, N2);
                    sort(temp_array[0], temp_array[N2 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data9 = shellSort(temp_array, N2);
                    sorted3_2 = true;
                } else if (user_choice_2 == 4 && !sorted4_2) {
                    int temp_array[N2];
                    for (int i : temp_array) {
                        temp_array[i] = array2[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data10 = mergeSort(temp_array, 0, N2 - 1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data11 = mergeSort(temp_array, 0, N2 - 1);
                    sort(temp_array[0], temp_array[N2 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data11 = mergeSort(temp_array, 0, N2 - 1);
                    sorted4_2 = true;
                } else if (sorted1_2 && sorted2_2 && sorted3_2 && sorted4_2) {
                    exit_2 = true;
                }
            }
            sorted2 = true;
            totalData.data2 = arrayData;
        } else puts("сортировка N2 уже была протестирована");
        if (user_choice == 3 && !sorted3) {
            bool exit_3 = false;
            bool sorted1_3 = false, sorted2_3 = false, sorted3_3 = false, sorted4_3 = false;
            array_data arrayData{};
            while (!exit_3) {
                int user_choice_3;
                puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
                cin >> user_choice_3;
                if (user_choice_3 == 1 && !sorted1_3) {
                    int temp_array[N3];
                    for (int i : temp_array) {
                        temp_array[i] = array3[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data1 = choicesSort(temp_array, N3);
                    puts("сортировка упорядоченного массива");
                    arrayData.data2 = choicesSort(temp_array, N3);
                    sort(temp_array[0], temp_array[N3 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data3 = choicesSort(temp_array, N3);
                    sorted1_3 = true;
                } else if (user_choice_3 == 2 && !sorted2_3) {
                    int temp_array[N3];
                    for (int i : temp_array) {
                        temp_array[i] = array3[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data4 = insertionSort(temp_array, N3);
                    puts("сортировка упорядоченного массива");
                    arrayData.data5 = insertionSort(temp_array, N3);
                    sort(temp_array[0], temp_array[N3 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data6 = insertionSort(temp_array, N3);
                    sorted2_3 = true;
                } else if (user_choice_3 == 3 && !sorted3_3) {
                    int temp_array[N3];
                    for (int i : temp_array) {
                        temp_array[i] = array3[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data7 = shellSort(temp_array, N3);
                    puts("сортировка упорядоченного массива");
                    arrayData.data8 = shellSort(temp_array, N3);
                    sort(temp_array[0], temp_array[N3 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data9 = shellSort(temp_array, N3);
                    sorted3_3 = true;
                } else if (user_choice_3 == 4 && !sorted4_3) {
                    int temp_array[N3];
                    for (int i : temp_array) {
                        temp_array[i] = array3[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data10 = mergeSort(temp_array, 0, N3 - 1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data11 = mergeSort(temp_array, 0, N3 - 1);
                    sort(temp_array[0], temp_array[N3 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data12 = mergeSort(temp_array, 0, N3 - 1);
                    sorted4_3 = true;
                } else if (sorted1_3 && sorted2_3 && sorted3_3 && sorted4_3) {
                    exit_3 = true;
                }
            }
            sorted3 = true;
            totalData.data3 = arrayData;
        } else puts("сортировка N3 уже была протестирована");
        if (user_choice == 4 && !sorted4) {
            bool exit_4 = false;
            bool sorted1_4 = false, sorted2_4 = false, sorted3_4 = false, sorted4_4 = false;
            array_data arrayData{};
            while (!exit_4) {
                int user_choice_4;
                puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
                cin >> user_choice_4;
                if (user_choice_4 == 1 && !sorted1_4) {
                    int temp_array[N4];
                    for (int i : temp_array) {
                        temp_array[i] = array4[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data1 = choicesSort(temp_array, N4);
                    puts("сортировка упорядоченного массива");
                    arrayData.data2 = choicesSort(temp_array, N4);
                    sort(temp_array[0], temp_array[N4 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data3 = choicesSort(temp_array, N4);
                    sorted1_4 = true;
                } else if (user_choice_4 == 2 && !sorted2_4) {
                    int temp_array[N4];
                    for (int i : temp_array) {
                        temp_array[i] = array4[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data4 = insertionSort(temp_array, N4);
                    puts("сортировка упорядоченного массива");
                    arrayData.data5 = insertionSort(temp_array, N4);
                    sort(temp_array[0], temp_array[N4 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data6 = insertionSort(temp_array, N4);
                    sorted2_4 = true;
                } else if (user_choice_4 == 3 && !sorted3_4) {
                    int temp_array[N4];
                    for (int i : temp_array) {
                        temp_array[i] = array4[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data7 = shellSort(temp_array, N4);
                    puts("сортировка упорядоченного массива");
                    arrayData.data8 = shellSort(temp_array, N4);
                    sort(temp_array[0], temp_array[N4 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data9 = shellSort(temp_array, N4);
                    sorted3_4 = true;
                } else if (user_choice_4 == 4 && !sorted4_4) {
                    int temp_array[N4];
                    for (int i : temp_array) {
                        temp_array[i] = array4[i];
                    }
                    puts("сортировка неупорядоченного массива");
                    arrayData.data10 = mergeSort(temp_array, 0, N4 - 1);
                    puts("сортировка упорядоченного массива");
                    arrayData.data11 = mergeSort(temp_array, 0, N4 - 1);
                    sort(temp_array[0], temp_array[N4 - 1]);
                    puts("сортировка упорядоченного в обратном порядке массива");
                    arrayData.data12 = mergeSort(temp_array, 0, N4 - 1);
                    sorted4_4 = true;
                } else if (sorted1_4 && sorted2_4 && sorted3_4 && sorted4_4) {
                    exit_4 = true;
                }
            }
            sorted4 = true;
            totalData.data4 = arrayData;
        } else puts("сортировка N4 уже была протестирована");
        if (sorted1 && sorted2 && sorted3 && sorted4) {
            exit = true;
        }
    }
}

void results(total_data totalData) {

}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int array1[N1], array2[N2], array3[N3], array4[N4];
    fill_arrays(array1, array2, array3, array4);
    total_data totalData{};
    totalData = sort_arrays(array1, array2, array3, array4, totalData);
    results(totalData);
}
