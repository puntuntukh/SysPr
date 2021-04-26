FROM ubuntu
COPY 1program.cpp 2program.cpp text /
RUN apt-get update -y
RUN apt-get install -y build-essential
RUN g++ 1program.cpp -o 1program
RUN g++ 2program.cpp -o 2program
CMD ./1program text 4
