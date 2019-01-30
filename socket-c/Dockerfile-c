FROM alpine
RUN apk update && apk upgrade
WORKDIR /root/
ADD server.c /root/
RUN apk update && apk add gcc libc-dev binutils && gcc server.c -o server && apk del gcc binutils
CMD ["./server"]
EXPOSE 5000
