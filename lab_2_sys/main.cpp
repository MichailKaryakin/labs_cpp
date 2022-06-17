#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <winsock2.h>

using namespace std;

struct packet {
    short transactionId;
    short protocolId;
    short length;
    char unitId;
    char functionCode;
    char data[22];
};

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
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 1;
        Packet.unitId = 0;
        Packet.functionCode = 65;
        Packet.data[0] = 'c';
        Packet.data[1] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 8);

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
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 7;
        Packet.unitId = 0;
        Packet.functionCode = 67;
        Packet.data[0] = 'M';
        Packet.data[1] = 'i';
        Packet.data[2] = 'c';
        Packet.data[3] = 'h';
        Packet.data[4] = 'a';
        Packet.data[5] = 'i';
        Packet.data[6] = 'l';
        Packet.data[7] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        printf("Message from server: %s\n", szBuffer + 8);

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

        // пакет протокола
        packet Packet{};
        Packet.transactionId = 0;
        Packet.protocolId = 0;
        Packet.length = 2;
        Packet.unitId = 0;
        Packet.functionCode = 69;
        Packet.data[0] = firstNumber;
        Packet.data[1] = secondNumber;
        Packet.data[2] = '\0';

        // отправка на сервер и получение ответа
        send(sock, (char*) &Packet, 30, 0);
        recv(sock, szBuffer, 30, 0);

        // вывод сообщения с сервера
        if (szBuffer[7] == 'E') {
            printf("Message from server: %d\n", *(szBuffer + 8));
        } else {
            printf("Message from server: %s\n", szBuffer + 8);
        }

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }
}
