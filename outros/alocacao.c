/*	Alocação dinâmica de memória

1.Quando você precisa de muita memória. O tamanho típico da
pilha é de 1 MB, então qualquer coisa maior que 50-100 KB
deve ser alocada dinamicamente, ou você corre o risco de
travar. Algumas plataformas podem ter esse limite ainda menor.

2.Quando a memória deve viver após o retorno da função.
A memória da pilha é destruída quando a função termina,
a memória dinâmica é liberada quando você quiser (controle).

3.Quando você está construindo uma estrutura (como matriz ou gráfico)
de tamanho que é desconhecido (ou seja, pode ficar grande), muda
dinamicamente ou é muito difícil de calcular previamente. A alocação
dinâmica permite que seu código solicite naturalmente a memória,
peça por peça, a qualquer momento e somente quando você precisar dela.
Não é possível solicitar repetidamente mais e mais espaço de pilha em
um loop for (dados dinâmicos).

Caso contrário, prefira a alocação de pilha. É mais rápido e não pode vazar.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*alocação dinâmica de memória
	malloc(size_t size)			memory allocation	alocar memória
	calloc(size_t num, size_t size)		contigous allocation	alocação de multiplos itens "matriz"
	realloc(void *ptr, size_t new_size)	re-allocation		re-alocar
	free(void *ptr)				de-allocation		des-alocar liberar
	*/

	unsigned short *valor = malloc( sizeof(unsigned short) );
	*valor = 10;
	printf("%d-%x\n", *valor, &valor);



	int *matrizDinamica = calloc(4,sizeof(int));

	int posicaoGravacao;
	unsigned short valorASerGravado = 1;
	for(posicaoGravacao=0; posicaoGravacao<4; posicaoGravacao++, valorASerGravado++)
	{
		matrizDinamica[posicaoGravacao] = valorASerGravado;
		printf("%d\n", *(matrizDinamica + posicaoGravacao) );
	}



	valor = realloc(valor, sizeof(unsigned short) );
	printf("%d-%x\n", *valor, &valor);


	free(valor);

	return 0;
}
