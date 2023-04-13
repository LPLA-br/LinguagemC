/*ponteiros, enumerações, estruturas*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

struct comum
{
	bool val;
} estado = {true}, estado2 = {false};

enum diasSemana
{
	domingo = 1, segunda, terca, quarta, quinta, sexta, sabado
};

typedef struct
{
	unsigned short numero;
	char caractere;
} Documento;

typedef struct
{
	char *nome;
	char *nome2;
	bool (* zeris)(int);
} Nomes;

bool eZero(int num);

/*função ponteiro*/
bool (* apontar)(int) = eZero;

void ponteirosEControles(void);

int main( int argc, char *argv[] )
{
	char *cadeiaDeCaracteres = " teste\0";

	uint8_t i;
	for( i = 1; *(cadeiaDeCaracteres + i) != '\0'; i++ )
	{
		putc(*(cadeiaDeCaracteres + i), stdout);
	}

	char letra = 'c';
	char *letrapnt = &letra;
	char **letrapntpnt = &letrapnt;
	**letrapntpnt = 'd';
	printf("\n %c", **letrapntpnt);



	Documento registro1 = {13, 'v'};
	printf("\n estrutura %i %c", registro1.numero, registro1.caractere);

	Documento *registropnt = &registro1;
	printf("\n ponteiro %i %c", registropnt->numero, registropnt->caractere);

	Documento *registropnt2;
	registropnt2 = &registro1;
	registropnt2->numero++; /*funciona como*/
	printf("\n ponteiro %i %c", registropnt->numero, registropnt->caractere);



	struct comum localAMain = {true}; /*sem typedef*/
	printf("\n 2 estruturas globais e uma local %b %b (%b)", estado.val, estado2.val, localAMain.val);

	printf("\n %b", apontar(4));



	Nomes grupo1;
	grupo1.nome = malloc(10*sizeof(int)); /*duas notações distintas para alocação*/
	grupo1.nome2 = malloc(sizeof(int[10]));
	grupo1.zeris = eZero;

	strcpy(grupo1.nome, "roma");
	strcpy(grupo1.nome2, "italia");

	printf("\nA cidade de %s fica na %s", grupo1.nome, grupo1.nome2);
	free(grupo1.nome2);
	free(grupo1.nome);

	grupo1.zeris(0);

	exit(0);
}

bool eZero(int num)
{
	if( num == 0 )
	{
		printf("\n é zero ");
		return true;
	}
	else
	{
		printf("\n não é zero ");
		return false;
	}
}

void ponteirosEControles(void)
{

    /* VALOR=MUTÁVEL  ENDEREÇO=MUTÁVEL */
    char* demostracaoA = "aaa\0";

    /* VALOR=IMÚTAVEL ENDEREÇO=MÚTAVEL */
    const char* demostracaoB = "bbb\0";

    /* VALOR=MÚTAVEL ENDEREÇO=IMÚTAVEL */
    char* const demostracaoC = "ccc\0";

    /* VALOR=IMÚTAVEL ENDEREÇO=IMÚTAVEL */
    const char* const demostracaoD = "ddd\0";

    /*UNISTD.H*/
    char* const nome[10] = "teste\0";
}
