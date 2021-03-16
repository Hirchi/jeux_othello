SRCDIR=src
LIBDIR=lib
DOCDIR=doc
BINDIR=bin
PDFFLAGS =-interaction nonstopmode
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS=-Wall -O3 -pedantic -std=c99 -I$(INCLUDEDIR)
LDFLAGS= -L$(LIBDIR) -llistechainee -lutile
EXEC=othello

all :  prg doc

prg : $(BINDIR)/$(EXEC)

$(LIBDIR)/liblistechainee.a : $(SRCDIR)/listeChaineeGenerique.o
	$(AR) $(ARFLAGS) $@ $<

$(LIBDIR)/libutile.a : $(SRCDIR)/utile.o
	$(AR) $(ARFLAGS) $@ $<
	
$(SRCDIR)/partie.o : $(SRCDIR)/partie.c $(SRCDIR)/minmax.o $(SRCDIR)/humain.o
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/testListeChaineeGenerique.o : $(TESTDIR)/testListeChaineeGenerique.c $(LIBDIR)/liblistechainee.a
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/testCouleur.o : $(TESTDIR)/testCouleur.c $(SRCDIR)/couleur.o
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/testPosition.o : $(TESTDIR)/testPosition.c $(SRCDIR)/position.o
	$(CC) -o $@ -c $< $(CFLAGS)
	
$(TESTDIR)/testPartie.o : $(TESTDIR)/testPartie.c $(SRCDIR)/humain.o $(SRCDIR)/partie.o
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/testUtiles.o : $(TESTDIR)/testUtiles.c $(LIBDIR)/libutile.a
	$(CC) -o $@ -c $< $(CFLAGS)

$(TESTDIR)/tests.o : $(TESTDIR)/tests.c $(TESTDIR)/testCellule.o $(TESTDIR)/testCouleur.o $(TESTDIR)/testCoup.o $(TESTDIR)/testCoups.o $(TESTDIR)/testJoueur.o $(TESTDIR)/testListeChaineeGenerique.o $(TESTDIR)/testPartie.o $(TESTDIR)/testPlateau.o $(TESTDIR)/testPosition.o $(TESTDIR)/testStrategie.o $(TESTDIR)/testUtiles.o $(TESTDIR)/testPartie.o
	$(CC) -o $@ -c $< $(CFLAGS)
	
$(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

tests: $(TESTDIR)/tests.o $(SRCDIR)/partie.o $(SRCDIR)/humain.o $(SRCDIR)/minmax.o $(TESTDIR)/testJoueur.o $(TESTDIR)/testUtiles.o $(TESTDIR)/testStrategie.o $(TESTDIR)/testJoueur.o $(TESTDIR)/testCellule.o $(TESTDIR)/testListeChaineeGenerique.o $(TESTDIR)/testCouleur.o $(TESTDIR)/testCoup.o $(TESTDIR)/testPosition.o $(TESTDIR)/testPlateau.o $(TESTDIR)/testPartie.o $(TESTDIR)/testCoups.o $(SRCDIR)/position.o $(SRCDIR)/joueur.o $(SRCDIR)/coup.o $(SRCDIR)/coups.o $(SRCDIR)/cellule.o $(SRCDIR)/couleur.o $(SRCDIR)/utile.o $(SRCDIR)/plateau.o $(SRCDIR)/ihm.o $(SRCDIR)/coups.o $(SRCDIR)/partie.o $(SRCDIR)/strategie.o $(LIBDIR)/libutile.a
	gcc -o $(BINDIR)/test $^ $(LDFLAGS) -lcunit
	
.PHONY: doc

doc:
	doxygen $(DOCDIR)/Doxyfile

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/menu.o $(SRCDIR)/minmax.o $(SRCDIR)/couleur.o $(SRCDIR)/strategie.o $(SRCDIR)/utile.o $(SRCDIR)/position.o $(SRCDIR)/joueur.o $(SRCDIR)/coup.o $(SRCDIR)/partie.o $(SRCDIR)/cellule.o $(SRCDIR)/plateau.o $(LIBDIR)/liblistechainee.a $(SRCDIR)/coups.o $(SRCDIR)/ihm.o $(SRCDIR)/humain.o $(LIBDIR)/libutile.a
	$(CC)  -o $@ $^ $(LDFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*.o
	rm -rf $(DOCDIR)/latex
	rm -rf $(DOCDIR)/html
