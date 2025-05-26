#include "cardapio.h"

// Cardápio
void exibirCardapio()
{
    printf("====== CARDÁPIO ======\n");
    printf("- Entradas -\n");
    printf(" 1. Sopa de cebola\n");
    printf(" 2. Salada Caesar\n");
    printf(" 3. Bruschetta\n");
    printf(" 4. Carpaccio de Carne\n");
    printf(" 5. Camarão ao Alho\n");
    printf("\n- Pratos principais -\n");
    printf(" 6. Lasanha à bolonhesa\n");
    printf(" 7. Filé Mignon com fritas\n");
    printf(" 8. Frango grelhado com legumes\n");
    printf(" 9. Bacalhau à Gomes de Sá\n");
    printf("10. Risoto de Cogumelos\n");
    printf("\n- Sobremesas -\n");
    printf("11. Tiramisu\n");
    printf("12. Cheesecake de Frutas vermelhas\n");
    printf("13. Mousse de Chocolate\n");
    printf("14. Pudim de Leite\n");
    printf("15. Sorvete de baunilha com calda de morango\n");
    printf("======================\n");
}

char *escolhaCardapio(int escolhido)
{
    char *cardapio[15] = {"Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne",
                                "Camarão ao Alho", "Lasanha à bolonhesa", "Filé Mignon com fritas", "Frango grelhado com legumes",
                                "Bacalhau à Gomes de Sá", "Risoto de Cogumelos", "Tiramisu", "Cheesecake de Frutas vermelhas", "Mousse de Chocolate",
                                "Pudim de Leite", "Sorvete de baunilha com calda de morango"};
    return cardapio[escolhido - 1];
}
