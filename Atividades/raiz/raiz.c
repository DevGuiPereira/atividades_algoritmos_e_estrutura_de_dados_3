#include <stdio.h> //biblioteca base do programa, onde consegue receber e imprimir dados
float raizquadrada(float, int *);
float escreve(float);              //inicializadores de função
void imprime(int, float);


int main()
	{
		float valor;
		int x=0, *iteracao=&x; //variáveis necessárias
		char resposta[100];
		
		valor=escreve(valor); //valor recebe a função escreve
		imprime(valor, raizquadrada(valor,iteracao)); //a função 'imprime' recebe as variáveis valor e a função raizquadrada
		return(0);  //encerra o programa
	}
	
float raizquadrada(float valor, int *iteracao)
	{
		float raiz=valor, precisao=0.001; //variáveis necessárias para a função raizquadrada

		while((raiz*raiz-valor)>=precisao)
			{
				raiz=(raiz+(valor/raiz))/2;    // comandos para encontrar a raiz quadrada
				*iteracao++;
			}
		return(raiz);	//retorna o valor da raiz quadrada
	}	
	
float escreve(float valor)
	{
		printf("digite um valor para ter sua raiz: \n"); //imprime no cmd
		scanf("%f",&valor); //recebe dados pelo teclado
		return(valor); //retorna o valor
	}

void imprime(int valor, float resposta )
	{
		printf("o valor da raiz de %d é %f \n",valor,resposta); //imprime a resposta do codigo
	}