#!/bin/bash
i=1
until [ $i -gt 9 ]
do
    dan=2
    until [ $dan -gt 9 ]
    do
        let "result = dan * i"
        echo -n "$dan*$i=$result  "
        let "dan += 1"
    done
    echo
    let "i += 1"
done
