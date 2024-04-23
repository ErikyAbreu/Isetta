#include "dataHora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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