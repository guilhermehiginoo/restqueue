#ifndef LISTA_PEDIDOS_H
#define LISTA_PEDIDOS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct pedido {
    char prato[100];
    struct pedido *proximo;
} Pedido;

typedef struct pedido Pedido;

  
void exibirPedidos(Pedido *cabeca);
void anotarPedido(Pedido **cabeca, char *prato);
void cancelarPedido(Pedido **cabeca, char *prato);

#endif