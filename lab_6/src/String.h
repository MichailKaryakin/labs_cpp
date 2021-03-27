#pragma once

#include <cstring>
#include <iostream>
#include <cctype>

class String {
protected:
    int length;
    char* data;
public:
    String() {
        this->length = 0;
        this->data = nullptr;
    }

    explicit String(char* str) {
        this->length = strlen(str);
        this->data = new char[this->length];
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = str[i];
        }
        this->data[this->length] = '\0';
    }

    explicit String(char symbol) {
        this->length = 1;
        this->data = new char[2];
        this->data[0] = symbol;
        this->data[this->length] = '\0';
    }

    String(const String& obj) {
        this->length = obj.length;
        this->data = new char[obj.length];
        for (int i = 0; i < obj.length; ++i) {
            this->data[i] = obj.data[i];
        }
        this->data[obj.length] = '\0';
    }

    ~String() {
        delete[] this->data;
    }

    int data_length() const {
        return this->length;
    }

    virtual String& operator=(char* str) {
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
    explicit StringId(char* str) : String(str) {
        if (!isId(str)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringId(const StringId& obj) : String(obj) {
        if (!isId(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    int first_occurrence(const char* symbol) {
        int i = 0;
        while (this->data[i] != *symbol) {
            i++;
        }
        return i;
    }

    void StringId_tolower() {
        for (int i = 0; i < this->length; ++i) {
            this->data[i] = tolower(this->data[i]);
        }
    }

    StringId& operator-(const char* str) {
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
private:
    static bool isBin(char* str) {
        for (int i = 0; i < strlen(str); ++i) {
            if ((str[i] - 48) != 0 && (str[i] - 48) != 1) {
                return false;
            }
        }
        return true;
    };
public:
    explicit StringBin(char* str) : String() {
        if (isBin(this->data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    StringBin(const StringBin& obj) : String(obj) {
        if (!isBin(obj.data)) {
            this->length = 0;
            this->data = nullptr;
        }
    }

    void Inversion() {
        int current_symbol_index = 0;
        while (current_symbol_index + 1 <= this->length / 2) {
            char temp = this->data[current_symbol_index];
            this->data[current_symbol_index] = this->data[this->length - current_symbol_index + 1];
            this->data[this->length - current_symbol_index + 1] = temp;
        }
    }

    StringBin& operator-(char* str) {

    }

    StringBin& operator=(char* str) override {
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
