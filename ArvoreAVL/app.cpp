#include "arv.h"

int main() {
    // Criar árvore manual desbalanceada: 30 → 20 → 10
    Arv* raiz = new Arv{30, NULL, NULL, 0};
    raiz->esq = new Arv{20, NULL, NULL, 0};
    raiz->esq->esq = new Arv{10, NULL, NULL, 0};

    atualizarAlturasArvore(raiz);

    // Mostrar antes e depois do balanceamento
    mostrarEstadoCompleto("Arvore manual", raiz, true);

    // Inserir nós (com balanceamento automático)
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 5);
    mostrarEstadoCompleto("Apos insercoes (25 e 5)", raiz);

    // Remover nó 30 (com balanceamento automático)
    raiz = remover(raiz, 30);
    mostrarEstadoCompleto("Apos remocao de 30", raiz);

    return 0;
}
