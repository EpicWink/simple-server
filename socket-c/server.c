#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char** argv) {
    int sock_fd, conn_fd;
    struct sockaddr_in addr;
    int opt = 1;
    int addrlen = sizeof(addr);
    char buffer[4096] = {0};
    const char *resp_str = "HTTP/1.0 200 OK\r\nContent-Type: text/plain; charset=utf-8\r\nContent-Length: 2\r\nServer: spam/0.1\r\n\r\nHi";
    int port = 5000;

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        fprintf(stderr, "Error: failed to initialise server socket\n");
        exit(1);
    }

    // Configure socket
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        fprintf(stderr, "Error: failed to configure server socket\n");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    // Bind socket
    if (bind(sock_fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error: failed to bind server socket to port %d\n", port);
        exit(1);
    }
    if (listen(sock_fd, 3) < 0) {
        fprintf(stderr, "Error: failed to start listening with server socket\n");
        exit(1);
    }
    printf("Started listening on port %d\n", port);

    // Accept connection
    if ((conn_fd = accept(sock_fd, (struct sockaddr *) &addr, (socklen_t*) &addrlen)) < 0) {
        fprintf(stderr, "Error: failed to accept connections with server socket\n");
        exit(1);
    }
    fprintf(
        stderr,
        "New connection from: %d.%d.%d.%d:%d\n",
        addr.sin_addr.s_addr % 256,
        (addr.sin_addr.s_addr >> 8) % 256,
        (addr.sin_addr.s_addr >> 16) % 256,
        (addr.sin_addr.s_addr >> 24) % 256,
        addr.sin_port);

    // Recieve request
    if (recv(conn_fd, buffer, 4096, 0) < 0) {
        fprintf(stderr, "Error: failed to recieve request from connection\n");
        exit(1);
    }
    fprintf(stderr, "Request:\n%s\n", buffer);

    // Send response
    if (send(conn_fd, resp_str, strlen(resp_str), 0) < 0) {
        fprintf(stderr, "Error: failed to send response to connection\n");
        exit(1);
    }
    fprintf(stderr, "Response:\n%s\n", resp_str);

    // Clean up
    if (shutdown(conn_fd, SHUT_RDWR) < 0) {
        fprintf(stderr, "Error: failed to shutdown connection\n");
        exit(1);
    }
    if (shutdown(sock_fd, SHUT_RDWR) < 0) {
        fprintf(stderr, "Error: failed to shutdown server socket\n");
        exit(1);
    }

    return 0;
}
