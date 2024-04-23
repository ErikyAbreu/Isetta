#include "vendas.h"
#include <stdio.h>
#include <stdlib.h>


void carregarVendas(Vendas vendas[], int *numVendas){
    FILE *file = fopen("vendas.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ARQUIVO NÃO ENCONTRADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    while (fscanf(file, "%s %lld %lld %s %d %s %s %d %f %s %d %d %d %d %d %d", vendas[*numVendas].cliente.nome, &vendas[*numVendas].cliente.cpf, &vendas[*numVendas].cliente.numero, vendas[*numVendas].cliente.email, 
                                                                                &vendas[*numVendas].veiculo.id, vendas[*numVendas].veiculo.marca, vendas[*numVendas].veiculo.modelo, &vendas[*numVendas].veiculo.ano, &vendas[*numVendas].veiculo.preco, vendas[*numVendas].vendedor, 
                                                                                &vendas[*numVendas].dataHora.dia, &vendas[*numVendas].dataHora.mes, &vendas[*numVendas].dataHora.ano, &vendas[*numVendas].dataHora.hora, &vendas[*numVendas].dataHora.minuto, &vendas[*numVendas].dataHora.segundo) 
                                                                                != EOF) {
        (*numVendas)++;
    }

    fclose(file);
}

int cadastrarVendas(Vendas vendas[], int *numVendas, Cliente clientes[],int numClientes, Veiculo veiculo[], int numVeiculos, char vendedor[MAX_CARACTERE_NOME]) {
    long long int cpf;
    int id;

    if (*numVendas >= MAX_VENDAS) {
        printf("=================================\n \n");
        printf("LIMITE DE VENDAS ALCANÇADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    listarClientes(clientes, numClientes);

    printf("\n\nINFORME O CPF DO COMPRADOR: ");
    scanf("%lld", &cpf);

    for (int i = 0; i < numClientes; i++)
    {
        if(clientes[i].cpf == cpf){
            strcpy(vendas[*numVendas].cliente.nome, clientes[i].nome); 
            vendas[*numVendas].cliente.cpf = clientes[i].cpf;
            vendas[*numVendas].cliente.numero = clientes[i].numero;
            strcpy(vendas[*numVendas].cliente.email, clientes[i].email); 
        }
    }

    listarVeiculos(veiculo, numVeiculos);

    printf("\n\nINFORME O ID DO VEÍCULO COMPRADO: ");
    scanf("%d", &id);

    for (int i = 0; i < numVeiculos; i++)
    {
        if(veiculo[i].id == id){
            vendas[*numVendas].veiculo.id = 0;
            strcpy(vendas[*numVendas].veiculo.marca, veiculo[i].marca); 
            strcpy(vendas[*numVendas].veiculo.modelo, veiculo[i].modelo);
            vendas[*numVendas].veiculo.ano = veiculo[i].ano;
            vendas[*numVendas].veiculo.preco = veiculo[i].preco;
            
        }
    }
    
    strcpy(vendas[*numVendas].vendedor, vendedor);

    vendas[*numVendas].dataHora = obterDataHoraAtual();

    printf("=================================\n \n");
    printf("VENDA REALIZADA COM SUCESSO!");
    printf("\n \n================================= \n\n");

    (*numVendas)++;
    return id;
}

void salvarVendas(Vendas vendas[], int numVendas) {
    FILE *file = fopen("vendas.txt", "w");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    for (int i = 0; i < numVendas; i++) {
        fprintf(file, "%s %lld %lld %s %d %s %s %d %f %s %d %d %d %d %d %d\n", vendas[i].cliente.nome, vendas[i].cliente.cpf, vendas[i].cliente.numero, vendas[i].cliente.email, 
                                                                                vendas[i].veiculo.id, vendas[i].veiculo.marca, vendas[i].veiculo.modelo, vendas[i].veiculo.ano, vendas[i].veiculo.preco, vendas[i].vendedor, 
                                                                                vendas[i].dataHora.dia, vendas[i].dataHora.mes, vendas[i].dataHora.ano, vendas[i].dataHora.hora, vendas[i].dataHora.minuto, vendas[i].dataHora.segundo);
    }

    fclose(file);
}

void listarVendas(Vendas vendas[], int numVendas){
    FILE *file = fopen("vendas.txt", "r");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("=================================\n \n");
    for (int i = 0; i < numVendas; i++) {
        printf("- DADOS DO COMPRADOR \n\tNOME: %s \tCPF: %lld \tTELEFONE: %lld \tE-MAIL: %s \n- DADOS DO VEÍCULO \n\tMARCA: %s \tMODELO: %s \tANO: %d \tPREÇO: %.2f \n- DADOS DA VENDA \n\tVENDEDOR: %s \tDATA: %d / %d / %d \tHORÁRIO: %d : %d : %d\n\n\n", 
                vendas[i].cliente.nome, vendas[i].cliente.cpf, vendas[i].cliente.numero, vendas[i].cliente.email, 
                vendas[i].veiculo.marca, vendas[i].veiculo.modelo, vendas[i].veiculo.ano, vendas[i].veiculo.preco, vendas[i].vendedor, 
                vendas[i].dataHora.dia, vendas[i].dataHora.mes, vendas[i].dataHora.ano, vendas[i].dataHora.hora, vendas[i].dataHora.minuto, vendas[i].dataHora.segundo);
    }
    printf("\n================================= \n\n");

    fclose(file);
}