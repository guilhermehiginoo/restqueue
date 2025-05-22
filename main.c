#include <stdio.h>
#include "listaPedidos.h"
#include "filaCozinha.h"
#include "cardapio.h"

int main()
{
    // Inicializa a lista
    Pedido *cabeca = NULL;
    // Inicializa a fila
    Fila f;
    inicializar_fila(&f);
    int input;
    // Loop infinito do menu
    while (1)
    {
        printf("\n====== MENU ======\n");
        printf("1. Adicionar pedido\n");
        printf("2. Processar fila\n");
        printf("3. Cancelar pedido\n");
        printf("4. Cancelar todos os pedidos. CANCELAAAAAA TUDO!\n");
        printf("5. Listar pedidos do salão\n");
        printf("6. Mostrar fila da cozinha\n");
        if (f.tamanho > 0)
        {
            printf("7. Perguntar ao garçom se já está pronto...\n");
        }
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

            printf("Pedidos enviados para o cozinheiro! Aguarde...\n");
            processa_fila(&f, cabeca);
            // limparListaPedidos(&cabeca);

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
        }

        case 5:
        {
            printf("Pedidos pendentes (salão):\n");
            exibirPedidos(cabeca);
            break;
        }
        case 6:
        {
            printf("Pedidos pendentes (cozinha):\n");
            exibir_fila(&f);
            break;
        }
        case 7:
        {
            if (f.tamanho > 0)
            {
                printf("Pedido pronto!\n");
                printf("Aqui está o seu pedido: \n");
                for (int i = 0; i < f.tamanho; i++)
                {
                    printf("%c", f.dados[i]);
                }
                printf("\n");
                limparFilaCozinha(&f);
                printf("Deseja mais alguma coisa?\n");
            }
            else
            {
                printf("Nenhum pedido pronto!\n");
            }
            break;
        }
        case 0:
            printf("Encerrando...\n");
            limparListaPedidos(&cabeca);
            limparFilaCozinha(&f);
            printf("Todos os pedidos foram cancelados. Até logo!\n");
            printf("Agradecemos pela sua visita!\n");
            return 0;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
