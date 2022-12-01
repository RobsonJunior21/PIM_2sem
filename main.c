#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include "cadastro.h"


struct Relatorio{
int codigo;
float orcamento, lucro, despesa;
char observ[250];
char deletado;
};

struct Funcionario {
int codigo;
char nome[50];
char cpf[12];
char endereco[50];
char email[80];
char fone[17];
char deletado;
};

struct Produto {
int codigo;
char descricao[50];
float valor;
char deletado;
};

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
FILE *pont_arq;

void criptografia(void);
void montarMenu(const char* funcionalidade);
void gerenciarMenu(int opcao, const char* funcionalidade);
void menuAdministrador(void);
void menuCliente(void);
void retornarMensagem(const char* mensagem);
void montarMenuPrincipal(void);
void gerenciarMenuPrincipal(int opcao);
void menuOperador(void);
void sair(void);

void cadastrarCliente(void);
void alterarCliente(void);
void consultarCliente(void);
void excluirCliente(void);

void cadastrarEstoqueProdutos(void);
void alterarEstoqueProdutos(void);
void consultarEstoqueProdutos(void);
void excluirEstoqueProdutos(void);

void cadastrarFuncionario(void);
void alterarFuncionario(void);
void consultarFuncionario(void);
void excluirFuncionario(void);

void cadastrarRelatorios(void);
void alterarRelatorios(void);
void consultarRelatorios(void);
void excluirRelatorios(void);

void retornarMensagem(const char* mensagem)
{
    printf(mensagem);
    return;
}


void sobre()
{
    printf("\n\n\t\t\tPIM\n\n");
    printf("\tAnálise e Desenvolvimento de Sistemas\n\tPIM - Projeto Integrado Multidisciplinar\n");
    printf("\tIntegrantes:\n\t\tJoão Augusto\n\t\tRobson de Oliveira Júnior\n\t\tJúlia Gomes de Jesus\n\t\tTales Novaes de Oliveira Moraes\n\n\t");
    printf("Pressione qualquer tecla para retornar.");
    getch();
    system("cls || clear");
    montarMenuPrincipal();
}

void menuAdministrador()
{
    int continuar = 0;

    printf("\n\tMenu de Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Cliente\n");
    printf("2. Gerenciar Produtos\n");
    printf("3. Gerenciar Funcionários\n");
    printf("4. Gerenciar Relatórios\n");
    printf("5. Criptografia\n");
    printf("6. Voltar ao Menu Principal\n");
    printf("7. Sair\n");

    scanf("%i", &continuar);
    system("cls || clear");

    switch(continuar)
    {
        case 1:
            montarMenu("Cliente");
            break;
        case 2:
            montarMenu("Produtos");
            break;
        case 3:
            montarMenu("Funcionario");
            break;
        case 4:
            montarMenu("Relatórios");
            break;
        case 5:
            criptografia();
        break;
        case 6:
            montarMenuPrincipal();
            break;
        case 7:
            exit(1);
            break;
        default:
            retornarMensagem("Digite uma opcao valida\n");
            system("pause");
    }
}
void montarMenu(const char* funcionalidade)
{
   int opcao = 0;
    printf("\n\tMenu de Administrador - %s\n\n", funcionalidade);
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar %s\n", funcionalidade);
    printf("2. Alterar %s\n", funcionalidade);
    printf("3. Consultar %s\n", funcionalidade);
    printf("4. Excluir %s\n", funcionalidade);
    printf("5. Voltar ao Menu Principal\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenu(opcao, funcionalidade);
}
void gerenciarMenu(int opcao, const char* funcionalidade)
{
    char funcao;
    switch(opcao)
    {
        case 1:
            if(funcionalidade == "Cliente")
            {
                cadastrarCliente();
            }
            else if (funcionalidade == "Produtos")
            {
                cadastrarEstoqueProdutos();
            }
            else if (funcionalidade == "Funcionario")
            {
                cadastrarFuncionarios();
            }
            else
            {
                cadastrarRelatorios();
            }
            break;

        case 2:
            if(funcionalidade == "Cliente")
            {
                alterarCliente();
            }
            else if (funcionalidade == "Produtos")
            {
                alterarEstoqueProdutos();
            }
            else if (funcionalidade == "Funcionario")
            {
                alterarFuncionarios();
            }
            else
            {
                alterarRelatorios();
            }
            break;

        case 3:
            if(funcionalidade == "Cliente")
            {
                consultarCliente();
            }
            else if (funcionalidade == "Produtos")
            {
                consultarEstoqueProdutos();
            }
            else if (funcionalidade == "Funcionario")
            {
                consultarFuncionarios();
            }
            else
            {
                consultarRelatorios();
            }
            break;

        case 4:
            if(funcionalidade == "Cliente")
            {
                excluirCliente();
            }
            else if (funcionalidade == "Produtos")
            {
                excluirEstoqueProdutos();
            }
            else if (funcionalidade == "Funcionario")
            {
                excluirFuncionarios();
            }
            else
            {
                excluirRelatorios();
            }
            break;
        case 5:
            menuAdministrador();
            break;
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}

void montarMenuPrincipal()
{
    int opcao = 0;
    printf("\n\tMenu Principal\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Menu Principal\n");
    printf("2. Sobre\n");
    printf("3. Sair\n");
    system("pause>nul");
    scanf("%i", &opcao);
    system("cls || clear");
    gerenciarMenuPrincipal(opcao);
}
void gerenciarMenuPrincipal(int opcao)
{
    switch(opcao)
    {
        case 1:
            menuAdministrador();
            break;
        case 2:
            sobre();
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("Digite uma opcao valida\n");
            system("pause");
    }
}

void criptografia()
{
    FILE *origem, *destino;
    int opcao;

    puts("Opções de criptografia");
    puts("Digite 1 ou 2 conforme abaixo:");
    puts("  1 - Criptografar");
    puts("  2 - Descriptografar");

    scanf("%d", &opcao);

    if (opcao == 1)
    {

        origem = fopen("origem.txt", "r");
        destino = fopen("destino.txt", "w");

        if(origem != NULL && destino != NULL)
        {
            char c;
            int contador = 0;
            int i = 0;

            while(( c = fgetc(origem)) != EOF)
            {
                contador++;

                i = c;
                i = i * contador;

                fprintf(destino,"%i ", i);
                printf("%i", i);
            }

            fclose(origem);
            fclose(destino);

        }
        else
        {
            puts("Erro de leitura/escrita nos arquivos...");
        }

    }
    else if(opcao == 2)
    {
        origem = fopen("destino.txt", "r");
        destino = fopen("descriptografado.txt", "w");

        if(origem != NULL && destino != NULL)
        {
            int contador = 0;
            char c[100];
            int i = 0;

            while(fscanf(origem, "%s", c) != EOF)
            {
                contador++;

                i = atoi(c);
                i /= contador;

                printf("%c", i);

                fprintf(destino,"%c", i);
            }

            fclose(origem);
            fclose(destino);
        }
    }
    else
    {
        puts("Opcao invalida...");
    }
    puts("\n");
    system("pause");
}

int main()
{
	int var;
   	 setlocale(LC_ALL,"Portuguese");
   	 system("title PIM - Projeto Integrado Multidisciplinar");
     system("color 07");
     cadastro();

}
