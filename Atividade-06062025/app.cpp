#include "arv.h"

int main()
{
    // EXEMPLO 1: Inserção direta com alinhamento
    printf("EXEMPLO 1: Inserção em árvore já alinhada\n");
    Arv A1 = NULL;
    A1 = inserirAlinhado(A1, 15);
    A1 = inserirAlinhado(A1, 4);
    A1 = inserirAlinhado(A1, 20);
    A1 = inserirAlinhado(A1, 17);
    A1 = inserirAlinhado(A1, 19);

    printf("Em ordem (sem threads): ");
    emordem(A1);
    l();

    printf("Alinhada em ordem (com threads): ");
    alinhadaEmOrdem(A1);
    l();

    // EXEMPLO 2: Conversão de uma árvore normal
    printf("EXEMPLO 2: Converter árvore tradicional para alinhada\n");
    Arv A2 = arv(
        arv(
            arv(NULL, 10, NULL),
            20,
            arv(NULL, 25, NULL)),
        30,
        arv(
            arv(NULL, 40, NULL),
            50,
            arv(NULL, 60, NULL)));

    printf("Em ordem original (antes de alinhar): ");
    emordem(A2);
    l();

    converteBSTemEnlacadaDireita(A2); // cria os enlaces

    printf("Alinhada em ordem: ");
    alinhadaEmOrdem(A2);
    l();

    // ALGORITMO DE MORRI
    // Construindo a árvore do exemplo:
    //       10
    //      /  \
    //     5    20
    //    / \
    //   3   7

    // PARABÉNS, ANINHA
    Arv A3 = arv(arv(arv(NULL, 3, NULL), 5, arv(NULL, 7, NULL)), 10, arv(NULL, 20, NULL));

    printf("PreOrder convencional: ");
    preordem(A3);
    l();
    printf("Algoriritmo de Morris: ");
    MorrisPreOrder(A3);
    l();

    Arv A4 = NULL;
    A4 = inserir(A4, 7);
    A4 = inserir(A4, 6);
    A4 = inserir(A4, 22);
    A4 = inserir(A4, 14);
    A4 = inserir(A4, 40);
    A4 = inserir(A4, 63);

    printf("Em ordem: "); emordem(A4); l();
    printf("Pre ordem: "); preordem(A4); l();
    printf("Pos ordem: "); posordem(A4); l();
    printf("Altura: %d", altura(A4)); l(); 
     

    return 0;
}
