#!/bin/bash -e
bison -d syntax_analyzer.y
flex flex_analyzer.l
gcc -o parser syntax_analyzer.tab.c lex.yy.c
