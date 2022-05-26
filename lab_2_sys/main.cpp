#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <winsock2.h>

#define offset 48

using namespace std;

int main() {
    int user_choice = 0;
    puts("1 - check connection, 2 - hello name, 3 - sum of two numbers");
    cin >> user_choice;

    if (user_choice == 1) {
        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // массив пакета протокола
        char message[] = "d";
        unsigned int messageLength = strlen(message);
        unsigned int array[5] = {0, 0, messageLength, 0, 65};
        string container;
        container += to_string(array[0]);
        container += to_string(array[1]);
        container += array[2] + offset;
        container += to_string(array[3]);
        container += array[4];
        container += message;

        // отправка на сервер и получение ответа
        send(sock, container.c_str(), container.length(), 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 5);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 2) {
        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // массив пакета протокола
        char message[] = "Michail";
        unsigned int messageLength = strlen(message);
        unsigned int array[5] = {0, 0, messageLength, 0, 67};
        string container;
        container += to_string(array[0]);
        container += to_string(array[1]);
        container += array[2] + offset;
        container += to_string(array[3]);
        container += array[4];
        container += message;

        // отправка на сервер и получение ответа
        send(sock, container.c_str(), container.length(), 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 5);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 3) {
        // получение чисел от пользователя
        int firstNumber;
        int secondNumber;
        cout << "enter two numbers: " << endl;
        cin >> firstNumber >> secondNumber;

        // начало работы
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // настройка сокета
        SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        sockaddr_in sockAddr{};
        memset(&sockAddr, 0, sizeof(sockAddr));
        sockAddr.sin_family = PF_INET;
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        sockAddr.sin_port = htons(502);
        connect(sock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // буфер приёма
        char szBuffer[30] = {0};

        // массив пакета протокола
        string message;
        message += to_string(firstNumber);
        message += ' ';
        message += to_string(secondNumber);
        unsigned int array[5] = {0, 0, message.length(), 0, 69};
        string container;
        container += to_string(array[0]);
        container += to_string(array[1]);
        container += array[2] + offset;
        container += to_string(array[3]);
        container += array[4];
        container += message;

        // отправка на сервер и получение ответа
        send(sock, container.c_str(), container.length(), 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 5);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }
}
