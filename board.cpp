class board
{
public:
    float coin_x;
    float coin_y;
    int in_hole;
    float vel_x;
    float vel_y;
    char color;

void make_pattern_triangle()
{

glPushMatrix();

glRotatef(0,0,0,1);
for(int i=0;i<8;i++)

{


    glRotatef(((float)360/(float)8)*i,0,0,1);
    glPushMatrix();
    glBegin(GL_TRIANGLES);

    if(i==1||i==2||i==5||i==6)
        glColor3f(0.6875f, 0.0898f, 0.121f);
    else
        glColor3f(0,0,0);

    glVertex3f(-ball_rad,0, 0.0f);
    glVertex3f(0,0, 0.0f);
    glVertex3f(0,0.6, 0.0f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex3f(ball_rad,0, 0.0f);
    glVertex3f(0,0, 0.0f);
    glVertex3f(0,0.6, 0.0f);
    glEnd();
    glPopMatrix();
}


glPopMatrix();

glPushMatrix();

for(int i=1;i<=8;i++)
{
 glRotatef(((float)360/(float)8)*i,0,0,1);
   
    glPushMatrix();
    glTranslatef(ball_rad,ball_rad,0);
    glRotatef(180,0,0,1);
    glBegin(GL_TRIANGLES);

    glColor3f(0.15,0.25,0.66);
    glVertex3f(-0.045,0,0);
    glVertex3f(0.045, 0,0);
    glVertex3f(0,0.0656, 0.0f);
    glEnd();
    glPopMatrix();
}

glPopMatrix();

}

void drawArrow()
{
    //small circle
    glPushMatrix();
    glTranslatef(1.485, -1.5, 0.0f);
    glColor3f(0,0,0);
    glPointSize(1);
    drawCircle(0.065);
    glPopMatrix();
    //line
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(1.8,-1.8,0.0);
    glVertex3f(0.6,-0.6,0);
    glEnd();
    //arc
    glPushMatrix();
    glTranslatef(0.8, -0.8, 0.0f);
    glBegin(GL_POINTS);
    for(int i=0;i<270;++i)
      {
      glVertex3f(0.3*cos(3.14159*i/180),0.3*sin(3.14159*i/180),0);
      }
    glEnd();
    glPopMatrix();

    //triangles
    glPushMatrix();
    glTranslatef(0.78,-1.1, 0.0);
    glRotatef(15, 0.0f, 0.0f, 1.0f);
    glScalef(0.05f, 0.05f, 0.05f);
    drawTriangle();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.08,-0.8, 0.0);
    glRotatef(45, 0.0f, 0.0f, 1.0f);
    glScalef(0.05f, 0.05f, 0.05f);
    drawTriangle();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.82,-1.8, 0.0);
    glRotatef(-15, 0.0f, 0.0f, 1.0f);
    glScalef(0.05f, 0.05f, 0.05f);
    drawTriangle();
    glPopMatrix();

    //corner hole
    glPushMatrix();
    glTranslatef(2.28,-2.28,0);
    glColor3f(0,0,0);
    drawBall(0.2);
    glPopMatrix();

}

void drawDblLine()
{
    
    
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(1.45,-1.3,0.0);
    glVertex3f(1.45,1.3,0);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex3f(1.70,-1.3,0.0);
    glVertex3f(1.70,1.3,0);
    glEnd();
    glPushMatrix();
    glTranslatef(1.56, 1.3, 0.0f);
    glColor3f(0.6875f, 0.0898f, 0.121f);
    drawBall(0.125);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.56, -1.3, 0.0f);
    glColor3f(0.6875f, 0.0898f, 0.121f);
    //drawCircle(0.11);
    drawBall(0.125);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.56, -1.3, 0.0f);
    glColor3f(0,0,0);
    glPointSize(2);
    drawCircle(0.13);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.56, 1.3, 0.0f);
    drawCircle(0.13);
    glPopMatrix();
}


};