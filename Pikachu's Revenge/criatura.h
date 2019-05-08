#ifndef CRIATURA_H_INCLUDED
#define CRIATURA_H_INCLUDED

#include "utilitarios.h"
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <time.h>
#define ALVOSMAX 20 //define numero maximo de alvos

extern int n_monstros;

struct Monstro{
    GLuint textura;
    int hp;
    int vmin;
    int vmax;
    int alvox;
    int alvoy;
    int x;
    int y;
    int pts;
    float G, B;
};
int level;
int monstro;
int valor;
int municao;
int inocente;

int pontos, metralhadora;

void VerificarColisao(int x, int y);

void LevelUp(int level);

void MudarPontos(int x);

void initCriatura();

void DesenharAlvo();

void Andar();

void MouseClick(int button, int state, int x, int y);

#endif // CRIATURA_H_INCLUDED
