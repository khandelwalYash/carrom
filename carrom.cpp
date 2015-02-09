#include <iostream>
#include <cmath>
#include<stdio.h>
#include <GL/glut.h>
#include <sys/time.h>
#include "coins.cpp"
#include "striker.cpp"
#include "globals.cpp"
#include "board.cpp"
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)

coin coins[20];
strkr striker;
board myBoard;
int main(int argc, char **argv) {

    // Initialize GLUT
    gettimeofday(&tim,NULL);
    t1 = tim.tv_sec+(tim.tv_usec/1000000.0);
    assign_coins();
    assign_striker();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    
    glutInitWindowSize(w,h);
    glutInitWindowPosition(0,0);

    glutCreateWindow("YASH's CARROM");  // Setup the window
    initRendering();

    // Register callbacks
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(handleKeypress1);
    glutSpecialFunc(handleKeypress2);
    glutMotionFunc(handleMouseclick1);
    glutMouseFunc(handleMouseclick);
    glutReshapeFunc(handleResize);
    glutTimerFunc(10, update, 0);
    glutTimerFunc(1000, update_striker_speed,0);

    glutMainLoop();
    
    return 0;
}
void getScore(int value){

                        if(value==0)
                                drawDigit(0);
                        if(value<0){
                                flag0=1;
                                value *= -1;
                        }
                        while (value!=0){
                                drawDigit(value%10);
                                value = value/10;
                                x=x-0.7;
                                y=0;
                        }
                        if(flag0==1){
                                drawDigit(-1);
                        }        

                        x=-3.5;
                        y=0;
                }

                void drawDigit(int digit){

                        if(digit==-1){
                                drawSubDigit(6);
                        }

                        if(digit==0){
                                drawSubDigit(1);
                                drawSubDigit(2);
                                drawSubDigit(3);
                                drawSubDigit(4);
                                drawSubDigit(5);
                                drawSubDigit(7);
                        }

                        if(digit==1){
                                drawSubDigit(1);
                                drawSubDigit(2);
                        }

                        if(digit==2){
                                drawSubDigit(5);
                                drawSubDigit(1);
                                drawSubDigit(6);
                                drawSubDigit(4);
                                drawSubDigit(7);
                        }

                        if(digit==3){
                                drawSubDigit(5);
                                drawSubDigit(1);
                                drawSubDigit(6);
                                drawSubDigit(2);
                                drawSubDigit(7);
                        }

                        if(digit==4){
                                drawSubDigit(3);
                                drawSubDigit(1);
                                drawSubDigit(6);
                                drawSubDigit(2);
                        }

                        if(digit==5){
                                drawSubDigit(3);
                                drawSubDigit(5);
                                drawSubDigit(6);
                                drawSubDigit(2);
                                drawSubDigit(7);
                        }

                        if(digit==6){
                                drawSubDigit(3);
                                drawSubDigit(5);
                                drawSubDigit(6);
                                drawSubDigit(2);
                                drawSubDigit(7);
                                drawSubDigit(4);
                        }

                        if(digit==7){
                                drawSubDigit(1);
                                drawSubDigit(5);
                                drawSubDigit(2);
                        }

                        if(digit==8){
                                drawSubDigit(3);
                                drawSubDigit(4);
                                drawSubDigit(5);
                                drawSubDigit(6);
                                drawSubDigit(2);
                                drawSubDigit(7);
                                drawSubDigit(1);
                        }

                        if(digit==9){
                                drawSubDigit(3);
                                drawSubDigit(5);
                                drawSubDigit(6);
                                drawSubDigit(2);
                                drawSubDigit(7);
                                drawSubDigit(1);
                        }
                }

                void drawSubDigit(int i){

                        if(i==1)
                                line(x,y+0.3,x,y);
                        if(i==2)
                                line(x,y,x,y-0.3);
                        if(i==3)
                                line(x-0.3,y+0.3,x-0.3,y);
                        if(i==4)
                                line(x-0.3,y,x-0.3,y-0.3);
                        if(i==5)
                                line(x,y+0.3,x-0.3,y+0.3);
                        if(i==6)
                                line(x,y,x-0.3,y);
                        if(i==7)
                                line(x,y-0.3,x-0.3,y-0.3);
                }

                void line(float x1, float y1,
                        float x2, float y2){

                        glColor3f(1,1,1);
                        glLineWidth(10);
                        glBegin(GL_LINES);
                                glVertex2f(x1, y1);
                                glVertex2f(x2, y2);
                        glEnd();
                        glLineWidth(2);

                }

