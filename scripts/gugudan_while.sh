#!/bin/bash
i=1
while [ $i -le 9 ]
do
    dan=2
    while [ $dan -le 9 ]
    do
        let "result = dan * i"
        echo -n "$dan*$i=$result  "
        let "dan += 1"
    done
    echo
    let "i += 1"
done
