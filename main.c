#include <stdio.h>
#include "listaPedidos.h"
#include "filaCozinha.h"

int main() {
    // Inicializa a lista
    Pedido *cabeca = NULL;
    // Inicializa a fila
    Fila f;
    inicializar_fila(&f);
    int input;
    // Loop infinito do menu
    while (1) {
        printf("\n====== MENU ======\n");
        printf("1. Adicionar pedido\n");
        printf("2. Processar fila\n");
        printf("3. Cancelar pedido\n");
        printf("4. Listar todos os pendentes (salão)\n");
        printf("5. Listar todos os pendentes (cozinha)\n");
        printf("0. Sair\n");
        printf("===================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                int escolha;
                exibirCardapio();
                printf("Digite o número do prato: ");
                scanf("%d", &escolha);
                // Insira função para anotar o pedido
                printf("Pedido anotado!\n");
                break;
            }
            case 2:
                processa_fila(&f, cabeca);
                break;
            case 3: {
                int escolha;
                exibirCardapio();
                printf("Digite o número do pedido a cancelar: ");
                scanf("%d", &escolha);
                // Insira função para cancelar o pedido
                printf("Pedido removido!\n");
                break;
            }
            case 4: {
                printf("Pedidos pendentes (salão):\n");
                // Insira função para exibir pedidos
                break;
            }
            case 5: {
                printf("Pedidos pendentes (cozinha):\n");
                exibir_fila(&f);
                break;
            }
            case 0:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
