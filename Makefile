CPPFLAGS=-std=c++14 -O2
LDLIBS=-lsimlib

FILES=$(shell find src/ -name '*.cpp' -or -name '*.h')

OBJECTS=${FILES:.cpp=.o}

.PHONY: all pack doc pack run

all: sim

doc: doc.pdf

doc.pdf: doc/doc.tex doc/_titlepage.tex
	test -f doc/doc.tex && cd doc && pdflatex doc.tex && cd .. && mv doc/doc.pdf ./

sim: main.cpp $(OBJECTS)
	$(CXX) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

run: sim
	./sim

pack:
	zip -r 04_xkolar71_xkavan05.zip Makefile doc.pdf src/ main.cpp