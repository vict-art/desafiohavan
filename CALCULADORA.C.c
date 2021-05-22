#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

char clientes[TAM][100];
char moedaorigem[TAM][10];
char moedadestino[TAM][10];
char dataoperacao[TAM][20];
float valororiginal[TAM];
float valorconvertido[TAM];
float taxacobrada[TAM];
int posicao = 0;

int montaMenu();
void cadastraoperacao();
void relatoriocliente();
void relatoriooperacao();

int main(void)
{

    int opcao;
    opcao = -1;

    while (opcao != 0)
    {
        opcao = montaMenu();
        switch(opcao)
        {
        case 1:
            cadastraoperacao();
            break;
        case 2:
            relatoriocliente();
            break;
        case 3: relatoriooperacao();
            break;

        }
    }

    return 0;
}

int montaMenu()
{
    int escolha;
    system("color 1F");
    system("cls");
    printf("-----------------------\n");
    printf("*** Converte moedas ***\n");
    printf("-----------------------\n");
    printf("1-Cadastro operacoes\n");
    printf("2-Relatorio de clientes\n");
    printf("3-Relatorio de operacoes \n");
    printf("\n");
    printf("0-Sair do programa \n");
    printf("-----------------------\n");
    printf("Opcao escolhida => ");
    scanf("%d", &escolha);

    return escolha;
}
void cadastraoperacao()
{
    float valorcotacao = 0;

    fflush(stdin);
    system("cls");
    printf("cadastro de operacoes\n");
    printf("codigo: %d \n", posicao);
    printf("nome: ");
    gets(clientes[posicao]);
    printf("moeda de origem: ");
    gets(moedaorigem[posicao]);
    printf("cotacao do %s hoje: ", moedaorigem[posicao]);
    scanf(" %f", &valorcotacao);
    fflush(stdin);
    printf("moeda de destino: ");
    gets( moedadestino[posicao]);
    printf("data de operacao: ");
    gets(dataoperacao[posicao]);
    printf("valor original: ");
    scanf(" %f",&valororiginal[posicao]);
    valorconvertido[posicao] = valororiginal[posicao] * valorcotacao;
    taxacobrada[posicao] = valorconvertido[posicao] * 0.1;
    printf("valor convertido: %.2f \n", valorconvertido[posicao]);
    printf("taxa cobrada %.2f \n", taxacobrada[posicao]);
    posicao = posicao + 1;
    printf("operacao cadastrado com sucesso\n");
    system("pause");


}
void relatoriocliente()
{
    int i;
    char nome[100];
    float totalconvertido=0;
    float totaltaxa=0;

    fflush(stdin);
    system("cls");
    printf("-RELATORIO DE CLIENTES- \n");
    printf("informe o nome do cliente:");
    gets(nome);

    printf(" \n");
    printf("CODIGO | NOME | MOEDA ORIGEM | MOEDA DESTINO | DATA OPERACAO | VALOR ORIGINAL | VALOR CONVERTIDO | TAXA COBRADA \n");
    for (i=0; i<posicao; i++)
    {
        if (strcmp(nome,clientes[i])==0)
        {
            printf("%d   | %s   \t|   %s   \t|   %s   \t| %s \t   |  %.2f  \t| %.2f \t| %.2f \n", i, clientes[i],moedaorigem[i], moedadestino[i],dataoperacao[i], valororiginal[i], valorconvertido[i], taxacobrada[i]);
            totalconvertido=totalconvertido + valorconvertido[i];
            totaltaxa=totaltaxa + taxacobrada[i];
        }
    }
    printf("\n");
    printf("total convertido = %.2f \n  ", totalconvertido);
    printf("total taxa cobrada = %.2f \n",  totaltaxa);
    system("pause");
}


void relatoriooperacao()
{
    int i;
    float totalconvertido=0;
    float totaltaxa=0;

    fflush(stdin);
    system("cls");
    printf("-RELATORIO DE OPERACOES- \n");

    printf(" \n");
    printf("CODIGO | NOME | MOEDA ORIGEM | MOEDA DESTINO | DATA OPERACAO | VALOR ORIGINAL | VALOR CONVERTIDO | TAXA COBRADA \n");
    for (i=0; i<posicao; i++)
    {

        printf("%d   | %s   \t|   %s   \t|   %s   \t| %s \t   |  %.2f  \t| %.2f \t| %.2f \n", i, clientes[i],moedaorigem[i], moedadestino[i],dataoperacao[i], valororiginal[i], valorconvertido[i], taxacobrada[i]);
        totalconvertido=totalconvertido + valorconvertido[i];
        totaltaxa=totaltaxa + taxacobrada[i];

    }
    printf("\n");
    printf("total convertido = %.2f \n  ", totalconvertido);
    printf("total taxa cobrada = %.2f \n",  totaltaxa);
    system("pause");




}



