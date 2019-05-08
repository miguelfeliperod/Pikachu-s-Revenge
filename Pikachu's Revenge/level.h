#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "utilitarios.h"
#include "escrita.h"
#include <stdio.h>
#include <GL/gl.h>
#include <SOIL/SOIL.h>

#define LARGURA 1368 // Largura da janela
#define ALTURA 720     // Altura da janela

void initLevel();
void DesenharLevel();

#endif // LEVEL_H_INCLUDED
