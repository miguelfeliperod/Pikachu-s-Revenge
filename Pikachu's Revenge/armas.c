#include "armas.h"

int municao=1, cartucho=0;
int arma = 0;
void iniciarArmas(){                 //Database de armas
    //pistola
    Armas[0].cartucho = 4;
    Armas[0].dano = 4;
    Armas[0].municao = 8;
    Armas[0].splash = 0;
    Armas[0].cartuchoPorLevel = 3;
    //metralhadora
    Armas[1].cartucho = 4;
    Armas[1].dano = 1;
    Armas[1].municao = 35;
    Armas[1].splash = 0;
    Armas[1].cartuchoPorLevel = 3;
    //Sniper
    Armas[2].cartucho = 6;
    Armas[2].dano = 8;
    Armas[2].municao = 4;
    Armas[2].splash = 0;
    Armas[2].cartuchoPorLevel = 4;
    //Bazooka
    Armas[3].cartucho = 5;
    Armas[3].dano = 4;
    Armas[3].municao = 6;
    Armas[3].splash = 50;
    Armas[3].cartuchoPorLevel = 2;
}