void assign_striker()
{
    striker.x = striker_x;
    striker.y = striker_y;
    striker.vel_x = striker_velx;
    striker.vel_y = striker_vely;
}

void assign_coins()
{
    float i;
        coins[0].coin_x = 0;
        coins[0].coin_y = 0;
        coins[0].vel_x = 0.000f;
        coins[0].vel_y = 0.00f;
    for(i=1 ; i<7 ;i++)
    {
        coins[(int)i].in_hole = 0;
        coins[(int)i].coin_x = 2*ball_rad*cos(DEG2RAD(60*i));
        coins[(int)i].coin_y = 2*ball_rad*sin(DEG2RAD(60*i));
        coins[(int)i].vel_x = 0.00f;
        coins[(int)i].vel_y = 0.0f;
    }
    for(i=7 ; i<19 ;i++)
    {
        coins[(int)i].in_hole = 0;
        coins[(int)i].coin_x = 4*ball_rad*cos(DEG2RAD(30*i));
        coins[(int)i].coin_y = 4*ball_rad*sin(DEG2RAD(30*i));
        coins[(int)i].vel_x = 0.00f;
        coins[(int)i].vel_y = 0.00f;
    }
}

// Function to draw objects on the screen
void drawScene() {
    float i,j;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    // Draw Box
    glTranslatef(0.0f, 0.0f, -8.0f);
    glColor3f(0.1f, 0.1f, 0.01f);
    drawBox(box_len);

    //Draw circle
    glPushMatrix();
    glTranslatef(0,0, 0.0f);
    glColor3f(0.6875f, 0.0898f, 0.121f);
    drawCircle(0.6);
    drawCircle(0.7);
    glPopMatrix();
    
    //centre pattern
    myBoard.make_pattern_triangle();

    //Draw inner box
    myBoard.drawDblLine();
    glPushMatrix();
    glTranslatef(0, 0, 0.0f);
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    myBoard.drawDblLine();
     glRotatef(180, 0.0f, 0.0f, 1.0f);
    myBoard.drawDblLine();
     glRotatef(270, 0.0f, 0.0f, 1.0f);
    myBoard.drawDblLine();
    myBoard.drawArrow();
    glRotatef(90, 0.0f, 0.0f, 1.0f);
    myBoard.drawArrow();
    glRotatef(180, 0.0f, 0.0f, 1.0f);
    myBoard.drawArrow();
    glRotatef(270, 0.0f, 0.0f, 1.0f);
    myBoard.drawArrow();
    glPopMatrix();

    //coins
    for(i=0 ; i<19 ;i++)
    {
        if(coins[int(i)].in_hole == 0.0)
        {
            if(i==0)
            {
                glPushMatrix();
                glColor3f(0.871f, 0.148f, 0.148f);
                glTranslatef(coins[(int)i].coin_x,coins[(int)i].coin_y,0);
                coins[(int)i].color = 'r';
                drawBall(ball_rad);
                glPopMatrix();        
            }
            else{
            glPushMatrix();
            glTranslatef(coins[(int)i].coin_x,coins[(int)i].coin_y,0);
            if((int)i%2)
            {
                
                coins[(int)i].color = 'b';
                glColor3f(1,1,1);
                drawCircle(ball_rad-0.01);
                glColor3f(0.0f, 0.0f, 0.0f);
             }
            else
            {
                glColor3f(0,0,0);
                drawCircle(ball_rad);
                glColor3f(1,1,1);
                coins[(int)i].color = 'w';
            }
            drawBall(ball_rad);
            glPopMatrix();
            }
        }
    }

    //striker
    glPushMatrix();
    glColor3f(0.429f, 0.488f, 0.046f);
    glTranslatef(striker.x,striker.y,0);
    drawBall(0.2);
    glColor3f(0,0,0);
    
    drawCircle(striker_rad);
    if( striker.vel_x == 0 && striker.vel_y==0 && count==19)
    draw_marker();
    glPopMatrix();

    //speed bar
    glColor3f(1,1,1);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(3.5,-1.4,0.0);
    glVertex3f(3.5,2.6,0);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(4,-1.40,0.0);
    glVertex3f(4,2.6,0);
    glEnd();
   
    for(int i=1;i<=striker.speed_factor;i++)
    {
        if(striker.speed_factor <= 10)
        {
        glPushMatrix();
        glTranslatef(3.75,-1.55 + float(i)/2.5 ,0);
        glColor3f((float)i/9,1-(float)i/9,0);
        
        glBegin(GL_QUADS);
        glVertex2f(-0.25,-0.2);
        glVertex2f(-0.25,0.2);
        glVertex2f(0.25,0.2);
        glVertex2f(0.25,-0.2);
        glEnd();
        glPopMatrix();
        }

    }

    //hole coins
    j=0;float k=0;
    for(int i=0;i<19;i++)
    {
        if(coins[i].in_hole == 1)
        {   coins[i].coin_x = -10;
            coins[i].coin_y = -10;
            coins[i].vel_x = 0;
            coins[i].vel_y=0;
            glPushMatrix();
            if(coins[i].color == 'b')
            {
                glColor3f(0,0,0);
                j+=1;
                glTranslatef(-5,0.30*j,0);
            }
            else if(coins[i].color == 'w')
            {
                glColor3f(1,1,1);
                k+=1;
               glTranslatef(-5.6,0.30*k,0);
            }
            else if(coins[i].color == 'r')
            {
                glColor3f(0.871f, 0.148f, 0.148f);
                glTranslatef(-5.3,1.35,0);
            }
            drawBall(ball_rad);
            glPopMatrix();     
        }

    }
int time_ ;
gettimeofday(&tim,NULL);
double t2 = tim.tv_sec+(tim.tv_usec/1000000.0);
time_ = int(t2 -t1);
if(old_time + 1 == time_)
score = score - 1;
if(in_hole_flag == 'w')
{
    score+=10;
   in_hole_flag = 'x';
}
else if(in_hole_flag == 'b')
{
    score -= 5;
    in_hole_flag = 'x';
}
else if(in_hole_flag == 'r')
{
    score += 50;
    in_hole_flag = 'x';
}
glPushMatrix();
glColor3f(1,0,1);
glRasterPos3f(-4,0,0);
old_time = time_;
getScore(score);
glPopMatrix();

glPushMatrix();
glTranslatef(-4.2,-0.5,0);
glRasterPos2f(0.0f, 0.0f);
int len;
char string[100]="SCORE";
len = 5;
for (int hh = 0; hh < len; hh++) {
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[hh]);
}
glPopMatrix();
/*    // Draw Triangle
    glPushMatrix();
    glTranslatef(tri_x, tri_y, 0.0f);
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 0.5f);
    drawTriangle();
    glPopMatrix();*/

    glPopMatrix();
    glutSwapBuffers();
}

