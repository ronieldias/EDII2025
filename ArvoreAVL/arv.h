#include <iostream>
#include <algorithm>
using namespace std;

struct Arv
{
    int valor;
    Arv *esq;
    Arv *dir;
    int altura;
};

int altura(Arv *no)
{
    if (no != NULL)
    {
        return no->altura;
    }
    return -1;
}

int fatorBalanceamento(Arv *no)
{
    if (no != NULL)
    {
        return altura(no->dir) - altura(no->esq);
    }
    return 0;
}

void atualizarAltura(Arv *no)
{
    int altEsq = altura(no->esq);
    int altDir = altura(no->dir);
    //no->altura = (altEsq > altDir ? altEsq : altDir) + 1;
    if (altEsq > altDir)
        no->altura = altEsq + 1;
    else
       no->altura = altDir + 1;
}

/*
               10             k2 =  20
                 \                 /  \
                 null             10  30
                /  \
    (k2->esq) null  30

*/

Arv *rotacaoSimplesEsq(Arv *k1)
{
    Arv *k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
    atualizarAltura(k1);
    atualizarAltura(k2);
    return k2;
}

Arv *rotacaoSimplesDir(Arv *k2)
{
    Arv *k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    atualizarAltura(k2);
    atualizarAltura(k1);
    return k1;
}

Arv *balancear(Arv *no)
{
    atualizarAltura(no);
    int fb = fatorBalanceamento(no);

    if (fb < -1)
    {
        if (fatorBalanceamento(no->esq) > 0)
        {
            no->esq = rotacaoSimplesEsq(no->esq);
        }
        return rotacaoSimplesDir(no);
    }
    else
    {
        if (fb > 1)
        {
            if (fatorBalanceamento(no->dir) < 0)
            {
                no->dir = rotacaoSimplesDir(no->dir);
            }
            return rotacaoSimplesEsq(no);
        }
    }
    return no;
}

Arv *inserir(Arv *raiz, int valor)
{
    if (raiz == NULL)
    {
        Arv *novo = new Arv;
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
        return novo;
    }

    if (valor < raiz->valor)
    {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return balancear(raiz);
}

Arv *encontrarMinimo(Arv *no)
{
    while (no->esq != NULL)
    {
        no = no->esq;
    }
    return no;
}

Arv *remover(Arv *raiz, int valor)
{
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor)
    {
        raiz->esq = remover(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = remover(raiz->dir, valor);
    }
    else
    {
        if (raiz->esq == NULL || raiz->dir == NULL)
        {
            Arv *temp = raiz->esq ? raiz->esq : raiz->dir;
            delete raiz;
            return temp;
        }
        else
        {
            Arv *temp = encontrarMinimo(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }

    return balancear(raiz);
}

void imprimirInOrdem(Arv *raiz)
{
    if (raiz != NULL)
    {
        imprimirInOrdem(raiz->esq);
        cout << raiz->valor << " ";
        imprimirInOrdem(raiz->dir);
    }
}

void imprimirFatores(Arv *raiz)
{
    if (raiz != NULL)
    {
        imprimirFatores(raiz->esq);
        cout << "No " << raiz->valor << ": FB = " << fatorBalanceamento(raiz) << endl;
        imprimirFatores(raiz->dir);
    }
}

int alturaArvore(Arv *raiz)
{
    return altura(raiz);
}
