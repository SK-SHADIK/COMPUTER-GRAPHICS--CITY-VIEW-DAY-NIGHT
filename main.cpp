#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;

//Lights are on at night and off at day time
//Colors are more dark at night time
//Clouds are animated

void circle(float rx,float ry, float cx, float cy)
{
    float th;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        th=i*3.1416/180;
        glVertex2f(cx+(rx*cos(th)), cy+(ry*sin(th)));
    }
    glEnd();
}

void circle1(float x, float y, double r)
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1=x+((r-.07)*cos(A));
        float y1=y+((r)*sin(A));
        glVertex2f(x1,y1);
    }
    glEnd();
}
void circle2(float x, float y, double r)
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1=x+((r-.03)*cos(A));
        float y1=y+((r)*sin(A));
        glVertex2f(x1,y1);
    }
    glEnd();
}
void circle3(float x, float y, double r)
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1=x+((r-.09)*cos(A));
        float y1=y+((r)*sin(A));
        glVertex2f(x1,y1);
    }
    glEnd();
}
void Cloud1()
{
    glColor3ub(230, 230, 250);//Lavender
    circle1(7,9.4,0.49);
    circle2(7.4,9.4,0.38);
    circle1(7.9,9.45,0.58);
    circle3(8.6,9.47,0.68);
}
void Cloud2()
{
    glColor3ub(230, 230, 250);//Lavender
    circle1(12.0,11.4,0.59);
    circle2(12.6,11.4,0.43);
    circle1(13.2,11.45,0.58);
    circle3(13.7,11.4,0.68);
}
void Cloud3()
{
    glColor3ub(105, 105, 105);//GRAY FOR NIGHT
    circle1(7,9.4,0.49);
    circle2(7.4,9.4,0.38);
    circle1(7.9,9.45,0.58);
    circle3(8.6,9.47,0.68);
}
void Cloud4()
{
    glColor3ub(105, 105, 105);//GRAY FOR NIGHT
    circle1(12.0,11.4,0.59);
    circle2(12.6,11.4,0.43);
    circle1(13.2,11.45,0.58);
    circle3(13.7,11.4,0.68);
}
void Moon()
{
    glColor3ub(199, 199, 199);
    glVertex2d(2.4,13.2);
    circle(0.4,0.7,2.4,13.2);
}
void Sun()
{
    glColor3ub(255, 255, 0);
    glVertex2d(2.4,13.2);
    circle(0.5,0.75,2.4,13.2);
}



float cloud_move1=0.0f;
float cloud_move2=0.0f;

