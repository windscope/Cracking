CFLAG=-ldl -g -Wall -Werror -O1 -std=c++11 -o
SOURCE=tree.cc
TESTSOURCE=test.cc
BALANCED=balanced_tree.cpp
OUTTS=test.exe
OUTBL=balanced.exe
CC=g++
all: balance

test: test.cc
	${CC} ${TESTSOURCE} ${SOURCE} ${CFLAG} ${OUTTS}
balance: balanced_tree.cpp
	${CC} ${BALANCED} ${SOURCE} ${CFLAG} ${OUTBL}
clean:
	rm -r *.exe *.dSYM core*
