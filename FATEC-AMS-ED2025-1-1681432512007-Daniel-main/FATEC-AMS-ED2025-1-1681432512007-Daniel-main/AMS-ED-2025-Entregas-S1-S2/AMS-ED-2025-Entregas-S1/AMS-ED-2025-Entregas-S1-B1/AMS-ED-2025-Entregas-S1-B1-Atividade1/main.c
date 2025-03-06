#include <stdio.h>

int main() {
    int prec;
    int desc;
    int valFin;
    
    printf("Digite o valor do produto: \n");
    scanf("%d", &prec);
    
    printf("Digite o valor do desconto: \n");
    scanf("%d", &desc);
    
    valFin = prec - desc;
    
    printf("Valor do produto: %d\n", prec);
    printf("Desconto: %d\n", desc);
    printf("Valor final: %d\n", valFin);

    return 0;
}
