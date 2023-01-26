#include <stdlib.h>
#include <stdio.h>
#include "libpilha.h"

pilha_t* pilha_cria (int nelem){
    pilha_t *p = (pilha_t*)malloc(sizeof(pilha_t));
    p->topo = -1;
    p->nelem = nelem;
    p->elems = (int*)malloc(sizeof(int)*p->nelem);
    return p;
    
}

int push (pilha_t* pilha, int elem){
    pilha->topo++;
    pilha->elems[pilha->topo]= elem;
   
    return 0;
}

int pop (pilha_t* pilha){
    if(pilha->topo == -1){
        return 0;
    }
    pilha->elems[pilha->topo] = 0;
    pilha->topo = pilha->topo - 1;
    pilha->nelem--;
    return pilha->topo;
}

int pilha_topo (pilha_t* pilha){
    return pilha->elems[pilha->topo];
};

int pilha_vazia (pilha_t* pilha){
    if(pilha->topo == -1){
        return 1;
    }
    return 0;
}

int pilha_tamanho (pilha_t* pilha){
    return pilha->nelem;
}

pilha_t* pilha_destroi (pilha_t* pilha){
    free(pilha->elems);
    free(pilha);
    return NULL;
}
void pilha_imprime (pilha_t* pilha){
    int i;
     printf("[");
    for(i = 0; i < pilha->nelem; i++){
        if (pilha->elems[i] == 0){
            printf(" ");
        }else
        printf(" %d", pilha->elems[i]);
    }
    printf("]\n");
}


