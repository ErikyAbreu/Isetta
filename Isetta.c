#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_USUARIO 10
#define MAX_CARACTERE_EMAIL 80
#define MAX_CARACTERE_NOME 30
#define MAX_CARACTERE_SENHA 30
#define MAX_VEICULO 100
#define MAX_CLIENTE 100
#define MAX_VENDAS 100

typedef struct Pessoa {
    char email[MAX_CARACTERE_EMAIL];
    char nome[MAX_CARACTERE_NOME];
    char senha[MAX_CARACTERE_SENHA];
} Usuario;

typedef struct Carro{
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    float preco;
} Veiculo;

typedef struct PessoaCliente{
    char nome[30];
    long long cpf;
    long long numero;
    char email[30];
}Cliente;

typedef struct Data{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DataHora;

typedef struct HistoricoDeVendas{
    Cliente cliente;
    Veiculo veiculo;
    char vendedor[MAX_CARACTERE_NOME];
    DataHora dataHora;
}Vendas;

void carregarUsuarios(Usuario usuario[], int *numUsuarios);
void cadastrarUsuario(Usuario usuario[], int *numUsuario);
void salvarUsuarios(Usuario usuario[], int numUsuario);
void salvarUsuarios(Usuario usuario[], int numUsuario);
void excluirUsuario(Usuario usuario[], int *numUsuario, char email[MAX_CARACTERE_EMAIL]);
int realizarLogin(Usuario usuario[], int numUsuario, char *email, char *senha);
void carregarVeiculos(Veiculo veiculo[], int *numVeiculo);
void cadastrarVeiculo(Veiculo veiculo[], int *numVeiculo);
void salvarVeiculo(Veiculo veiculo[], int numVeiculo);
void listarVeiculos(Veiculo veiculo[], int numVeiculo);
void editarVeiculo(Veiculo veiculo[], int numVeiculo);
void excluirVeiculo(Veiculo veiculo[], int *numVeiculo, int id);
void buscarVeiculo(Veiculo veiculo[], int numVeiculo);
void carregarCliente(Cliente cliente[], int *numCliente);
void cadastrarCliente(Cliente cliente[], int *numCliente);
void salvarCliente(Cliente cliente[], int numCliente);
void listarClientes(Cliente cliente[], int numCliente);
void editarCliente(Cliente cliente[], int numCliente);
void excluirCliente(Cliente cliente[], int *numCliente);
void carregarVendas(Vendas vendas[], int *numVendas);
int cadastrarVendas(Vendas vendas[], int *numVendas, Cliente clientes[],int numClientes, Veiculo veiculo[], int numVeiculos, char vendedor[MAX_CARACTERE_NOME]);
void salvarVendas(Vendas vendas[], int numVendas);
void listarVendas(Vendas vendas[], int numVendas);
void limparBancoDados();

int main(void){
    Usuario usuario[MAX_USUARIO];
    int numUsuario = 0;
    char email[MAX_CARACTERE_EMAIL];
    char senha[MAX_CARACTERE_SENHA];
    char vendedor[MAX_CARACTERE_NOME];
    int menu;
    Veiculo veiculo[MAX_VEICULO];
    int numVeiculo = 0;
    int menuSistema = 0;
    Cliente cliente[MAX_CLIENTE];
    int numCliente = 0;
    Vendas vendas[MAX_VENDAS];
    int numVendas = 0;
    int id;

    setlocale(LC_ALL, "");

    printf("=================================\n \n \n");
    printf("SEJA BEM-VINDO AO SISTEMA ISETTA!");
    printf("\n \n \n================================= \n\n");

    system("pause");

    carregarUsuarios(usuario, &numUsuario);

    do {
        printf("==================================\n \n");
        printf("ESCOLHA UMA OPÇÃO: \n");
        printf("1 - CADASTRAR USUÁRIO \n");
        printf("2 - REALIZAR LOGIN \n");
        printf("3 - DESCRIÇÃO DO SISTEMA \n");
        printf("0 - FECHAR SISTEMA ");
        printf("\n \n================================== \n\n");

        printf("OPÇÃO: ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                printf("==================================\n \n");
                printf("FINALIZANDO O SISTEMA ISETTA.");
                printf("\n \n================================== \n\n");

                system("pause");
                break;
            case 1:
                cadastrarUsuario(usuario, &numUsuario);
                salvarUsuarios(usuario, numUsuario);
                system("pause");
                break;
            case 2:
                printf("INFORME O EMAIL DO USUÁRIO: ");
                scanf("%s", email);

                printf("INFORME A SENHA: ");
                scanf("%s", senha);

                int indiceUsuario = realizarLogin(usuario, numUsuario, email, senha);
                if (indiceUsuario != -1) {
                    printf("======================================\n \n");
                    printf("LOGIN BEM-SUCEDIDO! BEM-VINDO, %s.", usuario[indiceUsuario].nome);
                    printf("\n \n====================================== \n\n");

                    carregarVeiculos(veiculo, &numVeiculo);
                    carregarCliente(cliente, &numCliente);
                    carregarVendas(vendas, &numVendas);

                    system("pause");
                    
                    do {
                        printf("==================================\n \n");
                        printf("ESCOLHA UMA OPÇÃO: \n");
                        printf("1 - CADASTRAR VEÍCULO \n");
                        printf("2 - EDITAR VEÍCULO\n");
                        printf("3 - EXCLUIR VEÍCULO\n");
                        printf("4 - VENDER VEÍCULO\n");
                        printf("5 - LISTAR VEÍCULOS \n");
                        printf("6 - BUSCAR VEÍCULO\n");
                        printf("7 - CADASTRAR CLIENTE\n");
                        printf("8 - EDITAR CLIENTE\n");
                        printf("9 - EXCLUIR CLIENTE\n");
                        printf("10 - HISTÓRICO DE VENDAS\n");
                        printf("11 - LIMPAR BANCO DE DADOS\n");
                        printf("12 - EXCLUIR CONTA\n");
                        printf("0 - SAIR ");
                        printf("\n \n================================== \n\n");

                        printf("OPÇÃO: ");
                        scanf("%d", &menuSistema);

                        switch (menuSistema){
                            case 0:
                                break;
                            case 1:
                                cadastrarVeiculo(veiculo, &numVeiculo);
                                salvarVeiculo(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 2:
                                editarVeiculo(veiculo, numVeiculo);
                                salvarVeiculo(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 3:
                                listarVeiculos(veiculo, numVeiculo);
                                printf("INFORME O IDENTIFICADOR DO VEÍCULO QUE DESEJA EXCLUIR: ");
                                scanf("%d", &id);
                                excluirVeiculo(veiculo, &numVeiculo, id);
                                salvarVeiculo(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 4:
                                for(int i = 0; i < numUsuario; i++){
                                    if(strcmp(usuario[i].email, email) == 0){
                                      strcpy(vendedor, usuario[i].nome);   
                                    }
                                }

                                id = cadastrarVendas(vendas, &numVendas, cliente, numCliente, veiculo, numVeiculo, vendedor);
                                salvarVendas(vendas, numVendas);
                                excluirVeiculo(veiculo, &numVeiculo, id);
                                salvarVeiculo(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 5:
                                listarVeiculos(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 6:
                                buscarVeiculo(veiculo, numVeiculo);
                                system("pause");
                                break;
                            case 7:
                                cadastrarCliente(cliente, &numCliente);
                                salvarCliente(cliente, numCliente);
                                system("pause");
                                break;
                            case 8:
                                editarCliente(cliente, numCliente);
                                salvarCliente(cliente, numCliente);
                                system("pause");
                                break;
                            case 9:
                                excluirCliente(cliente, &numCliente);
                                salvarCliente(cliente, numCliente);
                                system("pause");
                                break;
                            case 10:
                                listarVendas(vendas, numVendas);
                                system("pause");
                                break;
                            case 11:
                                limparBancoDados();
                                printf("===================================================\n \n");
                                printf("PARA SEGURANÇA DO SISTEMA, O ISETTA SERÁ FINALIZADO!");
                                printf("\n \n=================================================== \n\n");
                                system("pause");
                                menuSistema = 0;
                                menu = 0;
                                break;
                            case 12:
                                excluirUsuario(usuario, &numUsuario, email);
                                salvarUsuarios(usuario, numUsuario);
                                printf("====================================\n \n");
                                printf("VOCÊ FOI DESLOGADO DO SISTEMA ISETTA!");
                                printf("\n \n==================================== \n\n");
                                system("pause");
                                menuSistema = 0;
                                break;
                            default:
                                printf("===================================================\n \n");
                                printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA.\n");
                                printf("\n \n=================================================== \n\n");
                                system("pause");
                        } 
                        }while (menuSistema != 0);
        
                } else {
                    printf("====================================\n \n");
                    printf("NOME DO USUÁRIO OU SENHA INCORRETOS.\n");
                    printf("\n \n==================================== \n\n");
                    system("pause");
                }
                break;
            case 3:
                printf("============================================================================\n \n");
                printf("                               SISTEMA ISETTA\n");
                printf("O SISTEMA DE VENDAS DE VEÍCULOS ISETTA É UMA PLATAFORMA DESENVOLVIDA PARA\nFACILITAR E OTIMIZAR AS ATIVIDADES RELACIONADAS À VENDA DE AUTOMÓVEIS.\nTENDO O NOME INSPIRADO NO PRIMEIRO CARRO FABRICADO NO BRASIL, O ISETTA\nOFERECE UMA INTERFACE INTUITIVA E FUNCIONALIDADES ABRANGENTES QUE ATENDEM\nÀS NECESSIDADES DE CONCESSIONÁRIAS E REVENDEDORES DE VEÍCULOS. ELE PERMITE\nO CADASTRO, EDIÇÃO E EXCLUSÃO DE VEÍCULOS, ALÉM DE FACILITAR O PROCESSO DE\nVENDA AO REGISTRAR INFORMAÇÕES DETALHADAS SOBRE O VEÍCULO E O CLIENTE. O\nSISTEMA TAMBÉM OFERECE RECURSOS PARA O CADASTRO E GERENCIAMENTO DE CLIENTES,\nBEM COMO UM HISTÓRICO DE VENDAS PARA ANÁLISES FINANCEIRAS. ALÉM DISSO, O\nISETTA POSSUI FUNCIONALIDADES PARA LIMPEZA DO BANCO DE DADOS E EXCLUSÃO DE\nCONTAS DE USUÁRIO, GARANTINDO PRIVACIDADE E SEGURANÇA DAS INFORMAÇÕES.\nCOM O ISETTA, AS CONCESSIONÁRIAS E REVENDAS DE VEÍCULOS PODEM GERENCIAR\nDE FORMA EFICIENTE O ESTOQUE, OS CLIENTES E AS VENDAS, CONTRIBUINDO PARA\nA OTIMIZAÇÃO DOS PROCESSOS E O AUMENTO DA PRODUTIVIDADE.");
                printf("\n \n============================================================================ \n\n");
                system("pause");
                break;
            default:
                printf("===================================================\n \n");
                printf("OPÇÃO INVÁLIDA! POR FAVOR, ESCOLHA UMA OPÇÃO VÁLIDA.\n");
                printf("\n \n=================================================== \n\n");
                system("pause");
        }
    } while (menu != 0);
        
    return 0;
}

DataHora obterDataHoraAtual() {
    DataHora dataHoraAtual;
    
    time_t agora;
    time(&agora);
    struct tm *local = localtime(&agora);

    dataHoraAtual.dia = local->tm_mday;
    dataHoraAtual.mes = local->tm_mon + 1;
    dataHoraAtual.ano = local->tm_year + 1900;
    dataHoraAtual.hora = local->tm_hour;
    dataHoraAtual.minuto = local->tm_min;
    dataHoraAtual.segundo = local->tm_sec;

    return dataHoraAtual;
}

void carregarUsuarios(Usuario usuario[], int *numUsuarios) {
    FILE *file = fopen("usuarios.txt", "r");
    if (file == NULL) {
        printf("====================================\n \n");
        printf("\nARQUIVO NÃO ENCONTRADO! \n");
        printf("\n \n==================================== \n\n");
        return;
    }

    while (fscanf(file, "%s %s %s", usuario[*numUsuarios].email, usuario[*numUsuarios].nome, usuario[*numUsuarios].senha) != EOF) {
        (*numUsuarios)++;
    }

    fclose(file);
}

void cadastrarUsuario(Usuario usuario[], int *numUsuario) {
    if (*numUsuario >= MAX_USUARIO) {
        printf("=================================\n \n");
        printf("LIMITE DE USUÁRIOS ALCANÇADO!");
        printf("\n \n================================= \n\n");
        return;
    }

    printf("INFORME O EMAIL DO USUÁRIO: ");
    scanf("%s", usuario[*numUsuario].email);

    if (strlen(usuario[*numUsuario].email) >= 80 || strchr(usuario[*numUsuario].email, '@') == NULL) {
        printf("=================================\n \n");
        printf("NOME DO USUÁRIO INVÁLIDO! \nDEVE CONTER '@' E POSSUIR MENOS DE 80 CARACTERES.");
        printf("\n \n================================= \n\n");
        return;
    }

    for (int i = 0; i < *numUsuario; i++) {
        if (strcmp(usuario[i].email, usuario[*numUsuario].email) == 0) {
            printf("=================================\n \n");
            printf("USUÁRIO JÁ CADASTRADO!");
            printf("\n \n================================= \n\n");
            return;
        }
    }

    printf("INFORME O NOME DO USUÁRIO: ");
    scanf("%s", usuario[*numUsuario].nome);

    printf("INFORME UMA SENHA: ");
    scanf("%s", usuario[*numUsuario].senha);

    printf("=================================\n \n");
    printf("USUÁRIO CADASTRADO COM SUCESSO!");
    printf("\n \n================================= \n\n");

    (*numUsuario)++;
}

void salvarUsuarios(Usuario usuario[], int numUsuario) {
    FILE *file = fopen("usuarios.txt", "w");
    if (file == NULL) {
        printf("=================================\n \n");
        printf("ERRO AO ABRIR ARQUIVO!");
        printf("\n \n================================= \n\n");
        return;
    }

    for (int i = 0; i < numUsuario; i++) {
        fprintf(file, "%s %s %s\n", usuario[i].email, usuario[i].nome, usuario[i].senha);
    }

    fclose(file);
}

int realizarLogin(Usuario usuario[], int numUsuario, char *email, char *senha) {
    for (int i = 0; i < numUsuario; i++) {
        if (strcmp(usuario[i].email, email) == 0 && strcmp(usuario[i].senha, senha) == 0) {
            return i; 
        }
    }
    return -1;
}

void excluirUsuario(Usuario usuario[], int *numUsuario, char email[MAX_CARACTERE_EMAIL]) {
    for (int i = 0; i < *numUsuario; i++) {
        if (strcmp(usuario[i].email, email) == 0) {
            for (int j = i; j < *numUsuario - 1; j++) {
                strcpy(usuario[j].email, usuario[j + 1].email);
                strcpy(usuario[j].nome, usuario[j + 1].nome);
                strcpy(usuario[j].senha, usuario[j + 1].senha);
            }
            (*numUsuario)--;
            printf("=================================\n \n");
            printf("USUÁRIO EXCLUÍDO COM SUCESSO!");
            printf("\n \n================================= \n\n");
            return;
        }
    }
    printf("=================================\n \n");
    printf("CLIENTE NÃO ENCONTRADO!");
    printf("\n \n================================= \n\n");
}

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
    long long cpf;
    long long numero;
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
    int cpf;
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