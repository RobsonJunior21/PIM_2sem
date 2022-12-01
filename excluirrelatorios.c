#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>


void excluirRelatorios()
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
    char certeza;
    printf ("\nDigite o codigo do relat�rio que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&relatorios, sizeof(relatorios), 1, arq))
    {
        if (cod == relatorios.codigo)
        {
            printf("Relat�rio %d --- Or�amento: R$ %4.2f --- Lucro R$ %4.2f ---Despesas R$ %4.2f\nObserva��es: %s\n",relatorios.codigo, relatorios.orcamento, relatorios.lucro, relatorios.despesa, relatorios.observ);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este relat�rio? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                relatorios.deletado = '*';
                fseek(arq,sizeof(struct Relatorio)*-1, SEEK_CUR);
                fwrite(&relatorios, sizeof(relatorios), 1, arq);
                fseek(arq, sizeof(relatorios)* 0, SEEK_END);
                retornarMensagem("\nRelat�rio excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Relat�rio");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Relat�rio");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }
    fclose(arq);
}
