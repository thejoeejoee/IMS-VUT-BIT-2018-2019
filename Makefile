.PHONY: all

all: manual.pdf

manual.pdf: doc/doc.tex doc/_titlepage.tex
	test -f doc/doc.tex && cd doc && pdflatex doc.tex && cd .. && mv doc/doc.pdf ./
