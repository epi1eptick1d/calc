FROM debian:latest

RUN apt-get update && \
    apt-get install -y gcc libcunit1-dev && \
    apt-get clean

WORKDIR /app

COPY . .

RUN gcc test.c -o calc -l cunit

CMD ["./calc"]
