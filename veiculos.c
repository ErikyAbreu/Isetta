#include "veiculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void carregarVeiculos(Veiculo veiculo[], int *numVeiculo){
    FILE *file = fopen("veiculo.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ARQUIVO NÃO ENCONTRADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    while (fscanf(file, "%d %s %s %d %f", &veiculo[*numVeiculo].id, veiculo[*numVeiculo].marca, veiculo[*numVeiculo].modelo, &veiculo[*numVeiculo].ano, &veiculo[*numVeiculo].preco) != EOF) {
        (*numVeiculo)++;
    }

    fclose(file);
}

void cadastrarVeiculo(Veiculo veiculo[], int *numVeiculo) {
    if (*numVeiculo >= MAX_VEICULO) {
        printf("=================================\n \n");
        printf("LIMITE DE VEÍCULO ALCANÇADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    veiculo[*numVeiculo].id = *numVeiculo;

    printf("INFORME A MARCA DO VEÍCULO: ");
    scanf("%s", veiculo[*numVeiculo].marca);

    printf("INFORME O MODELO DO VEÍCULO: ");
    scanf("%s", veiculo[*numVeiculo].modelo);

    printf("INFORME O ANO DE FABRICAÇÃO DO VEÍCULO: ");
    scanf("%d", &veiculo[*numVeiculo].ano);

	printf("INFORME O PREÇO DO VEÍCULO: ");
    scanf("%f", &veiculo[*numVeiculo].preco);

    printf("=================================\n \n");
    printf("VEÍCULO CADASTRADO COM SUCESSO!");
    printf("\n \n================================= \n\n");

    (*numVeiculo)++;
}

void salvarVeiculo(Veiculo veiculo[], int numVeiculo) {
    FILE *file = fopen("veiculo.txt", "w");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    for (int i = 0; i < numVeiculo; i++) {
        fprintf(file, "%d %s %s %d %.2f\n", veiculo[i].id, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco);
    }

    fclose(file);
}

void listarVeiculos(Veiculo veiculo[], int numVeiculo){
    FILE *file = fopen("veiculo.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("=================================\n \n");
    for (int i = 0; i < numVeiculo; i++) {
        printf("ID: %d \t MARCA: %s \t MODELO: %s \t ANO: %d \t PREÇO: %.2f \n", veiculo[i].id, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco);
    }
    printf("\n================================= \n\n");
    fclose(file);
}

void editarVeiculo(Veiculo veiculo[], int numVeiculo) {
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    float preco;
    int opcao = 0;

    listarVeiculos(veiculo, numVeiculo);

    printf("\n\nINFORME O ID DO VEÍCULO QUE DESEJA EDITAR: ");
    scanf("%d", &id);

    for (int i = 0; i < numVeiculo; i++) {
        if (veiculo[i].id == id) {
            printf("==================================\n \n");
            printf("ESCOLHA UMA OPÇÃO: \n");
            printf("1 - EDITAR MARCA \n");
            printf("2 - EDITAR MODELO \n");
            printf("3 - EDITAR ANO \n");
            printf("4 - EDITAR PREÇO");
            printf("\n \n================================== \n\n");

            printf("OPÇÃO: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("INFORME A NOVA MARCA: ");
                    scanf("%s", marca);

                    strcpy(veiculo[i].marca, marca);
                    printf("=================================\n \n");
                    printf("MARCA ATUALIZADA COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 2:
                    printf("INFORME O NOVO MODELO: ");
                    scanf("%s", modelo);

                    strcpy(veiculo[i].modelo, modelo);
                    printf("=================================\n \n");
                    printf("MODELO ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 3:
                    printf("INFORME O ANO: ");
                    scanf("%d", &ano);

                    veiculo[i].ano = ano;
                    printf("=================================\n \n");
                    printf("ANO ATUALIZADO COM SUCESSO!");
                    printf("\n \n================================= \n\n");
                    break;
                case 4:
                    printf("INFORME O NOVO PREÇO: ");
                    scanf("%f", &preco);

                    veiculo[i].preco = preco;
                    printf("=================================\n \n");
                    printf("PREÇO ATUALIZADO COM SUCESSO!");
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
    printf("VEÍCULO NÃO ENCONTRADO!");
    printf("\n \n================================= \n\n");
}

void excluirVeiculo(Veiculo veiculo[], int *numVeiculo, int id) {

    for (int i = 0; i < *numVeiculo; i++) {
        if (veiculo[i].id == id) {
            for (int j = i; j < *numVeiculo - 1; j++) {
                strcpy(veiculo[j].marca, veiculo[j + 1].marca);
                strcpy(veiculo[j].modelo, veiculo[j + 1].modelo);
                veiculo[j].ano = veiculo[j + 1].ano;
                veiculo[j].preco = veiculo[j + 1].preco;
            }
            (*numVeiculo)--;
            printf("=================================\n \n");
            printf("VEÍCULO EXCLUÍDO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            return;
        }
    }
    printf("=================================\n \n");
    printf("VEÍCULO NÃO ENCONTRADO!");
    printf("\n \n================================= \n\n");
}

void buscarVeiculo(Veiculo veiculo[], int numVeiculo){
    char marca[30];
    char modelo[30];
    int ano;
    int opcao;
    int vazio = 0;

    printf("==================================\n \n");
    printf("ESCOLHA UMA OPÇÃO: \n");
    printf("1 - BUSCAR POR MARCA \n");
    printf("2 - BUSCAR POR MODELO \n");
    printf("3 - BUSCAR POR ANO");
    printf("\n \n================================== \n\n");

    printf("OPÇÃO: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("INFORME A MARCA QUE DESEJA: ");
            scanf("%s", marca);

            printf("=================================\n \n");
            for (int i = 0; i < numVeiculo; i++) {
                if(strcmp(veiculo[i].marca, marca) == 0){
                    printf("ID: %d \t MARCA: %s \t MODELO: %s \t ANO: %d \t PREÇO: %.2f \n", veiculo[i].id, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco);
                    vazio = 1;
            }}printf("\n================================= \n\n"); 
            if(vazio == 0){
                printf("====================================================\n \n");
                printf("NENHUM VEÍCULO É COMPATÍVEL COM ESSA CARACTERÍSTICA!");
                printf("\n \n==================================================== \n\n");
            }

            break;
        case 2:
            printf("INFORME O MODELO QUE DESEJA: ");
            scanf("%s", modelo);

            printf("=================================\n \n");
            for (int i = 0; i < numVeiculo; i++) {
                if(strcmp(veiculo[i].modelo, modelo) == 0){
                    printf("ID: %d \t MARCA: %s \t MODELO: %s \t ANO: %d \t PREÇO: %.2f \n", veiculo[i].id, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco);
                    vazio = 1;
            }}printf("\n================================= \n\n");
            if(vazio == 0){
                printf("====================================================\n \n");
                printf("NENHUM VEÍCULO É COMPATÍVEL COM ESSA CARACTERÍSTICA!\n");
                printf("\n \n==================================================== \n\n");
            }

            break;
        case 3:
            printf("INFORME O ANO QUE DESEJA: ");
            scanf("%d", &ano);

            printf("=================================\n \n");
            for (int i = 0; i < numVeiculo; i++) {
                if(veiculo[i].ano == ano){
                    printf("ID: %d \t MARCA: %s \t MODELO: %s \t ANO: %d \t PREÇO: %.2f \n", veiculo[i].id, veiculo[i].marca, veiculo[i].modelo, veiculo[i].ano, veiculo[i].preco);
                    vazio = 1;
            }}printf("\n================================= \n\n");
            if(vazio == 0){
                printf("====================================================\n \n");
                printf("NENHUM VEÍCULO É COMPATÍVEL COM ESSA CARACTERÍSTICA\n");
                printf("\n \n==================================================== \n\n");
            }
            break;
        default:
            printf("====================================================\n \n");
            printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA.");
            printf("\n \n==================================================== \n\n");
            break;
    }

}