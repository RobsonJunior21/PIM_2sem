#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void cadastrarFuncionarios()
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
    struct Funcionario funcionarios;
    int retorno;
    arq = fopen("funcionario.pro", "ab");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do funcionário: \n");
    scanf("%d", &funcionarios.codigo);
    printf("Digite o nome do funcionário: \n");
    fflush(stdin);
    gets(funcionarios.nome);
    printf("Digite o cpf do funcionário: \n");
    scanf("%s", &funcionarios.cpf);
    printf("Digite o endereço do funcionário: \n");
    fflush(stdin);
    gets(funcionarios.endereco);
    printf("Digite o email do funcionário: \n");
    scanf("%s", &funcionarios.email);
    printf("Digite o telefone do funcionário: \n");
    scanf("%s", &funcionarios.fone);

    retorno = fwrite (&funcionarios, sizeof(funcionarios), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\n Dados do funcionário incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionarios");
    }else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do funcionário.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Funcionarios");
    }
}
