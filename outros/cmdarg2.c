#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

/*argumentos de linha de comando
 *para comandos estilo unix de uma
 *letra só.
 * [LETRA]flag
 *baseado em cat.c do openbsd*/
bool hflag = 0, cflag = 0;

int main(int argc, char *argv[])
{
	int ch;
	/*função getopt() lé argumentos -[LETRA]
	 *cabecalho posix unistd.h*/
	while((ch = getopt(argc, argv, "hc")) != -1 )
	{
		switch(ch)
		{
			case 'h':
				hflag = 1;
				break;
			case 'c':
				cflag = 1;
				break;
			default:
				break;
		}
	}

	if(argc == 0)
	{
		printf("\nnone\n");
		exit(0);
	}
	else if(hflag == 1)
		system("date +%r");
	else if(hflag == 1 && cflag == 1)
	{
		system("date +%r");
		system("cal");
	}
	else if(cflag == 1)
		system("cal");
	else exit(0);
}

