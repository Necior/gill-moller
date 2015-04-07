#!/bin/sh 

COUNT=8

gcc -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -O1 -lm -o gm_o1 gill_moller.c
gcc -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -O2 -lm -o gm_o2 gill_moller.c
gcc -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -O3 -lm -o gm_o3 gill_moller.c

./gm_o1 ${COUNT} > gm_o1.csv
./gm_o2 ${COUNT} > gm_o2.csv
./gm_o3 ${COUNT} > gm_o3.csv
