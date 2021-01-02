#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {  
    int difficulty = 0; // Dificuldade do jogo
    int maxTries = 0;   // Quantidade máxima de jogadas
    int playerMove = 0; // Movimento do jogador 
    int aiMove = 0;     // Movimento da inteligência artificial 

    system("/usr/bin/clear");
    printf("           /---------------\\            \n");
    printf("===========| JO - KEN - PÔ |===========\n");
    printf("           \\---------------/            \n");
    printf("\n");
    printf("---------------------------------------\n");
    printf("[1] - Melhor de três\n");
    printf("[2] - Melhor de cinco\n");
    printf("[3] - Melhor de nove\n");
    printf("---------------------------------------\n");
    printf(">> Escolha: ");
    scanf("%d", &difficulty);
    
    // Escolha da dificuldade do jogo
    switch (difficulty) {
        case 1:
            maxTries = 3;
            break;
        case 2:
            maxTries = 5;
            break;
        case 3:
            maxTries = 9;
            break;
        default:
            maxTries = 3;
            break;
    }

    for (int i = 1; i <= maxTries; i++) {
        system("/usr/bin/clear");

        // Jogada do jogador
        printf("---------------------------------------\n");
        printf("Jogada [%d/%d]\n", i, maxTries);
        printf("---------------------------------------\n");
        printf("[1] Pedra\n");
        printf("[2] Papel\n");
        printf("[3] Tesoura\n");
        printf("---------------------------------------\n");
        printf(">> Escolha: ");
        scanf("%d", &playerMove);

        // Jogada da AI
        srand(time(0) * 100);
        aiMove = (rand() % 3) + 1;
    }
}
