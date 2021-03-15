FROM lab2
COPY hello.s .
RUN chmod ugo+x hello.s
RUN apt-get update -y
RUN apt-get install -y build-essential
CMD ./hello.s