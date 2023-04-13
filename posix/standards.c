/* PORTABLE OPERATING SYSTEM INTERFACE UNIX
 * TESTANDO BIBLIOTECAS PADRONIZADAS POSIX*/

#include <stdio.h> /* entrada|saída de arquivos e informações */
#include <string.h> /* funções para cadeias de caracteres terminadas com null byte */
#include <ctype.h> /* verificações e conversões com tipos primitivos. */
#include <stdint.h> /* tamanhos padronizados de inteiros */
#include <stdlib.h> /* alocação de memória. utilidades do processo, aleatórios e outros ...*/
#include <stdbool.h> /* boleanos padrão */
#include <unistd.h> /* operações unix: opções de uma letra, permissões, current dir, processos, shell etc...*/
#include <errno.h> /* números de erro padrão */
#include <math.h> /*requer link na compilação com gcc ... -lm*/

/*flags de argumentos de linha de comando unistd.h*/
bool aflag = false;
bool eflag = false;
bool sflag = false;

/*valor inteiro de retorno para stdout*/
int rval;

int aflagAvivada(void);
void show_errno(void);
void intypeSize(void);
void* qualquer( void* desconhecido );

int main(int argc, char *argv[])
{

	int ch;

	/* getopt() -> unistd.h    tratamento de opções de uma letra.  */
	while( (ch = getopt(argc, argv, "aes")) != -1 )
	{
		switch( ch )
		{
			case 'a':
				aflag = true;
				break;
			case 'e':
				eflag = true;
				break;
			case 's':
				sflag = true;
				break;
			default:
				break;
		}
	}

	/* Programa funciona de acordo com as
     * flags solicitadas na linha de
     * comando do shell */

	if( aflag == true )
	{
        fork();
        unsigned int v = 0;
        for( ; v <= 3; v++ )
        {
		    aflagAvivada();
            sleep(1);
        }
		exit(0);
	}
	else if( eflag == true )
	{
        /* Números de erros indicados pelo sistema operacional */

		fputs("MATH_ERRNO is ", stdout);
		puts(math_errhandling & MATH_ERRNO ? "set" : "not set");

		errno = 0;
		1.0/0;
		show_errno();

		errno = 0;
		acos(+1.1);
		show_errno();

		errno = 0;
		log(0.0);
		show_errno();

		errno = 0;
		sin(0.0);
		show_errno();

		exit(0);
	}
	else if( sflag == true )
	{
		intypeSize();
	}
	else exit(0);
}

int aflagAvivada(void)
{
	printf("\nflag 'a' foi ativada por ti.");
	return 0;
}

/* 
 * muitas bibliotecas Padrão C indicam erros
 * através de inteiros para errno. Os códigos
 * de erro são listados em errno.h*/
void show_errno(void)
{
	const char *err_info = "unknown_error";
	switch (errno)
	{
		case EDOM:
			err_info = "domain error";
			break;
		case EILSEQ:
			err_info = "illegal sequence";
			break;
		case ERANGE:
			err_info = "pole or range error";
			break;
		case 0:
			err_info = "no error";
	}
	fputs(err_info, stdout);
	puts(" occurred");
}

void intypeSize(void)
{
	/* INTEIROS
     * demostrando o tamanho de tipos
	 * definidas no cabeçalho stdint.h*/
	printf("\n %i", sizeof(uint8_t) );	/*1 byte*/
	printf("\n %i", sizeof(uint16_t) );	/*2 bytes*/
	printf("\n %i", sizeof(uint32_t) );	/*4 bytes*/
	printf("\n %i", sizeof(uint64_t) );	/*8 bytes*/
}

void* qualquer( void* desconhecido )
{
    return desconhecido;
}
