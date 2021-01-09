#!/bin/sh
# Prepare sound samples to be written to SD card,
# downsample and reduce bit depth.
mkdir -p ../sd
cd $1
find . -name '*wav' -exec sox --norm=-3 {} -r 16000 -b 8 ../../sd/{} \;
