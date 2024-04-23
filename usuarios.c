#include "usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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