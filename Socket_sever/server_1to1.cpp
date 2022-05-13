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
#include <vector>

using namespace std;

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_ADDR "127.0.0.1"
const int DEFAULT_PORT = 12057;

time_t current;
char timebuff[26];

SOCKET ListenSocket = INVALID_SOCKET;
SOCKET ClientSocket = INVALID_SOCKET;

bool otherClosed = false;
bool selfClosed = false;
string INFO = "[sever] ";

void sendmsg() {    
    while (true) {
        char* s = new char[50];
        string ss;
        getline(cin, ss);
        strcpy(s, ss.c_str());
        const char* str = s;

        if (s[0] == '0') {
            if (otherClosed == true) {
                printf("You have closed the diolague!");
                break;
            }
            send(ClientSocket, str, strlen(str) + sizeof(char), NULL);
            printf("You have closed the diolague!");
            selfClosed = true;
            break;
        }
        send(ClientSocket, str, strlen(str) + sizeof(char), NULL);
        cout << INFO;
    }
}

void recvmsg() {              
    while(true) {
        char szBuffer[50] = { "00000000000000000000000" };
        recv(ClientSocket, szBuffer, MAXBYTE, NULL);

        if (szBuffer[0] == '0') {
            if (selfClosed == false) {
                printf("The other has closed the diolague!");
                printf("please print '0' to exit!");
                otherClosed = true;
            }
            send(ClientSocket, "0", strlen("0") + sizeof(char), NULL);
            break;
        }
        cout << "Message form client: " << szBuffer << endl << INFO;
    }
}

int main() {

    WSADATA wsaData;
    int iResult;
    struct sockaddr_in sockAddr;

    system("mode con cols=60 lines=20");

    // Print time
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
    sockAddr.sin_addr.s_addr = inet_addr(DEFAULT_ADDR);
    sockAddr.sin_port = htons(DEFAULT_PORT);

    // Allow Broadcast
    int so_broadcast = TRUE;
    iResult = setsockopt(ClientSocket, SOL_SOCKET, SO_BROADCAST, (char*)&so_broadcast, sizeof(so_broadcast));

    // Binding a Socket
    iResult = bind(ListenSocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR)); 
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    cout << INFO << "Setup successfully\n" << INFO;
    
    // Listening on a Socket
    iResult = listen(ListenSocket, SOMAXCONN); 
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    cout << "Listening on a Socket...\n" << INFO;
    
    // Accept a Connection
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    ClientSocket = accept(ListenSocket, (SOCKADDR*)&clntAddr, &nSize);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Send and Receive
    thread t2(recvmsg);
    thread t1(sendmsg);
    t1.join();
    t2.join();

    //Close
    closesocket(ClientSocket);
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}