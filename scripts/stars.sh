#!/bin/bash
for row in 5 4 3 2 1
do
    col=1
    while [ $col -le $row ]
    do
        echo -n "*"
        let "col += 1"
    done
    echo
done
