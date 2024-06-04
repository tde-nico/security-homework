FROM ubuntu:22.04

RUN apt-get update && \
	apt-get install -y socat

RUN useradd -d /home/chall/ -m -p chall -s /bin/bash chall
RUN echo "chall:chall" | chpasswd

COPY ./remote_login /home/chall/remote_login
COPY ./flag.txt /home/chall/flag.txt

RUN chmod +x /home/chall/remote_login

USER chall

WORKDIR /home/chall

EXPOSE 1337

ENTRYPOINT [ "socat", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:./remote_login" ]
