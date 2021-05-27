#include <iostream>
#include <fstream>
#include <windows.h>
#include "src/sortings.h"

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
            symbol_count = 0;
            break;
        }
        temp.clear();
    }
    fin.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);
    int array1[N1], array2[N2], array3[N3], array4[N4];
    fill_arrays(array1, array2, array3, array4);
    bool exit = false;
    bool sorted1 = false, sorted2 = false, sorted3 = false, sorted4 = false;
    while (!exit) {
        int user_choice;
        puts("1 - сортировка N1, 2 - сортировка N2, 3 - сортировка N3, 4 - сортировка N4");
        cin >> user_choice;
        if (user_choice == 1 && !sorted1) {
            int temp_array[N1];
            for (int i : temp_array) {
                temp_array[i] = array1[i];
            }
            int user_choice_1;
            puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
            cin >> user_choice_1;
            // сортировка
            sorted1 = true;
        } else puts("сортировка N1 уже была протестирована");
        if (user_choice == 2 && !sorted2) {
            int temp_array[N2];
            for (int i : temp_array) {
                temp_array[i] = array2[i];
            }
            int user_choice_2;
            puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
            cin >> user_choice_2;
            // сортировка
            sorted2 = true;
        } else puts("сортировка N2 уже была протестирована");
        if (user_choice == 3 && !sorted3) {
            int temp_array[N3];
            for (int i : temp_array) {
                temp_array[i] = array3[i];
            }
            int user_choice_3;
            puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
            cin >> user_choice_3;
            // сортировка
            sorted3 = true;
        } else puts("сортировка N3 уже была протестирована");
        if (user_choice == 4 && !sorted4) {
            int temp_array[N4];
            for (int i : temp_array) {
                temp_array[i] = array4[i];
            }
            int user_choice_4;
            puts("1 - сортировка выбором, 2 - сортировка вставками, 3 - сортировка шелла, 4 - сортировка слиянием");
            cin >> user_choice_4;
            // сортировка
            sorted4 = true;
        } else puts("сортировка N4 уже была протестирована");
        if (sorted1 & sorted2 & sorted3 & sorted4) {
            exit = true;
        }
    }

}
