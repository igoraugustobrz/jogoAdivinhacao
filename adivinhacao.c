#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(){

    // Imprime o cabeçalho do jogo
    printf("******************************************");
    printf("* Bem-vindo ao nosso jogo de adivinhação *");
    printf("******************************************");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    printf("%d", &nivel);

    int numerodetentativas;

    // Nível de dificuldade
    switch (nivel) {
        case 1:
            numerodetentativas = 20;
            break;
        
        case 2:
            numerodetentativas = 15;
            break;

        case 3:
            numerodetentativas = 6;
            break;

        default:
            prinf("Número inválido");
            break;
    }

    // Tentativas do usuário
    for(int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }

        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;

    }

    printf("Fim de jogo!\n");

    if(acertou) {
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo!\n");
    }

    return 0;
}