#include <iostream>
#include <conio.h>
#include <windows.h>
#include "src/Deque.h"

using namespace std;

int main() {
    Deque deque;
    while (!_kbhit()) {
        if (rand() % 100 + 1 <= rand() % 100 + 1) {
            int rand_number = rand();
            deque.InRight(rand_number);
            cout << "the message came from the other program: " << rand_number << "\n";
            Sleep(1000);
        }
        if (rand() % 100 + 1 <= rand() % 100 + 1) {
            int rand_number = rand();
            deque.InLeft(rand_number);
            cout << "the message came from the user: " << rand_number << "\n";
            Sleep(1000);
        }
        if (!deque.Empty()) {
            int extracted_elem = deque.OutRight();
            cout << "passed to the processing program: " << extracted_elem << "\n";
            Sleep(1000);
        }
    }
}
