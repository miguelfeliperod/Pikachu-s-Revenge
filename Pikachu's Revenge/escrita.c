#include "escrita.h"

void Escrever(void * font, char *s, float x, float y){
    int i;
    glRasterPos2f(x, y);
    for (i=0; i < strlen(s); i++)
       glutBitmapCharacter(font, s[i]);
}

void EscreverPontos(int pontos, float x, float y)
{             //Transformador de String
    char pontuacao[5];
    sprintf(pontuacao, "%d", pontos);
    Escrever(GLUT_BITMAP_HELVETICA_18, pontuacao, x, y);
}
