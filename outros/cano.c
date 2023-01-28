/*programa que pode receber e mandar
 *dados por pipes no terminal.
 *stdin-->programa-->stdout*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		if(!(strcmp(argv[1],"--saida")))
		{
			/*puts() escreve uma cadeia de caracteres para stdout
			 *./cano --saida | cat */
			puts("saida stdout usando a função puts");
			exit(0);
		}
	}

	/*ler cada caractere stdin
	 *echo testando | ./cano */
	char caractere;
	unsigned short limitador = 10;
	while( limitador != 0)
	{
		//lendo cada caractere de stdin
		caractere = getchar();
		printf("%c", caractere);
		limitador--;
	}
	exit(0);
}
