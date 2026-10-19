#!/bin/bash
for i in 1 2 3 4 5 6 7 8 9
do
    for dan in 2 3 4 5 6 7 8 9
    do
        let "result = dan * i"
        echo -n "$dan*$i=$result  "
    done
    echo
done
