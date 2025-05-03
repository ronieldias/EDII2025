#include "heap.h"

int main(){
    Arv R_min = arv(
        arv(arv(arv(NULL,8,NULL),4,arv(NULL,9,NULL)),2,arv(arv(NULL,10,NULL),5,arv(NULL,11,NULL))),
        1,
        arv(arv(arv(NULL,12,NULL),6,arv(NULL,13,NULL)),3,arv(arv(NULL,14,NULL),7,arv(NULL,15,NULL)))
    );

    Arv R_max = arv(
        arv(arv(arv(NULL,8,NULL),12,arv(NULL,7,NULL)),14,arv(arv(NULL,6,NULL),11,arv(NULL,5,NULL))),
        15,
        arv(arv(arv(NULL,4,NULL),10,arv(NULL,3,NULL)),13,arv(arv(NULL,2,NULL),9,arv(NULL,1,NULL)))
    );

    l();
    printf("Arvore Inicial Heap-Max: "); heap_max(R_max);
    printf("\n");
    printf("Numero total de nos Heap-Max: %d", contarNos(R_max)); l();

}