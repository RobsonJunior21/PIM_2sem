#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void excluirEstoqueProdutos()
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
    char certeza;
    printf ("\nDigite o código do produto que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, arq))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descrição: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricao, produtos.valor);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletado = '*';
                fseek(arq,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&produtos, sizeof(produtos), 1, arq);
                fseek(arq, sizeof(produtos)* 0, SEEK_END);
                retornarMensagem("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Produtos");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Produtos");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    fclose(arq);
}
