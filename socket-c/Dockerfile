FROM alpine
RUN apk update && apk upgrade
WORKDIR /root/
ADD server.c /root/
RUN apk update && apk add gcc libc-dev && gcc server.c -o server && apk del gcc
CMD ["./server"]
EXPOSE 5000