void draw_marker()
{   glPushMatrix();
        glRotatef(-90+mouse_theta,0,0,1);
        glLineWidth(3); 
        glBegin(GL_LINES); 
        glVertex3f(0,0, 0.0);
        glVertex3f(0,0.8, 0.0);

glEnd();


    glPopMatrix();

}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {
    float u1,u2,ini_cos,ini_sin,rot_velx,energy,rot_vely,rot_velx1,rot_vely1;
    // Handle ball collisions with box
    int i,j;
    count=0;
 
        if((striker.x + striker_rad >= box_len/2 && striker.vel_x > 0)|| (striker.x - striker_rad <= -box_len/2 && striker.vel_x <0))
        striker.vel_x *= -1;
        if((striker.y + striker_rad >= box_len/2 && striker.vel_y > 0) || (striker.y - striker_rad <= -box_len/2 && striker.vel_y < 0))
        striker.vel_y *= -1;
    
    for(i=0;i<19;i++)
    {  
         flag1=0;

        if(pow(abs(coins[i].coin_x) - 2.28 , 2) + pow(abs(coins[i].coin_y) - 2.28 , 2) < 0.04)
        {

            in_hole_flag = coins[i].color;
            coins[i].in_hole = 1;
        }
        if(pow(abs(striker.x) - 2.28, 2) + pow(abs(striker.y) - 2.28,2) < 0.04 )
        {
            striker.x = 0;
            striker.y = -1.6;
            striker.vel_y = 0;
            striker.vel_x = 0;
            score-=5;
         //   checkLeft();
        }
            if(coins[i].vel_x==0 && coins[i].vel_y==0)
                count++;

            if(sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2) ) <= ball_rad + striker_rad)
            {

             if((coins[i].coin_x - striker.x)*(coins[i].vel_x - striker.vel_x) + (coins[i].coin_y - striker.y)*(coins[i].vel_y - striker.vel_y) < 0)
             {
                ini_cos = (coins[i].coin_x - striker.x) / sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2));
                ini_sin = (coins[i].coin_y - striker.y) / sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2));
                u1=(striker.vel_x * ini_cos + striker.vel_y * ini_sin);
                u2 =(coins[i].vel_x * ini_cos + coins[i].vel_y * ini_sin);

                
                rot_velx =  (u2 * (-striker_mass + ball_mass) + 2*striker_mass*u1) / (ball_mass + striker_mass);
                rot_vely = -coins[i].vel_x * ini_sin + coins[i].vel_y * ini_cos ;//0

                rot_velx1 =(u1 * (striker_mass - ball_mass) + 2*ball_mass*u2) / (ball_mass + striker_mass);

                rot_vely1 = -striker.vel_x * ini_sin + striker.vel_y * ini_cos;
                striker.vel_x = rot_velx * ini_cos - rot_vely * ini_sin;
                coins[i].vel_y = (rot_velx *     ini_sin + rot_vely * ini_cos);//-y1
                
                                
                coins[i].vel_x = (rot_velx1 * ini_cos - rot_vely1 * ini_sin);
                striker.vel_y = (rot_velx1 * ini_sin + rot_vely1 * ini_cos);  
                }
                    }
                
        

    if((coins[i].coin_x + ball_rad >= box_len/2 && coins[i].vel_x > 0) || (coins[i].coin_x - ball_rad <= -box_len/2 && coins[i].vel_x <0))
        coins[i].vel_x *= -1;
    if((coins[i].coin_y + ball_rad >= box_len/2 && coins[i].vel_y > 0)|| (coins[i].coin_y - ball_rad <= -box_len/2 && coins[i].vel_y < 0))
        coins[i].vel_y *= -1;

    
    for(j=i+1;j<19;j++)
    {
        if(sqrt(pow((coins[i].coin_x - coins[j].coin_x),2) + pow( (coins[i].coin_y - coins[j].coin_y),2) ) <= 2*ball_rad)
        {
            
        if((coins[i].coin_x - coins[j].coin_x)*(coins[i].vel_x - coins[j].vel_x) + (coins[i].coin_y - coins[j].coin_y)*(coins[i].vel_y - coins[j].vel_y) < 0)
        {
        ini_cos = (coins[i].coin_x - coins[j].coin_x) / sqrt(pow((coins[i].coin_x - coins[j].coin_x),2) + pow( (coins[i].coin_y - coins[j].coin_y),2));
        ini_sin = (coins[i].coin_y - coins[j].coin_y) / sqrt(pow((coins[i].coin_x - coins[j].coin_x),2) + pow( (coins[i].coin_y - coins[j].coin_y),2));
        rot_velx = (coins[j].vel_x * ini_cos + coins[j].vel_y * ini_sin);//y1
        rot_vely = -coins[i].vel_x * ini_sin + coins[i].vel_y * ini_cos ;//0

        
        rot_velx1 = (coins[i].vel_x * ini_cos + coins[i].vel_y * ini_sin);//y
        rot_vely1 = -coins[j].vel_x * ini_sin + coins[j].vel_y * ini_cos;//0
        coins[i].vel_x = rot_velx * ini_cos - rot_vely * ini_sin;//0
        coins[i].vel_y = (rot_velx * ini_sin + rot_vely * ini_cos);//-y1
        
        coins[j].vel_x = (rot_velx1 * ini_cos - rot_vely1 * ini_sin);//0
        coins[j].vel_y = (rot_velx1 * ini_sin + rot_vely1 * ini_cos);//-y
    }
        }
    
    }
    applyFriction(i);
    // Update position of ball
    coins[i].coin_x += coins[i].vel_x;
    coins[i].coin_y += coins[i].vel_y;

        energy+=pow(coins[i].vel_x,2) + pow(coins[i].vel_y,2); 
    
}
    applyFriction(100);
    striker.x += striker.vel_x;
    striker.y += striker.vel_y;
    energy+=2*(pow(striker.vel_x,2) + pow(striker.vel_y,2));
