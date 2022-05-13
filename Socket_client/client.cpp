#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread> 
#include <string>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment(lib, "ws2_32.lib")  
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;

#define DEFAULT_BUFLEN 512
#define CLIENT_DEFAULT_ADDR "127.0.0.1"
#define SERVER_DEFAULT_ADDR "127.0.0.1"
const int SEVER_DEFAULT_PORT = 12057;
const int CLIENT_DEFAULT_PORT = 12345;
int clntPort;

SOCKET ConnectSocket = INVALID_SOCKET;
string INFO = "[client:" + to_string(clntPort) + "] ";
bool otherClosed = false;
bool selfClosed = false;

void receiveMsg() {
    int iResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    memset(recvbuf, 0, DEFAULT_BUFLEN);
    while (true) {
        recv(ConnectSocket, recvbuf, recvbuflen, NULL);
        
        cout << "Message: " << recvbuf << endl << INFO;
    }
}

void sendMsg() {
    int iResult;
    char* sendbuf = new char[DEFAULT_BUFLEN];
    memset(sendbuf, 0, DEFAULT_BUFLEN);
    while (true) {
        char* s = new char[50];
        string ss;
        getline(cin, ss);
        strcpy(s, ss.c_str());
        const char* str = s;
        if (s[0] == '0') {
            if (otherClosed == true) {
                printf("You have closed the diolague!");
                return;
            }
            send(ConnectSocket, str, strlen(str) + sizeof(char), NULL);
            printf("You have closed the diolague!");
            selfClosed = true;
            break;
        }
        send(ConnectSocket, str, strlen(str) + sizeof(char), NULL);
        cout << INFO;
    }
}

int main(int argc, char** argv) {

    int iResult;
    time_t current;
    char timeBuff[26];
    WSADATA wsaData;
    string clientPort;
    struct sockaddr_in sockAddr;
   
    system("mode con cols=60 lines=20");

    // Validate the parameters
    if (argc != 2) 
        clntPort = CLIENT_DEFAULT_PORT;
    else {
        clntPort = atoi(argv[1]);
    }

    INFO = "[client:" + to_string(clntPort) + "] ";

    // Print time
    current = time(&current);
    ctime_s(timeBuff, sizeof timeBuff, &current);
    cout << timeBuff;

    // StartUp
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); 
    if (ConnectSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    
    // Client Info
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(CLIENT_DEFAULT_ADDR);
    sockAddr.sin_port = htons(clntPort);

    // Binding a Socket
    iResult = bind(ConnectSocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    cout << INFO << "Setup successfully\n";

    // Server Info
    memset(&sockAddr, 0, sizeof(sockAddr));  
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(SERVER_DEFAULT_ADDR);
    sockAddr.sin_port = htons(SEVER_DEFAULT_PORT);

    // Connect to server.
    iResult = connect(ConnectSocket, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR)); 
    if (iResult == SOCKET_ERROR) {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
    }
    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    cout << INFO << "Connect to sever successfully!\n" << INFO;

    // Send and Receive
    thread t1(sendMsg);
    thread t2(receiveMsg);
    t1.join();
    t2.join();
    
    // Close 
    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}