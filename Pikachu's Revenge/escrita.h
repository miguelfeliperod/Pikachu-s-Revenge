#ifndef ESCRITA_H_INCLUDED
#define ESCRITA_H_INCLUDED

#include "utilitarios.h"
#include <SOIL/SOIL.h>
#include <GL/gl.h>
#include <stdio.h>
#include <time.h>

void Escrever(void * font, char *s, float x, float y);
void EscreverVariavel(int num, float x, float y);
void EscreverPontos(int pontos, float x, float y);


#endif // ESCRITA_H_INCLUDED
