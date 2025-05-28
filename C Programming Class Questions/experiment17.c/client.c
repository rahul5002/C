#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() 
{
    int sock = 0;
    struct sockaddr_in server_address;
    char *message = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("Socket creation error");
        return -1;
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Converting address
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) 
    {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    {
        perror("Connection failed");
        return -1;
    }

    // Sending message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    // Reading response from server
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s\n", buffer);

    close(sock);
    return 0;
}
