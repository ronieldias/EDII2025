#include "arv.h"

int main(){
    Arv R = arv(arv(arv(NULL,
                        4,
                        NULL),
                    2,
                    arv(NULL,
                        5,
                        NULL)),
                1,
                arv(NULL,
                    3,
                    arv(NULL,
                        6,
                        NULL))
    );
    
    printf("Em ordem: "); emordem(R);
    l();
    printf("Pre ordem: "); preordem(R);
    l();
    printf("Pos ordem: "); posordem(R);
    l();
    printf("Qtde Nos: %d", nos(R));
    l();
    printf("Qtde Folhas: %d", folhas(R));
    l();
    printf("Altura: %d", altura(R));

    return 0;
}