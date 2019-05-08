#ifndef ARMAS_H_INCLUDED
#define ARMAS_H_INCLUDED

#include "utilitarios.h"
#include <SOIL/SOIL.h>
#include <GL/gl.h>
#include <stdio.h>
#include <time.h>

struct Arma{
    int municao;
    int cartucho;
    int dano;
    int splash;
    int corMira;
    int cartuchoPorLevel;
};
int arma, cartucho;
struct Arma Armas[3];

#endif // ARMAS_H_INCLUDED
