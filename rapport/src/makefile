all: rapport.pdf


rapport.pdf:
	pdflatex -interaction nonstopmode -halt-on-error -file-line-error -output-directory . --shell-escape index.tex
	pdflatex -interaction nonstopmode -halt-on-error -file-line-error -output-directory . --shell-escape index.tex #Deuxieme passage de pdflatex pour générer le sommaire
	mv index.pdf rapport.pdf

clean:
	rm -rf ./*.pdf
	rm -rf ./*.log
	rm -rf ./*.aux
	rm -rf ./*.dvi
	rm -rf ./*.toc
	rm -rf ./*.out
	rm -rf ./*.idx
	rm -rf ./*.ilg
	rm -rf ./*.ind
