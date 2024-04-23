#ifndef VENDAS_H
#define VENDAS_H

#include "clientes.h"
#include "dataHora.h"
#include "veiculos.h"
#include "usuarios.h"

#define MAX_VENDAS 100

typedef struct HistoricoDeVendas {
    Cliente cliente;
    Veiculo veiculo;
    char vendedor[MAX_CARACTERE_NOME];
    DataHora dataHora;
} Vendas;

void carregarVendas(Vendas vendas[], int *numVendas);
int cadastrarVendas(Vendas vendas[], int *numVendas, Cliente clientes[], int numClientes, Veiculo veiculo[], int numVeiculos, char vendedor[MAX_CARACTERE_NOME]);
void salvarVendas(Vendas vendas[], int numVendas);
void listarVendas(Vendas vendas[], int numVendas);

#endif
