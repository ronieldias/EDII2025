#include "arv.h"

int main() {

    // ==== Exemplo rotação simples à direita ====

    Arv* A1 = new Arv{40, NULL, NULL, 0};
    A1->esq = new Arv{20, NULL, NULL, 0};
    A1->dir = new Arv{60, NULL, NULL, 0};
    A1->esq->esq = new Arv{15, NULL, NULL, 0};

    atualizarAlturasArvore(A1);

    cout << "\nArvore 1 antes de inserir 10" << endl;
    mostrarAntesBalancear(A1);
    
    cout << "\nArvore 1 depois de inserir 10 (espera-se rotacao simples direita)" << endl;
    A1 = inserirSemBalancear(A1, 10);  // Inserção sem balancear
    mostrarAntesBalancear(A1);            // Mostrar estado já com nó 10, mas sem balancear

    A1 = balancear(A1);                // Balancear explicitamente
    mostrarDepoisBalancear(A1);           // Mostrar estado após balancear

    // ==== Exemplo rotação dupla (Esquerda-Direita) ====

    Arv* A2 = new Arv{30, NULL, NULL, 0};
    A2->esq = new Arv{20, NULL, NULL, 0};
    A2->esq->esq = new Arv{10, NULL, NULL, 0};

    atualizarAlturasArvore(A2);

    cout << "\nArvore 2 antes de insercoes (espera-se rotacao dupla)" << endl;
    mostrarAntesBalancear(A2);

    A2 = inserirSemBalancear(A2, 25);
    A2 = inserirSemBalancear(A2, 5);

    cout << "\nArvore 2 apos insercoes (25 e 5)" << endl;
    mostrarAntesBalancear(A2);

    A2 = balancear(A2);
    mostrarDepoisBalancear(A2);

    // Remover nó 30 (balanceamento automático)
    A2 = remover(A2, 30);
    cout << "\nArvore 2 apos remocao de 30" << endl;
    mostrarAntesBalancear(A2);
    A2 = balancear(A2);
    mostrarDepoisBalancear(A2);

    return 0;
}
