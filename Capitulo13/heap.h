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


void mostrar_heap(Arv raiz) {
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
    free(fila);
}

void heap_Max(Arv raiz) {
    if (raiz == NULL) return;

    Arv maior = raiz;

    if (raiz->esq && raiz->esq->item > maior->item)
        maior = raiz->esq;

    if (raiz->dir && raiz->dir->item > maior->item)
        maior = raiz->dir;

    if (maior != raiz) {
        // Trocar os valores
        int temp = raiz->item;
        raiz->item = maior->item;
        maior->item = temp;

        // Continuar ajustando recursivamente
        heap_Max(maior);
    }
}

void construirHeapMax(Arv raiz) {
    if (raiz == NULL) return;

    // Primeiro ajusta os filhos
    construirHeapMax(raiz->esq);
    construirHeapMax(raiz->dir);

    // Depois ajusta o pai
    heap_Max(raiz);
    
}

void heapifyCompletoMax(Arv raiz, int vezes) {
    for (int i = 0; i < vezes; i++) {
        construirHeapMax(raiz);
    }
}

void heap_Min(Arv raiz) {
    if (raiz == NULL) return;

    Arv menor = raiz;

    if (raiz->esq && raiz->esq->item < menor->item)
        menor = raiz->esq;

    if (raiz->dir && raiz->dir->item < menor->item)
        menor = raiz->dir;

    if (menor != raiz) {
        // Trocar os valores
        int temp = raiz->item;
        raiz->item = menor->item;
        menor->item = temp;

        // Continuar ajustando recursivamente
        heap_Min(menor);
    }
}

void construirHeapMin(Arv raiz) {
    if (raiz == NULL) return;

    // Primeiro ajusta os filhos
    construirHeapMin(raiz->esq);
    construirHeapMin(raiz->dir);

    // Depois ajusta o pai
    heap_Min(raiz);
    
}

void heapifyCompletoMin(Arv raiz, int vezes) {
    for (int i = 0; i < vezes; i++) {
        construirHeapMin(raiz);
    }
}

void l(){
    printf("\n--------------------------------------------\n");
}