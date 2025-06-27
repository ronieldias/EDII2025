#include <iostream>
using namespace std;

struct Arv {
    int valor;
    Arv* esq;
    Arv* dir;
    int altura;
};

// Funções básicas
int altura(Arv* no) {
    if (no == NULL) {
        return -1;
    }
    return no->altura;
}

int fatorBalanceamento(Arv* no) {
    if (no == NULL) return 0;
    return altura(no->dir) - altura(no->esq);
}

int atualizarAlturasArvore(Arv* raiz) {
    if (raiz == NULL) 
        return -1;

    int altEsq = atualizarAlturasArvore(raiz->esq);
    int altDir = atualizarAlturasArvore(raiz->dir);

    if (altEsq > altDir)
        raiz->altura = altEsq + 1;
    else
        raiz->altura = altDir + 1;      

    return raiz->altura;
}

// Rotações
Arv* rotacaoSimplesEsq(Arv* k1) {
    Arv* k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
    atualizarAlturasArvore(k1);
    atualizarAlturasArvore(k2);
    return k2;
}

Arv* rotacaoSimplesDir(Arv* k2) {
    Arv* k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    atualizarAlturasArvore(k2);
    atualizarAlturasArvore(k1);
    return k1;
}

// Balanceamento
Arv* balancear(Arv* no) {
    if (no == NULL) return NULL;

    atualizarAlturasArvore(no);
    int fb = fatorBalanceamento(no);

    if (fb < -1) {
        if (fatorBalanceamento(no->esq) > 0)
            no->esq = rotacaoSimplesEsq(no->esq);
        return rotacaoSimplesDir(no);
    }
    if (fb > 1) {
        if (fatorBalanceamento(no->dir) < 0)
            no->dir = rotacaoSimplesDir(no->dir);
        return rotacaoSimplesEsq(no);
    }
    return no;
}

// Inserção sem balanceamento
Arv* inserirSemBalancear(Arv* raiz, int valor) {
    if (raiz == NULL) {
        Arv* novo = new Arv{valor, NULL, NULL, 0};
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esq = inserirSemBalancear(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserirSemBalancear(raiz->dir, valor);

    atualizarAlturasArvore(raiz);
    return raiz;
}

// Remoção (mantém balanceamento automático)
Arv* encontrarMinimo(Arv* no) {
    while (no->esq != NULL)
        no = no->esq;
    return no;
}

Arv* remover(Arv* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            Arv* temp = raiz->esq ? raiz->esq : raiz->dir;
            delete raiz;
            return temp;
        } else {
            Arv* temp = encontrarMinimo(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }
    return balancear(raiz);
}

// Impressão
void imprimirInOrdem(Arv* raiz) {
    if (raiz != NULL) {
        imprimirInOrdem(raiz->esq);
        cout << raiz->valor << " ";
        imprimirInOrdem(raiz->dir);
    }
}

void imprimirFatores(Arv* raiz) {
    if (raiz != NULL) {
        imprimirFatores(raiz->esq);
        cout << "No " << raiz->valor << ": FB = " << fatorBalanceamento(raiz) << endl;
        imprimirFatores(raiz->dir);
    }
}

void mostrarAntesBalancear(Arv* raiz) {
    cout << "\nAntes do balanceamento:" << endl;
    imprimirInOrdem(raiz);
    cout << "\nFatores antes:" << endl;
    imprimirFatores(raiz);
    cout << "Altura antes: " << altura(raiz) << endl;
}

void mostrarDepoisBalancear(Arv* raiz) {
    cout << "\nBalanceando..." << endl;
    raiz = balancear(raiz);
    atualizarAlturasArvore(raiz);

    cout << "\nApos o balanceamento:" << endl;
    imprimirInOrdem(raiz);
    cout << "\nFatores apos:" << endl;
    imprimirFatores(raiz);
    cout << "Altura apos: " << altura(raiz) << endl;
}
