#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: se necesitan 2 argumentos"
    exit 1
fi



if [ ! -d "$1" ]; then
    echo "Error: directorio no encontrado"
    exit 1
fi 

numfiles=$(find $1 -type f 2>/dev/null | wc -l)
numlines=$(grep -r $2 $1 | wc -l)

echo "The number of files are $numfiles and the number of matching lines are $numlines"