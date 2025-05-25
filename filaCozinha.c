#include "filaCozinha.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializa a lista, inicialmente com tamanho 0
void inicializar_fila(Fila* fila)
{
  fila->tamanho = 0;
}

// Retorna a lista com tamanho 0
int fila_vazia(Fila* fila)
{
  return fila->tamanho == 0;
}

// Retorna a lista com tamanho máximo
int fila_cheia(Fila* fila)
{
  return fila->tamanho == TAMANHO_MAX;
}


// Exibe os pratos na fila, se houver
void exibir_fila(Fila* fila)
{
  // Verifica se a fila está vazia, se sim, imprime que nenhum pedido está sendo processado
  if(fila_vazia(fila)){
    printf("Nenhum pedido sendo processado\n");
  }
  // Se não, imprimie os pratos
  else{
    for(int i = 0; i < fila->tamanho; i++){
        printf("%c", fila->dados[i]);
    }
    printf("\n");
  }
}

// Mecanismo importante para o projeto
// Processa a fila de pedidos, copiando os pratos da lista de pedidos para a fila
void processa_fila(Fila *fila, Pedido *lista) {
    // Enquanto a lista não for nula
    while (lista != NULL) {
        int i = 0;
        // Copia os caracteres do prato um a um
        while (lista->prato[i] != '\0') {
            fila->dados[fila->tamanho++] = lista->prato[i++];
        }
        // Adiciona uma nova linha após cada prato
        fila->dados[fila->tamanho++] = '\n';
        // Avança para o próximo pedido
        lista = lista->proximo;
        
    }
}

void limparFilaCozinha(Fila *fila) {
    fila->tamanho = 0;
}