/*Manipular arquivos de texto com funções
  da biblioteca de entrada e saída padrão.
  Argumentos gravar ou ler.*/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		/*w -> abrir o arquivo para gravação
	  	  r -> abrir o arquivo para leitura*/
		if( !(strcmp(*(argv+1), "gravar")) )
		{
			FILE *arquivo = fopen("/home/luiz/Programação/C/exemplos/data.txt","w");
			char string[20];
			printf("\nNão insira palavra maior que 19 caracteres.\n");
			scanf("\n%s",string);
			fputs(string,arquivo);
			fclose(arquivo);
		}
		else if( !(strcmp(*(argv+1), "ler")) )
		{
			FILE *arquivo = fopen("/home/luiz/Programação/C/exemplos/data.txt","r");
			char data_txt[20];
			printf("\n%s", fgets(data_txt,sizeof(data_txt),arquivo) );
			fclose(arquivo);
		}
	}
	return 0;
}
