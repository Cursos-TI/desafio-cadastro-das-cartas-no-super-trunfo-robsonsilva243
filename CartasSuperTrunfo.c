#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país
typedef struct {
    char nome[50];                  // Nome do país
    int codigo;                     // Código da carta
    int populacao;                 // População do país
    float area;                     // Área do país
    float pib;                      // PIB do país
    float densidade_populacional;   // Densidade populacional (calculada)
} Carta;

// Função para calcular a densidade populacional
void calcular_densidade(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area; // Densidade populacional
    } else {
        carta->densidade_populacional = 0; // Evitar divisão por zero
    }
}

// Função para comparar dois atributos
void comparar_atributos(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;
    float soma_carta1, soma_carta2;

    // Atribuir valores com base nos atributos escolhidos
    switch (atributo1) {
        case 1: // População
            valor1_carta1 = carta1.populacao;
            valor1_carta2 = carta2.populacao;
            break;
        case 2: // Área
            valor1_carta1 = carta1.area;
            valor1_carta2 = carta2.area;
            break;
        case 3: // PIB
            valor1_carta1 = carta1.pib;
            valor1_carta2 = carta2.pib;
            break;
        case 4: // Densidade Populacional
            valor1_carta1 = carta1.densidade_populacional;
            valor1_carta2 = carta2.densidade_populacional;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    switch (atributo2) {
        case 1: // População
            valor2_carta1 = carta1.populacao;
            valor2_carta2 = carta2.populacao;
            break;
        case 2: // Área
            valor2_carta1 = carta1.area;
            valor2_carta2 = carta2.area;
            break;
        case 3: // PIB
            valor2_carta1 = carta1.pib;
            valor2_carta2 = carta2.pib;
            break;
        case 4: // Densidade Populacional
            valor2_carta1 = carta1.densidade_populacional;
            valor2_carta2 = carta2.densidade_populacional;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Comparação dos atributos
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s:\n", carta1.nome);
    printf("Atributo 1 (%d): %.2f\n", atributo1, valor1_carta1);
    printf("Atributo 2 (%d): %.2f\n", atributo2, valor2_carta1);
    
    printf("Carta 2 - %s:\n", carta2.nome);
    printf("Atributo 1 (%d): %.2f\n", atributo1, valor1_carta2);
    printf("Atributo 2 (%d): %.2f\n", atributo2, valor2_carta2);

    // Soma dos atributos
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    printf("Soma dos Atributos:\n");
    printf("Carta 1 - %s: %.2f\n", carta1.nome, soma_carta1);
    printf("Carta 2 - %s: %.2f\n", carta2.nome, soma_carta2);

    // Determinar o vencedor
    if (soma_carta1 > soma_carta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (soma_carta1 < soma_carta2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Declaração de duas cartas
    Carta carta1 = {"Brasil", 1, 213000000, 8515767, 2100000000};
    Carta carta2 = {"Argentina", 2, 45000000, 2780400, 450000000};

    // Cálculo da densidade populacional
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    // Menu para escolher os atributos
    int atributo1, atributo2;

    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // Menu para escolher o segundo atributo
    printf("Escolha o segundo atributo para comparar (não pode ser o mesmo que o primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    // Verificar se os atributos são diferentes
    if (atributo1 == atributo2) {
        printf("Você não pode escolher o mesmo atributo duas vezes!\n");
        return 1; // Finaliza o programa com erro
    }

    // Chama a função de comparação com os atributos escolhidos
    comparar_atributos(carta1, carta2, atributo1, atributo2);

    return 0; // Finaliza o programa
