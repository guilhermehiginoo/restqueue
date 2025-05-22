#ifndef LISTA_PEDIDOS_H
#define LISTA_PEDIDOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pedido {
    char prato[100];
    struct pedido *proximo;
} Pedido;

typedef struct pedido Pedido;

void criarListaPedidos();
void exibirPedidos(Pedido *cabeca);
void anotarPedido(Pedido **cabeca, char *prato);
void cancelarPedido(Pedido **cabeca, int indice);
void limparListaPedidos(Pedido **cabeca);

#endif