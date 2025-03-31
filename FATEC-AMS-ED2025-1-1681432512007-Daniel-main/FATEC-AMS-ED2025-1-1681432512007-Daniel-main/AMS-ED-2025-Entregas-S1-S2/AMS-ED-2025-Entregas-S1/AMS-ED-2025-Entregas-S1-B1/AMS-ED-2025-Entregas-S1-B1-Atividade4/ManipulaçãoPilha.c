#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    double dados[MAX];
    int topo;
} Pilha;

void push(Pilha *p, double valor) { p->dados[++p->topo] = valor; }
double pop(Pilha *p) { return p->dados[p->topo--]; }

void calcular_RPN(char *exp) {
    Pilha p = {.topo = -1};
    char *token = strtok(exp, " ");
    while (token) {
        if (strspn(token, "-0123456789") == strlen(token))
            push(&p, atof(token));
        else {
            double b = pop(&p), a = pop(&p);
            push(&p, (*token == '+') ? a + b : (*token == '-') ? a - b : (*token == '*') ? a * b : a / b);
        }
        token = strtok(NULL, " ");
    }
    printf("Resultado: %.2f\n", pop(&p));
}

int main() {
    char exp[MAX];
    printf("Digite a expressão RPN: ");
    fgets(exp, MAX, stdin);
    calcular_RPN(strtok(exp, "\n"));
    return 0;
}