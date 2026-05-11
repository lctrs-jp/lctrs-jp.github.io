#!/bin/sh

#echo "Naive Strategy"
#time ./timeout $1 ocamlrun crein-1.0 -show-stats -naive-strategy $2

echo "\n\nModified Strategy"
time ./timeout $1 ocamlrun crein-1.0 -show-stats $2
