/*criação de processos
 *funções fork() exit()
 wait() e execute*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct Contador
{
	unsigned a, b;
	unsigned atraso;
};

int main(int argc, char *argv[])
{
	fork(); //dividindo o processo em dois
	if( argc > 2 )
	{

		struct Contador regressivo;
		regressivo.atraso = atoi( *(argv+1) );
		for(regressivo.a = regressivo.atraso; regressivo.a > 0; regressivo.a--)
		{
			for(regressivo.b = regressivo.atraso; regressivo.b > 0; regressivo.b--);
			printf("\n %i", regressivo.a);
		}
	}
	exit(0); //Termina o processo.
}
