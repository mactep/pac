#include <stdio.h>
#include "ponto.h"

int main(int argc, char const* argv[])
{
    Ponto* teste;
    teste = cria(1, 2);

    float x, y;
    acessa(teste, &x, &y);
    printf("x: %f\ny: %f\n", x, y);

    atribui(teste, 3, 4);
    acessa(teste, &x, &y);
    printf("x: %f\ny: %f\n", x, y);

    Ponto* eoq;
    Ponto* mlk;
    eoq = cria(1, 2);
    mlk = cria(3, 4);
    printf("Distancia: %f\n", distancia(eoq, mlk));

    return 0;
}
