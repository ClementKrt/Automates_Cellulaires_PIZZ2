Jeu: main.o matriceensdl.o reglesautomate.o figuresjeudelavie.o
	gcc -o Jeu reglesautomate.o main.o matriceensdl.o figuresjeudelavie.o `sdl-config --cflags --libs` 


figuresjeudelavie.o:figuresjeudelavie.c
	gcc -c figuresjeudelavie.c -Wall -Wextra -o figuresjeudelavie.o


matriceensdl.o:matriceensdl.c 
	gcc -c matriceensdl.c -Wall -Wextra -o matriceensdl.o `sdl-config --cflags --libs`

reglesautomate.o:reglesautomate.c
	gcc -c reglesautomate.c -Wall -Wextra -o reglesautomate.o 

main.o:main.c matriceensdl.h reglesautomate.h figuresjeudelavie.h
	gcc -c main.c -Wall -Wextra -o main.o `sdl-config --cflags --libs`
