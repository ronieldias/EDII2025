#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct arv
{
    struct arv *esq;
    int item;
    struct arv *dir;
    bool sucessor; // true se dir é um enlace (thread), false se é filho
} *Arv;

// Cria novo nó
Arv arv(Arv e, int x, Arv d)
{
    Arv n = (Arv)malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    n->sucessor = false;
    return n;
}

// Inserção ordenada em árvore alinhada à direita
Arv inserirAlinhado(Arv raiz, int valor)
{
    Arv p = raiz, prev = NULL;
    Arv novo = arv(NULL, valor, NULL);

    if (raiz == NULL)
        return novo;

    // Percorre a árvore até encontrar a posição correta
    while (p != NULL)
    {
        prev = p;
        if (valor < p->item)
        {
            if (p->esq != NULL)
                p = p->esq;
            else
                break;
        }
        else if (!p->sucessor)
        {
            p = p->dir;
        }
        else
        {
            break;
        }
    }

    // Insere como filho esquerdo
    if (valor < prev->item)
    {
        prev->esq = novo;
        novo->dir = prev;
        novo->sucessor = true;
    }
    else
    {
        // Insere como filho direito, mantendo os enlaces corretos
        if (prev->sucessor)
        {
            novo->dir = prev->dir;
            novo->sucessor = true;
            prev->sucessor = false;
        }
        prev->dir = novo;
    }

    return raiz;
}

// Em ordem tradicional (sem usar threads)
void emordem(Arv A)
{
    if (A == NULL)
        return;
    emordem(A->esq);
    printf("%d ", A->item);
    if (!A->sucessor)
        emordem(A->dir);
}

void alinhadaEmOrdem(Arv raiz)
{
    Arv prev, p = raiz;

    if (p != 0)
    {
        while (p->esq != 0)
        { // Vai para o nó mais à esquerda
            p = p->esq;
        }
        while (p != 0)
        {
            printf("%d ", p->item); // Visita
            prev = p;
            p = p->dir; // Move para a direita (pode ser filho ou enlace)

            // Se p não é nulo E o ponteiro direito de prev NÃO era um enlace...
            if (p != 0 && prev->sucessor == false)
            {
                while (p->esq != 0)
                { // ...então vá para o mais à esquerda dessa subárvore
                    p = p->esq;
                }
            }
        }
    }
}

// Função auxiliar para criar threads (enlaces)
void criaEnlaces(Arv atual, Arv *anteriorPtr)
{
    if (atual == NULL)
        return;

    criaEnlaces(atual->esq, anteriorPtr);

    if (*anteriorPtr != NULL && (*anteriorPtr)->dir == NULL)
    {
        (*anteriorPtr)->dir = atual;
        (*anteriorPtr)->sucessor = true;
    }

    *anteriorPtr = atual;
    criaEnlaces(atual->dir, anteriorPtr);
}

// Conversão de árvore comum para alinhada à direita
void converteBSTemEnlacadaDireita(Arv raiz)
{
    Arv anterior = NULL;
    criaEnlaces(raiz, &anterior);
}

// estética
void l()
{
    printf("\n--------------------------------------------\n");
}

void MorrisPreOrder(Arv raiz)
{
    Arv p = raiz;
    Arv tmp;

    while (p != nullptr)
    {
        if (p->esq == nullptr)
        {
            printf("%d ", p->item);
            p = p->dir;
        }
        else
        {
            tmp = p->esq;
            while (tmp->dir != nullptr && tmp->dir != p)
            {
                tmp = tmp->dir;
            }

            if (tmp->dir == nullptr)
            {
                printf("%d ", p->item);
                tmp->dir = p;
                p = p->esq;
            }
            else
            {
                tmp->dir = nullptr;
                p = p->dir;
            }
        }
    }
}

void preordem(Arv A)
{
    if (A == NULL)
        return;
    printf("%d ", A->item);
    emordem(A->esq);
    if (!A->sucessor)
        emordem(A->dir);
}

void posordem(Arv A)
{
    if (A == NULL)
        return;
    posordem(A->esq);
    posordem(A->dir);
    printf("%d ", A->item);
}

Arv inserir(Arv raiz, int x)
{
    // Se a árvore está vazia, cria um novo nó
    if (raiz == NULL)
    {
        return arv(NULL, x, NULL); // Retorna um novo nó com valor 'x'
    }

    // Se o valor a ser inserido é menor que o valor do nó atual
    if (x < raiz->item)
    {
        raiz->esq = inserir(raiz->esq, x); // Insere na subárvore à esquerda
    }
    else if (x > raiz->item)
    {
        raiz->dir = inserir(raiz->dir, x); // Insere na subárvore à direita
    }

    // Caso o valor já exista na árvore, não faz nada (não permite duplicatas)
    return raiz;
}

int altura(Arv A)
{
    if (A == NULL)
        return 0;

    int aEsq = altura(A->esq);
    int aDir = altura(A->dir);

    return 1 + max(aEsq, aDir);
}
