#MakefileWindows
alle:
	gcc -o schlange schlange.c -L. -lib\lpdcurses -lib\lpthread
komprimieren:
	tar -cjf schlange-win32.tar.bz2 schlange.exe lib\pdcurses.dll lib\pthread.dll