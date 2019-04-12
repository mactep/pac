#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

Lista* lst_cria(){
    Lista *nova_lista;
    nova_lista = NULL;

    return nova_lista;
}

Lista* lst_insere (Lista *l, int i){
    Lista *novo_item;
    novo_item = (Lista*) malloc(sizeof(Lista));

    novo_item->info = i;
    novo_item->prox = l;

    return novo_item;
}

void lst_imprime (Lista *l){
    Lista *p;

    for (p = l; p != NULL; p = p->prox) {
        printf("%d\n", p->info);
    }
}

Lista* lst_busca (Lista *l, int v){
    Lista *p;

    for(p = l; p != NULL; p = p->prox) {
        if(p->info == v) {
            return p;
        }
    }
    return NULL;
}

void lst_retira (Lista *l, int v){
    Lista *anterior;
    anterior = NULL;
    Lista *p;
    p = l;

    if (p->info == v){
        free(p);
    } else {
        for(p = l; p != NULL; p = p->prox){
            if(p->info == v) {
                anterior->prox = p->prox;
                free(p);
                break;
            }
            anterior = p;
        }
    }
}

int lst_vazia (Lista *l){
    if (l == NULL){
        return 1;
    } else {
        return 0;
    }
}

void lst_libera (Lista *l){
    Lista *p = l;

    while (p != NULL){

    }
}
