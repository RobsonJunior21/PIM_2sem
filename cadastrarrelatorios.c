#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void cadastrarRelatorios()
{
    struct Relatorio{
    int codigo;
    float orcamento, lucro, despesa;
    char observ[250];
    char deletado;
};
    FILE *arq;
    FILE *pont_arq;
    struct Relatorio relatorios;
    int retorno;
    arq = fopen("relatorio.pro", "ab");
    pont_arq = fopen("relatorio.txt", "ab");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }

    printf("Digite o codigo do relat�rio: \n");
    scanf("%d", &relatorios.codigo);
    fprintf(pont_arq, "%d\n", relatorios.codigo);
    printf("Digite o or�amento disponivel (Apenas n�meros): \n");
    scanf("%f", &relatorios.orcamento);
    fprintf(pont_arq, "Or�amento: R$ %4.2f\n", relatorios.orcamento);
    printf("Digite o lucro desse m�s(Apenas n�meros): \n");
    scanf("%f", &relatorios.lucro);
    fprintf(pont_arq, "Lucro: R$ %4.2f\n", relatorios.lucro);
    printf("Digite a despesa desse m�s(Apenas n�meros): \n");
    scanf("%f", &relatorios.despesa);
    fprintf(pont_arq, "Despesas: R$ %4.2f\n", relatorios.despesa);
    printf("Digite as demais observa��es: \n");
    fflush(stdin);
    gets(relatorios.observ);
    fprintf(pont_arq, "Oberva��es: %s\n", relatorios.observ);

    retorno = fwrite (&relatorios, sizeof(relatorios), 1, arq);

    if (retorno == 1)
    {
        fclose (arq);
        fclose (pont_arq);
        retornarMensagem("\n Dados do relat�rio inclu�dos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }else
    {
        fclose (arq);
        fclose (pont_arq);
        retornarMensagem("\n Falha ao gravar dados do relat�rio.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Relat�rio");
    }
}
