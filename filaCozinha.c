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

// Insere um prato no fim da fila, seguindo o FIFO
void inserir_fila(Fila* fila, char prato)
{
  if(fila_cheia(fila)){
    printf("A fila está cheia!");
  }else{
    // Coloca o prato em dados, a partir da posição atual de tamanho e incrementa 1 do tamanho
    // Assim, o prato é adicionado no fim da fila
    fila->dados[fila->tamanho] = prato;
    fila->tamanho++;
  }
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
    printf("Pedidos: \n");
    for(int i = 0; i < fila->tamanho; i++){
        printf("%c", fila->dados[i]);
    }
    printf("\n");
  }
}

// Mecanismo importante para o projeto
// Processa a fila de pedidos, copiando os pratos da lista de pedidos para a fila
void processa_fila(Fila *fila, Pedido *lista) {
  // Enquanto a lista não for nula, ou seja, enquanto não for vazia
    while (lista != NULL) {
        int pratoTamanho = strlen(lista->prato);
        // strlen retorna o tamanho da string, ou seja, o número de caracteres
        memcpy(&fila->dados[fila->tamanho], lista->prato, pratoTamanho);
        // memcpy copia blocos de memória, de forma que memcpy(destino, origem, tamanho)
        // Copia o prato da lista para a fila
        fila->tamanho += pratoTamanho;
        // Incrementa o tamanho da fila pelo tamanho do prato
        // Adiciona um caractere de nova linha para separar os pratos
        // Isso é importante para que o usuário saiba onde começa e termina cada prato
        fila->dados[fila->tamanho++] = '\n';
        // Avança para o próximo pedido na lista
        lista = lista->proximo;
    }
}

void limparFilaCozinha(Fila *fila) {
    fila->tamanho = 0;
}