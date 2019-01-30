import os
import socket
import logging as lg

lg.basicConfig(level=lg.DEBUG, format="%(asctime)s [%(levelname)8s] %(name)s: %(message)s")
log = lg.getLogger()

bufsize = int(os.environ.get("RECV_BUFSIZE", 4096))
port = int(os.environ.get("SERVER_PORT", 5000))
host = "0.0.0.0"
response_header_str_fmt = (
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/plain; charset=utf-8\r\n"
    "Content-Length: %d\r\n"
    "Server: spam/0.1\r\n\r\n")

with socket.socket() as sock:
    sock.bind((host, port))
    sock.listen()
    log.info("Server started on: %s:%s" % (host, port))

    while True:
        conn, addr = sock.accept()
        log.info("New connection from: %s:%s" % addr)

        with conn:
            request_str = conn.recv(bufsize).decode()
            log.debug("Request:\n%s" % request_str)

            response_body_str = request_str.replace("\r\n", "; ").replace("\n", "; ")
            response_header_str = response_header_str_fmt % len(response_body_str)
            response_str = response_header_str + response_body_str
            log.debug("Response:\n%s" % response_str)
            conn.send(response_str.encode())