float p=0.0,q=0.0;

if(count==19)
{
    flag1=1;

    if( striker.vel_x==0 && striker.vel_y==0  )
    {
        if(striker.x >1.3 || striker.x<-1.3)
        striker.x = 0;
        striker.y = -1.6;
    }
}
for(i=0;i<19;i++)
{
    p = abs(coins[i].vel_x);
    q = abs(coins[i].vel_y);

if(p<0.0005 && q<0.0005)
{
    coins[i].vel_x=0;
    coins[i].vel_y=0;
}
}
if(abs(striker.vel_y)<0.0005 && abs(striker.vel_x)<0.0005)
{
    striker.vel_x=0;    
    striker.vel_y=0;
}
int total_inhole = 0;
for(int i=0 ; i<19 ; i++)
{
    if(coins[i].in_hole == 1)
    total_inhole+=1;

}
if(total_inhole == 19)
{

    printf("Yeah!! you won and Your score is %d",score);
    exit(0);
}


    glutTimerFunc(10, update, 0);
}
void update_striker_speed(int value)
{
    if(flag == 1)
    {
        striker.incSpeed();
        if(striker.speed_factor==10)
            flag = 0;
    }
    else
     { 
       striker.decSpeed();
       if(striker.speed_factor == 1)
        flag =1;

    }
    glutTimerFunc(1000,update_striker_speed,0);
}
void applyFriction(int i)
{
    if(i==100)
    {
            float x = striker.vel_x;
            float y = striker.vel_y;
            if(x*x + y*y)
        {
            striker.vel_x = x - (x*9.8*0.00006)/sqrt(x*x + y*y);
            striker.vel_y = y - (y*9.8*0.00006)/sqrt(x*x + y*y);
        }
    }
    else
    {
        float x = coins[i].vel_x;
        float y = coins[i].vel_y;
        if(x*x + y*y)
        {
            coins[i].vel_x = x - (x*9.8*0.00006)/sqrt(x*x + y*y);
            coins[i].vel_y = y - (y*9.8*0.00006)/sqrt(x*x + y*y);
        }
    }
}

