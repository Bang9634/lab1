#!/bin/bash
count=$(ls -1A | while read -r file
do
    if [ -f "$file" ] && [ ! -L "$file" ]
    then
        echo "$file"
    fi
done | wc -l)

echo "Regular files: $count"
