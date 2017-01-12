###################################################
# Dockerfile to test the MagicBand Reader Project #
# Based on Ubuntu                                 #
###################################################

FROM ubuntu
MAINTAINER Rift Creations

RUN apt-get update

RUN apt-get install gcc-avr -y
RUN apt-get install avr-libc -y
RUN apt-get install avrdude -y

RUN apt-get install git -y
CMD git clone https://github.com/reuterni/MagicBand.git && cd MagicBand && make && cd .. && rm -r MagicBand
