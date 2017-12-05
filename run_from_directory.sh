#!/bin/bash -e

for filename in ./$1/*.java; do
	echo $filename
    cat $filename | ./typechecker
done
