#ifndef MIRA_H_INCLUDED
#define MIRA_H_INCLUDED

#include "utilitarios.h"
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>
#include <SOIL/SOIL.h>

void initMira();
void DesenharMira();
void Mouse(int x, int y);
int my, mx;

#endif // MIRA_H_INCLUDED
