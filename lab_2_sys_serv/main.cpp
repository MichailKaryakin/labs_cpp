#include <winsock2.h>
#include <iostream>

#define offset 48

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
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            printf("work\n");
            recv(clientSock, szBuffer, 30, 0);
            printf("Message:%s\n", szBuffer);

            if (szBuffer[4] == 'A') {
                response = "connection completed";
            }

            unsigned int array[5] = {0, 0, response.length(), 0, 65};
            string container;
            container += to_string(array[0]);
            container += to_string(array[1]);
            container += array[2] + offset;
            container += to_string(array[3]);
            container += array[4];
            container += response;

            send(clientSock, container.c_str(), container.length(), 0);
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }

    if (user_choice == 2) {
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
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            printf("work\n");
            recv(clientSock, szBuffer, 30, 0);
            printf("Message:%s\n", szBuffer);

            if (szBuffer[4] == 'C') {
                response = "Hello, ";
                response += (szBuffer + 5);
            }

            unsigned int array[5] = {0, 0, response.length(), 0, 65};
            string container;
            container += to_string(array[0]);
            container += to_string(array[1]);
            container += array[2] + offset;
            container += to_string(array[3]);
            container += array[4];
            container += response;

            send(clientSock, container.c_str(), container.length(), 0);
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }

    if (user_choice == 3) {
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
        char szBuffer[30] = {0};
        SOCKET clientSock;

        // Отправляем данные клиенту
        while (true) {
            nSize = sizeof(SOCKADDR);
            clientSock = accept(servSock, (SOCKADDR*) &clientAddr, &nSize);

            printf("work\n");
            recv(clientSock, szBuffer, 30, 0);
            printf("Message:%s\n", szBuffer);

            if (szBuffer[4] == 'E') {
                int firstNumber;
                int secondNumber;

                string numbers;
                numbers += (szBuffer + 5);
                string delimiter = " ";
                size_t pos = 0;
                string token;
                while ((pos = numbers.find(delimiter)) != string::npos) {
                    token = numbers.substr(0, pos);
                    firstNumber = stoi(token);
                    numbers.erase(0, pos + delimiter.length());
                }
                secondNumber = stoi(numbers);

                response = "the sum of numbers - " + to_string(firstNumber + secondNumber);
            }

            unsigned int array[5] = {0, 0, response.length(), 0, 65};
            string container;
            container += to_string(array[0]);
            container += to_string(array[1]);
            container += array[2] + offset;
            container += to_string(array[3]);
            container += array[4];
            container += response;

            send(clientSock, container.c_str(), container.length(), 0);
        }

        // Закрываем сокет
        closesocket(clientSock);
        closesocket(servSock);

        // Прекращаем использование DLL
        WSACleanup();

        return 0;
    }
}
