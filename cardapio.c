void exibirCardapio(){
    printf("====== CARDÁPIO ======\n");
    printf("- Entradas - \n");
    printf("1. Sopa de cebola\n2.Salada Caesar \n3. Bruschetta \n");
    printf("4. Carpaccio de Carne\n5. Camarão ao Alho \n");
    printf("- Pratos principais -\n");
    printf("6. Lasanha à bolonhesa\n7. Filé Mignon com fritas \n8. Frango grelhado com legumes\n");
    printf("9. Bacalhau à Gomes de Sá\n10. Risoto de Cogumelos\n");
    printf("- Sobremesas -\n");
    printf("11. Tiramisu\n12. Cheesecake de Frutas vermmelhas\n13. Mousse de Chocolate\n14. Pudim de Leite\n15.Sorvete de baunilha com calda de morango\n");
}

 char* escolhaCardapio(int escolhido){
     char* cardapio[15] = {"Sopa de Cebola", "Salada Caesar", "Bruschetta", "Carpaccio de Carne",
         "Camarão ao Alho", "Lasanha à bolonhesa", "Filé Mignon com fritas", "Frango grelhado com legumes",
        "Bacalhau à Gomes de Sá", "Risoto de Cogumelos", "Tiramisu", "Cheesecake de Frutas vermelhas", "Mousse de Chocolate",
         "Pudim de Leite", "Sorvete de baunilha com calda de morango"};
    return cardapio[escolhido - 1];
}
