#include <stdio.h>

int main() {

    // ===== CARTA 1 =====
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // ===== CARTA 2 =====
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // ===== ENTRADA CARTA 1 =====
    printf("==== Cadastro da Carta 1 ====\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);


    // ===== ENTRADA CARTA 2 =====
    printf("\n==== Cadastro da Carta 2 ====\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);


    // ===== CALCULOS =====

    float densidade1 = (float) populacao1 / area1;
    float densidade2 = (float) populacao2 / area2;

    float pibPerCapita1 = pib1 / (float) populacao1;
    float pibPerCapita2 = pib2 / (float) populacao2;

    float superPoder1 =
        populacao1 +
        area1 +
        pib1 +
        pontosTuristicos1 +
        pibPerCapita1 +
        (1 / densidade1);

    float superPoder2 =
        populacao2 +
        area2 +
        pib2 +
        pontosTuristicos2 +
        pibPerCapita2 +
        (1 / densidade2);


    // ===== ESCOLHA DOS ATRIBUTOS =====

    int atributo1, atributo2;

    printf("\nEscolha o PRIMEIRO atributo para comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");

    scanf("%d", &atributo1);


    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");

    if(atributo1 != 1) printf("1 - Populacao\n");
    if(atributo1 != 2) printf("2 - Area\n");
    if(atributo1 != 3) printf("3 - PIB\n");
    if(atributo1 != 4) printf("4 - Pontos Turisticos\n");
    if(atributo1 != 5) printf("5 - Densidade Demografica\n");

    scanf("%d", &atributo2);


    if(atributo1 == atributo2){
        printf("Erro: nao pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }


    // ===== VARIAVEIS PARA CALCULO =====

    float valor1_carta1 = 0;
    float valor1_carta2 = 0;

    float valor2_carta1 = 0;
    float valor2_carta2 = 0;


    // ===== ATRIBUTO 1 =====

    switch(atributo1){

        case 1:
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;

        case 2:
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;

        case 3:
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;

        case 4:
            valor1_carta1 = pontosTuristicos1;
            valor1_carta2 = pontosTuristicos2;
            break;

        case 5:
            valor1_carta1 = densidade1;
            valor1_carta2 = densidade2;
            break;
    }


    // ===== ATRIBUTO 2 =====

    switch(atributo2){

        case 1:
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;

        case 2:
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;

        case 3:
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;

        case 4:
            valor2_carta1 = pontosTuristicos1;
            valor2_carta2 = pontosTuristicos2;
            break;

        case 5:
            valor2_carta1 = densidade1;
            valor2_carta2 = densidade2;
            break;
    }


    // ===== REGRA DA DENSIDADE (MENOR VENCE) =====

    if(atributo1 == 5){
        valor1_carta1 = 1 / valor1_carta1;
        valor1_carta2 = 1 / valor1_carta2;
    }

    if(atributo2 == 5){
        valor2_carta1 = 1 / valor2_carta1;
        valor2_carta2 = 1 / valor2_carta2;
    }


    // ===== SOMA FINAL =====

    float somaCarta1 = valor1_carta1 + valor2_carta1;
    float somaCarta2 = valor1_carta2 + valor2_carta2;


    // ===== RESULTADO =====

    printf("\n===== RESULTADO DA RODADA =====\n");

    printf("\nCarta 1: %s\n", nomeCidade1);
    printf("Carta 2: %s\n", nomeCidade2);

    printf("\nSoma da Carta 1: %.2f\n", somaCarta1);
    printf("Soma da Carta 2: %.2f\n", somaCarta2);

    if(somaCarta1 > somaCarta2){
        printf("\nVencedor: Carta 1 (%s)\n", nomeCidade1);
    }
    else if(somaCarta2 > somaCarta1){
        printf("\nVencedor: Carta 2 (%s)\n", nomeCidade2);
    }
    else{
        printf("\nEmpate!\n");
    }

    return 0;
}