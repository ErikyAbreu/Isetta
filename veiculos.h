#ifndef VEICULOS_H
#define VEICULOS_H

#define MAX_VEICULO 100

typedef struct Carro {
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    float preco;
} Veiculo;

void carregarVeiculos(Veiculo veiculo[], int *numVeiculo);
void cadastrarVeiculo(Veiculo veiculo[], int *numVeiculo);
void salvarVeiculo(Veiculo veiculo[], int numVeiculo);
void listarVeiculos(Veiculo veiculo[], int numVeiculo);
void editarVeiculo(Veiculo veiculo[], int numVeiculo);
void excluirVeiculo(Veiculo veiculo[], int *numVeiculo, int id);
void buscarVeiculo(Veiculo veiculo[], int numVeiculo);

#endif
