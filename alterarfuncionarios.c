#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void alterarFuncionarios()
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
    printf ("\nDigite o código do funcionário que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((cod == funcionarios.codigo) && (funcionarios.deletado != '*'))
        {
            printf("Cod %d --- Nome: %-8s \n,", funcionarios.codigo, funcionarios.nome);
            printf("CPF: %s --- Endereco: %s\n",funcionarios.cpf, funcionarios.endereco);
            printf("Email: %s --- Fone: %s\n \n",funcionarios.email, funcionarios.fone);
            encontrado = 1;

                       fseek(arq,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite o novo nome: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("\nDigite o novo cpf....: \n");
            scanf("%s", &funcionarios.cpf);
            printf("\nDigite o novo endereço....: \n");
            fflush(stdin);
            gets(funcionarios.endereco);
            printf("\nDigite o novo email....: \n");
            scanf("%s", &funcionarios.email);
            printf("\nDigite o novo telefone....: \n");
            scanf("%s", &funcionarios.fone);
            fwrite(&funcionarios, sizeof(funcionarios), 1, arq);
            fseek(arq, sizeof(funcionarios)* 0, SEEK_END);

            retornarMensagem("\n Dados do funcionário alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Funcionario");
        }
    }
    if (!encontrado)
    {
        retornarMensagem("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionario");
    }
    fclose(arq);
}
