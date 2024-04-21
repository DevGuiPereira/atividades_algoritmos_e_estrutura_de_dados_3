//ALUNO : GUILHERME REIS PEREIRA

#include <stdio.h>
#include <stdlib.h>

// Declaração das funções
void help();
void menu();
int Fatorial(int *numero);
int compararString(char str1[], char str2[]);
float sequenciaHarmonica(int *numero);
double calcularS();
float calcularE(int *numero);
float raizQuadrada(float *numero);
double calculoMacCos(int *numero);
double calculoMacSen(int *numero);

int main(int argc, char *argv[])
{
    // Variáveis de controle e armazenamento de dados
    int op1 = 0, *op2 = &op1, n = 0;
    float x = 0;
    
    // Verifica se o programa foi executado com argumentos e exibe ajuda se necessário
    if (argc == 2 && (compararString(argv[1], "-h") == 1 || compararString(argv[1], "-help")))
    {
        help();
    }
    else
    {
        system("cls"); // Limpa a tela do console
        
        // Loop principal do programa
        do
        {
            menu(); // Exibe o menu de opções
            scanf("%d", op2); // Lê a opção do usuário
            system("cls"); // Limpa a tela do console
            
            // Switch para tratar a escolha do usuário
            switch (*op2)
            {
            case 1:
                // Calcula o fatorial de um número
                do
                {
                    printf("Digite um valor para n: ");
                    scanf("%d", &n);
                    if (n < 0)
                    {
                        printf("O valor de n tem que ser positivo\n");
                    }
                    else
                    {
                        printf("O fatorial de %d = %d\n", n, Fatorial(&n));
                        *op2 = 0;
                    }
                } while (*op2 == 1);
                break;
            case 2:
                // Calcula a Sequência Harmônica de um número
                do
                {
                    printf("Digite um valor para n: ");
                    scanf("%d", &n);
                    if (n <= 0)
                    {
                        printf("O valor de n deve ser maior que 0\n");
                    }
                    else
                    {
                        printf("A Sequencia Harmonica de %d = %f\n", n, sequenciaHarmonica(&n));
                        *op2 = 0;
                    }
                } while (*op2 == 2);
                break;
            case 3:
                // Realiza o cálculo de S
                do
                {
                    printf(" resposta da equação: %.4f\n", calcularS());
                    *op2 = 0;
                } while (*op2 == 3);
                break;
            case 4:
                // Realiza o cálculo de E
                do
                {
                    printf("Digite um valor para n: ");
                    scanf("%d", &n);
                    if (n < 0)
                    {
                        printf("O valor de n deve ser positivo\n");
                    }
                    else
                    {
                        printf("O calculo de %d = %f\n", n, calcularE(&n));
                        *op2 = 0;
                    }
                } while (*op2 == 4);
                break;
            case 5:
                // Calcula a raiz quadrada de um número
                do
                {
                    printf("Digite um valor para x: ");
                    scanf("%f", &x);
                    if (x < 0)
                    {
                        printf("O valor de x deve ser positivo\n");
                    }
                    else
                    {
                        printf("A raiz quadrada de %f = %.4f\n", x, raizQuadrada(&x));
                        *op2 = 0;
                    }
                } while (*op2 == 5);
                break;
            case 6:
                // Calcula o cosseno de um número
                do
                {
                    printf("Digite um valor para n: ");
                    scanf("%d", &n);
                    printf("O cosseno de %d = %.5lf\n", n, calculoMacCos(&n));
                    *op2=0;
                }while(*op2 == 6);
                break;
            case 7:
                // Calcula o seno de um número
                do
                {
                    printf("Digite um valor para n: ");
                    scanf("%d", &n);
                    printf("O seno de %d = %.5lf\n", n, calculoMacSen(&n));
                    *op2 = 0;
                } while (*op2 == 7);
                break;
            case 0:
                // Encerra o programa
                op1 = 1;
                system("cls");
                break;
            default:
                // Caso o usuário escolha uma opção inválida
                printf("Digite um valor entre 0 e 7\n");
                *op2 = 0;
                break;
            }
        } while (op1 == 0);
    }
    return 0;
}

