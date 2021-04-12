#include <iostream>
#include "src/Queue.h"

#define array_size 10

using namespace std;

template<class T>
void array_sort_even(T* array) {
    T* temp_array = new T[array_size / 2];
    for (int i = 0, k = 0; i < array_size; i = i + 2, ++k) {
        temp_array[k] = array[i];
    }
    for (int i = 0; i < array_size / 2; ++i) {
        for (int k = 0; k < array_size / 2; ++k) {
            if (temp_array[k] > temp_array[k + 1]) {
                T temp = temp_array[k];
                temp_array[k + 1] = temp_array[k];
                temp_array[k] = temp;
            }
        }
    }
    for (int i = 0, k = 0; i < array_size; i = i + 2, ++k) {
        array[i] = temp_array[k];
    }
    delete[] temp_array;
}

int main() {
    int user_choice;
    puts("1 - function template, 2 - class template");
    cin >> user_choice;
    while (cin.fail() == 1 || user_choice > 2) {
        cout << "попробуйте ещё раз\n";
        cin.clear();
        cin.sync();
        cin >> user_choice;
    }
    if (user_choice == 1) {
        int user_choice_1;
        puts("1 - long, 2 - unsigned char");
        cin >> user_choice_1;
        while (cin.fail() == 1 || user_choice > 2) {
            cout << "попробуйте ещё раз\n";
            cin.clear();
            cin.sync();
            cin >> user_choice_1;
        }
        if (user_choice_1 == 1) {
            long array[array_size];
            puts("наполните массив:");
            for (long& i : array) {
                cin >> i;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> i;
                }
            }
            array_sort_even(array);
            puts("отсортированный массив:");
            for (long& i : array) {
                cout << i;
            }
        } else if (user_choice_1 == 2) {
            unsigned char array[array_size];
            puts("наполните массив:");
            for (unsigned char& i : array) {
                cin >> i;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> i;
                }
            }
            array_sort_even(array);
            puts("отсортированный массив:");
            for (unsigned char& i : array) {
                cout << i;
            }
        }
    } else if (user_choice == 2) {
        int user_choice_2;
        puts("1 - long, 2 - unsigned char");
        cin >> user_choice_2;
        while (cin.fail() == 1 || user_choice > 2) {
            cout << "попробуйте ещё раз\n";
            cin.clear();
            cin.sync();
            cin >> user_choice_2;
        }
        if (user_choice_2 == 1) {
            Queue<long> object(array_size);
            int user_choice_2_1;
            puts("1 - Empty, 2 - Full, 3 - Front, 4 - EnQueue, 5 - DeQueue");
            cin >> user_choice_2_1;
            while (cin.fail() == 1 || user_choice > 5) {
                cout << "попробуйте ещё раз\n";
                cin.clear();
                cin.sync();
                cin >> user_choice_2_1;
            }
            if (user_choice_2_1 == 1) {
                if (object.Empty()) {
                    puts("очередь пустая");
                } else {
                    puts("очередь не пустая");
                }
            } else if (user_choice_2_1 == 2) {
                if (object.Full()) {
                    puts("очередь полная");
                } else {
                    puts("очередь не полная");
                }
            } else if (user_choice_2_1 == 3) {
                printf("передний элемент: %l\n", object.Front());
            } else if (user_choice_2_1 == 4) {
                int num_of_elements;
                puts("введите количество элементов:");
                cin >> num_of_elements;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> num_of_elements;
                }
                for (int i = 0; i < num_of_elements; ++i) {
                    long temp;
                    puts("введите элемент:");
                    cin >> temp;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> temp;
                    }
                    if (object.EnQueue(temp)) {
                        puts("элемент добавлен в очередь");
                    } else {
                        puts("очередь заполнена");
                    }
                }
            } else if (user_choice_2_1 == 5) {
                int num_of_elements;
                puts("введите количество элементов:");
                cin >> num_of_elements;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> num_of_elements;
                }
                puts("извлечённые элементы:");
                for (int i = 0; i < num_of_elements; ++i) {
                    printf("%l\n", object.DeQueue());
                }
            }
        } else if (user_choice_2 == 2) {
            Queue<unsigned char> object(array_size);
            int user_choice_2_2;
            puts("1 - Empty, 2 - Full, 3 - Front, 4 - EnQueue, 5 - DeQueue");
            cin >> user_choice_2_2;
            while (cin.fail() == 1 || user_choice > 5) {
                cout << "попробуйте ещё раз\n";
                cin.clear();
                cin.sync();
                cin >> user_choice_2_2;
            }
            if (user_choice_2_2 == 1) {
                if (object.Empty()) {
                    puts("очередь пустая");
                } else {
                    puts("очередь не пустая");
                }
            } else if (user_choice_2_2 == 2) {
                if (object.Full()) {
                    puts("очередь полная");
                } else {
                    puts("очередь не полная");
                }
            } else if (user_choice_2_2 == 3) {
                printf("передний элемент: %uc\n", object.Front());
            } else if (user_choice_2_2 == 4) {
                int num_of_elements;
                puts("введите количество элементов:");
                cin >> num_of_elements;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> num_of_elements;
                }
                for (int i = 0; i < num_of_elements; ++i) {
                    long temp;
                    puts("введите элемент:");
                    cin >> temp;
                    while (cin.fail() == 1) {
                        cout << "попробуйте ещё раз\n";
                        cin.clear();
                        cin.sync();
                        cin >> temp;
                    }
                    if (object.EnQueue(temp)) {
                        puts("элемент добавлен в очередь");
                    } else {
                        puts("очередь заполнена");
                    }
                }
            } else if (user_choice_2_2 == 5) {
                int num_of_elements;
                puts("введите количество элементов:");
                cin >> num_of_elements;
                while (cin.fail() == 1) {
                    cout << "попробуйте ещё раз\n";
                    cin.clear();
                    cin.sync();
                    cin >> num_of_elements;
                }
                puts("извлечённые элементы:");
                for (int i = 0; i < num_of_elements; ++i) {
                    printf("%uc\n", object.DeQueue());
                }
            }
        }
    }
}
