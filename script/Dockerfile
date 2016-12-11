###################################################
# Dockerfile to test the MagicBand Reader Project #
# Based on Ubuntu                                 #
###################################################

FROM ubuntu
MAINTAINER Rift Creations

RUN apt-get update
RUN apt-get install wget -y
RUN apt-get install build-essential -y

RUN mkdir avr

RUN PREFIX=$HOME/avr
RUN export PREFIX

RUN PATH=$PATH:$PREFIX/bin
RUN export PATH

RUN wget "http://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.gz"
RUN gunzip -c binutils-2.27.tar.gz | tar xf -
RUN binutils-2.27/./configure --prefix=$PREFIX --target=avr --disable-nls
RUN make
RUN make install

RUN apt-get install gcc-avr -y
RUN apt-get install avr-libc -y

RUN apt-get install git -y
RUN git clone https://github.com/reuterni/MagicBand.git
RUN cd MagicBand && make
