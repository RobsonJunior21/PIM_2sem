#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void cadastrarEstoqueProdutos()
{
    struct Produto {
    int codigo;
    char descricao[50];
    float valor;
    char deletado;
};
    FILE *arq;
struct Produto produtos;
    int retorno;
    arq = fopen("produtos.pro", "ab");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o código do produto: \n");
    scanf("%d", &produtos.codigo);
    printf("Digite a descrição do produto: \n");
    fflush(stdin);
    gets(produtos.descricao);
    printf("Digite o valor do produto: \n");
    scanf("%f", &produtos.valor);
    retorno = fwrite (&produtos, sizeof(produtos), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\n Dados do produto incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
    else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do produto.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Produtos");
    }
}
