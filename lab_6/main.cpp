#include <iostream>
#include <vector>
#include "cstdio"
#include "src/String.h"

using namespace std;

int main() {
    system("chcp 65001");
    String* array[6] = {nullptr};
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
            } else if (user_choice_1 == 2 && called) {
                int num;
                puts("введите номер элемента:\n");
                cin >> num;
                int user_choice_1_2;
                puts("выберите тип: 1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка");
                cin >> user_choice_1_2;
                if (user_choice_1_2 == 1) {
                    char temp_array[100];
                    puts("начальное значение:");
                    fflush(stdin);
                    gets(temp_array);
                    array[num - 1] = new String(temp_array);
                } else if (user_choice_1_2 == 2) {
                    char temp_array[100];
                    puts("начальное значение:");
                    fflush(stdin);
                    gets(temp_array);
                    array[num - 1] = new StringId(temp_array);
                } else if (user_choice_1_2 == 3) {
                    char temp_array[100];
                    puts("начальное значение:");
                    fflush(stdin);
                    gets(temp_array);
                    array[num - 1] = new StringBin(temp_array);
                }
            }
        } else if (user_choice == 2) {
            int user_choice_2;
            puts("1 - Строка, 2 - Строка-идентификатор, 3 - Битовая строка, 4 - Задать операнды");
            cin >> user_choice_2;
            static bool called;
            int test_num;
            if (user_choice_2 == 1 && called) {
                int user_choice_2_1;
                puts("1 - длина строки, 2 - перегрузка оператора \'=\'");
                cin >> user_choice_2_1;
                if (user_choice_2_1 == 1) {
                    printf("длина строки: %d\n", array[test_num]->data_length());
                } else if (user_choice_2_1 == 2) {
                    char test_string[100];
                    *array[test_num] = gets(test_string);
                }
            } else if (user_choice_2 == 2 && called) {
                int user_choice_2_2;
                puts("1 - перегрузка оператора \'=\', 2 - первое вхождение символа, 3 - перевод в нижний регистр, 4 - перегрузка оператора \'-\'");
                cin >> user_choice_2_2;
                if (user_choice_2_2 == 1) {
                    char test_string[100];
                    *array[test_num] = gets(test_string);
                } else if (user_choice_2_2 == 2) {
                    String* virtualCall = array[test_num];
                    auto* childCall = (StringId*) virtualCall;
                    char symbol;
                    puts("введите символ");
                    cin >> symbol;
                    printf("первое вхождение введённого символа: %d", childCall->first_occurrence(symbol));
                } else if (user_choice_2_2 == 3) {
                    String* virtualCall = array[test_num];
                    auto* childCall = (StringId*) virtualCall;
                    childCall->to_low();
                } else if (user_choice_2_2 == 4) {
                    String* virtualCall = array[test_num];
                    auto* childCall = (StringId*) virtualCall;
                    char string[20];
                    puts("введите строку:");
                    fflush(stdin);
                    gets(string);
                    *childCall - string;
                }
            } else if (user_choice_2 == 3 && called) {
                int user_choice_2_3;
                puts("1 - перегрузка оператора \'=\', 2 - инвертирование числа, 3 - перегрузка оператора \'-\'");
                cin >> user_choice_2_3;
                if (user_choice_2_3 == 1) {
                    char test_string[100];
                    *array[test_num] = gets(test_string);
                } else if (user_choice_2_3 == 2) {
                    String* virtualCall = array[test_num];
                    auto* childCall = (StringBin*) virtualCall;
                    childCall->Inversion();
                } else if (user_choice_2_3 == 3) {
                    String* virtualCall = array[test_num];
                    auto* childCall = (StringBin*) virtualCall;
                    char string[20];
                    puts("введите битовую строку:");
                    fflush(stdin);
                    gets(string);
                    *childCall - string;
                }
            } else if (user_choice_2 == 4) {
                called = true;
                puts("введите номер объекта, над которым будет производиться тестирование:");
                cin >> test_num;
            }
        } else if (user_choice == 3) {
            exit = true;
        }
    }
    return 0;
}
