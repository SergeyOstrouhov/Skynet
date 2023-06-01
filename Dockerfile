FROM ubuntu 18
LABEL  maintainer="Ostroukhov"
ENV TZ=Europe/Moscow  
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
RUN apt-get update  
RUN apt-get install qt5-default -y  
RUN apt-get install qtbase5-dev -y  
RUN apt-get install qt5-qmake  
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir Ostroukhov
WORKDIR /root/Ostroukhov/
COPY *.cpp /root/Ostroukhov/
COPY *.h /root/Ostroukhov/
COPY *.pro /root/Ostroukhov/

RUN qmake exam.pro
RUN make

ENTRYPOINT ["./exam"]