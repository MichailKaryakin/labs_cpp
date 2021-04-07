#pragma once

#include <cstring>
#include <iostream>
#include <cctype>
#include <cmath>

class String {
    static int copy_constr_num_of_calls;
protected:
    int length;
    char* data;
public:
    String() {
        puts("default constructor used");
        this->length = 0;
        this->data = nullptr;
    }

    explicit String(char* str) {
        puts("constructor with string as a parameter used");
        this->length = strlen(str);
        this->data = new char[this->length];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = str[i];
        }
        this->data[this->length] = '\0';
    }

    explicit String(char symbol) {
        puts("constructor with symbol as a parameter used");
        this->length = 1;
        this->data = new char[2];
        this->data[0] = symbol;
        this->data[this->length] = '\0';
    }

    String(const String& obj) {
        printf("copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        this->length = obj.length;
        this->data = new char[obj.length];
        for (int i = 0; i < obj.length; ++i) {
            this->data[i] = obj.data[i];
        }
        this->data[obj.length] = '\0';
    }

    ~String() {
        puts("destructor used");
        delete[] this->data;
    }

    int data_length() const {
        puts("data length method used");
        return this->length;
    }

    virtual String& operator=(char* str) {
        puts("operator \'=\' override");
        this->length = strlen(str);
        this->data = new char[this->length];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = str[i];
        }
        this->data[this->length] = '\0';
        return *this;
    }
};

class StringId : public String {
    static int copy_constr_num_of_calls;
private:
    static bool isId(char* str) {
        if (*str == '\0') return false;
        if (isdigit(*str)) return false;
        for (int i = 1; *str; str++, i++) {
            if (!(*str == '_' || isalnum(*str))) return false;
        }
        return true;
    }

    static void array_shift(char* array, int begin, int end, int shift_count) {
        int i;
        if (shift_count > 0) {
            for (i = end; i >= begin; i--) {
                array[i + shift_count] = array[i];
            }
        }
        if (shift_count < 0) {
            for (i = begin; i <= end; i++) {
                array[i + shift_count] = array[i];
            }
        }
    }

public:
    StringId() : String() {}

