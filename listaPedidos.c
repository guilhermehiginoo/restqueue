#include "listaPedidos.h"

// Função de inserção Pedido fim da lista.
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

// Função de remoção em uma posição intermediária da lista.
void cancelarPedido(Pedido **cabeca, char prato)
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
    int i = 0;
    int igual = 1;
    while (atual->prato[i] != '\0' && prato[i] != '\0')
    {
      if (atual->prato[i] != prato[i])
      {
        igual = 0;
        break;
      }
      i++;
    }
    if (atual->prato[i] != prato[i])
    {
      igual = 0;
    }

    if (igual)
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
    printf("Lista vazia!\n");
    return;
  }

  Pedido *atual = cabeca;

  while (atual != NULL)
  {
    printf("%s ", atual->prato);
    atual = atual->proximo;
  }
  printf("\n");
}