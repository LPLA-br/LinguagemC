#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>

#define LARGURA 30
#define ALTURA 10

typedef struct
{
	int x;
	int y;
} Janela;

int main( int argc, char *argv[] )
{
	WINDOW *janela;
	Janela j = {(80 - LARGURA)/2, (24-ALTURA)/2};
	initscr();
	clear();
	noecho();
	cbreak();

	janela = newwin(ALTURA, LARGURA, j.y, j.x);
	keypad(janela, TRUE);
	mvprintw(0, 0, "Programa com biblioteca ncurses rodou !");
	refresh(); //atualiza a tela

	unsigned short caractere = 'c', movey = 23, movex = 2;
	bool loop = true, modoDesenho = true;
	while( loop )
	{
		caractere = wgetch(janela);
		switch( caractere )
		{
			case KEY_UP:
				if( modoDesenho == true )
					mvprintw(movey, movex, "0");
				--movey;
				refresh();
				break;
			case KEY_DOWN:
				if( modoDesenho == true )
					mvprintw(movey, movex, "0");
				++movey;
				refresh();
				break;
			case KEY_LEFT:
				if( modoDesenho == true )
					mvprintw(movey, movex, "0");
				--movex;
				refresh();
				break;
			case KEY_RIGHT:
				if( modoDesenho == true )
					mvprintw(movey, movex, "0");
				++movex;
				refresh();
				break;
			case 'm':
				if( modoDesenho == true )
					modoDesenho = false;
				else modoDesenho = true;
				break;
			default:
				clear();
				loop = false;
				break;
		}
	}

	clrtoeol();
	refresh();
	endwin();
	exit(0);
}
