/*conclusão: matrizes multidimensionais ocupam a memoria
linearmente assim como uma unidimensional*/
#include<stdio.h>
#define X 5
#define Y 5

void f(int a[Y][X]);

void f2(int *a, int y, int x);

void f3(int a[][5]);

void f4(void);

int main()
{
    int teste[Y][X]={{1,2,3,4,5},
                     {5,4,3,2,1},
                     {1,2,3,4,5},
                     {5,4,3,2,1},
                     {1,2,3,4,5}};
    f(teste);
    printf("----------\n");
    f2( (int *)teste, 5, 5);
    printf("----------\n");
    f3(teste);
    f4();
    return 0;
}

void f(int a[Y][X])
{
    int c,d;
    for(c=0; c<Y; c++)
    {
        for(d=0; d<X; d++) printf(" %d",a[c][d]);
        printf("\n");
    }
}

void f2(int *a, int y, int x)
{
    int c,d;
    for(c=0; c<y; c++)
    {
        for(d=0; d<x; d++)
        {
            printf(" %d", *a);
            a++;
        }
        printf("\n");
    }
}

void f3(int a[][5])
{
    int c,d;
    for(c=0; c<5; c++)
    {
        for(d=0; d<5; d++) printf(" %d",a[c][d]);
        printf("\n");
    }
}

void f4(void)
{
    unsigned char a, b;
    for(a=0, b=10; (a!=5) && (b!=5); a++, b--)
    {
        printf("\na%i b%i", a, b);
    }
}
