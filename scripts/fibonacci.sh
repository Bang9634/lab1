#!/bin/bash
n=10
a=0
b=1
i=0

while [ $i -lt $n ]
do
    echo -n "$a "
    let "next = a + b"
    a=$b
    b=$next
    let "i += 1"
done
echo
