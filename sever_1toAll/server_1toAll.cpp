#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread>
#include <string>
#include <list>
using namespace std;

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define SERVER_DEFAULT_ADDR "127.0.0.1"
const int DEFAULT_PORT = 12057;

time_t current;
char timebuff[26];

SOCKET ListenSocket = INVALID_SOCKET;
SOCKET ClientSocket = INVALID_SOCKET;
list<SOCKET> ClientList;

bool selfClosed = false;
string INFO = "[sever] ";

void recvmsg() {
    int iResult, iSendResult;
    SOCKADDR_IN server;
    char recvbuf[DEFAULT_BUFLEN];
    memset(recvbuf, 0, DEFAULT_BUFLEN);
    int recvbuflen = DEFAULT_BUFLEN;
    while (true) {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, NULL);
        if (recvbuf[0] == '0') {
            cout << "The client has closed the diolague!\n" << INFO;
            ClientList.remove(ClientSocket);
            closesocket(ClientSocket);
            return;
        }
        cout << "Message form client: " << recvbuf << endl << INFO;

        // broadcast
        for (auto it = ClientList.begin(); it != ClientList.end(); ++it) {
            send(*it, recvbuf, strlen(recvbuf) + sizeof(char), NULL);
        }
    }
}

int main() {

    WSADATA wsaData;
    int iResult;
    struct sockaddr_in sockAddr;

    current = time(&current);
    ctime_s(timebuff, sizeof timebuff, &current);
    printf("%s", timebuff);

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Sever Info
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(SERVER_DEFAULT_ADDR);
    sockAddr.sin_port = htons(DEFAULT_PORT);

    // Binding a Socket
    iResult = bind(ListenSocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    cout << INFO << "Setup successfully\n" << INFO;

    // Listen
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
    }
    cout << "Listening on a Socket...\n" << INFO;

    // Accept
    while (true) {
        // Accept a Connection
        SOCKADDR clntAddr;
        int nSize = sizeof(SOCKADDR);
        ClientSocket = accept(ListenSocket, (SOCKADDR*)&clntAddr, &nSize);
        if (ClientSocket != INVALID_SOCKET) {
            // Receive and send
            ClientList.push_back(ClientSocket);
            thread t2(recvmsg);
            t2.detach();
        }
    }

    // close
    closesocket(ClientSocket);
    closesocket(ListenSocket);
    WSACleanup();
    system("pause");
    return 0;
}