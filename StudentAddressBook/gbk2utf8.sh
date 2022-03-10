#!/bin/bash
for i in `find . -type f -name '*'`
do
    convmv -f GBK -t UTF-8 --notest $i
done