void drawBox(float len) {
   
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
    glColor3f(1,0.8,0.2);
    glVertex2f(-(len+10) / 2, -(len+10) / 2);
    glVertex2f((len+10) / 2, -(len+10) / 2);
    glVertex2f((len+10) / 2, (len+10) / 2);
    glVertex2f(-(len+10) / 2, (len+10) / 2);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.8,0.21,0);
    glVertex2f(-(len+1) / 2, -(len+1) / 2);
    glVertex2f((len+1) / 2, -(len+1) / 2);
    glVertex2f((len+1) / 2, (len+1) / 2);
    glVertex2f(-(len+1) / 2, (len+1) / 2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.99,0.96,0.558);
    
    glVertex2f(-len / 2, -len / 2);
    glVertex2f(len / 2, -len / 2);
    glVertex2f(len / 2, len / 2);
    glVertex2f(-len / 2, len / 2);
    glEnd();
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawCircle(float rad)
{

glBegin(GL_POINTS);
 for(int i=0;i<720;++i)
  {
  glVertex3f(rad*cos(3.14159*i/180),rad*sin(3.14159*i/180),0);
  }
 glEnd();
}
void drawBall(float rad) {
    
   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++) {
       glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
   }
   glEnd();
}

void drawTriangle() {

    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0,0,0);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glColor3f(0,0,0);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();
}

