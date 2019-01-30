FROM ubuntu
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y python3-pip && \
    pip3 install flask && \
    rm -rf /var/lib/apt/lists/*
WORKDIR /root/
ENV FLASK_APP=server.py
ENV FLASK_ENV=development
ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8
EXPOSE 5000
CMD ["flask", "run", "-h", "0.0.0.0", "-p", "5000", "--no-reload", "--no-debugger", "--without-threads"]
ADD server.py /root/
