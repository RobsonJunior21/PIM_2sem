#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void alterarCliente()

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

{
    FILE *arq;
    arq = fopen("cliente.pro", "r+b");
    if (arq == NULL)
    {
        retornarMensagem("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Cliente");
    }

    struct Cliente clientes;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo do cliente que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, arq))
    {
        if ((cod == clientes.codigo) && (clientes.deletado != '*'))
        {
            printf("Cod %d --- Nome: %-8s --- CPF: %s\n",clientes.codigo, clientes.nome, clientes.cpf);
            printf("Data de nascimento: %s --- Endereco: %s\n",clientes.aniversario, clientes.endereco);
            printf("Email: %s --- Fone: %s\n \n",clientes.email, clientes.fone);
            encontrado = 1;

            fseek(arq,sizeof(struct Cliente)*-1, SEEK_CUR);
            printf("\nDigite o novo nome: \n");
            fflush(stdin);
            gets(clientes.nome);
            printf("\nDigite o novo cpf....: \n");
            scanf("%s", &clientes.cpf);
            printf("\nDigite a nova data de nascimento....: \n");
            scanf("%s", &clientes.aniversario);
            printf("\nDigite o novo endereço....: \n");
            fflush(stdin);
            gets(clientes.endereco);
            printf("\nDigite o novo email....: \n");
            scanf("%s", &clientes.email);
            printf("\nDigite o novo telefone....: \n");
            scanf("%s", &clientes.fone);
            fwrite(&clientes, sizeof(clientes), 1, arq);
            fseek(arq, sizeof(clientes)* 0, SEEK_END);

            retornarMensagem("\n Dados do cliente alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
            montarMenu("Cliente");
        }
    }
        if (!encontrado)
    {
        retornarMensagem("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Cliente");
    }
    fclose(arq);
}
