#!/bin/sh
mkdir -p ../sd
cd $1
find . -name '*wav' -exec sox {} -r 16000 -b 8 ../../sd/{} \;
