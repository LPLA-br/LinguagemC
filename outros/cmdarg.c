/*demostração argumentos de linha de comando
 *ao executar-lo passe os argumentos fale ou
 *conte para ver o que acontece.
 * argumento 0 é o nome do programa
 * e os restantes são os passados
 * pelo usuário.*/

#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[])
{
	printf("\n%d - ", argc);
	unsigned short iteracao;

	/*mostrando argumentos de linha de comando passados*/
	for(iteracao=0; iteracao<argc; iteracao++)
	{
		printf("  %s", argv[iteracao]);
	}
	printf("\n");

	if(argc > 1)
	{
		if( !(strcmp(argv[1],"conte\0")) )
		{
			unsigned demo = 0;
			while(demo < 10)
			{
				printf(" %d", demo);
				demo++;
			}
		}
		else if( !(strcmp(argv[1],"fale\0")) )
		{
			printf("\nEu sou um programa que demostra os argumentos de linha de comando.\nTenha um bom dia !\n");
		}
		else
		{
			printf("\n Me desculpe, mas não entendi o que você passou para mim.\n tente os argumentos conte ou fale.\n");
		}
	}

	return 0;
}
