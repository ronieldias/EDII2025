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
    Arv R4 = arv(arv(arv(NULL,
                        4,
                        NULL),
                    2,
                    NULL),  // Nó 2 tem apenas filho à esquerda
                1,
                arv(NULL,
                    3,
                    arv(NULL,
                        6,
                        NULL))
    );
    
    //Um nó tem apenas filho à direita
    Arv R5 = arv(arv(NULL,
                        2,
                        arv(NULL,
                            5,
                            NULL)),
                    1,
                    arv(NULL,
                        3,
                        NULL)  // Nó 3 tem apenas filho à direita
    );

    Arv R7 = arv(
        arv(
            arv(
                arv(NULL, 5, NULL),
                '+',
                arv(NULL, 3, NULL)
            ),
            '/',
            arv(NULL, 4, NULL)
        ),
        '*',
        arv(
            arv(NULL, 6, NULL),
            '-',
            arv(NULL, 1, NULL)
        )
    );

    // arvore de busca binaria
    Arv R8 = arv(
        arv(
            arv(NULL, 1, NULL),
            3,
            arv(
                arv(NULL, 4, NULL),
                6,
                arv(NULL, 7, NULL)
            )
        ),
        8,
        arv(
            NULL,
            10,
            arv(
                arv(NULL, 13, NULL),
                14,
                NULL
            )
        )
    );
    
    printf("Em ordem: "); emordem(R); l();
    printf("Pre ordem: "); preordem(R); l();
    printf("Pos ordem: "); posordem(R); l();
    printf("Qtde Nos: %d", nos(R)); l();
    printf("Qtde Folhas: %d", folhas(R)); l();
    printf("Altura: %d", altura(R)); l();
    printf("Tem o item 3? %s", tem(R, 6) ? "Sim" : "Nao"); l();
    printf("Arvore EB? %s", eb(R5) ? "Sim" : "Nao"); l();
    printf("Arvores R e R iguais? %s", igual(R, R) ? "Sim" : "Nao"); l();
    printf("O valor da expressão ((5+3)/4)*(6-1) é: %d\n", valor(R7)); l();
    printf("Decrescente: "); exibe_dec(R8); l();

    return 0;
}