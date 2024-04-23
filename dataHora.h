#ifndef DATAHORA_H
#define DATAHORA_H

typedef struct Data{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DataHora;

DataHora obterDataHoraAtual();

#endif