// Função de inserção no fim da lista.
void insercao_no_fim_da_lsl(No **cabeca, int valor){
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = NULL;

  if(*cabeca == NULL){
    *cabeca = novo_no;
    return;
  }
  
  No *atual = *cabeca;

  while(atual->proximo != NULL) {
    atual = atual->proximo;
  }
  
  atual->proximo = novo_no;
}


// Função de remoção no início da lista.
void remocao_no_inicio_da_lsl(No **cabeca){
  if(*cabeca == NULL){
    printf("A lista está vazia!\n");
    return;
  }

  No *temp = *cabeca;
  *cabeca = (*cabeca)->proximo;
  free(temp);
}


// Função de remoção no fim da lista.
void remocao_no_fim_da_lsl(No **cabeca){
  if(*cabeca == NULL || (*cabeca)->proximo == NULL){
    remocao_no_inicio_da_lsl(cabeca);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while(atual->proximo != NULL){
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = NULL;

  free(atual);
}


// Função de remoção em uma posição intermediária da lista.
void remocao_no_meio_da_lsl(No **cabeca, int valor){
  if(*cabeca == NULL){
    printf("Lista vazia!\n");
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while(atual != NULL && atual->valor != valor){
    anterior = atual;
    atual = atual->proximo;
  }

  if(atual == NULL){
    printf("Valor inexistente na lista!\n");
    return;
  }

  if(anterior == NULL){
    *cabeca = atual->proximo;
  }else{
    anterior->proximo = atual->proximo;
  }

  free(atual);
}


// Função de busca por valor na lista.
void busca_por_valor_na_lsl(No *cabeca, int valor){
  No *atual = cabeca;

  while(atual != NULL && atual->valor != valor){
    atual = atual->proximo;
  }
  
  if(atual != NULL)
    printf("Valor %d encontrado!\n", valor);
  else
   printf("Valor %d não encontrado!\n", valor);
}


// Função de varredura da lista.
void percorre_a_lsl(No *cabeca){
  No *atual = cabeca;
  int total = 0;

  while(atual != NULL){
    total = total + atual->valor;
    atual = atual->proximo;
  }
  printf("Total = %d.\n", total);
}


// Função de impressão de valores da lista.
void imprime_a_lsl(No *cabeca) {
  if(cabeca == NULL){
    printf("Lista vazia!\n");
    return;
  }

  No *atual = cabeca;
  
  while(atual != NULL){
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

  
