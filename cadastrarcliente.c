#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void cadastrarCliente()
{
    struct Cliente{
        int codigo;
        char nome[50];
        char cpf[12];
        char aniversario[11];
        char endereco[50];
        char email[80];
        char fone[17];
        char dataRegistro[15];
        char deletado;
};
    FILE *arq;

    struct Cliente clientes;
    int retorno;
    arq = fopen("cliente.pro", "ab");
    if (arq == NULL)
    {
        retornarMensagem("Erro ao abrir arquivo");
        return;
    }
    printf("Digite o codigo do cliente: \n");
    scanf("%d", &clientes.codigo);
    printf("Digite o nome do cliente: \n");
    fflush(stdin);
    gets(clientes.nome);
    printf("Digite o cpf do cliente: \n");
    scanf("%s", &clientes.cpf);
    printf("Digite a data de nascimento do cliente: \n");
    scanf("%s", &clientes.aniversario);
    printf("Digite o endereço do cliente: \n");
    fflush(stdin);
    gets(clientes.endereco);
    printf("Digite o email do cliente: \n");
    scanf("%s", &clientes.email);
    printf("Digite o fone do cliente: \n");
    scanf("%s", &clientes.fone);

    retorno = fwrite (&clientes, sizeof(clientes), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        retornarMensagem("\n Dados do cliente incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Cliente");
    }else
    {
        fclose (arq);
        retornarMensagem("\n Falha ao gravar dados do cliente.");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Cliente");
    }
}
