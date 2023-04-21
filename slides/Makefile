all: exer move clean

fName:=smToBsm

exer: *.tex
	echo *.tex|xargs -n1 pdflatex --interaction=nonstopmode --halt-on-error
	echo *.tex|xargs -n1 pdflatex --interaction=nonstopmode --halt-on-error
	echo *.tex|xargs -n1 pdflatex --interaction=nonstopmode --halt-on-error

move: output
	mv $(fName).pdf output/$(fName).pdf

output:
	mkdir -p output/

clean:
	$(RM) -f *.glo *.gls *.idx *.ilg *.ind *.toc *.log *.lof *.lot *.aux *.blg *.bbl *.nav *.snm *.vrb *.out Solution_*.tex
