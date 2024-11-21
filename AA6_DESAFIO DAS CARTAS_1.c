#include <stdio.h>

#define NUM_CIDADES 32
#define TAM_CODIGO 5  // Aumentado para incluir o caractere nulo
#define TAM_NOME 50

// Definição das variáveis para armazenar as propriedades das cidades
char codigo[NUM_CIDADES][TAM_CODIGO] = {
    "RJ01", "RJ02", "RJ03", "RJ04",  // Rio de Janeiro
    "RS01", "RS02", "RS03", "RS04",  // Rio Grande do Sul
    "PR01", "PR02", "PR03", "PR04",  // Paraná
    "MG01", "MG02", "MG03", "MG04",  // Minas Gerais
    "BA01", "BA02", "BA03", "BA04",  // Bahia
    "ES01", "ES02", "ES03", "ES04",  // Espírito Santo
    "RN01", "RN02", "RN03", "RN04",  // Rio Grande do Norte
    "AM01", "AM02", "AM03", "AM04"   // Amazonas
};
char nome[NUM_CIDADES][TAM_NOME] = {
    "Rio de Janeiro", "Petrópolis", "Niterói", "Angra dos Reis",  // Rio de Janeiro
    "Porto Alegre", "Caxias do Sul", "Pelotas", "Santa Maria",    // Rio Grande do Sul
    "Curitiba", "Londrina", "Maringá", "Foz do Iguaçu",           // Paraná
    "Belo Horizonte", "Uberlândia", "Contagem", "Juiz de Fora",   // Minas Gerais
    "Salvador", "Feira de Santana", "Vitória da Conquista", "Ilhéus",  // Bahia
    "Vitória", "Vila Velha", "Cariacica", "Guarapari",            // Espírito Santo
    "Natal", "Mossoró", "Parnamirim", "Caicó",                    // Rio Grande do Norte
    "Manaus", "Parintins", "Itacoatiara", "Tefé"                  // Amazonas
};
int populacao[NUM_CIDADES] = {
    6775561, 307000, 515317, 207044,      // Rio de Janeiro
    1492530, 517451, 343132, 285159,      // Rio Grande do Sul
    1963726, 575377, 430157, 258823,      // Paraná
    2512070, 699097, 673849, 573285,      // Minas Gerais
    2886698, 619609, 341597, 162327,      // Bahia
    365855, 501325, 398534, 125421,       // Espírito Santo
    890480, 300618, 267036, 68791,        // Rio Grande do Norte
    2338239, 114273, 101337, 61142        // Amazonas
};
float area[NUM_CIDADES] = {
    1182.3, 795.8, 133.9, 816.3,          // Rio de Janeiro
    496.8, 1643.0, 1609.6, 1780.6,        // Rio Grande do Sul
    435.0, 1650.3, 487.0, 617.7,          // Paraná
    331.4, 4114.0, 195.2, 1436.8,         // Minas Gerais
    693.8, 1370.0, 3204.2, 1585.2,        // Bahia
    93.4, 210.3, 280.6, 592.0,            // Espírito Santo
    170.3, 2238.4, 123.3, 1243.3,         // Rio Grande do Norte
    11401.1, 7232.7, 8966.6, 23704.0      // Amazonas
};
float pib[NUM_CIDADES] = {
    360000.0, 14500.0, 20000.0, 7500.0,   // Rio de Janeiro (em milhões)
    75000.0, 20000.0, 12000.0, 8500.0,    // Rio Grande do Sul
    120000.0, 22000.0, 18000.0, 10500.0,  // Paraná
    210000.0, 37000.0, 30000.0, 15000.0,  // Minas Gerais
    150000.0, 24000.0, 12000.0, 8500.0,   // Bahia
    60000.0, 18000.0, 9500.0, 6500.0,     // Espírito Santo
    75000.0, 13000.0, 9000.0, 3500.0,     // Rio Grande do Norte
    95000.0, 7000.0, 5000.0, 3000.0       // Amazonas
};
int pontos_turisticos[NUM_CIDADES] = {
    25, 15, 18, 12,                       // Rio de Janeiro
    20, 10, 8, 6,                         // Rio Grande do Sul
    22, 13, 11, 9,                        // Paraná
    30, 17, 15, 14,                       // Minas Gerais
    35, 20, 10, 8,                        // Bahia
    18, 16, 12, 10,                       // Espírito Santo
    25, 12, 10, 5,                        // Rio Grande do Norte
    40, 15, 10, 7                         // Amazonas
};

