#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <winsock2.h>

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
        char* szBuffer[6];

        // пакет протокола
        const char* array[6];
        array[0] = "0";
        array[1] = "0";
        array[2] = "1";
        array[3] = "0";
        array[4] = "65";
        array[5] = "0";

        // отправка на сервер и получение ответа
        for (auto & i : array) {
            send(sock, i, strlen(i) + sizeof(char), 0);
        }

        for (auto & i : szBuffer) {
            recv(sock, i, 512, 6);
        }

        printf("Message from server: %s\n", szBuffer[5]);

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
