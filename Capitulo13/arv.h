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

//13.1
void emordem(Arv A){
    if(A == NULL)
        return;
    emordem(A->esq);
    printf("%d ", A->item);
    emordem(A->dir);
}

//13.1
void preordem(Arv A){
    if(A== NULL)
        return;
    printf("%d ", A->item);
    preordem(A->esq);
    preordem(A->dir);
}

//13.1
void posordem(Arv A){
    if(A == NULL)
        return;
    posordem(A->esq);
    posordem(A->dir);
    printf("%d ", A->item);
}

//13.2
int nos(Arv A){
    if(A == NULL)
        return 0;
    return 1 + nos(A->esq) + nos(A->dir);
}

//13.3
int folhas(Arv A){
    if(A == NULL)
        return 0;
    if(A->esq == NULL && A->dir == NULL)
        return 1;
    return folhas(A->esq) + folhas(A->dir);
}

//13.4
int altura(Arv A){
    if(A == NULL)
        return 0;
    
    int aEsq = altura(A->esq);
    int aDir = altura(A->dir);

    return 1 + max(aEsq, aDir);
}

//13.5
bool tem(Arv A, int x){
    if(A == NULL)
        return false;
    else if(A->item == x)
        return true;
    else
        return tem(A->esq, x) || tem (A->dir, x);
}

//13.6
bool eb(Arv A){
    //se vazia
    if(A == NULL)
        return true;
    //se o nó tem apenas um filho
    if((A->esq == NULL && A->dir != NULL) || (A->esq != NULL && A->dir == NULL))
        return false;
    return eb(A->esq) && eb(A->dir);
}

//13.7
bool igual(Arv A, Arv B){
    if(A == NULL && B == NULL)
        return true;
    else if(A == NULL || B == NULL)
        return false;
    else if(A->item != B->item)
        return false;
    else{
        return igual(A->esq, B->esq) && igual(A->dir, B->dir);
    }
}

//13.8
int valor(Arv A) {
    // Se o nó for nulo, retorna 0 (caso base)
    if (A == NULL)
        return 0;
    
    // Se for uma folha (operando), retorna o valor do item
    if (A->esq == NULL && A->dir == NULL) {
        return A->item;  // Já é um inteiro
    }
    
    // Avalia recursivamente as subárvores
    int valorEsq = valor(A->esq);
    int valorDir = valor(A->dir);
    
    // Aplica a operação correspondente
    switch (A->item) {
        case '+': return valorEsq + valorDir;
        case '-': return valorEsq - valorDir;
        case '*': return valorEsq * valorDir;
        case '/': return valorEsq / valorDir;
        default: return 0;  // Caso de erro
    }
}

//13.9
void exibe_dec(Arv A){
    if(A== NULL)
        return;
    exibe_dec(A->dir);
    printf("%d ", A->item);
    exibe_dec(A->esq);    
}

// raiz -esquerda -direita
void percorre(Arv A){
	if (A==NULL) return;
	cout<<A->item<<" ";
	percorre(A->esq);
	percorre(A->dir);	
}

int remmax(Arv *A){
    if(*A == NULL) abort();
    while ((*A)->dir != NULL) A = &(*A)->dir;
    Arv n = *A;
    int x = n -> item;
    *A = n ->esq;
    free(n);
    return x;
}

void rem(int x, Arv *A){
    if(*A == NULL) return;
    if(x == (*A)->item){
        Arv n = *A;
        if(n->esq == NULL) *A = n->dir;
        else if (n->dir == NULL) *A = n->esq;
        else n->item = remmax(&n->esq);
        if(n != *A) free(n);
    }
    else if(x <= (*A)->item) rem(x, &(*A)->esq);
    else rem(x, &(*A)->dir);
};

//estética haha
void l(){
    printf("\n--------------------------------------------\n");
}