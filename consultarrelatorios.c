#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void consultarRelatorios()
{
    struct Relatorio{
    int codigo;
    float orcamento, lucro, despesa;
    char observ[250];
    char deletado;
};
    FILE *arq;
    arq = fopen("relatorio.pro", "rb");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }
    struct Relatorio relatorios;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do relat�rio que procura: \n");
    scanf ("%d", &cod);

    while (fread (&relatorios, sizeof(relatorios), 1, arq))
    {
        if ((cod == relatorios.codigo) && (relatorios.deletado != '*'))
        {
            printf("Relat�rio %d --- Or�amento: R$ %4.2f --- Lucro R$ %4.2f ---Despesas R$ %4.2f\nObserva��es: %s\n",relatorios.codigo, relatorios.orcamento, relatorios.lucro, relatorios.despesa, relatorios.observ);
            encontrado = 1;
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
