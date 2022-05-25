#include <winsock2.h>
#include <iostream>

using namespace std;

int main() {
    int user_choice = 0;
    puts("1 - check connection, 2 - hello name, 3 - sum of two numbers");
    cin >> user_choice;
    if (user_choice == 1) {
        // Инициализируем DLL
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создаем сокет
        SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

        // Привязываем сокет
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr)); // Каждый байт заполняется 0
        sockAddr.sin_family = PF_INET; // Использовать IPv4-адрес
        sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Определенный IP-адрес
        sockAddr.sin_port = htons(502); // Порт
        bind(servSock, (SOCKADDR*) &sockAddr, sizeof(SOCKADDR));

        // Входим в состояние мониторинга
        listen(servSock, 20);

        // Подготовка полей
        SOCKADDR clientAddr;
        int nSize;
        string response = "Invalid Function Code!";
        char szBuffer[30];
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);
            printf("work\n");
            recv(clientSock, szBuffer, 30, 0);
            printf("Message:%s\n", szBuffer);
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }

    if (user_choice == 2) {

    }

    if (user_choice == 3) {

    }
}
