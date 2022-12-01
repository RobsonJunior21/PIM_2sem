#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

void excluirCliente()
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
    char certeza;
    printf ("\nDigite o codigo do cliente que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, arq))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d --- Nome: %-8s --- CPF: %s\n",clientes.codigo, clientes.nome, clientes.cpf);
            printf("Data de nascimento: %s --- Endereco: %s\n",clientes.aniversario, clientes.endereco);
            printf("Email: %s --- Fone: %s\n \n",clientes.email, clientes.fone);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este cliente? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                clientes.deletado = '*';
                fseek(arq,sizeof(struct Cliente)*-1, SEEK_CUR);
                fwrite(&clientes, sizeof(clientes), 1, arq);
                fseek(arq, sizeof(clientes)* 0, SEEK_END);
                retornarMensagem("\nCliente excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                montarMenu("Cliente");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                montarMenu("Cliente");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        montarMenu("Cliente");
    }
    fclose(arq);
}
