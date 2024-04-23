#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregarCliente(Cliente cliente[], int *numCliente){
    FILE *file = fopen("cliente.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ARQUIVO NÃO ENCONTRADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    while (fscanf(file, "%s %lld %lld %s", cliente[*numCliente].nome, &cliente[*numCliente].cpf, &cliente[*numCliente].numero, cliente[*numCliente].email) != EOF) {
        (*numCliente)++;
    }

    fclose(file);
}

void cadastrarCliente(Cliente cliente[], int *numCliente) {
    if (*numCliente >= MAX_CLIENTE) {
        printf("=================================\n \n");
        printf("LIMITE DE CLIENTES ALCANÇADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("INFORME O NOME DO CLIENTE: ");
    scanf("%s", cliente[*numCliente].nome);

    printf("INFORME O CPF DO CLIENTE (SOMENTE OS NÚMEROS): ");
    scanf("%lld", &cliente[*numCliente].cpf);

    for (int i = 0; i < *numCliente; i++) {
        if (cliente[i].cpf == cliente[*numCliente].cpf) {
            printf("=================================\n \n");
            printf("USUÁRIO JÁ CADASTRADO!");
            printf("\n \n================================= \n\n");
            return;
        }
    }

    printf("INFORME O TELEFONE DO CLIENTE (SOMENTE OS NÚMEROS): ");
    scanf("%lld", &cliente[*numCliente].numero);

	printf("INFORME O E-MAIL DO CLIENTE: ");
    scanf("%s", cliente[*numCliente].email);

    if (strlen(cliente[*numCliente].email) >= 80 || strchr(cliente[*numCliente].email, '@') == NULL) {
        printf("=================================\n \n");
        printf("NOME DO USUÁRIO INVÁLIDO! \nDEVE CONTER '@' E POSSUIR MENOS DE 80 CARACTERES.");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("=================================\n \n");
    printf("CLIENTE CADASTRADO COM SUCESSO!");
    printf("\n \n================================= \n\n");

    (*numCliente)++;
}

void salvarCliente(Cliente cliente[], int numCliente) {
    FILE *file = fopen("cliente.txt", "w");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    for (int i = 0; i < numCliente; i++) {
        fprintf(file, "%s %lld %lld %s\n", cliente[i].nome, cliente[i].cpf, cliente[i].numero, cliente[i].email);
    }

    fclose(file);
}

void listarClientes(Cliente cliente[], int numCliente){
    FILE *file = fopen("cliente.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("=================================\n \n");
    for (int i = 0; i < numCliente; i++) {
        printf("NOME: %s \t CPF: %lld \t TELEFONE: %lld \t E-MAIL: %s \n", cliente[i].nome, cliente[i].cpf, cliente[i].numero, cliente[i].email);
    }
    printf("\n================================= \n\n");
    fclose(file);
}

void editarCliente(Cliente cliente[], int numCliente) {
    char nome[30];
    long long int cpf;
    long long int numero;
    char email[30];
    int opcao = 0;

    listarClientes(cliente, numCliente);

    printf("\nINFORME O CPF DO CLIENTE QUE DESEJA EDITAR: ");
    scanf("%lld", &cpf);

    for (int i = 0; i < numCliente; i++) {
        if (cliente[i].cpf == cpf) {
            printf("==================================\n \n");
            printf("ESCOLHA UMA OPÇÃO: \n");
            printf("1 - EDITAR NOME \n");
            printf("2 - EDITAR CPF \n");
            printf("3 - EDITAR NÚMERO \n");
            printf("4 - EDITAR E-MAIL");
            printf("\n \n================================== \n\n");

            printf("OPÇÃO: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("INFORME O NOVO NOME: ");
                    scanf("%s", nome);

                    strcpy(cliente[i].nome, nome);
                    printf("=================================\n \n");
                    printf("NOME ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 2:
                    printf("INFORME O NOVO CPF: ");
                    scanf("%lld", &cpf);

                    cliente[i].cpf = cpf;
                    printf("=================================\n \n");
                    printf("CPF ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 3:
                    printf("INFORME O NOVO TELEFONE: ");
                    scanf("%lld", &numero);

                    cliente[i].numero = numero;
                    printf("=================================\n \n");
                    printf("TELEFONE ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 4:
                    printf("INFORME O NOVO E-MAIL: ");
                    scanf("%s", email);

                    strcpy(cliente[i].email, email);
                    printf("=================================\n \n");
                    printf("E-MAIL ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                default:
                    printf("===================================================\n \n");
                    printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA.");
                    printf("\n \n=================================================== \n\n");
                }
            return;
        } 
    }
    printf("=================================\n \n");
    printf("CLIENTE NÃO ENCONTRADO!");
    printf("\n \n================================= \n\n");
}

void excluirCliente(Cliente cliente[], int *numCliente) {
    long long int cpf;

    listarClientes(cliente, *numCliente);

    printf("INFORME O CPF DO CLIENTE QUE DESEJA EXCLUIR: ");
    scanf("%lld", &cpf);

    for (int i = 0; i < *numCliente; i++) {
        if (cliente[i].cpf == cpf) {
            for (int j = i; j < *numCliente - 1; j++) {
                strcpy(cliente[j].nome, cliente[j + 1].nome);
                cliente[j].cpf = cliente[j + 1].cpf;
                cliente[j].numero = cliente[j + 1].numero;
                strcpy(cliente[j].email, cliente[j + 1].email);
            }
            (*numCliente)--;
            printf("=================================\n \n");
            printf("CLIENTE EXCLUÍDO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            return;
        }
    }
    printf("=================================\n \n");
    printf("CLIENTE NÃO ENCONTRADO!");
    printf("\n \n================================= \n\n");
}