/*Objetos sem herança e polimorfismo*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int valor1;
	int valor2;
	int (*ptrMetodo)(int, int);
} TClasse;

int soma(int v1, int v2);
int FuncaoConstrutora(TClasse *objetoAlvo);

int main(void)
{
	TClasse objeto;
	int Resultado;

	/*chama a função construtora*/
	if( FuncaoConstrutora( &objeto ) == 0 ) exit(0);
	objeto.valor1 = 1;
	objeto.valor2 = 2;
	Resultado = objeto.ptrMetodo(objeto.valor1, objeto.valor2);
	printf("\n%i", Resultado);
	exit(0);
}

int soma(int v1, int v2)
{
	return v1+v2;
}

int FuncaoConstrutora(TClasse *objetoAlvo)
{
	if( objetoAlvo == NULL ) exit(0);
	objetoAlvo->valor1 = 0;
	objetoAlvo->valor2 = 0;
	objetoAlvo->ptrMetodo = soma;
	return 1;
}



