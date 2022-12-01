#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void excluirFuncionarios()
{
    struct Funcionario {
    int codigo;
    char nome[50];
    char cpf[12];
    char endereco[50];
    char email[80];
    char fone[17];
    char deletado;
};
    FILE *arq;
    arq = fopen("funcionario.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionario");
    }
    struct Funcionario funcionarios;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo do funcionário que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if (cod == funcionarios.codigo)
        {
            printf("Cod %d --- Nome: %-8s \n",funcionarios.codigo, funcionarios.nome);
            printf("CPF: %s --- Endereco: %s\n",funcionarios.cpf, funcionarios.endereco);
            printf("Email: %s --- Fone: %s\n \n",funcionarios.email, funcionarios.fone);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este funcionário? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                funcionarios.deletado = '*';
                fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
                fwrite(&funcionarios, sizeof(funcionarios), 1, arq);
                fseek(arq, sizeof(funcionarios)* 0, SEEK_END);
                retornarMensagem("\nFuncionário excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Funcionario");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Funcionario");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionario");
    }
    fclose(arq);
}
