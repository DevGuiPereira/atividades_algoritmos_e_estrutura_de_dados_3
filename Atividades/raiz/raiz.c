#include <stdio.h>
float raizquadrada(float, int *);
float escreve(float);
void imprime(int, float);


int main()
	{
		float valor;
		int x=0, *iteracao=&x;
		char resposta[100];
		
		valor=escreve(valor);
		imprime(valor, raizquadrada(valor,iteracao));
		return(0);
	}
	
float raizquadrada(float valor, int *iteracao)
	{
		float raiz=valor, precisao=0.001;

		while((raiz*raiz-valor)>=precisao)
			{
				raiz=(raiz+(valor/raiz))/2;
				*iteracao++;
			}
		return(raiz);	
	}	
	
float escreve(float valor)
	{
		printf("digite um valor para ter sua raiz: \n");
		scanf("%f",&valor);
		return(valor);
	}

void imprime(int valor, float resposta )
	{
		printf("o valor da raiz de %d é %f \n",valor,resposta);
	}