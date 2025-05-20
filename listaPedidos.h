#ifndef no
#define no


struct no {
  int valor;
  struct no *proximo;
};

typedef struct no No;

  
void imprime_a_lsl(cabeca);
void insercao_no_inicio_da_lsl(&cabeca, 10);
void insercao_no_fim_da_lsl(&cabeca, 40);
void insercao_no_meio_da_lsl(&cabeca, 25, 3);
void remocao_no_inicio_da_lsl(&cabeca);
void remocao_no_fim_da_lsl(&cabeca);
void remocao_no_meio_da_lsl(&cabeca, 20);
void busca_por_valor_na_lsl(cabeca, 70);
void percorre_a_lsl(cabeca);

  #endif