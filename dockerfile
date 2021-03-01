FROM lab
COPY sp2.sh .
RUN chmod ugo+x sp2.sh
RUN apt-get update -y
RUN apt-get install -y genisoimage
CMD ./sp2.sh

