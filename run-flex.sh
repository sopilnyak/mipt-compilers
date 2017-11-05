#!/bin/bash -e

echo "Running flex analyzer..."
flex flex_analyzer.l
echo "Done"
echo "Compiling..."
gcc lex.yy.c -lfl
echo "Done"
echo "Input:"
./a.out
