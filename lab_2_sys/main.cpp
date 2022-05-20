#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <winsock2.h>

using namespace std;

// структура с полями протокола
struct packet {
    int16_t transactionId;
    int16_t protocolId;
    int16_t length;
    int8_t unitId;
    int8_t functionCode;
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

        // заполнение структуры
        packet Packet;
        Packet.transactionId = 0x00;
        Packet.protocolId = 0x00;
        Packet.length = 0x01;
        Packet.unitId = 0x00;
        Packet.functionCode = 65;

        // массив пакета протокола
        char array[30];
        memcpy(array, &Packet.transactionId, 2);
        memcpy(array + 2, &Packet.protocolId, 2);
        memcpy(array + 4, &Packet.length, 2);
        memcpy(array + 6, &Packet.unitId, 2);
        memcpy(array + 8, &Packet.functionCode, 1);
        char str[] = "check";
        memcpy(array + 9, str, strlen(str) + 1);

        // отправка на сервер и получение ответа
        send(sock, array, strlen(array) + 1, 0);

        // закрытие сокета
        closesocket(sock);

        // завершение работы
        WSACleanup();
        system("pause");
        return 0;
    }

    if (user_choice == 2) {

    }

    if (user_choice == 3) {

    }
}
