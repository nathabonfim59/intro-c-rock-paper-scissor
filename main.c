#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Jogadas disponíveis
#define MOVE_ROCK 1      // Jogada Pedra
#define MOVE_PAPER 2     // Jogada Papel
#define MOVE_SCISSOR 3   // Jogada Tesoura

#define ROUND_WIN 1      // Jogador ganhou
#define ROUND_LOSE 0     // AI ganhou
#define ROUND_TIE 2      // Empate

int main() {  
    int difficulty = 0;   // Dificuldade do jogo
    int maxRounds = 0;     // Quantidade máxima de jogadas
    int playerMove = 0;   // Movimento do jogador 
    int aiMove = 0;       // Movimento da inteligência artificial 
    int playerPoints = 0; // Pontos do jogador
    int aiPoints = 0;     // Pontos da AI
    int roundStatus = 0; // Verifa se o usuário ganhou a rodada

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
            maxRounds = 3;
            break;
        case 2:
            maxRounds = 5;
            break;
        case 3:
            maxRounds = 9;
            break;
        default:
            maxRounds = 3;
            break;
    }

    for (int i = 1; i <= maxRounds; i++) {
        system("/usr/bin/clear");

        // Jogada do jogador
        printf("---------------------------------------\n");
        printf("Jogada [%d/%d]\n", i, maxRounds);
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

        // Cálculo dos pontos
        if (playerMove == MOVE_ROCK) {

            if (aiMove == MOVE_SCISSOR) {
                roundStatus = ROUND_WIN;
                playerPoints += 1;
            } else if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_LOSE;
                aiPoints += 1;
            } else if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_TIE;
            }
    
        } else if (playerMove == MOVE_PAPER) {

            if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_WIN;
                playerPoints += 1;
            } else if (aiMove == MOVE_SCISSOR) {
                roundStatus = ROUND_LOSE;
                aiPoints += 1;
            } else if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_TIE;
            }

        } else if (playerMove == MOVE_SCISSOR) {

            if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_WIN;
                playerPoints += 1;
            } else if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_LOSE;
                aiPoints += 1;
            } else if (aiMove == MOVE_SCISSOR) {
                roundStatus = ROUND_TIE;
            }
        }

    }

    // Feedback da jogada
    printf("Pontos jogador: %d\n", playerPoints);
    printf("Pontos AI: %d\n", aiPoints);
}
