#include <stdio.h>

#define MAX_CANDIDATOS 50

typedef struct {
    char nome[100];
    float PE, AC, PP, EB, NF;
} Candidato;

float calcular_media(float notas[], int tamanho) {
    float soma = 0, maior = notas[0], menor = notas[0];

    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }
    
    return (soma - maior - menor) / (tamanho - 2);
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int total = 0;
    char opcao;

    do {
        if (total >= MAX_CANDIDATOS) break;
        
        Candidato *c = &candidatos[total];
        float notas[10];

        printf("\nNome: ");
        scanf(" %[^\n]", c->nome);

        printf("Digite as 4 notas de PE: ");
        for (int i = 0; i < 4; i++) scanf("%f", &notas[i]);
        c->PE = calcular_media(notas, 4);

        printf("Digite as 5 notas de AC: ");
        for (int i = 0; i < 5; i++) scanf("%f", &notas[i]);
        c->AC = calcular_media(notas, 5);

        printf("Digite as 10 notas de PP: ");
        for (int i = 0; i < 10; i++) scanf("%f", &notas[i]);
        c->PP = calcular_media(notas, 10);

        printf("Digite as 3 notas de EB: ");
        for (int i = 0; i < 3; i++) scanf("%f", &notas[i]);
        c->EB = calcular_media(notas, 3);

        c->NF = (c->PE * 0.3) + (c->AC * 0.1) + (c->PP * 0.4) + (c->EB * 0.2);

        total++;

        printf("\nAdicionar outro candidato? (S/N): ");
        scanf(" %c", &opcao);

    } while (opcao == 'S' || opcao == 's');

    printf("\nLista de Candidatos:\n");
    for (int i = 0; i < total; i++) {
        printf("%d. %s - NF: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].NF);
    }

    return 0;
}