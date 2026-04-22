FROM python:alpine
FROM alpine:3.14

RUN apk add py3-flask
RUN apk add build-base
RUN apk add cmake make

RUN addgroup -g 2000 tp2024user \
    && adduser -u 2000 -G tp2024user -s /bin/sh -D tp2024user

USER tp2024user

WORKDIR /opt/techprog

COPY . .

RUN sh ./build.sh

CMD [ "python3" , "app.py" , "--port" , "8898" , "--host" , "0.0.0.0" ]
