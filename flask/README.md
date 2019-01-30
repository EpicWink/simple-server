# Simple server - Flask
Implement the simple server with `flask` in Python.

## Building
Build the Ubuntu server image
```bash
docker build . -t simpleserver
```

Build the Alpine server image
```bash
docker build . -t simpleserver -f Dockerfile-alpine
```

## Running
```bash
docker run -it -p 5000:5000 simpleserver
```
