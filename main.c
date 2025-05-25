#include <stdio.h>
#include "listaPedidos.h"
#include "filaCozinha.h"
#include "cardapio.h"

int main()
{
    // Inicializa a lista
    Pedido *cabeca = NULL;
    // Inicializa a fila
    Fila filas[TAMANHO_MAX];
    int count = 1;
    int input;
    // Loop infinito do menu
    while (1)
    {
        printf("\n====== MENU ======\n");
        printf("1. Adicionar pedido\n");
        printf("2. Enviar pedidos para cozinha\n");
        printf("3. Cancelar pedido\n");
        printf("4. Cancelar todos os pedidos. CANCELAAAAAA TUDO!\n");
        printf("5. Listar pedidos do salão\n");
        printf("6. Mostrar fila da cozinha\n");
        printf("0. Sair\n");
        printf("===================\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
        {
            int escolha;
            exibirCardapio();
            printf("Digite o número do prato: ");
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > 15)
            {
                printf("Eita, não temos isso no cardápio... Escolhe outra coisa aí, vai!.\n");
                break;
            }
            anotarPedido(&cabeca, (char *)escolhaCardapio(escolha));
            printf("Pedido anotado!\n");
            break;
        }
        case 2:
            if (cabeca == NULL)
            {
                printf("Nenhum pedido para cozinhar!\n");
                break;
            }
            Fila f;
            inicializar_fila(&f);
            processa_fila(&f, cabeca);
            filas[count] = f;
            printf("Pedidos enviados para o cozinheiro! Aguarde...\n");
            limparListaPedidos(&cabeca);
            limparFilaCozinha(&f);
            count++;
            break;
        case 3:
        {
            int escolha;
            exibirPedidos(cabeca);
            printf("Digite o número do pedido a cancelar: ");
            scanf("%d", &escolha);
            cancelarPedido(&cabeca, escolha);

            printf("Algo mais?\n");
            break;
        }

        case 4:
        {
            printf("Cancelando todos os pedidos...\n");
            limparListaPedidos(&cabeca);
            break;
        }

        case 5:
        {
            printf("Pedidos pendentes (salão):\n");
            exibirPedidos(cabeca);
            break;
        }
        case 6:
        {
            printf("Pedidos pendentes (cozinha):\n\n");
            for (int i = 1; i < count; i++){
                printf("Pedido %d:\n", i);
                exibir_fila(&filas[i]);
            }
            break;
        }
        case 0:
            printf("Encerrando...\n");
            limparListaPedidos(&cabeca);
            limparFilaCozinha(&f);
            printf("Agradecemos pela sua visita!\n");
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
