/*todos os cabeçalhos incluidos abaixo
 *seguem os padrões posix C99 esperados
 *em qualquer sistema da grande familia UNIX
 *este programa é apenas uma demostração
 *incompleta escrita apenas para passar o tempo
 *na pausa entre aulas.*/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <math.h> /*requer link na compilação com gcc ... -lm*/

/*flags de argumentos de linha de comando unistd.h*/
uint8_t aflag = false, eflag = false, sflag = false;
/*valor inteiro de retorno para stdout*/
int rval;

int prototipe(void);
void show_errno(void);
void intypeSize(void);

int main(int argc, char *argv[])
{

	int ch;

	/*tratamento padrão de argumentos de linha de comando com unistd.h
	 *baseado no código fonte do programa cat do sistema operacional
	 *open-bsd*/
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

	/*programa*/

	if( aflag == true )
	{
		prototipe();
		exit(0);
	}
	else if( eflag == true )
	{
		/*testando função show_errno()
		para biblioteca padrão math.h*/
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

int prototipe(void)
{
	printf("\nfunção inútil que faz");
	return 0;
}

/*Indicador padrão de erros.
 *muitas bibliotecas Padrão C indicam erros
 *através de inteiros para errno. Os códigos
 *de erro são listados em errno.h*/
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
	/*demostrando o tamanho de tipos
	definidas no cabeçalho stdint.h*/
	printf("\n %i", sizeof(uint8_t) );	/*1 byte*/
	printf("\n %i", sizeof(uint16_t) );	/*2 bytes*/
	printf("\n %i", sizeof(uint32_t) );	/*4 bytes*/
	printf("\n %i", sizeof(uint64_t) );	/*8 bytes*/
}

/*carpe diem*/