// Initializing some openGL 3D rendering options
void initRendering() {

    glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
    glEnable(GL_COLOR_MATERIAL);    // Enable coloring
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

    if (key == 27) {
        exit(0);     // escape key is pressed
    }
    if (key=='c')
        {
            striker.decTheta(str_theta);
           
            mouse_theta -= 3.14159;
            if(mouse_theta <=0)
            {
                mouse_theta = 0;
            }
        }
    if (key=='a')
        {
            if(mouse_theta < 183)
            striker.incTheta(str_theta);
            mouse_theta += 3.14159;
            if(mouse_theta >=180)
            {
                mouse_theta = 180;
            }    
        }
    if(key == ' ')
    {
        if(count==19)
        {
            striker.vel_x =0.6*cos((mouse_theta*PI)/180) * striker.speed_factor *0.025;
            striker.vel_y =0.6*sin((mouse_theta*PI)/180) * striker.speed_factor * 0.025;
        }
    }


}

void checkLeft(int i)
{
    if(sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2) ) <= ball_rad + striker_rad)
        {
                while(sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2) ) <= ball_rad + striker_rad && striker.x>-1)
                striker.x -=0.02;
        }
}
void checkRight(int i)
{
    if(sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2) ) <= ball_rad + striker_rad && striker.x<1)
        {
                while(sqrt(pow((coins[i].coin_x - striker.x),2) + pow( (coins[i].coin_y - striker.y),2) ) <= ball_rad + striker_rad)
                striker.x +=0.02;
        }

}
void handleKeypress2(int key, int x, int y) {
int i,j;
    if (key == GLUT_KEY_LEFT)
    {
        if(striker.vel_x == 0 && striker.vel_y == 0)           
            if((striker.x <= 1.25 && striker.x >= -1.25)  || striker.x >= 1.25)
            {
                for(i=0;i<19;i++)
                {
                    checkLeft(i);
                    
                    if(striker.x < -1.3)
                    {
                        striker.x = 0;
                       for(j=0;i<19;j++)
                        {
                            checkLeft(i);
                        }
                    }
                }
                striker.moveLeft();

            }
    }
        if (key == GLUT_KEY_RIGHT)
            if(striker.vel_x == 0 && striker.vel_y == 0)
            if((striker.x >= -1.25 && striker.x <= 1.25)|| striker.x <= -1.25)
            {
                 for(i=0;i<19;i++)
                {
                    checkRight(i);
                    if(striker.x > 1.3)
                    {   
                        striker.x = 0;
                        for(j=0;i<19;j++)
                        {
                            checkLeft(i);
                        }
                    }
                }
                striker.moveRight();
            }
            
    if(key == GLUT_KEY_UP)
        {
            if(striker.speed_factor <10)
            striker.incSpeed();
        }
    if(key == GLUT_KEY_DOWN)
        {
            if(striker.speed_factor > 1)
            striker.decSpeed();
        }
}

void handleMouseclick(int button, int state, int x, int y) {
       float x1,y1;
    x1 = (float)(x - 654)/111.4;
    y1 = (float)(-y + 374)/110.96;
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            {
                mouse_theta = atan((float)(y1-striker.y)/(float)(x1 - striker.x))*180/PI;

            }
    }
    if(mouse_theta < 0)
        mouse_theta+=180;
}

void handleMouseclick1(int x, int y)
{
    float x1,y1;
    x1 = (float)(x - 654)/111.4;
    y1 = (float)(-y + 374)/110.96;
    striker.x = x1;
    striker.y = y1;
}
