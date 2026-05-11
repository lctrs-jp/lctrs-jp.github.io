#!/bin/sh

#echo "Naive Strategy"
#./timeout $1 ocamlrun crein-1.0 -verbose -naive-strategy $2 > result-naive.txt

echo "\n\nModified Strategy"
./timeout $1 ocamlrun crein-1.0 -verbose $2 > result-modif.txt
