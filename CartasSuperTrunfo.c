#include <stdio.h>
#include <stdlib.h>

// Definindo uma estrutura para representar uma cidade
typedef struct {
    char estado;               // Estado da cidade
    char codigo[4];           // Código da carta (ex: A01)
    char nome[50];            // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área da cidade em km²
    float pib;                // PIB da cidade
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional
    float pib_per_capita;     // PIB per capita
    float super_poder;        // Soma de todas as propriedades
} Cidade;

// Função para calcular a densidade populacional, PIB per capita e Super Poder
void calcular_propriedades(Cidade *cidade) {
    if (cidade->area > 0) {
        cidade->densidade_populacional = cidade->populacao / cidade->area; // Densidade populacional
    } else {
        cidade->densidade_populacional = 0; // Evita divisão por zero
    }

    if (cidade->populacao > 0) {
        cidade->pib_per_capita = cidade->pib / cidade->populacao; // PIB per capita
    } else {
        cidade->pib_per_capita = 0; // Evita divisão por zero
    }

    // Calcula o Super Poder como a soma das propriedades
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos;
}

// Função para exibir os dados da cidade
void exibir_dados(Cidade cidade) {
    printf("\nDados da Cidade:\n");
    printf("Estado: %c\n", cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: R$%.2f\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: R$%.2f\n", cidade.pib_per_capita);
    printf("Super Poder: %.2f\n", cidade.super_poder);
}

// Função para comparar duas cidades
void comparar_cidades(Cidade cidade1, Cidade cidade2) {
    printf("\nComparação entre %s e %s:\n", cidade1.nome, cidade2.nome);

    // Comparação da Densidade Populacional
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("Densidade Populacional: %s vence (%.2f < %.2f)\n", cidade1.nome, cidade1.densidade_populacional, cidade2.densidade_populacional);
    } else {
        printf("Densidade Populacional: %s vence (%.2f > %.2f)\n", cidade2.nome, cidade1.densidade_populacional, cidade2.densidade_populacional);
    }

    // Comparação da População
    if (cidade1.populacao > cidade2.populacao) {
        printf("População: %s vence (%d > %d)\n", cidade1.nome, cidade1.populacao, cidade2.populacao);
    } else {
        printf("População: %s vence (%d < %d)\n", cidade2.nome, cidade1.populacao, cidade2.populacao);
    }

    // Comparação da Área
    if (cidade1.area > cidade2.area) {
        printf("Área: %s vence (%.2f > %.2f)\n", cidade1.nome, cidade1.area, cidade2.area);
    } else {
        printf("Área: %s vence (%.2f < %.2f)\n", cidade2.nome, cidade1.area, cidade2.area);
    }

    // Comparação do PIB
    if (cidade1.pib > cidade2.pib) {
        printf("PIB: %s vence (R$%.2f > R$%.2f)\n", cidade1.nome, cidade1.pib, cidade2.pib);
    } else {
        printf("PIB: %s vence (R$%.2f < R$%.2f)\n", cidade2.nome, cidade1.pib, cidade2.pib);
    }

    // Comparação do Número de Pontos Turísticos
    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("Pontos Turísticos: %s vence (%d > %d)\n", cidade1.nome, cidade1.pontos_turisticos, cidade2.pontos_turisticos);
    } else {
        printf("Pontos Turísticos: %s vence (%d < %d)\n", cidade2.nome, cidade1.pontos_turisticos, cidade2.pontos_turisticos);
    }

    // Comparação do Super Poder
    if (cidade1.super_poder > cidade2.super_poder) {
        printf("Super Poder: %s vence (%.2f > %.2f)\n", cidade1.nome, cidade1);
        printf("Super Poder: %s vence (%.2f > %.2f)\n", cidade1.nome, cidade1.super_poder, cidade2.super_poder);
    } else {
        printf("Super Poder: %s vence (%.2f < %.2f)\n", cidade2.nome, cidade1.super_poder, cidade2.super_poder);
    }
}

int main() {
    // Array para armazenar as cartas de cidades
    Cidade cartas[32]; // 8 estados * 4 cidades
    int index = 0; // Índice para armazenar as cartas

    // Loop para cadastrar até 32 cidades
    for (char estado = 'A'; estado <= 'H'; estado++) { // Para cada estado de A a H
        for (int j = 1; j <= 4; j++) { // Para cada cidade de 01 a 04
            Cidade cidade; // Cria uma nova cidade

            // Gera o código da carta
            sprintf(cidade.codigo, "%c%02d", estado, j);
            cidade.estado = estado; // Atribui o estado

            printf("\nCadastro da cidade %s:\n", cidade.codigo);

            // Coleta os dados da cidade
            printf("Digite o nome da cidade: ");
            scanf(" %[^\n]", cidade.nome); // Lê o nome da cidade
            printf("Digite a população: ");
            scanf("%d", &cidade.populacao); // Lê a população
            printf("Digite a área em km²: ");
            scanf("%f", &cidade.area); // Lê a área
            printf("Digite o PIB: ");
            scanf("%f", &cidade.pib); // Lê o PIB
            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cidade.pontos_turisticos); // Lê o número de pontos turísticos

            // Calcula as propriedades adicionais
            calcular_propriedades(&cidade);

            // Armazena a cidade no array
            cartas[index] = cidade;
            index++; // Incrementa o índice

            // Exibe os dados da cidade cadastrada
            exibir_dados(cidade);
        }
    }

    // Comparação de duas cartas
    char codigo1[4], codigo2[4];
    printf("\nDigite o código da primeira cidade para comparação: ");
    scanf("%s", codigo1);
    printf("Digite o código da segunda cidade para comparação: ");
    scanf("%s", codigo2);

    Cidade cidade1, cidade2;
    int encontrada1 = 0, encontrada2 = 0;

    // Busca as cidades no array
    for (int i = 0; i < index; i++) {
        if (strcmp(cartas[i].codigo, codigo1) == 0) {
            cidade1 = cartas[i];
            encontrada1 = 1;
        }
        if (strcmp(cartas[i].codigo, codigo2) == 0) {
            cidade2 = cartas[i];
            encontrada2 = 1;
        }
    }

    // Verifica se as cidades foram encontradas e realiza a comparação
    if (encontrada1 && encontrada2) {
        comparar_cidades(cidade1, cidade2);
    } else {
        if (!encontrada1) {
            printf("Cidade com código %s não encontrada.\n", codigo1);
        }
        if (!encontrada2) {
            printf("Cidade com código %s não encontrada.\n", codigo2);
        }
    }

    printf("\nCadastro e comparação concluídos!\n");
    return 0; // Finaliza o programa
}