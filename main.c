#include "clientes.h"
#include "usuarios.h"
#include "veiculos.h"
#include "vendas.h"
#include "limparBancoDados.h"
#include "dataHora.h"
#include "clientes.c"
#include "usuarios.c"
#include "veiculos.c"
#include "vendas.c"
#include "limparBancoDados.c"
#include "dataHora.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

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