CFLAG=-ldl -Wall -std=c++11 -o
SOURCE=Linkedlist.cc
PROBLEM1=1.cc
PROBLEM2=2.cc
PROBLEMF=fabornaci.cc
OUT1=1.exe
OUTF=fabornaci.exe
OUT2=2.exe
CC=g++
all: p1

p1: 1.cc
	${CC} ${PROBLEM1} ${SOURCE} ${CFLAG} ${OUT1}
pf: fabornaci.cc
	${CC} ${PROBLEMF} ${SOURCE} ${CFLAG} ${OUTF}
p2: 2.cc
	${CC} ${PROBLEM2} ${SOURCE} ${CFLAG} ${OUT2}
clean:
	rm -rf *.o *~ *.exe *.out