    explicit StringId(char* str) : String(str) {
        puts("StringId constructor with string as a parameter used");
        if (!isId(str)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringId(const StringId& obj) : String(obj) {
        printf("StringId copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        if (!isId(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    ~StringId() = default;

    int first_occurrence(const char symbol) {
        puts("StringId first occurrence method used");
        int i = 0;
        while (this->data[i] != symbol) {
            i++;
        }
        return i;
    }

    void to_low() {
        puts("StringId to low method used");
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = tolower(this->data[i]);
        }
    }

    StringId& operator-(const char* str) {
        puts("StringId operator \'-\' override");
        for (int i = 0; i < this->length; ++i) {
            for (int k = 0; k < strlen(str); ++k) {
                if (this->data[i] == str[k]) {
                    array_shift(this->data, i + 1, this->length - 1, -1);
                    i--;
                    break;
                }
            }
        }
        return *this;
    }

    StringId& operator=(char* str) override {
        puts("StringId operator \'=\' override");
        if (isId(str)) {
            this->length = strlen(str);
            this->data = new char[this->length + 1];
            for (int i = 0; i < this->length; ++i) {
                this->data[i] = str[i];
            }
            this->data[this->length] = '\0';
            return *this;
        } else {
            this->length = 0;
            this->data = nullptr;
            return *this;
        }
    }
};

class StringBin : public String {
    static int copy_constr_num_of_calls;
private:
    struct Array {
        int size;
        int cap;
        char* data;
    };

    static Array NewArray(int cap) {
        Array mas{};
        mas.cap = cap;
        mas.size = 0;
        mas.data = (char*) malloc(mas.cap * sizeof(char));
        return mas;
    }

    static void Add(Array* mas, char new_val) {
        mas->size++;
        if (mas->size < mas->cap) {
            mas->data[mas->size] = new_val;
        } else {
            char* new_mas = (char*) malloc((mas->cap * 2) * sizeof(char));
            for (int j = 0; j < mas->size - 1; ++j) {
                new_mas[j] = mas->data[j];
            }
            free(mas->data);
            mas->data = new_mas;
            mas->cap = (int) (mas->cap * 2);
            mas->data[mas->size - 1] = new_val;
        }
    }

    static bool isBin(char* str) {
        for (int i = 0; i < strlen(str); ++i) {
            if ((str[i] - 48) != 0 && (str[i] - 48) != 1) {
                return false;
            }
        }
        return true;
    };

    static char* Invert_Bin(char* str) {
        for (int j = 1; j < strlen(str); ++j) {
            if (str[j] == 48) {
                str[j] = 49;
            } else {
                str[j] = 48;
            }
        }
        return str - 1;
    }

    static char* toStraight(char* str) {
        int i = strlen(str) - 1;
        if (str[i] == 48) {
            int k = i;
            while (str[k] != 49 && k != 0) {
                str[k] = 49;
                --k;
            }
            str[k] = 48;
        } else {
            str[i] = 48;
        }
        return Invert_Bin(str + 1);
    }

    static int toDecimal(char* str) {
        int number = 0;
        int order = 0;
        if (str[0] == 1) {
            str = toStraight(str);
        }
        for (int i = strlen(str) - 1; i > 0; --i) {
            number += (str[i] - 48) * (int) pow(2, order);
            ++order;
        }
        if (str[0] == 1) {
            number = -number;
        }
        return number;
    }

    static void Invert_string(char* str) {
        int current_symbol_index = 0;
        while (current_symbol_index + 1 <= strlen(str) / 2) {
            char temp = str[current_symbol_index];
            str[current_symbol_index] = str[strlen(str) - current_symbol_index + 1];
            str[strlen(str) - current_symbol_index + 1] = temp;
            ++current_symbol_index;
        }
    }

    static char* toBin(int number) {
        Array array = NewArray(5);
        if (number < 0) {
            Add(&array, 49);
        } else {
            Add(&array, 48);
        }
        while (number > 0) {
            Add(&array, number % 2 + 48);
            number /= 2;
        }
        Invert_string(array.data + 1);
        if (array.data[0] == 49) {
            array.data = Invert_Bin(array.data + 1);
            for (int i = array.size - 1; i > 0; --i) {
                if (array.data[i] == 48) {
                    array.data[i] = 49;
                    for (int j = i; j < array.size; ++j) {
                        array.data[j] = 48;
                    }
                    return array.data;
                }
            }
        }
        return array.data;
    }

public:
    StringBin() : String() {}

    explicit StringBin(char* str) : String(str) {
        puts("StringBin constructor with string as a parameter used");
        if (!isBin(this->data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringBin(const StringBin& obj) : String(obj) {
        printf("copy constructor used, number of calls: %d", ++copy_constr_num_of_calls);
        if (!isBin(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    ~StringBin() = default;

    void Inversion() {
        puts("StringBin Inversion method used");
        int current_symbol_index = 0;
        while (current_symbol_index + 1 <= this->length / 2) {
            char temp = this->data[current_symbol_index];
            this->data[current_symbol_index] = this->data[this->length - current_symbol_index + 1];
            this->data[this->length - current_symbol_index + 1] = temp;
            ++current_symbol_index;
        }
    }

    StringBin& operator-(char* str) {
        puts("StringBin operator \'-\' override");
        int first_number = toDecimal(this->data);
        int second_number = toDecimal(str);
        int result_length;
        this->length > strlen(str) ? result_length = this->length : result_length = strlen(str);
        char* result = toBin(first_number - second_number);
        this->length = strlen(result);
        this->data = new char[this->length];
        int i;
        for (i = 0; i < this->length; ++i) {
            this->data[i] = result[i];
        }
        if (this->length < result_length) {
            while (i < result_length) {
                this->data[i] = 48;
                ++i;
            }
            this->length = result_length;
        }
        this->data[this->length] = '\0';
        return *this;
    }

    StringBin& operator=(char* str) override {
        puts("StringBin operator \'=\' override");
        if (isBin(str)) {
            this->length = strlen(str);
            this->data = new char[this->length];
            for (int i = 0; i < this->length; ++i) {
                this->data[i] = str[i];
            }
            this->data[this->length] = '\0';
            return *this;
        } else {
            this->length = 0;
            this->data = nullptr;
            return *this;
        }
    }
};
