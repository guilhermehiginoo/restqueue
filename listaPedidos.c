#include "listaPedidos.h"

// Função de inserção Pedido fim da lista.

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

void cancelarPedido(Pedido **cabeca, char *prato)
{
  if (*cabeca == NULL)
  {
    printf("Lista vazia!\n");
    return;
  }

  Pedido *anterior = NULL;
  Pedido *atual = *cabeca;

  while (atual != NULL)
  {
    if (strcmp(atual->prato, prato) == 0)
    {
      break;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL)
  {
    printf("Pedido não foi feito!\n");
    return;
  }

  if (anterior == NULL)
  {
    *cabeca = atual->proximo;
  }
  else
  {
    anterior->proximo = atual->proximo;
  }

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
