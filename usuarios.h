#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_USUARIO 10
#define MAX_CARACTERE_EMAIL 80
#define MAX_CARACTERE_NOME 30
#define MAX_CARACTERE_SENHA 30

typedef struct Pessoa {
    char email[MAX_CARACTERE_EMAIL];
    char nome[MAX_CARACTERE_NOME];
    char senha[MAX_CARACTERE_SENHA];
} Usuario;

void carregarUsuarios(Usuario usuario[], int *numUsuarios);
void cadastrarUsuario(Usuario usuario[], int *numUsuario);
void salvarUsuarios(Usuario usuario[], int numUsuario);
int realizarLogin(Usuario usuario[], int numUsuario, char *email, char *senha);
void excluirUsuario(Usuario usuario[], int *numUsuario, char email[MAX_CARACTERE_EMAIL]);

#endif
