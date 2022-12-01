#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void alterarRelatorios()
{
    struct Relatorio{
    int codigo;
    float orcamento, lucro, despesa;
    char observ[250];
    char deletado;
};
    FILE *arq;
    arq = fopen("relatorio.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }

    struct Relatorio relatorios;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do relat�rio que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&relatorios, sizeof(relatorios), 1, arq))
    {
        if ((cod == relatorios.codigo) && (relatorios.deletado != '*'))
        {
            printf("Relat�rio %d --- Or�amento: R$ %4.2f --- Lucro R$ %4.2f ---Despesas R$ %4.2f\nObserva��es: %s\n",relatorios.codigo, relatorios.orcamento, relatorios.lucro, relatorios.despesa, relatorios.observ);
            encontrado = 1;

            fseek(arq,sizeof(struct Relatorio)*-1, SEEK_CUR);
            printf("\nDigite o novo or�amento: \n");
            scanf("%f", &relatorios.orcamento);
            printf("\nDigite os lucros do m�s....: \n");
            scanf("%f", &relatorios.lucro);
            printf("Digite a despesa desse m�s: \n");
            scanf("%f", &relatorios.despesa);
            printf("Digite as demais observa��es: \n");
            fflush(stdin);
            gets(relatorios.observ);

            fwrite(&relatorios, sizeof(relatorios), 1, arq);
            fseek(arq, sizeof(relatorios)* 0, SEEK_END);

            retornarMensagem("\n Dados do relat�rio alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Relat�rio");
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }
    fclose(arq);
}
