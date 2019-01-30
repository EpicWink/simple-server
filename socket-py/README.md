# Simple server - Socket (Python)
Implement the simple server with the `socket` standard library in Python.

## Building
```bash
docker build . -t simpleserver
```

## Running
```bash
docker run -it -p 5000:5000 simpleserver
```

Optional configuration environment variables (use `-e` flag in `docker run`):
* `RECV_BUFSIZE` - buffer size in request recieve, default: 4096
