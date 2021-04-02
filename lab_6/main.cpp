#include <iostream>
#include "src/String.h"

using namespace std;

int main() {
    system("chcp 65001");
    String* array;
    array = (String*) malloc(6 * sizeof(String));
    static int number_of_elements;
    bool exit = false;
    while (!exit) {
        int user_choice;
        puts("1 - Инициализация, 2 - Тестирование, 3 - Выход\n");
        cin >> user_choice;
        if (user_choice == 1) {
            static bool called;
            int user_choice_1;
            puts("1 - Число элементов, 2 - Начальное значение\n");
            cin >> user_choice_1;
            if (user_choice_1 == 1 && !called) {
                puts("Введите число элементов в массиве объектов:\n");
                cin >> number_of_elements;
                called = true;
            } else if (user_choice_1 == 2) {
                int num;
                puts("введите номер элемента:\n");
                cin >> num;
                int user_choice_1_2;
                puts("выберите тип: 1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка");
                cin >> user_choice_1_2;
                if (user_choice_1_2 == 1) {
                } else if (user_choice_1_2 == 1) {
                } else if (user_choice_1_2 == 1) {
                }
            }
        } else if (user_choice == 2) {
            int user_choice_2;
            puts("1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка, 4 - Задать операнды");
            cin >> user_choice_2;
            if (user_choice_2 == 1) {

            } else if (user_choice_2 == 2) {

            }
        } else if (user_choice == 3) {
            delete[] array;
            exit = true;
        }
    }
    return 0;
}
