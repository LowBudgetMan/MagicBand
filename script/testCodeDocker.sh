#!/bin/bash

clear

docker build -t magicband .
docker rm magicband
docker run --name magicband -it magicband
