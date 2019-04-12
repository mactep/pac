#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

Ponto* cria(float x, float y){
    Ponto* p;
    p = (Ponto*) malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    return p;
}

void libera(Ponto* p) {
    free(p);
}

void acessa(Ponto* p, float* x, float* y) {
    *x = p->x;
    *y = p->y;
}

void atribui(Ponto* p, float x, float y) {
    p->x = x;
    p->y = y;
}

float distancia(Ponto* p1, Ponto* p2) {
    float dist = sqrt(pow((p1->x - p2->x), 2.0) + pow((p1->y - p2->y), 2.0));
    return dist;
}
