#include <stdio.h>
#include <string.h>

void exibirCardapio(){
    printf("====== CARDÁPIO ======\n");
    printf("- Entradas - \n");
    printf("1. Sopa de cebola\n 2.Salada Caesar \n 3. Bruschetta \n");
    printf("4. Carpaccio de Carne\n 5. Camarão ao Alho \n");
    printf("- Pratos principais -");
    printf("6. Lasanha à bolonhesa\n 7. Filé Mignon com fritas \n 8. Frango grelhado com legumes\n");
    printf("9. Bacalhau à Gomes de Sá\n 10. Risoto de Cogumelos\n");
    printf("- Sobremesas -\n");
    printf("11. Tiramisu \n 12. Cheesecake de Frutas vermmelhas \n 13. Mousse de Chocolate \n 14. Pudim de Leite \n 15.Sorvete de baunilha com calda de morango \n")
}

const char* escolhaCardapio(int escolhido){
    const char* cardapio[15] = {"Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne",
         "Camarão ao Alho", "Lasanha à bolonhesa", "Filé Mignon com fritas", "Frango grelhado com legumes",
        "Bacalhau à Gomes de Sá", "Risoto de Cogumelos", "Tiramisu", "Cheesecake de Frutas vermelhas", "Mousse de Chocolate",
         "Pudim de Leite", "Sorvete de baunilha com calda de morango"};
    return cardapio[escolhido - 1];
}
