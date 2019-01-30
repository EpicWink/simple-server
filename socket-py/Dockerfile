FROM alpine
RUN apk update && apk upgrade && apk add python3
WORKDIR /root/
ADD server.py /root/
CMD ["python3", "server.py"]
EXPOSE 5000
