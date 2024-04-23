#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_CLIENTE 100

typedef struct PessoaCliente{
    char nome[30];
    long long int cpf;
    long long int numero;
    char email[30];
} Cliente;

void carregarCliente(Cliente cliente[], int *numCliente);
void cadastrarCliente(Cliente cliente[], int *numCliente);
void salvarCliente(Cliente cliente[], int numCliente);
void listarClientes(Cliente cliente[], int numCliente);
void editarCliente(Cliente cliente[], int numCliente);
void excluirCliente(Cliente cliente[], int *numCliente);

#endif