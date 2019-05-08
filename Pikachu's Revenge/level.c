#include "level.h"

GLuint texturaLevel[12];

void initLevel(){
        texturaLevel[0] = SOIL_load_OGL_texture("menu.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[1] = SOIL_load_OGL_texture("floresta.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[2] = SOIL_load_OGL_texture("caverna.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[3] = SOIL_load_OGL_texture("gelo.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[4] = SOIL_load_OGL_texture("ceu.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[5] = SOIL_load_OGL_texture("fogo.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[6] = SOIL_load_OGL_texture("cidade.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[7] = SOIL_load_OGL_texture("final.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[8] = SOIL_load_OGL_texture("gameover.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[9] = SOIL_load_OGL_texture("weapon.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[10] = SOIL_load_OGL_texture("win.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
        texturaLevel[11] = SOIL_load_OGL_texture("creditos.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
}

void DesenharLevel(int level)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaLevel[level]);
    glColor3fv(WHITE);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f( 0,  ALTURA,  0);
        glTexCoord2f(1, 0); glVertex3f(LARGURA,  ALTURA,  0);
        glTexCoord2f(1, 1); glVertex3f(LARGURA, 0,  0);
        glTexCoord2f(0, 1); glVertex3f( 0, 0,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void DesenharCreditos(){

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex3f(100.0, 100.0, 0.0);
        glVertex3f(100.0, 500.0, 0.0);
        glVertex3f(400.0, 500.0, 0.0);
        glVertex3f(400.0, 100.0, 0.0);

    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_24, "Creditos:", 150.0f, 140.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_10, "Feito por: Miguel Felipe Rodrigues", 140.0f, 180.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_24, "Agradecimentos:", 150.0f, 240.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_10, "Danielle Meira", 140.0f, 280.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_10, "Prof. Fernando Coutinho", 140.0f, 320.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_10, "Igor Chagas Marques", 140.0f, 360.0f);
    Escrever(GLUT_BITMAP_TIMES_ROMAN_10, "Thales Bacelar", 140.0f, 400.0f);
    glFlush();
}
