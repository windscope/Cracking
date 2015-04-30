CFLAG=-ldl -g -Wall -Werror -O1 -std=c++11 -o
SOURCE=tree.cc
TESTSOURCE=test.cc
BALANCED=balanced_tree.cpp
SORTARRAY=sorted_array_to_balanced_tree.cc
TREE2LIST=list_tree.cc
TRIE=trie.cc
TRIETEST=trie_test.cc
OUTTS=test.exe
OUTBL=balanced.exe
OUTSA=sorted_array.exe
OUTTL=tree2list.exe
OUTTTS=trie_test.exe
CC=g++
all: t2l

test: test.cc
	${CC} ${TESTSOURCE} ${SOURCE} ${CFLAG} ${OUTTS}
balance: balanced_tree.cpp
	${CC} ${BALANCED} ${SOURCE} ${CFLAG} ${OUTBL}
sortarray:  sorted_array_to_balanced_tree.cc
	${CC} ${SORTARRAY} ${SOURCE} ${CFLAG} ${OUTSA}
t2l:  list_tree.cc
	${CC} ${TREE2LIST} ${SOURCE} ${CFLAG} ${OUTTL}
trie:  trie_test.cc
	${CC} ${TRIETEST} ${TRIE} ${CFLAG} ${OUTTTS}
clean:
	rm -r *.exe *.dSYM core* *~
