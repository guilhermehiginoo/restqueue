#include "listaPedidos.h"

void criarListaPedidos()
{
  Pedido *cabeca = NULL;
}

void anotarPedido(Pedido **cabeca, char *prato)
{
  Pedido *novoPedido = malloc(sizeof(Pedido));
  int i = 0;
  while (prato[i] != '\0' && i < (int)sizeof(novoPedido->prato) - 1)
  {
    novoPedido->prato[i] = prato[i];
    i++;
  }
  novoPedido->prato[i] = '\0';
  novoPedido->proximo = NULL;

  if (*cabeca == NULL)
  {
    *cabeca = novoPedido;
    return;
  }

  Pedido *atual = *cabeca;

  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }

  atual->proximo = novoPedido;
}

void cancelarPedido(Pedido **cabeca, int indice)
{
    if (*cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Pedido *anterior = NULL;
    Pedido *atual = *cabeca;
    int i = 1;

    while (atual != NULL && i < indice) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    if (atual == NULL) {
        printf("Pedido não encontrado!\n");
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Pedido removido: %s\n", atual->prato);
    free(atual);
}

void exibirPedidos(Pedido *cabeca)
{
  if (cabeca == NULL)
  {
    printf("Nenhum pedido foi feito!\n");
    return;
  }

  Pedido *atual = cabeca;

  int j = 1;

  printf("Pedidos:\n");
  printf("-----------\n");

  while (atual != NULL)
  {
    printf("%d - %s\n", j, atual->prato);
    atual = atual->proximo;
    j++;
  }

  printf("-----------\n");
}

void limparListaPedidos(Pedido **cabeca) {
    Pedido *atual = *cabeca;
    while (atual != NULL) {
        Pedido *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *cabeca = NULL;
}