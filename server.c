#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

	// Listen for incoming connections
	if (listen(server_fd, 3) < 0) {
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connection
    if ((new_socket = accept(server_fd, NULL, NULL)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communication loop
    while (1) {
        valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected\n");
            break;
        }
        printf("Client: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));

        // Server sends a message to the client
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

