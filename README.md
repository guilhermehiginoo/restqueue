# Restqueue

## Descrição

Este projeto implementa um sistema básico para gerenciar os pedidos de um restaurante.  
Os pedidos são inicialmente armazenados em uma **lista ligada** (representando o salão) e, posteriormente, processados pela cozinha em ordem de chegada utilizando uma **fila**.  

A aplicação é desenvolvida em linguagem C, utilizando estruturas dinâmicas para manipulação eficiente dos dados.

---

## Estrutura do Projeto

- **ListaPedidos**: Lista ligada que armazena os pedidos recebidos no salão.  
- **FilaCozinha**: Fila que processa os pedidos em ordem FIFO (primeiro a entrar, primeiro a sair) para a cozinha.

---

## Funcionalidades

- Adicionar pedidos no salão (lista ligada).  
- Transferir pedidos para a fila da cozinha para processamento.  
- Processar pedidos pela cozinha na ordem correta.  
- Remover pedidos processados da fila.  

---

## Como Compilar e Executar

Utilize o `Makefile` para compilar e executar o projeto:

```bash
make        # compila o programa
make run    # executa o programa
make clean  # remove arquivos gerados pela compilação
