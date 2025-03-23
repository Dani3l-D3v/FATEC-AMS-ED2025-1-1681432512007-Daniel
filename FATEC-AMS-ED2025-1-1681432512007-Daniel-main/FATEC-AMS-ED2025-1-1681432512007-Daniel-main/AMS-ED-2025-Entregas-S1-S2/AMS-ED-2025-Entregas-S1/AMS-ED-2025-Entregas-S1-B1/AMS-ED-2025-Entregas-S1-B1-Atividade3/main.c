#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido {
    int numero;
    char cliente[50], descricao[100], status[20];
    int quantidade;
    struct Pedido *proximo;
} Pedido;

Pedido* inserir(Pedido* lista, int num, char* cli, char* desc, int qtd, char* stat) {
    Pedido* novo = malloc(sizeof(Pedido));
    if (!novo) return lista;
    *novo = (Pedido){num, "", "", "", qtd, lista};
    strcpy(novo->cliente, cli);
    strcpy(novo->descricao, desc);
    strcpy(novo->status, stat);
    return novo;
}

Pedido* deletar(Pedido* lista, int num) {
    Pedido *atual = lista, *anterior = NULL;
    while (atual && atual->numero != num) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (!atual) return lista;
    if (!anterior) lista = atual->proximo;
    else anterior->proximo = atual->proximo;
    free(atual);
    return lista;
}

void exibir(Pedido* lista) {
    while (lista) {
        printf("Pedido #%d - %s - %s - %d - %s\n", lista->numero, lista->cliente, lista->descricao, lista->quantidade, lista->status);
        lista = lista->proximo;
    }
}

int main() {
    Pedido* lista = NULL;
    lista = inserir(lista, 1, "Carlos", "Pizza", 2, "Pendente");
    lista = inserir(lista, 2, "Ana", "Hamburguer", 1, "Em preparo");
    
    exibir(lista);
    lista = deletar(lista, 1);
    exibir(lista);
    
    return 0;
}