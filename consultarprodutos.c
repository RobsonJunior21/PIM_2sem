#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void consultarEstoqueProdutos()
{
    struct Produto {
    int codigo;
    char descricao[50];
    float valor;
    char deletado;
};

    FILE *arq;
    arq = fopen("produtos.pro", "rb");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o código do produto que procura: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if ((cod == produtos.codigo) && (produtos.deletado != '*'))
        {
            printf("Cod %d --- Descrição: %-8s --- Valor R$ %4.2f\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            montarMenu("Produtos");
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    fclose(arq);
}
