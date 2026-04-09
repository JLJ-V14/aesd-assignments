#!/bin/bash


if [ $# -ne 2 ]; then
    echo "Error: se necesitan 2 argumentos"
    exit 1
fi

mkdir -p $(dirname $1)

echo $2 > $1

if [ $? -ne 0 ]; then
    echo "Error: no se pudo crear el fichero"
    exit 1
fi

