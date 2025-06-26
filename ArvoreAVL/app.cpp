#include "arv.h"

int main() {

    Arv* raiz = NULL;

    // Caso 1: Rotacao simples à direita (insercao): 30, 20, 10
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10);

    cout << "In-ordem apos insercao (rotacao direita): ";
    imprimirInOrdem(raiz);
    cout << endl;
    imprimirFatores(raiz);
    cout << "Altura da arvore: " << alturaArvore(raiz) << endl;

    // Remoção de nó que causará desbalanceamento: remove 10
    raiz = remover(raiz, 10);
    cout << "\nIn-ordem apos remocao: ";
    imprimirInOrdem(raiz);
    cout << endl;
    imprimirFatores(raiz);
    cout << "Altura da arvore: " << alturaArvore(raiz) << endl;

    return 0;
}