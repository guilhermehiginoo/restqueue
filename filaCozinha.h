#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPedidos.h"

#define TAMANHO_MAX 100

// Estrutura para armazenar os pedidos na fila
// A fila é implementada como um vetor de tamanho TAMANHO_MAX e um int que indica o tamanho atual da fila
// A fila é do tipo FIFO (First In First Out), ou seja, o primeiro pedido a entrar é o primeiro a sair
typedef struct {
    char dados[TAMANHO_MAX];
    int tamanho;
} Fila;


void inicializar_fila(Fila* fila);
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
void exibir_fila(Fila* fila);
void processa_fila(Fila *fila, Pedido *lista);
void limparFilaCozinha(Fila *fila);

#endif