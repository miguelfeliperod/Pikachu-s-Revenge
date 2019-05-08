#include "mira.h"
#include "armas.h"
GLsizei mx=0, my=0;
GLuint texturaMira[4];
int raioMira = 20;
void initMira(){
    texturaMira[0] = SOIL_load_OGL_texture("mira.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    texturaMira[1] = SOIL_load_OGL_texture("mira1.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    texturaMira[2] = SOIL_load_OGL_texture("mira2.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    texturaMira[3] = SOIL_load_OGL_texture("mira3.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
    if (texturaMira == 0 ) {
        printf("Erro ao carregar textura: '%s'\n", SOIL_last_result());
    }
}

void DesenharMira(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaMira[arma]);
    glColor3fv(WHITE);
    glBegin(GL_QUADS);
        glTexCoord2f(1, 1); glVertex3f(mx+raioMira, my+raioMira,  0);
        glTexCoord2f(0, 1); glVertex3f(mx-raioMira, my+raioMira,  0);
        glTexCoord2f(0, 0); glVertex3f(mx-raioMira, my-raioMira,  0);
        glTexCoord2f(1, 0); glVertex3f(mx+raioMira, my-raioMira,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Mouse(int x, int y){
    my = y;             //Coordenadas do mouse
    mx = x;

}
