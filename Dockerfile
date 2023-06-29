FROM ubuntu

# Mashonkin Ivan 221-331

RUN apt-get update
#RUN apt-get install gcc -y
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir MyProj_221_331_Mashonkin
WORKDIR /root/MyProj_221_331_Mashonkin/
COPY *.cpp /root/MyProj_221_331_Mashonkin/
COPY *.h /root/MyProj_221_331_Mashonkin/
COPY *.pro /root/MyProj_221_331_Mashonkin/
COPY *.txt /root/MyProj_221_331_Mashonkin/
COPY * /root/MyProj_221_331_Mashonkin/

RUN qmake my_Program.pro
RUN make

ENTRYPOINT ["./my_Program"]

# docker run -it --rm -p 33333:33333 --name exam my_program