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
        sockaddr_in sockAddr{};
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
        string defaultResponse = "Invalid Function Code!";
        char* szBuffer[6];
        SOCKET clientSock;

        // Пакет протокола
        const char* array[6];
        array[0] = "0";
        array[1] = "0";
        array[2] = "23";
        array[3] = "0";
        array[4] = "65";
        array[5] = defaultResponse.c_str();

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            recv(clientSock, szBuffer[0], 512, 0);
            recv(clientSock, szBuffer[1], 512, 0);
            recv(clientSock, szBuffer[2], 512, 0);

            if (!strcmp((szBuffer[0]), "0")) {
                array[2] = "19";
                array[5] = "Server is working!";
                puts("hui");
            }
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
