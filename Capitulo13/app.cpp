#include "arv.h"

int main(){
    //arvore exemplo do livro, Fig. 13.5
    Arv R = arv(
            arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),
            1,
            arv(NULL,3,arv(NULL,6,NULL)));

    //arvore somente com raiz
    Arv R2 = arv(NULL, 1, NULL);

    //arvore com todos os nós tendo dois filhos
    Arv R3 = arv(arv(arv(NULL,4,NULL),2,arv(NULL,5,NULL)),1,arv(arv(NULL,6,NULL),3,arv(NULL,7,NULL)));
    
    //Um nó tem apenas filho à esquerda
    // Nó 2 tem apenas filho à esquerda
    Arv R4 = arv(arv(arv(NULL,4,NULL),2,NULL),1,arv(NULL,3,arv(NULL,6,NULL)));
    
    //Um nó tem apenas filho à direita
    // Nó 3 tem apenas filho à direita
    Arv R5 = arv(arv(NULL,2,arv(NULL,5,NULL)),1,arv(NULL,3,NULL));

    Arv R6 = arv(arv(arv(arv(NULL, 5, NULL),'+',arv(NULL, 3, NULL)),'/',arv(NULL, 4, NULL)),'*',arv(arv(NULL, 6, NULL),'-',arv(NULL, 1, NULL)));

    // arvore de busca binaria
    Arv R7 = arv(arv(arv(NULL, 1, NULL),3,arv(arv(NULL, 4, NULL),6,arv(NULL, 7, NULL))),8,arv(NULL,10,arv(arv(NULL, 13, NULL),14,NULL)));

    //arvore binaria de busca balanceada
    Arv R8 = arv(arv(arv(arv(NULL,1,NULL),3,arv(NULL,4,NULL)),5,arv(arv(NULL,6,NULL),7,arv(NULL,9,NULL))),10,arv(arv(arv(NULL,11,NULL),12,arv(NULL,13,NULL)),15,arv(arv(NULL,18,NULL),20,arv(NULL,25,NULL))));
    
    printf("Em ordem: "); emordem(R); l();
    printf("Pre ordem: "); preordem(R); l();
    printf("Pos ordem: "); posordem(R); l();
    printf("Qtde Nos: %d", nos(R)); l();
    printf("Qtde Folhas: %d", folhas(R)); l();
    printf("Altura: %d", altura(R)); l();
    printf("Tem o item 3? %s", tem(R, 6) ? "Sim" : "Nao"); l();
    printf("Arvore EB? %s", eb(R5) ? "Sim" : "Nao"); l();
    printf("Arvores R e R iguais? %s", igual(R, R) ? "Sim" : "Nao"); l();
    printf("O valor da expressao ((5+3)/4)*(6-1) eh: %d", valor(R6)); l();
    printf("Decrescente: "); exibe_dec(R8); l();

    // Aula 25042025
    printf("Remocao do item maximo da arvore R7: %d", remmax(&R7)); l();
    printf("Árvore resultante: "); preordem(R7); l();
    printf("Remocao do item 7 da arvore R8"); l();
    rem(7, &R8);
    printf("Arvore resultante: "); preordem(R8); l();

    //ENVIAR PARA O RONIEL OK
    return 0;
}