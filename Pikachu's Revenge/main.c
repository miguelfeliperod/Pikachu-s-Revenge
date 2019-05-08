#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <SOIL/SOIL.h>
#include "criatura.h"
#include "mira.h"
#include "utilitarios.h"
#include "level.h"
#include "controle.h"
#include "escrita.h"
#include "armas.h"

//Por: Miguel Felipe Rodrigues

int reiniciar = 0, sair = 0;
int pause = 1;      //estado de pause 0= pause, 1= rodando
int meta = 100;     // meta de pontos para passar de level (varia ao decorrer do jogo)
int checkpoint = 1;  // variavel que impede o jogador de voltar em leveis anteriores

void Reiniciar();
void Sair();
void Pause();
void VerificarLevel();

void desenharMinhaCena()
{
    switch(level){
        case 0:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH_TEST);
                DesenharLevel(level);
                DesenharMira();
            glDisable(GL_DEPTH_TEST);
            glFlush();
            break;

        default:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable(GL_DEPTH_TEST);
                if(municao == 0 && cartucho ==0){
                    level = 8;
                    DesenharLevel(level);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Pontuação final:", 200.0f, 500.0f);
                    EscreverPontos(pontos, 350.0f, 500.0f);

                    Reiniciar();
                }
                if (level ==11){
                    DesenharLevel(level);
                    DesenharCreditos();
                }
                if (level == 9){
                    DesenharLevel(level);
                    glColor3f (0.7, 0.0, 0.0);
                //Descrição do menu de armas
                    Escrever( GLUT_BITMAP_TIMES_ROMAN_24 , "     Revolver", 650.0f, 40.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Municao:", 650.0f, 70.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Cartuchos:", 650.0f, 100.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Dano:", 650.0f, 130.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "Especial: Classico e equilibrado", 650.0f, 150.0f);

                    Escrever( GLUT_BITMAP_TIMES_ROMAN_24 , "     Metralhadora", 650.0f, 220.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Municao:", 650.0f, 250.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Cartuchos:", 650.0f, 280.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Dano:", 650.0f, 310.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "Especial: Segure o X para tiros ", 650.0f, 330.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "  rapidos ou o botao esquerdo ", 650.0f, 350.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "do mouse para tiros muito rapidos", 650.0f, 370.0f);

                    Escrever( GLUT_BITMAP_TIMES_ROMAN_24 , "     Sniper", 650.0f, 400.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Municao:", 650.0f, 430.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Cartuchos:", 650.0f, 460.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Dano:", 650.0f, 490.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "Especial: Dano alto, poucos cartuchos", 650.0f, 510.0f);

                    Escrever( GLUT_BITMAP_TIMES_ROMAN_24 , "     Bazooka", 650.0f, 580.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Municao:", 650.0f, 610.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Cartuchos:", 650.0f, 640.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Dano:", 650.0f, 670.0f);
                    Escrever( GLUT_BITMAP_HELVETICA_12 , "Especial: Causa dano em maior area", 650.0f, 690.0f);

                    glColor3f (0.0, 0.0, 0.0);
                    EscreverPontos(Armas[0].municao, 760.0f, 70.0f);
                    EscreverPontos(Armas[0].cartucho, 760.0f, 100.0f);
                    EscreverPontos(Armas[0].dano, 760.0f, 130.0f);

                    EscreverPontos(Armas[1].municao, 760.0f, 250.0f);
                    EscreverPontos(Armas[1].cartucho, 760.0f, 280.0f);
                    EscreverPontos(Armas[1].dano, 760.0f, 310.0f);

                    EscreverPontos(Armas[2].municao, 760.0f, 430.0f);
                    EscreverPontos(Armas[2].cartucho, 760.0f, 460.0f);
                    EscreverPontos(Armas[2].dano, 760.0f, 490.0f);

                    EscreverPontos(Armas[3].municao, 760.0f, 610.0f);
                    EscreverPontos(Armas[3].cartucho, 760.0f, 640.0f);
                    EscreverPontos(Armas[3].dano, 760.0f, 670.0f);
                }
                //Desenha o placar ao fim do jogo
                if (level ==10){
                    DesenharLevel(10);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Pontuação final:", 200.0f, 500.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Alvos inocentes:", 200.0f, 550.0f);
                    EscreverPontos(pontos, 350.0f, 500.0f);
                    EscreverPontos(inocente, 350.0f, 550.0f);
                    //Desenha o jogo e seus elementos, exceto para Menu, creditos, game over e tela de vitoria
                }
                if (level != 8 && level !=11 && level != 9 && level != 10 ){
                    VerificarLevel();
                    DesenharLevel(level);
                    DesenharAlvo();
                    DesenharMira();
                    if (metralhadora == 1){
                        VerificarColisao(mx,my);
                        if (municao>0 && level >0){
                            municao--;
                        }
                    }
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Pontos:", 30.0f, 40.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Meta:", 130.0f, 40.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Cartucho:", 1000.0f, 40.0f);
                    Escrever(GLUT_BITMAP_HELVETICA_18, "Municao:", 1000.0f, 80.0f);
                    glColor3f (0.7, 0.0, 0.0);
                    EscreverPontos(pontos, 100.0f, 40.0f);
                    EscreverPontos(meta, 180.0f, 40.0f);
                    EscreverPontos(cartucho, 1080.0f, 40.0f);
                    EscreverPontos(municao, 1080.0f, 80.0f);
                }
            glDisable(GL_DEPTH_TEST);

        glutSwapBuffers();
    }
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,LARGURA,ALTURA,0,1.0,-1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mainLoop(int value){       //loop principal do jogo

    if (pause == 1){
        Andar();
        glutPostRedisplay();
    }
    glutTimerFunc(30,mainLoop,++value);
}

void Teclado(unsigned char key, int x, int y){

    switch(key){
    case 13:
        if(level==0){
            level = 9;
        }
        break;
    case '1':
        if(level==9){
            arma = 0;
            level = 1;
            municao = Armas[arma].municao;
            cartucho = Armas[arma].cartucho;
        }
        break;
    case '2':
        if(level==9){
            arma = 1;
            level = 1;
            municao = Armas[arma].municao;
            cartucho = Armas[arma].cartucho;
        }
         break;
    case '3':
        if(level==9){
            arma = 2;
            level = 1;
            municao = Armas[arma].municao;
            cartucho = Armas[arma].cartucho;
        }
         break;
    case '4':
        if(level==9){
            arma = 3;
            level = 1;
            municao = Armas[arma].municao;
            cartucho = Armas[arma].cartucho;
        }
         break;
    case 'c':
        if(level==0){
            level = 11;
        }
        else if(level == 11)
            level = 0;
         break;
    case 'p':
        Pause();
        glColor3f (1.0, 0.0, 0.0);
        Escrever(GLUT_BITMAP_HELVETICA_18, "Pause", 600.0f, 340.0f);
        glFlush();
        reiniciar = 0;
        break;
    case 'r':
        Reiniciar();
        break;
    case 'n':               //tecla de negação para exit e reset
        if (reiniciar == 1){

        }
        else if( sair == 1){
            Pause();
            sair = 0;
        }
        break;
    case 'y':                   //tecla de confirmaçao para exit e reset
        if (reiniciar == 1){
            Pause();
            level = 0;
            reiniciar = 0;
            n_monstros = ALVOSMAX;
            checkpoint = 1;
            monstro = 0;
            arma = 0;
            municao =1;
            meta = 100;
            inocente = 0;
            pontos = 0;
            LevelUp(1);
        }
        else if(sair == 1){
            exit(0);
        }
        break;
    case 27:
         Sair();
         break;
    }
}

void Pause(){
    pause = -pause;
}
void Reiniciar(){
    reiniciar = 1;
    Pause();
    glColor3f (1.0, 0.0, 0.0);
    n_monstros = ALVOSMAX;
    Escrever(GLUT_BITMAP_HELVETICA_18, "Deseja reiniciar? y/n", 600.0f, 340.0f);
    glFlush();
}
void Sair(){
    sair = 1;
    Pause();
    glColor3f (1.0, 0.0, 0.0);
    Escrever(GLUT_BITMAP_HELVETICA_18, "Deseja sair? y/n", 600.0f, 340.0f);
    glFlush();
}
void VerificarLevel(){                  //Avaliador de nivel, passa o jogador para o nivel seguinte quando possivel
    if(pontos > 100  && checkpoint < 2){
        level = 2;                //Atualiza nivel
        meta = 300;              //Atualiza meta do nivel
        checkpoint++;             //Atualiza chekpoint
        LevelUp(level);
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;             //acrescimo de munição
    }
    if(pontos > 300  && checkpoint < 3){
        level = 3;
        checkpoint++;
        meta = 600;
        LevelUp(level);
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;
    }
    if(pontos > 600 && checkpoint < 4){
        level = 4;
        checkpoint++;
        meta = 1000;
        LevelUp(level);
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;
    }
    if(pontos > 1000  && checkpoint < 5){
        level = 5;
        checkpoint++;
        LevelUp(level);
        meta = 1500;
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;
    }
        if(pontos > 1500  && checkpoint < 6){
        level = 6;
        checkpoint++;
        meta = 2100;
        LevelUp(level);
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;
    }
        if(pontos > 2100  && checkpoint < 7){
        level = 7;
        checkpoint++;
        meta = 2800;
        LevelUp(level);
        cartucho = cartucho + Armas[arma].cartuchoPorLevel;
    }
    if(pontos > 2800  && checkpoint < 8){
        level = 10;
    }
}


void TecladoUp(unsigned char key, int x, int y){

    switch(key){
        case 'x':
            if(arma!=1){
                glutIgnoreKeyRepeat(1);
            }        //impede disparos seguidos com a tecla x
            else glutIgnoreKeyRepeat(0);                //permite disparos seguidos com a tecla x apenas para metralhadora
                VerificarColisao(x,y);
                if (municao>0){
                    municao--;
                }
        break;
    }
}

int main(int argc, char** argv)
{   glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(LARGURA,ALTURA);
    glutInitWindowPosition(0,0);
    glutCreateWindow("TP1");
    glutDisplayFunc(desenharMinhaCena);  //    glutPostRedisplay();
    glutReshapeFunc(reshape);
    initCriatura();                     //inicia banco de dados de alvos
    iniciarArmas();                     //inicia banco de dados de armas
    initLevel();                        //inicia banco de dados de leveis
    initMira();                         //inicia banco de dados de miras
    glutTimerFunc(20,mainLoop,0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutKeyboardFunc(Teclado);
    glutKeyboardUpFunc(TecladoUp);
    glutMouseFunc(MouseClick);
    glutPassiveMotionFunc(Mouse);
    glutMotionFunc(Mouse);
    glutMainLoop();
    return 0;
}
