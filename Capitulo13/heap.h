// Fazer heap pra fila (Heap_Min) e pilha (Heap_Max):
// Sistemas de Senhas (Heap_Min): Menor senha maior prioridade.
// Sistemas de Esportes (Heap_Max): Maior quantidade de pontos maior prioridade.

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>



using namespace std;

typedef struct arv{
    struct arv *esq;
    int item;
    struct arv *dir;
}*Arv;

Arv arv(Arv e, int x, Arv d){
    Arv n =(struct arv*)malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;

    return n;
}


int contarNos(Arv raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}


void heap_max(Arv raiz) {
    if (raiz == NULL) return;

    int total = contarNos(raiz);
    Arv* fila = (Arv*)malloc(total * sizeof(Arv)); 

    int ini = 0, fim = 0;

    fila[fim++] = raiz;

    while (ini < fim) {
        Arv atual = fila[ini++];

        printf("%d ", atual->item);

        if (atual->esq != NULL)
            fila[fim++] = atual->esq;
        if (atual->dir != NULL)
            fila[fim++] = atual->dir;
    }
}

void l(){
    printf("\n--------------------------------------------\n");
}