int main() {
    printf("Desafio das Cartas!\n\n");

    // Exibição dos Dados das Cidades Cadastradas
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Cidade %d:\n", i + 1);
        printf("Código: %s\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("População: %d\n", populacao[i]);
        printf("Área: %.2f km²\n", area[i]);
        printf("PIB: %.2f milhões\n", pib[i]);
        printf("Pontos Turísticos: %d\n", pontos_turisticos[i]);
        printf("\n");
    }

    // Comparação de Cartas:
    int cidade1, cidade2, atributo;

    printf("Comparação de Cartas!\n");
    printf("Digite o número da primeira cidade para comparar (1 a %d): ", NUM_CIDADES);
    scanf("%d", &cidade1);
    cidade1--; // Ajuste do índice para começar em 0

    printf("Digite o número da segunda cidade para comparar (1 a %d): ", NUM_CIDADES);
    scanf("%d", &cidade2);
    cidade2--; // Ajuste do índice para começar em 0

    // Solicitação do atributo com validação
    do {
        printf("Escolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("Digite o número do atributo (1 a 4): ");
        if (scanf("%d", &atributo) != 1) {
            // Limpar buffer em caso de erro de leitura (evita loop infinito)
            while (getchar() != '\n');
            printf("Entrada inválida! Por favor, insira um número entre 1 e 4.\n");
            atributo = 0; // Atribuir um valor fora do intervalo para repetir o loop
        }
    } while (atributo < 1 || atributo > 4);

    // Lógica de Comparação:
    switch (atributo) {
        case 1:
            if (populacao[cidade1] > populacao[cidade2]) {
                printf("A cidade vencedora é: %s (Maior População: %d habitantes)\n", nome[cidade1], populacao[cidade1]);
            } else if (populacao[cidade1] < populacao[cidade2]) {
                printf("A cidade vencedora é: %s (Maior População: %d habitantes)\n", nome[cidade2], populacao[cidade2]);
            } else {
                printf("As duas cidades têm a mesma população: %d habitantes\n", populacao[cidade1]);
            }
            break;
        case 2:
            if (area[cidade1] > area[cidade2]) {
                printf("A cidade vencedora é: %s (Maior Área: %.2f km²)\n", nome[cidade1], area[cidade1]);
            } else if (area[cidade1] < area[cidade2]) {
                printf("A cidade vencedora é: %s (Maior Área: %.2f km²)\n", nome[cidade2], area[cidade2]);
            } else {
                printf("As duas cidades têm a mesma área: %.2f km²\n", area[cidade1]);
            }
            break;
        case 3:
            if (pib[cidade1] > pib[cidade2]) {
                printf("A cidade vencedora é: %s (Maior PIB: %.2f milhões)\n", nome[cidade1], pib[cidade1]);
            } else if (pib[cidade1] < pib[cidade2]) {
                printf("A cidade vencedora é: %s (Maior PIB: %.2f milhões)\n", nome[cidade2], pib[cidade2]);
            } else {
                printf("As duas cidades têm o mesmo PIB: %.2f milhões\n", pib[cidade1]);
            }
            break;
        case 4:
            if (pontos_turisticos[cidade1] > pontos_turisticos[cidade2]) {
                printf("A cidade vencedora é: %s (Mais Pontos Turísticos: %d)\n", nome[cidade1], pontos_turisticos[cidade1]);
            } else if (pontos_turisticos[cidade1] < pontos_turisticos[cidade2]) {
                printf("A cidade vencedora é: %s (Mais Pontos Turísticos: %d)\n", nome[cidade2], pontos_turisticos[cidade2]);
            } else {
                printf("As duas cidades têm o mesmo número de pontos turísticos: %d\n", pontos_turisticos[cidade1]);
            }
            break;
        default:
            printf("Atributo inválido!\n");
    }

    return 0;
}
