CFLAG=-ldl -g -Wall -Werror -O1 -std=c++11 -o
SOURCE=tree.cc
TESTSOURCE=test.cc
OUTTS=test.exe
CC=g++
all: test

test: test.cc
	${CC} ${TESTSOURCE} ${SOURCE} ${CFLAG} ${OUTTS}
clean:
	rm -r *.exe *.dSYM
