#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct arv{
    struct arv *esq;
    int item;
    struct arv *dir;
}*Arv;

Arv arv(Arv e, int x, Arv d){
    Arv n =(Arv)malloc(sizeof(struct arv));
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
    if(A== NULL)
        return true;
    //se o nó tem apenas um filho
    if((A->esq == NULL && A->dir != NULL) || (A->esq != NULL && A->dir == NULL))
        return false;
    return eb(A->esq) && eb(A->dir);
}

//estética haha
void l(){
    printf("\n-----------------------------------\n");
}