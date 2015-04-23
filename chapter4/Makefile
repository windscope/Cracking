CFLAG=-ldl -g -Wall -Werror -O1 -std=c++11 -o
SOURCE=tree.cc
TESTSOURCE=test.cc
BALANCED=balanced_tree.cpp
SORTARRAY=sorted_array_to_balanced_tree.cc
OUTTS=test.exe
OUTBL=balanced.exe
OUTSA=sorted_array.exe
CC=g++
all: sortarray

test: test.cc
	${CC} ${TESTSOURCE} ${SOURCE} ${CFLAG} ${OUTTS}
balance: balanced_tree.cpp
	${CC} ${BALANCED} ${SOURCE} ${CFLAG} ${OUTBL}
sortarray:  sorted_array_to_balanced_tree.cc
	${CC} ${SORTARRAY} ${SOURCE} ${CFLAG} ${OUTSA}
clean:
	rm -r *.exe *.dSYM core*
