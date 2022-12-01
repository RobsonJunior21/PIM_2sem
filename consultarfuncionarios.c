#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void consultarFuncionarios()
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
     arq = fopen("funcionario.pro", "rb");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionario");
    }
    struct Funcionario funcionarios;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do funcionário que procura: \n");
    scanf ("%d", &cod);

    while (fread (&funcionarios, sizeof(funcionarios), 1, arq))
    {
        if ((cod == funcionarios.codigo) && (funcionarios.deletado != '*'))
        {
            printf("Cod %d --- Nome: %-8s \n",funcionarios.codigo, funcionarios.nome);
            printf("CPF: %s --- Endereco: %s\n",funcionarios.cpf, funcionarios.endereco);
            printf("Email: %s --- Fone: %s\n \n",funcionarios.email, funcionarios.fone);
            encontrado = 1;

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
