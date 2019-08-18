#Makefile
#Only Unix!
datei=schlange
alles:
	cc -o $(datei) $(datei).c -lcurses
leeren:
	rm $(datei)
komprimieren:
	tar -jcf $(datei).tar.bz2 $(datei).c Makefile win
