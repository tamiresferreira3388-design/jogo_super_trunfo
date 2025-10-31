#include <stdio.h>

// Estrutura de uma carta
struct Carta {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
};

int main() {
    struct Carta carta1 = {"Dragão Vermelho", 85, 70, 60};
    struct Carta carta2 = {"Tigre Branco", 75, 80, 65};
    int opcao, soma1, soma2;

    printf("===== SUPER TRUNFO =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Escolha o modo de comparação:\n");
    printf("1 - Comparar por um único atributo\n");
    printf("2 - Comparar por múltiplos atributos\n");
    printf("3 - Comparar por dois atributos (modo avançado)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        // --- DESAFIO 1: if / if-else (um único atributo)
        case 1: {
            int atributo;
            printf("\nEscolha o atributo:\n");
            printf("1 - Força\n2 - Velocidade\n3 - Inteligência\n");
            printf("Opção: ");
            scanf("%d", &atributo);

            if (atributo == 1) {
                if (carta1.forca > carta2.forca)
                    printf("Carta 1 venceu em Força!\n");
                else if (carta2.forca > carta1.forca)
                    printf("Carta 2 venceu em Força!\n");
                else
                    printf("Empate em Força!\n");
            } 
            else if (atributo == 2) {
                if (carta1.velocidade > carta2.velocidade)
                    printf("Carta 1 venceu em Velocidade!\n");
                else if (carta2.velocidade > carta1.velocidade)
                    printf("Carta 2 venceu em Velocidade!\n");
                else
                    printf("Empate em Velocidade!\n");
            } 
            else if (atributo == 3) {
                if (carta1.inteligencia > carta2.inteligencia)
                    printf("Carta 1 venceu em Inteligência!\n");
                else if (carta2.inteligencia > carta1.inteligencia)
                    printf("Carta 2 venceu em Inteligência!\n");
                else
                    printf("Empate em Inteligência!\n");
            } 
            else {
                printf("Atributo inválido!\n");
            }
            break;
        }

        // --- DESAFIO 2: if-else if + switch (múltiplos atributos)
        case 2: {
            int modo;
            printf("\nEscolha o modo de comparação:\n");
            printf("1 - Vencer em pelo menos 2 atributos\n");
            printf("2 - Vencer em todos os atributos\n");
            printf("Opção: ");
            scanf("%d", &modo);

            int pontos1 = 0, pontos2 = 0;

            // Força
            if (carta1.forca > carta2.forca) pontos1++;
            else if (carta2.forca > carta1.forca) pontos2++;

            // Velocidade
            if (carta1.velocidade > carta2.velocidade) pontos1++;
            else if (carta2.velocidade > carta1.velocidade) pontos2++;

            // Inteligência
            if (carta1.inteligencia > carta2.inteligencia) pontos1++;
            else if (carta2.inteligencia > carta1.inteligencia) pontos2++;

            switch (modo) {
                case 1:
                    if (pontos1 >= 2)
                        printf("Carta 1 venceu (melhor em 2 ou mais atributos)!\n");
                    else if (pontos2 >= 2)
                        printf("Carta 2 venceu (melhor em 2 ou mais atributos)!\n");
                    else
                        printf("Empate técnico!\n");
                    break;

                case 2:
                    if (pontos1 == 3)
                        printf("Carta 1 venceu (melhor em todos os atributos)!\n");
                    else if (pontos2 == 3)
                        printf("Carta 2 venceu (melhor em todos os atributos)!\n");
                    else
                        printf("Nenhuma carta venceu em todos os atributos.\n");
                    break;

                default:
                    printf("Opção inválida!\n");
            }
            break;
        }

        // --- DESAFIO 3: operador ternário + lógica combinada
        case 3: {
            printf("\nComparando pela soma de dois atributos (Força + Velocidade)...\n");
            soma1 = carta1.forca + carta1.velocidade;
            soma2 = carta2.forca + carta2.velocidade;

            printf("Pontuação Carta 1: %d\n", soma1);
            printf("Pontuação Carta 2: %d\n", soma2);

            // Comparação usando operador ternário
            (soma1 > soma2) ? printf("Carta 1 venceu!\n") :
            (soma2 > soma1) ? printf("Carta 2 venceu!\n") :
                              printf("Empate!\n");
            break;
        }

        default:
            printf("Opção inválida!\n");
    }

    printf("\n===== FIM DO JOGO =====\n");
    return 0;
}