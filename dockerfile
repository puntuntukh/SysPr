FROM ubuntu
COPY 1program.cpp 2program.cpp text /
RUN apt-get update -y
RUN apt-get install -y build-essential
RUN g++ thread.cpp -lpthread -o thread
CMD ./1program text 4