void displayday(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //AHNAF FAIAZ-----------------------------------------------------------------------------------

    glColor3ub(176, 226, 255);//Blue
    glBegin(GL_POLYGON); //SKY FOR DAY
	glVertex2d(0.0, 0.0);
	glVertex2d(15.0,0.0);
	glVertex2d(15.0, 15.0);
	glVertex2d(0.0, 15.0);
	glEnd();

    glPushMatrix();
    glTranslatef(cloud_move1,0.0,0.0);
    Cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move2,0.0,0.0);
    Cloud2();
    glPopMatrix();

    cloud_move1 += 0.02;
    {
    if(cloud_move1>8.5)
    {
        cloud_move1=-12.0;
    }
    }

    cloud_move2 += 0.01;
    {
    if(cloud_move2>3.5)
    {
        cloud_move2=-16.0;
    }
    }

    Sun();

    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glBegin(GL_POLYGON); //Building-1
	glVertex2d(6.8, 6.70);
	glVertex2d(7.0,7.0);
	glVertex2d(7.0, 7.2);
	glVertex2d(6.8, 7.3);
	glEnd();

	glColor3ub(0 ,206 ,209);//dark turquoise
    glBegin(GL_POLYGON); //Building-2
	glVertex2d(6.4, 6.2);
	glVertex2d(6.8,6.7);
	glVertex2d(6.8, 7.5);
	glVertex2d(6.4, 7.9);
	glEnd();

	glColor3ub(0 ,206 ,209);//dark turquoise
    glBegin(GL_POLYGON); //Building-2
	glVertex2d(6.0, 5.6);
	glVertex2d(6.4,6.2);
	glVertex2d(6.4, 7.9);
	glVertex2d(6.0, 7.77);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line middle
	glVertex2d(6.4, 7.9);
	glVertex2d(6.4,6.15);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-1L
	glVertex2d(6.0, 7.1);
	glVertex2d(6.4,7.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-1R
	glVertex2d(6.4, 7.3 );
	glVertex2d(6.8, 7.2 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-2L
	glVertex2d(6.0, 6.6);
	glVertex2d(6.4,6.65);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-2R
	glVertex2d(6.4, 6.65);
	glVertex2d(6.8,6.95);
	glEnd();

    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON); //BUILDING-2 ENTRY
	glVertex2d(6.5, 6.2);
	glVertex2d(6.6, 6.4);
	glVertex2d(6.6, 6.6);
	glVertex2d(6.5, 6.5);
	glEnd();

	glColor3ub(50, 205, 50);//Lime green
    glBegin(GL_POLYGON); //Building-3
	glVertex2d(5.4, 4.6);
	glVertex2d(6.2,5.8);
	glVertex2d(6.2, 7.0);
	glVertex2d(5.4, 7.15);
	glEnd();

	glColor3ub(50, 205, 50);//Lime green
    glBegin(GL_POLYGON); //Building-3
	glVertex2d(4.8, 3.8);
	glVertex2d(5.4, 4.6);
	glVertex2d(5.4, 7.15);
	glVertex2d(4.8, 6.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line middle
	glVertex2d(5.4, 4.6);
	glVertex2d(5.4,7.15);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-1L
	glVertex2d(5.0, 6.0);
	glVertex2d(5.4,6.25);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-1R
	glVertex2d(5.4, 6.25 );
	glVertex2d(6.2, 6.35 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-2L
	glVertex2d(5.0, 5.1);
	glVertex2d(5.4,5.25);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-2R
	glVertex2d(5.4,5.25);
	glVertex2d(6.2,6.0);
	glEnd();

	glColor3ub(147, 112, 219);// MEDIUM purple
    glBegin(GL_POLYGON); //Building-4
	glVertex2d(4.0, 2.6);
	glVertex2d(5.15, 4.2);
	glVertex2d(5.15, 11.8);
	glVertex2d(4.0, 12.2);
	glEnd();

	glColor3ub(147, 112, 219);// MEDIUM purple
    glBegin(GL_POLYGON); //Building-4
	glVertex2d(3.2, 1.6);
	glVertex2d(4.0, 2.6);
	glVertex2d(4.0, 12.2);
	glVertex2d(3.2, 11.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line middle
	glVertex2d(4.0, 2.6);
	glVertex2d(4.0,12.2);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-1L------
	glVertex2d(3.2, 10.2);
	glVertex2d(4.0,10.5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-1R
	glVertex2d(4.0,10.5);
	glVertex2d(5.15, 10.1 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-2L------
	glVertex2d(3.2, 8.8);
	glVertex2d(4.0,9.2);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-2R
	glVertex2d(4.0,9.2);
	glVertex2d(5.15, 8.8 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-3L-------
	glVertex2d(3.2, 7.4);
	glVertex2d(4.0,7.9);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-3R
	glVertex2d(4.0,7.9);
	glVertex2d(5.15,7.8);
	glEnd();
	glBegin(GL_LINES); //Building-4 line-4L-------
	glVertex2d(3.2, 6.0);
	glVertex2d(4.0,6.5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-4R
	glVertex2d(4.0,6.5);
	glVertex2d(5.15,6.55);
	glEnd();
	glBegin(GL_LINES); //Building-4 line-5L-------
	glVertex2d(3.2, 4.4);
	glVertex2d(4.0,5.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-5R
	glVertex2d(4.0,5.0);
	glVertex2d(5.15,5.3);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON); //BUILDING-4 ENTRY
	glVertex2d(4.2, 2.9);
	glVertex2d(4.85, 3.8);
	glVertex2d(4.85, 4.4);
	glVertex2d(4.2, 4.0);
	glEnd();

	glColor3ub(205, 102, 29);//Chocolate3
    glBegin(GL_POLYGON); //Building-5
	glVertex2d(2.0, 0.0);
	glVertex2d(3.8,2.35);
	glVertex2d(3.8, 7.8);
	glVertex2d(2.0, 8.52);
	glEnd();

	glColor3ub(205, 102, 29);//Chocolate3
    glBegin(GL_POLYGON); //Building-5
	glVertex2d(0.0, 0.0);
	glVertex2d(2.0,0.0);
	glVertex2d(2.0, 8.52);
	glVertex2d(0.0, 7.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line middle
	glVertex2d(2.0,0.0);
	glVertex2d(2.0,8.52);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-1L------
	glVertex2d(0.0, 6.3);
	glVertex2d(2.0,7.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-1R
	glVertex2d(2.0,7.0);
	glVertex2d(3.8, 6.4);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-2L------
	glVertex2d(0.0, 4.7);
	glVertex2d(2.0,5.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-2R
	glVertex2d(2.0,5.3);
	glVertex2d(3.8, 4.95 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-3L------
	glVertex2d(0.0, 3.2);
	glVertex2d(2.0,3.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-3R
	glVertex2d(2.0,3.3);
	glVertex2d(3.8, 3.9);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-4L------
	glVertex2d(0.0, 1.8);
	glVertex2d(2.0,1.7);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-4R
	glVertex2d(2.0,1.7);
	glVertex2d(3.8,3.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON); //BUILDING-5 ENTRY
	glVertex2d(2.4, 0.5);
	glVertex2d(3.55, 2.0);
	glVertex2d(3.55, 2.6);
	glVertex2d(2.4, 1.7);
	glEnd();


	//SHADIK HASAN-----------------------------------------------------------------------------------

//RIGHT SIDE BULDING


//LAST BULDING


glColor3ub(255, 255, 0);
glBegin(GL_POLYGON);
glVertex2d(8.0, 5.5);
glVertex2d(10.0, 2.8);
glVertex2d(10.0, 14.0);
glVertex2d(8.0, 15.0);
glVertex2d(7.0, 14.0);
glVertex2d(7.0, 7.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 15.0);
glVertex2d(8.0, 5.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 13.5);
glVertex2d(10.0, 13.5);
glEnd();




glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 12.0);
glVertex2d(10.0, 12.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 11.0);
glVertex2d(10.0, 11.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 10.0);
glVertex2d(10.0, 10.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 9.0);
glVertex2d(10.0, 9.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 8.0);
glVertex2d(10.0, 8.0);
glEnd();



//DOOR



glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(7.2, 6.7);
glVertex2d(7.8, 5.8);
glVertex2d(7.8, 6.7);
glVertex2d(7.2, 7.2);
glEnd();





//2nd BULDING



glColor3ub(255, 106, 106);
glBegin(GL_POLYGON);
glVertex2d(8.0, 5.5);
glVertex2d(14.0, 3.0);
glVertex2d(14.0, 13.0);
glVertex2d(8.0, 13.0);
glVertex2d(10.0, 14.0);
glVertex2d(14.0, 13.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 14.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 12.5);
glVertex2d(14.0, 12.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 11.5);
glVertex2d(14.0, 11.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 10.5);
glVertex2d(14.0, 10.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 9.5);
glVertex2d(14.0, 9.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 8.5);
glVertex2d(14.0, 8.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 7.5);
glVertex2d(14.0, 7.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 6.5);
glVertex2d(14.0, 6.5);
glEnd();




//DOOR



glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(8.2, 5.2);
glVertex2d(8.8, 4.4);
glVertex2d(8.8, 5.6);
glVertex2d(8.2, 6.0);
glEnd();





//1ST BULDING



glColor3ub(70, 130, 180);//
glBegin(GL_POLYGON);
glVertex2d(12.0, 0.0);
glVertex2d(20.0, 0.0);
glVertex2d(20.0, 10.0);
glVertex2d(12.0, 11.0);
glVertex2d(10.0, 10.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(12.0, 11.0);
glVertex2d(12.0, 0.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 9.0);
glVertex2d(20.0, 9.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 8.0);
glVertex2d(20.0, 8.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 7.0);
glVertex2d(20.0, 7.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 6.0);
glVertex2d(20.0, 6.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 5.0);
glVertex2d(20.0, 5.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 4.0);
glVertex2d(20.0, 4.0);
glEnd();




//DOOR



glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(10.5, 2.1);
glVertex2d(11.5, 0.7);
glVertex2d(11.5, 2.0);
glVertex2d(10.5, 3.0);
glEnd();

        //MAHMUDUL HASAN-----------------------------------------------------------------------------------

    glColor3ub(244 ,164 ,96);//Sandy Brown

    ///Road Side
    glBegin(GL_TRIANGLES);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(12.0f, 0.0f, 0.0f);
    glVertex3f(7.0f, 7.0f, 0.0f);

    /// Road
    glColor3f(0.5,0.5,0.5);
    glVertex3f(2.6f, 0.0f, 0.0f);
    glVertex3f(11.4f, 0.0f, 0.0f);
    glVertex3f(7.0f, 6.95f, 0.0f);
    glEnd();
///  *****   middle    *****
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///  1
    glVertex3f(6.95f, 1.2f, 0.0f);
    glVertex3f(7.05f, 1.2f, 0.0f);
    glVertex3f(7.05f, 2.0f, 0.0f);
    glVertex3f(6.95f, 2.0f, 0.0f);

    ///  2
    glVertex3f(6.95f, 2.2f, 0.0f);
    glVertex3f(7.05f, 2.2f, 0.0f);
    glVertex3f(7.05f, 3.0f, 0.0f);
    glVertex3f(6.95f, 3.0f, 0.0f);

    ///  3
    glVertex3f(6.95f, 3.2f, 0.0f);
    glVertex3f(7.05f, 3.2f, 0.0f);
    glVertex3f(7.05f, 4.0f, 0.0f);
    glVertex3f(6.95f, 4.0f, 0.0f);

    ///  4
    glVertex3f(6.96f, 4.2f, 0.0f);
    glVertex3f(7.04f, 4.2f, 0.0f);
    glVertex3f(7.04f, 5.0f, 0.0f);
    glVertex3f(6.96f, 5.0f, 0.0f);

    ///  5
    glVertex3f(6.96f, 5.2f, 0.0f);
    glVertex3f(7.04f, 5.2f, 0.0f);
    glVertex3f(7.04f, 6.0f, 0.0f);
    glVertex3f(6.96f, 6.0f, 0.0f);

    ///  6
    glVertex3f(6.97f, 6.2f, 0.0f);
    glVertex3f(7.03f, 6.2f, 0.0f);
    glVertex3f(7.03f, 7.0f, 0.0f);
    glVertex3f(6.97f, 7.0f, 0.0f);

    glEnd();



    ///******    zebra Crossing   *******
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///  1
    glVertex3f(3.0f, 0.2f, 0.0f);
    glVertex3f(3.5f, 0.2f, 0.0f);
    glVertex3f(4.0f, 1.0f, 0.0f);
    glVertex3f(3.5f, 1.0f, 0.0f);

    ///  2
    glVertex3f(3.7f, 0.2f, 0.0f);
    glVertex3f(4.2f, 0.2f, 0.0f);
    glVertex3f(4.7f, 1.0f, 0.0f);
    glVertex3f(4.2f, 1.0f, 0.0f);

    ///  3
    glVertex3f(4.4f, 0.2f, 0.0f);
    glVertex3f(4.9f, 0.2f, 0.0f);
    glVertex3f(5.4f, 1.0f, 0.0f);
    glVertex3f(4.9f, 1.0f, 0.0f);

    ///  4
    glVertex3f(5.2f, 0.2f, 0.0f);
    glVertex3f(5.7f, 0.2f, 0.0f);
    glVertex3f(6.1f, 1.0f, 0.0f);
    glVertex3f(5.6f, 1.0f, 0.0f);

    ///  5
    glVertex3f(6.05f, 0.2f, 0.0f);
    glVertex3f(6.55f, 0.2f, 0.0f);
    glVertex3f(6.8f, 1.0f, 0.0f);
    glVertex3f(6.4f, 1.0f, 0.0f);

    ///  6
    glVertex3f(7.0f, 0.2f, 0.0f);
    glVertex3f(7.5f, 0.2f, 0.0f);
    glVertex3f(7.45f, 1.0f, 0.0f);
    glVertex3f(7.1f, 1.0f, 0.0f);

    ///  7
    glVertex3f(7.8f, 0.2f, 0.0f);
    glVertex3f(8.3f, 0.2f, 0.0f);
    glVertex3f(8.1f, 1.0f, 0.0f);
    glVertex3f(7.7f, 1.0f, 0.0f);

    ///  8
    glVertex3f(8.5f, 0.2f, 0.0f);
    glVertex3f(9.0f, 0.2f, 0.0f);
    glVertex3f(8.7f, 1.0f, 0.0f);
    glVertex3f(8.3f, 1.0f, 0.0f);

    ///  9
    glVertex3f(9.2f, 0.2f, 0.0f);
    glVertex3f(9.7f, 0.2f, 0.0f);
    glVertex3f(9.3f, 1.0f, 0.0f);
    glVertex3f(8.9f, 1.0f, 0.0f);

    ///  10
    glVertex3f(9.9f, 0.2f, 0.0f);
    glVertex3f(10.4f, 0.2f, 0.0f);
    glVertex3f(9.9f, 1.0f, 0.0f);
    glVertex3f(9.5f, 1.0f, 0.0f);

    ///  11
    glVertex3f(10.6f, 0.2f, 0.0f);
    glVertex3f(11.1f, 0.2f, 0.0f);
    glVertex3f(10.5f, 1.0f, 0.0f);
    glVertex3f(10.1f, 1.0f, 0.0f);

    glEnd();


    /// ******   Buss Left  *******
    glBegin(GL_QUADS);

    /// Front

    glColor3f(0.0f, 0.8f, 0.0f);

    glVertex3f(4.35f, 1.3f, 0.0f);
    glVertex3f(5.05f, 1.3f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);
    glVertex3f(4.4f, 2.5f, 0.0f);

    /// Front Glass
    glColor3f(0.0f, 0.0f, 0.1f);

    glVertex3f(4.39f, 1.9f, 0.0f);
    glVertex3f(5.03f, 1.9f, 0.0f);
    glVertex3f(5.06f, 2.45f, 0.0f);
    glVertex3f(4.44f, 2.45f, 0.0f);

    /// Side

    glColor3f(0.0f, 0.5f, 0.0f);

    glVertex3f(5.05f, 1.3f, 0.0f);
    glVertex3f(6.2f, 3.5f, 0.0f);
    glVertex3f(6.1f, 4.5f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);

    /// Top
    glColor3f(0.0f, 0.3f, 0.0f);

    glVertex3f(4.4f, 2.5f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);
    glVertex3f(6.1f, 4.5f, 0.0f);
    glVertex3f(5.65f, 4.5f, 0.0f);

    glEnd();

    ///  Head Light
    glColor3ub(139, 126, 102);
    glVertex3f(4.35f, 1.3f, 0.0f);
    circle(0.1,0.11,4.5,1.5);
    circle(0.1,0.11,4.9,1.5);

    /// Wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.095,0.3,5.22,1.6);
    circle(0.09,0.3,6.1,3.2);



    /// ****** Bus Right ******
    glBegin(GL_QUADS);



    /// Back
    glColor3f(0.0f, 0.5f, 0.5f);

    glVertex3f(8.3f, 1.8f, 0.0f);
    glVertex3f(9.0f, 2.1f, 0.0f);
    glVertex3f(9.0f, 3.3f, 0.0f);
    glVertex3f(8.3f, 3.0f, 0.0f);

    /// Side
    glColor3f(0.0f, 0.4f, 0.5f);

    glVertex3f(8.3f, 1.8f, 0.0f);
    glVertex3f(8.3f, 3.0f, 0.0f);
    glVertex3f(7.45f, 5.3f, 0.0f);
    glVertex3f(7.35f, 4.5f, 0.0f);

    /// Top
    glColor3f(0.0f, 0.0f, 0.5f);

    glVertex3f(8.3f, 3.0f, 0.0f);
    glVertex3f(9.0f, 3.3f, 0.0f);
    glVertex3f(7.9f, 5.4f, 0.0f);
    glVertex3f(7.45f, 5.3f, 0.0f);

    ///  Back Line

    glColor3f(0.0f, 0.0f, 0.5f);

    glVertex3f(8.4f, 2.4f, 0.0f);
    glVertex3f(8.9f, 2.65f, 0.0f);
    glVertex3f(8.9f, 2.7f, 0.0f);
    glVertex3f(8.4f, 2.45f, 0.0f);

    glVertex3f(8.4f, 2.3f, 0.0f);
    glVertex3f(8.9f, 2.55f, 0.0f);
    glVertex3f(8.9f, 2.6f, 0.0f);
    glVertex3f(8.4f, 2.35f, 0.0f);

    glVertex3f(8.4f, 2.2f, 0.0f);
    glVertex3f(8.9f, 2.45f, 0.0f);
    glVertex3f(8.9f, 2.5f, 0.0f);
    glVertex3f(8.4f, 2.25f, 0.0f);

    glEnd();
    /// Wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.09,0.3,7.54,3.88);
    circle(0.095,0.3,8.09,2.4);



    /// Tree Left

    glBegin(GL_QUADS);


    glColor3f(0.7f, 0.5f, 0.8f);

    glVertex3f(2.8f, 0.6f, 0.0f);
    glVertex3f(2.9f, 0.6f, 0.0f);
    glVertex3f(2.9f, 1.6f, 0.0f);
    glVertex3f(2.8f, 1.6f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex3f(2.25f, 1.6f, 0.0f);
    glVertex3f(3.45f, 1.6f, 0.0f);
    glVertex3f(2.85f, 2.4f, 0.0f);

    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex3f(2.35f, 2.2f, 0.0f);
    glVertex3f(3.35f, 2.2f, 0.0f);
    glVertex3f(2.85f, 3.0f, 0.0f);

    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex3f(2.45f, 2.8f, 0.0f);
    glVertex3f(3.25f, 2.8f, 0.0f);
    glVertex3f(2.85f, 3.6f, 0.0f);
    glEnd();


    /// Tree Right

    glBegin(GL_QUADS);


    glColor3f(0.7f, 0.5f, 0.8f);

    glVertex3f(11.3f, 0.6f, 0.0f);
    glVertex3f(11.4f, 0.6f, 0.0f);
    glVertex3f(11.4f, 1.6f, 0.0f);
    glVertex3f(11.3f, 1.6f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex3f(10.75f, 1.6f, 0.0f);
    glVertex3f(11.95f, 1.6f, 0.0f);
    glVertex3f(11.35f, 2.4f, 0.0f);


    glVertex3f(10.85f, 2.2f, 0.0f);
    glVertex3f(11.85f, 2.2f, 0.0f);
    glVertex3f(11.35f, 3.0f, 0.0f);


    glVertex3f(10.95f, 2.8f, 0.0f);
    glVertex3f(11.75f, 2.8f, 0.0f);
    glVertex3f(11.35f, 3.6f, 0.0f);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //LEFT ROADLIGHT-1-STAND
	glVertex2d(5.1, 4.2);
	glVertex2d(5.2,4.2);
	glVertex2d(5.2, 5.4);
	glVertex2d(5.1, 5.4);
	glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //LEFT ROADLIGHT-1-UPPER_STAND
	glVertex2d(5.1, 5.4);
	glVertex2d(5.5,5.5);
	glVertex2d(5.5, 5.6);
	glVertex2d(5.1, 5.5);
	glEnd();
	glColor3ub(255,255,255);//LEFT ROADLIGHT
    glVertex2d(5.5,5.5);
    circle(0.1,0.11,5.5,5.5);

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //RIGHT ROADLIGHT-1-STAND
	glVertex2d(8.8, 4.2);
	glVertex2d(8.9,4.2);
	glVertex2d(8.9, 5.4);
	glVertex2d(8.8, 5.4);
	glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //RIGHT ROADLIGHT-1-UPPER_STAND
	glVertex2d(8.4, 5.5);
	glVertex2d(8.9, 5.4);
	glVertex2d(8.9, 5.5);
	glVertex2d(8.4, 5.6);
	glEnd();
    glColor3ub(255,255,255);//RIGHT ROADLIGHT
    glVertex2d(8.4,5.5);
    circle(0.1,0.11,8.4,5.5);


	glFlush();

}



///*********************************************************************************************************************************************************************************NIGHT
void displaynight(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


        //AHNAF FAIAZ-----------------------------------------------------------------------------------
    glColor3ub(25, 25, 112);//MIDNIGHT BLUE
    glBegin(GL_POLYGON); //SKY FOR NIGHT
	glVertex2d(0.0, 0.0);
	glVertex2d(15.0,0.0);
	glVertex2d(15.0, 15.0);
	glVertex2d(0.0, 15.0);
	glEnd();

    glPushMatrix();
    glTranslatef(cloud_move1,0.0,0.0);
    Cloud3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_move2,0.0,0.0);
    Cloud4();
    glPopMatrix();

    cloud_move1 += 0.02;
    {
    if(cloud_move1>8.5)
    {
        cloud_move1=-12.0;
    }
    }

    cloud_move2 += 0.01;
    {
    if(cloud_move2>3.5)
    {
        cloud_move2=-16.0;
    }
    }

    Moon();

    glColor3ub(0 ,0, 0);
    glBegin(GL_POLYGON); //Building-1
	glVertex2d(6.8, 6.70);
	glVertex2d(7.0,7.0);
	glVertex2d(7.0, 7.2);
	glVertex2d(6.8, 7.3);
	glEnd();

	glColor3ub(0 ,134, 139);
    glBegin(GL_POLYGON); //Building-2
	glVertex2d(6.4, 6.2);
	glVertex2d(6.8,6.7);
	glVertex2d(6.8, 7.5);
	glVertex2d(6.4, 7.9);
	glEnd();

	glColor3ub(0 ,134, 139);
    glBegin(GL_POLYGON); //Building-2
	glVertex2d(6.0, 5.6);
	glVertex2d(6.4,6.2);
	glVertex2d(6.4, 7.9);
	glVertex2d(6.0, 7.77);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line middle
	glVertex2d(6.4, 7.9);
	glVertex2d(6.4,6.15);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-1L
	glVertex2d(6.0, 7.1);
	glVertex2d(6.4,7.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-1R
	glVertex2d(6.4, 7.3 );
	glVertex2d(6.8, 7.2 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-2L
	glVertex2d(6.0, 6.6);
	glVertex2d(6.4,6.65);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-2 line-2R
	glVertex2d(6.4, 6.65);
	glVertex2d(6.8,6.95);
	glEnd();
    glColor3ub(255, 185, 15);
	glBegin(GL_POLYGON); //BUILDING-2 ENTRY
	glVertex2d(6.5, 6.2);
	glVertex2d(6.6, 6.4);
	glVertex2d(6.6, 6.6);
	glVertex2d(6.5, 6.5);
	glEnd();

	glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON); //Building-3
	glVertex2d(5.4, 4.6);
	glVertex2d(6.2,5.8);
	glVertex2d(6.2, 7.0);
	glVertex2d(5.4, 7.15);
	glEnd();

	glColor3ub(34, 139, 34);
    glBegin(GL_POLYGON); //Building-3
	glVertex2d(4.8, 3.8);
	glVertex2d(5.4, 4.6);
	glVertex2d(5.4, 7.15);
	glVertex2d(4.8, 6.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line middle
	glVertex2d(5.4, 4.6);
	glVertex2d(5.4,7.15);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-1L
	glVertex2d(5.0, 6.0);
	glVertex2d(5.4,6.25);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-1R
	glVertex2d(5.4, 6.25 );
	glVertex2d(6.2, 6.35 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-2L
	glVertex2d(5.0, 5.1);
	glVertex2d(5.4,5.25);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-3 line-2R
	glVertex2d(5.4,5.25);
	glVertex2d(6.2,6.0);
	glEnd();

	glColor3ub(138, 43, 226);
    glBegin(GL_POLYGON); //Building-4
	glVertex2d(4.0, 2.6);
	glVertex2d(5.15, 4.2);
	glVertex2d(5.15, 11.8);
	glVertex2d(4.0, 12.2);
	glEnd();

	glColor3ub(138, 43, 226);
    glBegin(GL_POLYGON); //Building-4
	glVertex2d(3.2, 1.6);
	glVertex2d(4.0, 2.6);
	glVertex2d(4.0, 12.2);
	glVertex2d(3.2, 11.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line middle
	glVertex2d(4.0, 2.6);
	glVertex2d(4.0,12.2);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-1L------
	glVertex2d(3.2, 10.2);
	glVertex2d(4.0,10.5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-1R
	glVertex2d(4.0,10.5);
	glVertex2d(5.15, 10.1 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-2L------
	glVertex2d(3.2, 8.8);
	glVertex2d(4.0,9.2);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-2R
	glVertex2d(4.0,9.2);
	glVertex2d(5.15, 8.8 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-3L-------
	glVertex2d(3.2, 7.4);
	glVertex2d(4.0,7.9);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-3R
	glVertex2d(4.0,7.9);
	glVertex2d(5.15,7.8);
	glEnd();
	glBegin(GL_LINES); //Building-4 line-4L-------
	glVertex2d(3.2, 6.0);
	glVertex2d(4.0,6.5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-4R
	glVertex2d(4.0,6.5);
	glVertex2d(5.15,6.55);
	glEnd();
	glBegin(GL_LINES); //Building-4 line-5L-------
	glVertex2d(3.2, 4.4);
	glVertex2d(4.0,5.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-4 line-5R
	glVertex2d(4.0,5.0);
	glVertex2d(5.15,5.3);
	glEnd();
	glColor3ub(255, 185, 15);
	glBegin(GL_POLYGON); //BUILDING-4 ENTRY
	glVertex2d(4.2, 2.9);
	glVertex2d(4.85, 3.8);
	glVertex2d(4.85, 4.4);
	glVertex2d(4.2, 4.0);
	glEnd();

	glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON); //Building-5
	glVertex2d(2.0, 0.0);
	glVertex2d(3.8,2.35);
	glVertex2d(3.8, 7.8);
	glVertex2d(2.0, 8.52);
	glEnd();

	glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON); //Building-5
	glVertex2d(0.0, 0.0);
	glVertex2d(2.0,0.0);
	glVertex2d(2.0, 8.52);
	glVertex2d(0.0, 7.8);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line middle
	glVertex2d(2.0,0.0);
	glVertex2d(2.0,8.52);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-1L------
	glVertex2d(0.0, 6.3);
	glVertex2d(2.0,7.0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-1R
	glVertex2d(2.0,7.0);
	glVertex2d(3.8, 6.4);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-2L------
	glVertex2d(0.0, 4.7);
	glVertex2d(2.0,5.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-2R
	glVertex2d(2.0,5.3);
	glVertex2d(3.8, 4.95 );
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-3L------
	glVertex2d(0.0, 3.2);
	glVertex2d(2.0,3.3);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-3R
	glVertex2d(2.0,3.3);
	glVertex2d(3.8, 3.9);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-4L------
	glVertex2d(0.0, 1.8);
	glVertex2d(2.0,1.7);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); //Building-5 line-4R
	glVertex2d(2.0,1.7);
	glVertex2d(3.8,3.0);
	glEnd();
	glColor3ub(255, 185, 15);
	glBegin(GL_POLYGON); //BUILDING-5 ENTRY
	glVertex2d(2.4, 0.5);
	glVertex2d(3.55, 2.0);
	glVertex2d(3.55, 2.6);
	glVertex2d(2.4, 1.7);
	glEnd();


	//SHADIK HASAN-----------------------------------------------------------------------------------
//RIGHT SIDE BULDING


//LAST BULDING


glColor3ub(238, 238, 0);
glBegin(GL_POLYGON);
glVertex2d(8.0, 5.5);
glVertex2d(10.0, 2.8);
glVertex2d(10.0, 14.0);
glVertex2d(8.0, 15.0);
glVertex2d(7.0, 14.0);
glVertex2d(7.0, 7.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 15.0);
glVertex2d(8.0, 5.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 13.5);
glVertex2d(10.0, 13.5);
glEnd();




glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 12.0);
glVertex2d(10.0, 12.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 11.0);
glVertex2d(10.0, 11.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 10.0);
glVertex2d(10.0, 10.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 9.0);
glVertex2d(10.0, 9.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(7.0, 8.0);
glVertex2d(10.0, 8.0);
glEnd();



//DOOR



glColor3ub(255, 185, 15);
glBegin(GL_POLYGON);
glVertex2d(7.2, 6.7);
glVertex2d(7.8, 5.8);
glVertex2d(7.8, 6.7);
glVertex2d(7.2, 7.2);
glEnd();





//2nd BULDING



glColor3ub(205, 85, 85);
glBegin(GL_POLYGON);
glVertex2d(8.0, 5.5);
glVertex2d(14.0, 3.0);
glVertex2d(14.0, 13.0);
glVertex2d(8.0, 13.0);
glVertex2d(10.0, 14.0);
glVertex2d(14.0, 13.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 14.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 12.5);
glVertex2d(14.0, 12.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 11.5);
glVertex2d(14.0, 11.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 10.5);
glVertex2d(14.0, 10.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 9.5);
glVertex2d(14.0, 9.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 8.5);
glVertex2d(14.0, 8.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 7.5);
glVertex2d(14.0, 7.5);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(8.0, 6.5);
glVertex2d(14.0, 6.5);
glEnd();




//DOOR



glColor3ub(255, 185, 15);
glBegin(GL_POLYGON);
glVertex2d(8.2, 5.2);
glVertex2d(8.8, 4.4);
glVertex2d(8.8, 5.6);
glVertex2d(8.2, 6.0);
glEnd();





//1ST BULDING



glColor3ub(54, 100, 139);
glBegin(GL_POLYGON);
glVertex2d(12.0, 0.0);
glVertex2d(20.0, 0.0);
glVertex2d(20.0, 10.0);
glVertex2d(12.0, 11.0);
glVertex2d(10.0, 10.0);
glVertex2d(10.0, 2.8);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(12.0, 11.0);
glVertex2d(12.0, 0.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 9.0);
glVertex2d(20.0, 9.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 8.0);
glVertex2d(20.0, 8.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 7.0);
glVertex2d(20.0, 7.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 6.0);
glVertex2d(20.0, 6.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 5.0);
glVertex2d(20.0, 5.0);
glEnd();



glColor3ub(0, 0, 0);
glBegin(GL_LINES);
glVertex2d(10.0, 4.0);
glVertex2d(20.0, 4.0);
glEnd();




//DOOR



glColor3ub(255, 185, 15);
glBegin(GL_POLYGON);
glVertex2d(10.5, 2.1);
glVertex2d(11.5, 0.7);
glVertex2d(11.5, 2.0);
glVertex2d(10.5, 3.0);
glEnd();

        //MAHMUDUL HASAN-----------------------------------------------------------------------------------

    glColor3ub(205, 133, 63);

    ///Road Side
    glBegin(GL_TRIANGLES);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(12.0f, 0.0f, 0.0f);
    glVertex3f(7.0f, 7.0f, 0.0f);

    /// Road
    glColor3f(0.5,0.5,0.5);
    glVertex3f(2.6f, 0.0f, 0.0f);
    glVertex3f(11.4f, 0.0f, 0.0f);
    glVertex3f(7.0f, 6.95f, 0.0f);
    glEnd();
///  *****   middle    *****
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///  1
    glVertex3f(6.95f, 1.2f, 0.0f);
    glVertex3f(7.05f, 1.2f, 0.0f);
    glVertex3f(7.05f, 2.0f, 0.0f);
    glVertex3f(6.95f, 2.0f, 0.0f);

    ///  2
    glVertex3f(6.95f, 2.2f, 0.0f);
    glVertex3f(7.05f, 2.2f, 0.0f);
    glVertex3f(7.05f, 3.0f, 0.0f);
    glVertex3f(6.95f, 3.0f, 0.0f);

    ///  3
    glVertex3f(6.95f, 3.2f, 0.0f);
    glVertex3f(7.05f, 3.2f, 0.0f);
    glVertex3f(7.05f, 4.0f, 0.0f);
    glVertex3f(6.95f, 4.0f, 0.0f);

    ///  4
    glVertex3f(6.96f, 4.2f, 0.0f);
    glVertex3f(7.04f, 4.2f, 0.0f);
    glVertex3f(7.04f, 5.0f, 0.0f);
    glVertex3f(6.96f, 5.0f, 0.0f);

    ///  5
    glVertex3f(6.96f, 5.2f, 0.0f);
    glVertex3f(7.04f, 5.2f, 0.0f);
    glVertex3f(7.04f, 6.0f, 0.0f);
    glVertex3f(6.96f, 6.0f, 0.0f);

    ///  6
    glVertex3f(6.97f, 6.2f, 0.0f);
    glVertex3f(7.03f, 6.2f, 0.0f);
    glVertex3f(7.03f, 7.0f, 0.0f);
    glVertex3f(6.97f, 7.0f, 0.0f);

    glEnd();



    ///******    zebra Crossing   *******
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    ///  1
    glVertex3f(3.0f, 0.2f, 0.0f);
    glVertex3f(3.5f, 0.2f, 0.0f);
    glVertex3f(4.0f, 1.0f, 0.0f);
    glVertex3f(3.5f, 1.0f, 0.0f);

    ///  2
    glVertex3f(3.7f, 0.2f, 0.0f);
    glVertex3f(4.2f, 0.2f, 0.0f);
    glVertex3f(4.7f, 1.0f, 0.0f);
    glVertex3f(4.2f, 1.0f, 0.0f);

    ///  3
    glVertex3f(4.4f, 0.2f, 0.0f);
    glVertex3f(4.9f, 0.2f, 0.0f);
    glVertex3f(5.4f, 1.0f, 0.0f);
    glVertex3f(4.9f, 1.0f, 0.0f);

    ///  4
    glVertex3f(5.2f, 0.2f, 0.0f);
    glVertex3f(5.7f, 0.2f, 0.0f);
    glVertex3f(6.1f, 1.0f, 0.0f);
    glVertex3f(5.6f, 1.0f, 0.0f);

    ///  5
    glVertex3f(6.05f, 0.2f, 0.0f);
    glVertex3f(6.55f, 0.2f, 0.0f);
    glVertex3f(6.8f, 1.0f, 0.0f);
    glVertex3f(6.4f, 1.0f, 0.0f);

    ///  6
    glVertex3f(7.0f, 0.2f, 0.0f);
    glVertex3f(7.5f, 0.2f, 0.0f);
    glVertex3f(7.45f, 1.0f, 0.0f);
    glVertex3f(7.1f, 1.0f, 0.0f);

    ///  7
    glVertex3f(7.8f, 0.2f, 0.0f);
    glVertex3f(8.3f, 0.2f, 0.0f);
    glVertex3f(8.1f, 1.0f, 0.0f);
    glVertex3f(7.7f, 1.0f, 0.0f);

    ///  8
    glVertex3f(8.5f, 0.2f, 0.0f);
    glVertex3f(9.0f, 0.2f, 0.0f);
    glVertex3f(8.7f, 1.0f, 0.0f);
    glVertex3f(8.3f, 1.0f, 0.0f);

    ///  9
    glVertex3f(9.2f, 0.2f, 0.0f);
    glVertex3f(9.7f, 0.2f, 0.0f);
    glVertex3f(9.3f, 1.0f, 0.0f);
    glVertex3f(8.9f, 1.0f, 0.0f);

    ///  10
    glVertex3f(9.9f, 0.2f, 0.0f);
    glVertex3f(10.4f, 0.2f, 0.0f);
    glVertex3f(9.9f, 1.0f, 0.0f);
    glVertex3f(9.5f, 1.0f, 0.0f);

    ///  11
    glVertex3f(10.6f, 0.2f, 0.0f);
    glVertex3f(11.1f, 0.2f, 0.0f);
    glVertex3f(10.5f, 1.0f, 0.0f);
    glVertex3f(10.1f, 1.0f, 0.0f);

    glEnd();


    /// ******   Buss Left  *******
    glBegin(GL_QUADS);

    /// Front

    glColor3f(0.0f, 0.8f, 0.0f);

    glVertex3f(4.35f, 1.3f, 0.0f);
    glVertex3f(5.05f, 1.3f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);
    glVertex3f(4.4f, 2.5f, 0.0f);

    /// Front Glass
    glColor3f(0.0f, 0.0f, 0.1f);

    glVertex3f(4.39f, 1.9f, 0.0f);
    glVertex3f(5.03f, 1.9f, 0.0f);
    glVertex3f(5.06f, 2.45f, 0.0f);
    glVertex3f(4.44f, 2.45f, 0.0f);

    /// Side

    glColor3f(0.0f, 0.5f, 0.0f);

    glVertex3f(5.05f, 1.3f, 0.0f);
    glVertex3f(6.2f, 3.5f, 0.0f);
    glVertex3f(6.1f, 4.5f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);

    /// Top
    glColor3f(0.0f, 0.3f, 0.0f);

    glVertex3f(4.4f, 2.5f, 0.0f);
    glVertex3f(5.1f, 2.5f, 0.0f);
    glVertex3f(6.1f, 4.5f, 0.0f);
    glVertex3f(5.65f, 4.5f, 0.0f);

    glEnd();

    ///  Head Light
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex3f(4.35f, 1.3f, 0.0f);
    circle(0.1,0.11,4.5,1.5);
    circle(0.1,0.11,4.9,1.5);

    /// Wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.095,0.3,5.22,1.6);
    circle(0.09,0.3,6.1,3.2);



    /// ****** Bus Right ******
    glBegin(GL_QUADS);



    /// Back
    glColor3f(0.0f, 0.5f, 0.5f);

    glVertex3f(8.3f, 1.8f, 0.0f);
    glVertex3f(9.0f, 2.1f, 0.0f);
    glVertex3f(9.0f, 3.3f, 0.0f);
    glVertex3f(8.3f, 3.0f, 0.0f);

    /// Side
    glColor3f(0.0f, 0.4f, 0.5f);

    glVertex3f(8.3f, 1.8f, 0.0f);
    glVertex3f(8.3f, 3.0f, 0.0f);
    glVertex3f(7.45f, 5.3f, 0.0f);
    glVertex3f(7.35f, 4.5f, 0.0f);

    /// Top
    glColor3f(0.0f, 0.0f, 0.5f);

    glVertex3f(8.3f, 3.0f, 0.0f);
    glVertex3f(9.0f, 3.3f, 0.0f);
    glVertex3f(7.9f, 5.4f, 0.0f);
    glVertex3f(7.45f, 5.3f, 0.0f);

    ///  Back Line

    glColor3f(0.0f, 0.0f, 0.5f);

    glVertex3f(8.4f, 2.4f, 0.0f);
    glVertex3f(8.9f, 2.65f, 0.0f);
    glVertex3f(8.9f, 2.7f, 0.0f);
    glVertex3f(8.4f, 2.45f, 0.0f);

    glVertex3f(8.4f, 2.3f, 0.0f);
    glVertex3f(8.9f, 2.55f, 0.0f);
    glVertex3f(8.9f, 2.6f, 0.0f);
    glVertex3f(8.4f, 2.35f, 0.0f);

    glVertex3f(8.4f, 2.2f, 0.0f);
    glVertex3f(8.9f, 2.45f, 0.0f);
    glVertex3f(8.9f, 2.5f, 0.0f);
    glVertex3f(8.4f, 2.25f, 0.0f);

    glEnd();
    /// Wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.09,0.3,7.54,3.88);
    circle(0.095,0.3,8.09,2.4);



    /// Tree Left

    glBegin(GL_QUADS);


    glColor3f(0.7f, 0.5f, 0.8f);

    glVertex3f(2.8f, 0.6f, 0.0f);
    glVertex3f(2.9f, 0.6f, 0.0f);
    glVertex3f(2.9f, 1.6f, 0.0f);
    glVertex3f(2.8f, 1.6f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(34, 139, 34);
    glVertex3f(2.25f, 1.6f, 0.0f);
    glVertex3f(3.45f, 1.6f, 0.0f);
    glVertex3f(2.85f, 2.4f, 0.0f);

    glColor3ub(34, 139, 34);
    glVertex3f(2.35f, 2.2f, 0.0f);
    glVertex3f(3.35f, 2.2f, 0.0f);
    glVertex3f(2.85f, 3.0f, 0.0f);

    glColor3ub(34, 139, 34);
    glVertex3f(2.45f, 2.8f, 0.0f);
    glVertex3f(3.25f, 2.8f, 0.0f);
    glVertex3f(2.85f, 3.6f, 0.0f);
    glEnd();


    /// Tree Right

    glBegin(GL_QUADS);


    glColor3f(0.7f, 0.5f, 0.8f);

    glVertex3f(11.3f, 0.6f, 0.0f);
    glVertex3f(11.4f, 0.6f, 0.0f);
    glVertex3f(11.4f, 1.6f, 0.0f);
    glVertex3f(11.3f, 1.6f, 0.0f);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3ub(34, 139, 34);
    glVertex3f(10.75f, 1.6f, 0.0f);
    glVertex3f(11.95f, 1.6f, 0.0f);
    glVertex3f(11.35f, 2.4f, 0.0f);


    glVertex3f(10.85f, 2.2f, 0.0f);
    glVertex3f(11.85f, 2.2f, 0.0f);
    glVertex3f(11.35f, 3.0f, 0.0f);


    glVertex3f(10.95f, 2.8f, 0.0f);
    glVertex3f(11.75f, 2.8f, 0.0f);
    glVertex3f(11.35f, 3.6f, 0.0f);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //LEFT ROADLIGHT-1-STAND
	glVertex2d(5.1, 4.2);
	glVertex2d(5.2,4.2);
	glVertex2d(5.2, 5.4);
	glVertex2d(5.1, 5.4);
	glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //LEFT ROADLIGHT-1-UPPER_STAND
	glVertex2d(5.1, 5.4);
	glVertex2d(5.5,5.5);
	glVertex2d(5.5, 5.6);
	glVertex2d(5.1, 5.5);
	glEnd();
	glColor3ub(255, 255, 0);//LEFT ROADLIGHT
    glVertex2d(5.5,5.5);
    circle(0.1,0.11,5.5,5.5);

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //RIGHT ROADLIGHT-1-STAND
	glVertex2d(8.8, 4.2);
	glVertex2d(8.9,4.2);
	glVertex2d(8.9, 5.4);
	glVertex2d(8.8, 5.4);
	glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON); //RIGHT ROADLIGHT-1-UPPER_STAND
	glVertex2d(8.4, 5.5);
	glVertex2d(8.9, 5.4);
	glVertex2d(8.9, 5.5);
	glVertex2d(8.4, 5.6);
	glEnd();
    glColor3ub(255, 255, 0);//RIGHT ROADLIGHT
    glVertex2d(8.4,5.5);
    circle(0.1,0.11,8.4,5.5);

	glFlush();

}


void handlekeypress(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'd':
    glutDisplayFunc(displayday);
    glutPostRedisplay();
    break;

    case 'n':
    glutDisplayFunc(displaynight);
    glutPostRedisplay();
    break;
    }
    glutPostRedisplay();//marks the current window as needing to be redisplayed.
}

void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 15, 0.0, 15, -10.0, 10.0);

}
void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}
int main (int argc, char** argv)
{
    cout<<"press 'n' to start night view"<<endl;
    cout<<"press 'd' to start day view"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1200,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("City View-Group:4");
    init();
    glutTimerFunc(25,update,0);
    glutKeyboardFunc(handlekeypress);
    glutDisplayFunc(displaynight);
    glutDisplayFunc(displayday);
    glutMainLoop();
    return 0;
}
