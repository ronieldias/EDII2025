#include "heap.h"

int main(){
    Arv R = arv(
        arv(arv(NULL,7,NULL),9,arv(NULL,6,NULL)),
        10,
        arv(arv(NULL,5,NULL),8,arv(NULL,4,NULL)));
    
    Arv R1 = arv(
        arv(arv(NULL,7,NULL),9,arv(NULL,10,NULL)),
        6,
        arv(arv(NULL,8,NULL),5,arv(NULL,4,NULL)));
    
    Arv R2 = arv(
        arv(arv(NULL,10,NULL),7,arv(NULL,6,NULL)),
        9,
        arv(arv(NULL,5,NULL),8, NULL));

    Arv R3 = arv(
        arv(arv(NULL,7,NULL),6,arv(NULL,9,NULL)),
        10,
        arv(NULL,8,NULL));

    /*Arv R4 = arv(
        arv(arv(arv(NULL,8,NULL),4,arv(NULL,9,NULL)),2,arv(arv(NULL,10,NULL),5,arv(NULL,11,NULL))),
        1,
        arv(arv(arv(NULL,12,NULL),6,arv(NULL,13,NULL)),3,arv(arv(NULL,14,NULL),7,arv(NULL,15,NULL)))
    );

    Arv R5 = arv(
        arv(arv(arv(NULL,8,NULL),12,arv(NULL,7,NULL)),14,arv(arv(NULL,6,NULL),11,arv(NULL,5,NULL))),
        15,
        arv(arv(arv(NULL,4,NULL),10,arv(NULL,3,NULL)),13,arv(arv(NULL,2,NULL),9,arv(NULL,1,NULL)))
    );
    
    Arv R6 = arv(
        arv(arv(arv(NULL,16,NULL),12,arv(NULL,7,NULL)),14,arv(arv(NULL,6,NULL),11,arv(NULL,5,NULL))),
        15,
        arv(arv(arv(NULL,4,NULL),10,arv(NULL,3,NULL)),13,arv(arv(NULL,2,NULL),9, NULL))
    );*/

    l();
    printf("Arvore R: "); mostrar_heap(R);
    printf("\nNumero total de nos R: %d", contarNos(R)); 
    int total0 = contarNos(R);
    heapifyCompletoMin(R, total0);
    printf("\nHeap-Min R: "); mostrar_heap(R); 
    l();
    printf("Arvore R1: "); mostrar_heap(R1);
    printf("\nNumero total de nos R1: %d", contarNos(R1));
    int total = contarNos(R1);
    heapifyCompletoMax(R1, total);
    printf("\nHeap-Max R1: "); mostrar_heap(R1); 
    heapifyCompletoMin(R1, total);
    printf("\nHeap-Min R1: "); mostrar_heap(R1); 
    l();
    printf("Arvore R2: "); mostrar_heap(R2);
    printf("\nNumero total de nos R2: %d", contarNos(R2));
    int total2 = contarNos(R2);
    heapifyCompletoMax(R2, total2);
    printf("\nHeap-Max R2: "); mostrar_heap(R2); 
    heapifyCompletoMin(R2, total2);
    printf("\nHeap-Min R2: "); mostrar_heap(R2); 
    l();
    printf("Arvore R3: "); mostrar_heap(R3);
    printf("\nNumero total de nos R3: %d", contarNos(R3)); 
    int total3 = contarNos(R3);
    heapifyCompletoMax(R3, total3);
    printf("\nHeap-Max R3: "); mostrar_heap(R3);
    heapifyCompletoMin(R3, total3);
    printf("\nHeap-Min R3: "); mostrar_heap(R3); l();

}