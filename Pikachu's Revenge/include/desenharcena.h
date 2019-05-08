#ifndef DESENHARCENA_H
#define DESENHARCENA_H



void DesenharMira(){
    glColor3fv(ORANGE);

float t, R=15,X=mx,Y=my,Z=0;
int i,N=30;

    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(X,Y,Z);
    glColor3fv(RED);
      for(i = 0; i < N; ++i) {
        t = 5 * M_PI * i / N;
        glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
      }
    glEnd();

        glBegin(GL_LINES);
        glVertex3f(mx-0,my+6,1.0f);
        glVertex3f(mx-0,my+16,1.0f);

        glVertex3f(mx-16,my-8,1.0f);
        glVertex3f(mx-6,my-0,0.0f);

        glVertex3f(mx+16,my-8,1.0f);
        glVertex3f(mx+6,my-0,1.0f);
    glEnd();

    glFlush();
}

#endif // DESENHARCENA_H
