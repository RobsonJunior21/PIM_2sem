#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void alterarEstoqueProdutos()
{
    struct Produto {
    int codigo;
    char descricao[50];
    float valor;
    char deletado;
};
FILE *arq;
arq = fopen("produtos.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }

    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o código que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if ((cod == produtos.codigo) && (produtos.deletado != '*'))
        {
            printf("Cod %d --- Descrição: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;

            fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
            printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            gets(produtos.descricao);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &produtos.valor);

            fwrite(&produtos, sizeof(produtos), 1, arq);
            fseek(arq, sizeof(produtos)* 0, SEEK_END);

            retornarMensagem("\n Dados do produto alterados com sucesso!");
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
