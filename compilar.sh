#!/bin/bash
# Compila todos los programas en ./bin
mkdir -p bin
for f in actividades/*.cpp ejercicios/*.cpp; do
    nombre=$(basename "$f" .cpp)
    g++ -std=c++11 -Wall -Wextra -I. "$f" -o "bin/$nombre" && echo "OK  $nombre" || echo "ERROR  $nombre"
done
