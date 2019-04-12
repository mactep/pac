#ifndef _LISTAENCADEADA_H
#define _LISTAENCADEADA_H

struct lista {
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista* lst_cria();

Lista* lst_insere (Lista *l, int i);

void lst_imprime (Lista *l);

Lista* lst_busca (Lista *l, int v);

void lst_retira (Lista *l, int v);

int lst_vazia (Lista *l);

void lst_libera (Lista *l);

#endif
