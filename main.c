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
    int maxRounds = 0;    // Quantidade máxima de jogadas
    int playerMove = 0;   // Movimento do jogador 
    int aiMove = 0;       // Movimento da inteligência artificial 
    int playerPoints = 0; // Pontos do jogador
    int aiPoints = 0;     // Pontos da AI
    int roundStatus = 0;  // Verifa se o usuário ganhou a rodada
    int pause = 0;        // Variável de pausa da tela

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
            } else if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_LOSE;
            } else if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_TIE;
            }
    
        } else if (playerMove == MOVE_PAPER) {

            if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_WIN;
            } else if (aiMove == MOVE_SCISSOR) {
                roundStatus = ROUND_LOSE;
            } else if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_TIE;
            }

        } else if (playerMove == MOVE_SCISSOR) {

            if (aiMove == MOVE_PAPER) {
                roundStatus = ROUND_WIN;
            } else if (aiMove == MOVE_ROCK) {
                roundStatus = ROUND_LOSE;
            } else if (aiMove == MOVE_SCISSOR) {
                roundStatus = ROUND_TIE;
            }
        } else {
            system("/usr/bin/clear");
            printf("Jogada inválida!\n");
            i--;

            printf("\n<Digite qualquer número para continuar>\n");
            scanf("%d", &pause);
            continue;
        }

        // Feedback da rodada
        system("/usr/bin/clear");

        printf("--------[RESULTADO DA RODADA]--------\n\n");
        printf("Jogador: ");
        switch (playerMove) {
            case MOVE_ROCK:
                printf("Pedra");
                break;
            case MOVE_PAPER:
                printf("Papel");
                break;
            case MOVE_SCISSOR:
                printf("Tesoura");
                break;
        }
        printf("\n\n");

        printf("AI.....: ");
        switch (aiMove) {
            case MOVE_ROCK:
                printf("Pedra");
                break;
            case MOVE_PAPER:
                printf("Papel");
                break;
            case MOVE_SCISSOR:
                printf("Tesoura");
                break;
        }
        printf("\n");

        printf("---------------------------------------\n");
        printf("=> ");
        switch (roundStatus) {
            case ROUND_WIN:
                printf("Jogador ganhou!");
                playerPoints += 1;
                break;
            case ROUND_LOSE:
                printf("AI ganhou!");
                aiPoints += 1;
                break;
            case ROUND_TIE:
                printf("Empate!");
                break;
        }
        printf("\n\n");
        printf("=== PONTOS ===\n");
        printf("Jogador....: %d\n", playerPoints);
        printf("AI.........: %d\n", aiPoints);
        printf("\n<Digite qualquer número para continuar>\n");
        scanf("%d", &pause);

        // Desempata o placar caso esteja empatado na última rodada
        if (i == maxRounds &&
            aiPoints == playerPoints) {
            i--;
        }
    }

    // Feedback da partida 
    system("/usr/bin/clear");
    printf("--------[RESULTADO DA PARTIDA]--------\n");
    printf("=> ");
    if (playerPoints > aiPoints) {
        printf("Jogador ganhou!!!\n");
    } else {
        printf("AI ganhou!!!\n");
    }
    printf("\n\n=== PONTOS ===\n");
    printf("Jogador....: %d\n", playerPoints);
    printf("AI.........: %d\n", aiPoints);
    printf("--------------------------------------\n");
    printf("\n<Digite qualquer número para continuar>\n");
    scanf("%d", &pause);
}
