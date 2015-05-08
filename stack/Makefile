CFLAG=-ldl -g -Wall -std=c++11 -o
PROBLEM1=1.cc
PROBLEM2=2.cc
PROBLEM3=3.cc
PROBLEM4=4.cc
PROBLEM5=5.cc
PROBLEM6=6.cc
OUT1=1.exe
OUT2=2.exe
OUT3=3.exe
OUT4=4.exe
OUT5=5.exe
OUT6=6.exe
CC=g++
all: p1 p2 p3 p4 p5 p6

p1: 1.cc
	${CC} ${PROBLEM1} ${SOURCE} ${CFLAG} ${OUT1}
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
	rm -rf *.o *~ *.exe *.out *.exe.dSYM