// Função para exibir a ajuda
void help()
{
    printf("Esta atividade apresenta sete funções. Abaixo está a descrição de cada uma:\n");
    printf("1 - Calcula o fatorial de um número, onde ele deve ser um número inteiro positivo.\n");
    printf("2 - Calcula a Sequência Harmônica de um número, onde ele deve ser inteiro maior que zero.\n");
    printf("3 - Realiza o cálculo de uma função, onde é uma soma de frações que possuem um padrão (numeradores impares e denominadores em sequência)\n");
    printf("4 - Realiza o cálculo de uma função, onde o número deve ser inteiro maior que zero.\n");
    printf("5 - Calcula a raiz quadrada de um número, onde ele deve ser um número real positivo.\n");
    printf("6 - Calcula o cosseno de um número utilizando o polinômio de MacLaurin.\n");
    printf("7 - Calcula o seno de um número utilizando o polinômio de MacLaurin.\n");
}

// Função para exibir o menu
void menu()
{
    printf("1 - Calcular fatorial de n\n");
    printf("2 - Sequencia Harmonica de n\n");
    printf("3 - Calcular valor de S\n");
    printf("4 - Calcular valor de E\n");
    printf("5 - Calcular raiz quadrada de n\n");
    printf("6 - Calcular cos de n\n");
    printf("7 - Calcular sen de n\n");
    printf("0 - Sair\n");
    printf("Digite uma opcao: ");
}

// Função para calcular o fatorial de um número
int Fatorial(int *numero)
{
    int resultado = 1,i;
    for ( i = 1; i <= *numero; i++)
    {
        resultado = resultado * i;
    }
    return resultado;
}

// Função para comparar duas strings
int compararString(char str1[], char str2[])
{
    int i = 0;
    while (*(str1 + i) != '\0' && *(str2 + i) != '\0')
    {
        if (*(str1 + i) != *(str2 + i))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

// Função para calcular a Sequência Harmônica de um número
float sequenciaHarmonica(int *numero)
{
    float resultado = 0, aux = 1,i;
    for ( i = 1; i <= *numero; i++)
    {
        if (i == 1)
        {
            resultado = 1;
        }
        else
        {
            resultado = resultado + (aux / i);
        }
    }
    return resultado;
}

// Função para calcular o valor de S
double calcularS()
{
    float div = 1, result = 0;
    int i;
    for ( i = 1; i <= 50; i++)
    {
        result = result + (div / i);
        div += 2;
    }
    return result;
}

// Função para calcular o valor de E
float calcularE(int *numero)
{
    float resultado = 0, aux = 1, fatorial = 1;
    int i,j;
    for ( i = 1; i <= *numero; i++)
    {
        fatorial = 1;
        for ( j = 1; j <= i; j++)
        {
            fatorial = fatorial * j;
        }
        resultado = resultado + (aux / fatorial);
    }
    return resultado;
}

// Função para calcular a raiz quadrada de um número
float raizQuadrada(float *numero)
{
    float raiz = *numero, erro = 0.0001;
    while ((raiz * raiz - *numero) >= erro)
    {
        raiz = (raiz + (*numero / raiz)) / 2;
    }
    return raiz;
}

// Função para calcular o cosseno de um número utilizando o polinômio de MacLaurin
double calculoMacCos(int *numero)
{
    double resultado = 1;
    int intfat = 2, potencia = 2, inte = 2;
    while (inte <= 25)
    {
        double aux = *numero, fatorial = 1;
        int i,j;
        for ( i = 1; i <= intfat; i++)
        {
            fatorial = fatorial * i;
        }
        for ( j = 2; j <= potencia; j++)
        {
            aux = aux * *numero;
        }
        if (inte % 2 == 0)
        {
            resultado = resultado - (aux / fatorial);
        }
        else
        {
            resultado = resultado + (aux / fatorial);
        }
        inte++;
        intfat += 2;
        potencia += 2;
    }
    return resultado;
}

// Função para calcular o seno de um número utilizando o polinômio de MacLaurin
double calculoMacSen(int *numero)
{
    double resultado = *numero;
    int intf = 3, pot = 3, inte = 2;
    while (inte <= 25)
    {
        double aux = *numero, fat = 1;
        int i, j;
        for ( i = 1; i <= intf; i++)
        {
            fat = fat * i;
        }
        for ( j = 2; j <= pot; j++)
        {
            aux = aux * *numero;
        }
    }
}