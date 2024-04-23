#include "limparBancoDados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limparBDVeiculos(){
FILE *file = fopen("veiculo.txt", "w");
            if (file == NULL) {
                printf("=================================\n \n");
                printf("ERRO AO ABRIR ARQUIVO!");
                printf("\n \n================================= \n\n");
                return;
            }
            printf("=================================\n \n");
            printf("BANDO DE DADOS LIMPO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            fclose(file);
}

void limparBDClientes(){
            FILE *file = fopen("cliente.txt", "w");
            if (file == NULL) {
                printf("=================================\n \n");
                printf("ERRO AO ABRIR ARQUIVO!");
                printf("\n \n================================= \n\n");
                return;
            }
            printf("=================================\n \n");
            printf("BANDO DE DADOS LIMPO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            fclose(file);
}

void limparBDVendas(){
            FILE *file = fopen("vendas.txt", "w");
            if (file == NULL) {
                printf("=================================\n \n");
                printf("ERRO AO ABRIR ARQUIVO!");
                printf("\n \n================================= \n\n");
                return;
            }
            printf("=================================\n \n");
            printf("BANDO DE DADOS LIMPO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            fclose(file);
}

void limparBancoDados(){
    int n;

    printf("==================================\n \n");
    printf("ESCOLHA UMA OPÇÃO: \n");
    printf("1 - LIMPAR BANDO DE DADOS DE VEÍCULOS \n");
    printf("2 - LIMPAR BANDO DE DADOS DE CLIENTES \n");
    printf("3 - LIMPAR BANDO DE DADOS DE VENDAS");
    printf("\n \n================================== \n\n");

    printf("OPÇÃO: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            limparBDVeiculos();
            break;
        case 2:
            limparBDClientes();
            break;
        case 3:
            limparBDVendas();
            break;
        default:
            printf("===================================================\n \n");
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA.");
            printf("\n \n=================================================== \n\n");
            break;
    }
}