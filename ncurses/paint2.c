#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdint.h>

/*gcc prg.c -o prg -lncurses*/

#define LARGURA 30
#define ALTURA 10

typedef struct
{
	char caractere;
	int px;
	int py;
	unsigned int direcao : 2; //dois bits, 4 combinações.
} Movel;

enum direcao {CIMA=0, DIREITA, BAIXO, ESQUERDA};

void none(void);

int main(int argc, char *argv[])
{
	WINDOW *janela;
	Movel a;

	a.px = 5;
	a.py = 5;
	a.direcao = 0;

	int comessax, comessay;
	int c = 'c'; //caractere

	initscr();
	clear();
	noecho();
	cbreak();

	comessax = (80 - LARGURA) / 2;
	comessay = (24 - ALTURA) / 2;

	janela = newwin(ALTURA, LARGURA, comessay, comessax);
	keypad(janela, TRUE);
	mvprintw(0,0, "Biblioteca Ncurses");
	refresh();

	a.caractere = '0';
	char impressao[] = " \0";

	while(true)
	{
		c = wgetch(janela);
		switch(c)
		{
			case KEY_UP:
				a.direcao = 0;
				break;
			case KEY_DOWN:
				a.direcao = 2;
				break;
			case KEY_LEFT:
				a.direcao = 1;
				break;
			case KEY_RIGHT:
				a.direcao = 3;
				break;
			case '1':
				a.caractere = '0';
				impressao[0] = a.caractere;
				break;
			case '0':
				a.caractere = ' ';
				impressao[0] = a.caractere;
				break;
			default:
				/*movimento autonomo
				 *na ultima direção
				 *definida.*/
				break;
		}
		switch( a.direcao )
		{
			case CIMA:
				a.py--;
				break;
			case DIREITA:
				a.px--;
				break;
			case BAIXO:
				a.py++;
				break;
			case ESQUERDA:
				a.px++;
			break;
		}
		mvprintw(a.py, a.px, impressao);
		refresh();
	}

	clrtoeol();
	refresh();
	endwin();

	exit(0);
}

void none(void)
{
	printf("\nNONE\n");
}

