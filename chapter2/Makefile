CFLAG=-ldl -g -Wall -Werror -O1 -std=c++11 -o
SOURCE=Linkedlist.cc
PROBLEM1=1.cc
PROBLEM2=2.cc
PROBLEM3=3.cc
PROBLEM4=4.cc
PROBLEM5=5.cc
PROBLEM6=6.cc
PROBLEMF=fabornaci.cc
OUT1=1.exe
OUTF=fabornaci.exe
OUT2=2.exe
OUT3=3.exe
OUT4=4.exe
OUT5=5.exe
OUT6=6.exe
CC=g++
all: p1

p1: 1.cc
	${CC} ${PROBLEM1} ${SOURCE} ${CFLAG} ${OUT1}
pf: fabornaci.cc
	${CC} ${PROBLEMF} ${SOURCE} ${CFLAG} ${OUTF}
p2: 2.cc
	${CC} ${PROBLEM2} ${SOURCE} ${CFLAG} ${OUT2}
p3: 3.cc
	${CC} ${PROBLEM3} ${SOURCE} ${CFLAG} ${OUT3}
p4: 4.cc
	${CC} ${PROBLEM4} ${SOURCE} ${CFLAG} ${OUT4}
p5: 5.cc
	${CC} ${PROBLEM5} ${SOURCE} ${CFLAG} ${OUT5}
p6: 6.cc
	${CC} ${PROBLEM6} ${SOURCE} ${CFLAG} ${OUT6}
clean:
	rm -rf *.o *~ *.exe *.out
