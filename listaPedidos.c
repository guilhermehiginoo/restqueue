#include "listaPedidos.h"

// Cria a lista, com o cabeça apontando para null
void criarListaPedidos()
{
  // Inicializa o ponteiro cabeça como NULL (lista vazia)
  Pedido *cabeca = NULL;
}

// Função para anotar pedido
void anotarPedido(Pedido **cabeca, char *prato)
{
  // Aloca memória para o novo pedido
  Pedido *novoPedido = malloc(sizeof(Pedido));
  int i = 0;
  // Copia o nome do prato para o campo prato do novo pedido
  while (prato[i] != '\0' && i < (int)sizeof(novoPedido->prato) - 1)
  {
    novoPedido->prato[i] = prato[i];
    i++;
  }
  novoPedido->prato[i] = '\0'; // Finaliza a string
  novoPedido->proximo = NULL;  // Novo pedido será o último da lista

  // Se a lista está vazia, novo pedido vira o primeiro
  if (*cabeca == NULL)
  {
    *cabeca = novoPedido;
    return;
  }

  // Senão, percorre até o final da lista
  Pedido *atual = *cabeca;
  while (atual->proximo != NULL)
  {
    atual = atual->proximo;
  }

  // Adiciona o novo pedido ao final
  atual->proximo = novoPedido;
}

// Função para cancelar pedido
void cancelarPedido(Pedido **cabeca, int indice)
{
    // Verifica se a lista está vazia
    if (*cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Pedido *anterior = NULL;
    Pedido *atual = *cabeca;
    int i = 1;

    // Percorre até o pedido do índice desejado
    while (atual != NULL && i < indice) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    // Se não encontrou o pedido
    if (atual == NULL) {
        printf("Pedido não encontrado!\n");
        return;
    }

    // Remove o pedido do início da lista
    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        // Remove do meio ou fim da lista
        anterior->proximo = atual->proximo;
    }

    printf("Pedido removido: %s\n", atual->prato);
    free(atual); // Libera memória do pedido removido
}

// Função para exibir pedidos
void exibirPedidos(Pedido *cabeca)
{
  // Se a lista está vazia
  if (cabeca == NULL)
  {
    printf("Nenhum pedido foi feito!\n");
    return;
  }

  Pedido *atual = cabeca;
  int j = 1;

  printf("Pedidos:\n");
  printf("-----------\n");

  // Percorre e imprime cada pedido
  while (atual != NULL)
  {
    printf("%d - %s\n", j, atual->prato);
    atual = atual->proximo;
    j++;
  }

  printf("-----------\n");
}

// Libera toda a memória alocada para a lista de pedidos
void limparListaPedidos(Pedido **cabeca) {
    Pedido *atual = *cabeca;
    // Percorre a lista liberando cada nó
    while (atual != NULL) {
        Pedido *prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *cabeca = NULL; // Lista agora está vazia
}