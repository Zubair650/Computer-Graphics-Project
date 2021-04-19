#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <time.h>
#include <iostream>
#include <mmsystem.h>
using namespace std;

float _rain = 0.0;
float _nt = 0.0;
bool rainday = false;
bool night = false;
float _run3 = 0.0;
int flag=0;

GLfloat position = 0.0f;
GLfloat positionR = 0.0f;
GLfloat positionB = 0.0f;
GLfloat positionC = 0.0f;
GLfloat speed = -0.2f;
GLfloat speedR = -0.2f;
GLfloat speedB = -0.2f;
GLfloat speedC = 0.2f;

void BoatMove(int value) {

    positionB += speedB;

	glutPostRedisplay();


	glutTimerFunc(100, BoatMove, 0);
}

void WhiteMan(int value) {

    //if(position > 1.0)
        //position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, WhiteMan, 0);

}

void RedMan(int value) {

    //if(position > 1.0)
        //position = -1.2f;

    positionR += speedR;

	glutPostRedisplay();


	glutTimerFunc(100, RedMan, 0);

}

void CART(int value) {

    //if(position > 1.0)
        //position = -1.2f;

    positionC += speedC;

	glutPostRedisplay();


	glutTimerFunc(100, CART, 0);

}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(currentfont,*c);
	}
}
void Boat()
{
//BOAT
    /////////////////boat body
    glLineWidth(2);
    glColor3ub (102, 102, 255);
    glBegin(GL_LINES);
    glVertex2i(200, 193);
    glVertex2i(270, 193);
    glEnd();

    glColor3ub (77, 26, 0);
    glBegin(GL_QUADS);
    glVertex2i(200, 205);
    glVertex2i(210, 193);
    glVertex2i(260, 193);
    glVertex2i(270, 205);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(200, 205);
    glVertex2i(210, 193);
    glVertex2i(260, 193);
    glVertex2i(270, 205);
    glVertex2i(200, 205);
    glEnd();

    /////////////////boat roof
    glColor3ub (255, 102, 51);
    glBegin(GL_QUADS);
    glVertex2i(220, 205);
    glVertex2i(250, 205);
    glVertex2i(250, 220);
    glVertex2i(220, 220);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(220, 205);
    glVertex2i(250, 205);
    glVertex2i(250, 220);
    glVertex2i(220, 220);
    glVertex2i(220, 205);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(225, 205);
    glVertex2i(225, 220);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(235, 205);
    glVertex2i(235, 220);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(245, 205);
    glVertex2i(245, 220);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(220, 210);
    glVertex2i(250, 210);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(220, 215);
    glVertex2i(250, 215);
    glEnd();


    ////////////////////khuti and dori
    glLineWidth(3);
    glColor3ub (153, 51, 0);
    //glBegin(GL_LINE);
    glBegin(GL_LINES);
    glVertex2i(270, 180);
    glVertex2i(270, 230);

    glVertex2i(270, 210);
    glVertex2i(260, 205);
    glEnd();
}

void Boat2()
{
glPushMatrix();
    glTranslatef(positionB,0.0f, 0.0f);
     //Sailor
    glColor3ub (170, 255, 128);//body
    glBegin(GL_QUADS);
    glVertex2i(255, 255);
    glVertex2i(262, 255);
    glVertex2i(262, 265);
    glVertex2i(255, 265);
    glEnd();
    glColor3ub (170, 255, 128);
    glBegin(GL_QUADS);
    glVertex2i(257, 265);
    glVertex2i(260, 265);
    glVertex2i(260, 267);
    glVertex2i(257, 267);
    glEnd();
    glColor3ub (255, 195, 77);//sailor face
    glBegin(GL_POLYGON);
    glVertex2i(257, 267);
    glVertex2i(260, 267);
    glVertex2i(262, 269);
    glVertex2i(262, 275);
    glVertex2i(255, 275);
    glVertex2i(255, 269);
    glVertex2i(257, 267);
    glEnd();
    glLineWidth(4);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(255, 275);
    glVertex2i(262, 275);
    glEnd();



    //2nd BOAT
    /////////////////boat body

    glColor3ub (102, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(190, 255);
    glVertex2i(200, 243);
    glVertex2i(270, 243);
    glVertex2i(280, 255);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(190, 255);
    glVertex2i(200, 243);
    glVertex2i(270, 243);
    glVertex2i(280, 255);
    glVertex2i(190, 255);
    glEnd();
    glLineWidth(2);
    glColor3ub (102, 102, 255);
    glBegin(GL_LINES);
    glVertex2i(193, 243);
    glVertex2i(277, 243);
    glEnd();



    /////////////////boat roof
    glColor3ub (179, 89, 0);
    glBegin(GL_QUADS);
    glVertex2i(210, 255);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glVertex2i(210, 275);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(210, 255);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glVertex2i(210, 275);
    glVertex2i(210, 255);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(217, 255);
    glVertex2i(217, 275);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(225, 255);
    glVertex2i(225, 275);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(235, 255);
    glVertex2i(235, 275);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(243, 255);
    glVertex2i(243, 275);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(210, 260);
    glVertex2i(250, 260);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(210, 265);
    glVertex2i(250, 265);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(210, 270);
    glVertex2i(250, 270);
    glEnd();

    /////Boat stick
    glLineWidth(4);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(254, 265);
    glVertex2i(267, 235);
    glEnd();
    //Sailors Hand
    glLineWidth(5);
    glColor3ub (255, 195, 77);
    glBegin(GL_LINES);
    glVertex2i(262, 265);
    glVertex2i(256, 262);
    glEnd();
    glPopMatrix();
}

void Grass()
{
glColor3ub (0, 153, 51);
    glBegin(GL_QUADS);
    glVertex2i(00, 0);
    glVertex2i(1240, 0);
    glVertex2i(1240, 190);
    glVertex2i(00, 190);
    glEnd();
}

void Farm()
{
glColor3ub (179, 89, 0);
    glBegin(GL_QUADS);
    glVertex2i(320, 100);
    glVertex2i(1240, 100);
    glVertex2i(1240, 185);
    glVertex2i(270, 185);
    glEnd();

    /*glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(300, 100);
    glVertex2i(1240, 100);
    glVertex2i(1240, 180);
    glVertex2i(250, 180);
    glVertex2i(300, 100);
    glEnd();*/

    glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(350, 100);
    glVertex2i(380, 100);
    glVertex2i(330, 180);
    glVertex2i(300, 180);
    glEnd();


    glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(400, 100);
    glVertex2i(430, 100);
    glVertex2i(380, 180);
    glVertex2i(350, 180);
    glEnd();

     glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(450, 100);
    glVertex2i(480, 100);
    glVertex2i(430, 180);
    glVertex2i(400, 180);
    glEnd();

    glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(500, 100);
    glVertex2i(530, 100);
    glVertex2i(480, 180);
    glVertex2i(450, 180);
    glEnd();

    glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(550, 100);
    glVertex2i(580, 100);
    glVertex2i(530, 180);
    glVertex2i(500, 180);
    glEnd();

    glColor3ub (230, 115, 0);
    glBegin(GL_QUADS);
    glVertex2i(600, 100);
    glVertex2i(630, 100);
    glVertex2i(580, 180);
    glVertex2i(550, 180);
    glEnd();


    //Crops

    //1st crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(320, 160);
    glVertex2i(325, 160);
    glVertex2i(315, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(320, 160);
    glVertex2i(325, 160);
    glVertex2i(319, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(320, 160);
    glVertex2i(325, 160);
    glVertex2i(323, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(325, 160);
    glVertex2i(330, 160);
    glVertex2i(327, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(325, 160);
    glVertex2i(330, 160);
    glVertex2i(331, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(325, 160);
    glVertex2i(330, 160);
    glVertex2i(335, 170);
    glEnd();

    //2nd crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 160);
    glVertex2i(375, 160);
    glVertex2i(365, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 160);
    glVertex2i(375, 160);
    glVertex2i(369, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 160);
    glVertex2i(375, 160);
    glVertex2i(373, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(375, 160);
    glVertex2i(380, 160);
    glVertex2i(377, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(375, 160);
    glVertex2i(380, 160);
    glVertex2i(383, 170);
    glEnd();

    //3rd Crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(420, 160);
    glVertex2i(425, 160);
    glVertex2i(415, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(420, 160);
    glVertex2i(425, 160);
    glVertex2i(419, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(420, 160);
    glVertex2i(425, 160);
    glVertex2i(423, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(425, 160);
    glVertex2i(430, 160);
    glVertex2i(427, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(425, 160);
    glVertex2i(430, 160);
    glVertex2i(433, 170);
    glEnd();

    //4th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(470, 160);
    glVertex2i(475, 160);
    glVertex2i(465, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(470, 160);
    glVertex2i(475, 160);
    glVertex2i(469, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(470, 160);
    glVertex2i(475, 160);
    glVertex2i(473, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(475, 160);
    glVertex2i(480, 160);
    glVertex2i(477, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(475, 160);
    glVertex2i(480, 160);
    glVertex2i(483, 170);
    glEnd();

    //5th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(520, 160);
    glVertex2i(525, 160);
    glVertex2i(515, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(520, 160);
    glVertex2i(525, 160);
    glVertex2i(519, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(520, 160);
    glVertex2i(525, 160);
    glVertex2i(523, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(525, 160);
    glVertex2i(530, 160);
    glVertex2i(527, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(525, 160);
    glVertex2i(530, 160);
    glVertex2i(533, 170);
    glEnd();

    //6th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(570, 160);
    glVertex2i(575, 160);
    glVertex2i(565, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(570, 160);
    glVertex2i(575, 160);
    glVertex2i(569, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(570, 160);
    glVertex2i(575, 160);
    glVertex2i(573, 170);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(575, 160);
    glVertex2i(580, 160);
    glVertex2i(577, 170);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(575, 160);
    glVertex2i(580, 160);
    glVertex2i(583, 170);
    glEnd();

    //7th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(340, 130);
    glVertex2i(345, 130);
    glVertex2i(335, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(340, 130);
    glVertex2i(345, 130);
    glVertex2i(339, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(340, 130);
    glVertex2i(345, 130);
    glVertex2i(343, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(345, 130);
    glVertex2i(350, 130);
    glVertex2i(347, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(345, 130);
    glVertex2i(350, 130);
    glVertex2i(353, 140);
    glEnd();

    //8th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(390, 130);
    glVertex2i(395, 130);
    glVertex2i(385, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(390, 130);
    glVertex2i(395, 130);
    glVertex2i(389, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(390, 130);
    glVertex2i(395, 130);
    glVertex2i(393, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(395, 130);
    glVertex2i(400, 130);
    glVertex2i(397, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(395, 130);
    glVertex2i(400, 130);
    glVertex2i(403, 140);
    glEnd();

    //9th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(440, 130);
    glVertex2i(445, 130);
    glVertex2i(435, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(440, 130);
    glVertex2i(445, 130);
    glVertex2i(439, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(440, 130);
    glVertex2i(445, 130);
    glVertex2i(443, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 130);
    glVertex2i(450, 130);
    glVertex2i(447, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 130);
    glVertex2i(450, 130);
    glVertex2i(453, 140);
    glEnd();

    //10th crop

    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(490, 130);
    glVertex2i(495, 130);
    glVertex2i(485, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(490, 130);
    glVertex2i(495, 130);
    glVertex2i(489, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(490, 130);
    glVertex2i(495, 130);
    glVertex2i(493, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(495, 130);
    glVertex2i(500, 130);
    glVertex2i(497, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(495, 130);
    glVertex2i(500, 130);
    glVertex2i(503, 140);
    glEnd();

    //11th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(540, 130);
    glVertex2i(545, 130);
    glVertex2i(535, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(540, 130);
    glVertex2i(545, 130);
    glVertex2i(539, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(540, 130);
    glVertex2i(545, 130);
    glVertex2i(543, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(545, 130);
    glVertex2i(550, 130);
    glVertex2i(547, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(545, 130);
    glVertex2i(550, 130);
    glVertex2i(553, 140);
    glEnd();

    //12th crop
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(590, 130);
    glVertex2i(595, 130);
    glVertex2i(585, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(590, 130);
    glVertex2i(595, 130);
    glVertex2i(589, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(590, 130);
    glVertex2i(595, 130);
    glVertex2i(593, 140);
    glEnd();
    glColor3ub (0, 204, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(595, 130);
    glVertex2i(600, 130);
    glVertex2i(597, 140);
    glEnd();
    glColor3ub (0, 153, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(595, 130);
    glVertex2i(600, 130);
    glVertex2i(603, 140);
    glEnd();


    //border gate
     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(320, 95);
    glVertex2i(325, 95);
    glVertex2i(325, 130);
    glVertex2i(320, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(340, 95);
    glVertex2i(345, 95);
    glVertex2i(345, 130);
    glVertex2i(340, 130);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(360, 95);
    glVertex2i(365, 95);
    glVertex2i(365, 130);
    glVertex2i(360, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(380, 95);
    glVertex2i(385, 95);
    glVertex2i(385, 130);
    glVertex2i(380, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(400, 95);
    glVertex2i(405, 95);
    glVertex2i(405, 130);
    glVertex2i(400, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(420, 95);
    glVertex2i(425, 95);
    glVertex2i(425, 130);
    glVertex2i(420, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(440, 95);
    glVertex2i(445, 95);
    glVertex2i(445, 130);
    glVertex2i(440, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(460, 95);
    glVertex2i(465, 95);
    glVertex2i(465, 130);
    glVertex2i(460, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(480, 95);
    glVertex2i(485, 95);
    glVertex2i(485, 130);
    glVertex2i(480, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(500, 95);
    glVertex2i(505, 95);
    glVertex2i(505, 130);
    glVertex2i(500, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(520, 95);
    glVertex2i(525, 95);
    glVertex2i(525, 130);
    glVertex2i(520, 130);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(540, 95);
    glVertex2i(545, 95);
    glVertex2i(545, 130);
    glVertex2i(540, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(560, 95);
    glVertex2i(565, 95);
    glVertex2i(565, 130);
    glVertex2i(560, 130);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(580, 95);
    glVertex2i(585, 95);
    glVertex2i(585, 130);
    glVertex2i(580, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(600, 95);
    glVertex2i(605, 95);
    glVertex2i(605, 130);
    glVertex2i(600, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(620, 95);
    glVertex2i(625, 95);
    glVertex2i(625, 130);
    glVertex2i(620, 130);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(320, 120);
    glVertex2i(1240, 120);
    glVertex2i(1240, 125);
    glVertex2i(320, 125);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(320, 105);
    glVertex2i(1240, 105);
    glVertex2i(1240, 110);
    glVertex2i(320, 110);
    glEnd();

    //2nd Border gate

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(280, 180);
    glVertex2i(285, 180);
    glVertex2i(285, 215);
    glVertex2i(280, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(300, 180);
    glVertex2i(305, 180);
    glVertex2i(305, 215);
    glVertex2i(300, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(320, 180);
    glVertex2i(325, 180);
    glVertex2i(325, 215);
    glVertex2i(320, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(340, 180);
    glVertex2i(345, 180);
    glVertex2i(345, 215);
    glVertex2i(340, 215);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(360, 180);
    glVertex2i(365, 180);
    glVertex2i(365, 215);
    glVertex2i(360, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(380, 180);
    glVertex2i(385, 180);
    glVertex2i(385, 215);
    glVertex2i(380, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(400, 180);
    glVertex2i(405, 180);
    glVertex2i(405, 215);
    glVertex2i(400, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(420, 180);
    glVertex2i(425, 180);
    glVertex2i(425, 215);
    glVertex2i(420, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(440, 180);
    glVertex2i(445, 180);
    glVertex2i(445, 215);
    glVertex2i(440, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(460, 180);
    glVertex2i(465, 180);
    glVertex2i(465, 215);
    glVertex2i(460, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(480, 180);
    glVertex2i(485, 180);
    glVertex2i(485, 215);
    glVertex2i(480, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(500, 180);
    glVertex2i(505, 180);
    glVertex2i(505, 215);
    glVertex2i(500, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(520, 180);
    glVertex2i(525, 180);
    glVertex2i(525, 215);
    glVertex2i(520, 215);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(540, 180);
    glVertex2i(545, 180);
    glVertex2i(545, 215);
    glVertex2i(540, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(560, 180);
    glVertex2i(565, 180);
    glVertex2i(565, 215);
    glVertex2i(560, 215);
    glEnd();

     glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(580, 180);
    glVertex2i(585, 180);
    glVertex2i(585, 215);
    glVertex2i(580, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(600, 180);
    glVertex2i(605, 180);
    glVertex2i(605, 215);
    glVertex2i(600, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(620, 180);
    glVertex2i(625, 180);
    glVertex2i(625, 215);
    glVertex2i(620, 215);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(280, 185);
    glVertex2i(1240, 185);
    glVertex2i(1240, 190);
    glVertex2i(280, 190);
    glEnd();

    glColor3ub (204, 204, 0);
    glBegin(GL_QUADS);
    glVertex2i(280, 200);
    glVertex2i(1240, 200);
    glVertex2i(1240, 205);
    glVertex2i(280, 205);
    glEnd();

}



void river(){
//RIVER
     glColor3ub (0, 51, 153);
    glBegin(GL_QUADS);
    glVertex2i(00, 190);
    glVertex2i(1240, 190);
    glVertex2i(1240, 280);
    glVertex2i(00, 280);
    glEnd();
}
void grass(){
glColor3ub (0, 153, 51);
    glBegin(GL_QUADS);
    glVertex2i(00, 0);
    glVertex2i(1240, 0);
    glVertex2i(1240, 190);
    glVertex2i(00, 190);
    glEnd();
}
void tree(){
//2ND TREE
    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(70, 230);
    glVertex2i(160, 230);
    glVertex2i(110, 280);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(70, 230);
    glVertex2i(110, 280);
    glVertex2i(160, 230);
    glEnd();


    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(74, 255);
    glVertex2i(146, 255);
    glVertex2i(110, 300);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(74, 255);
    glVertex2i(110, 300);
    glVertex2i(146, 255);
    glEnd();


    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(81, 275);
    glVertex2i(140, 275);
    glVertex2i(110, 310);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(81, 275);
    glVertex2i(110, 310);
    glVertex2i(140, 275);
    glEnd();

    //TREE
     glColor3ub (115, 77, 38);
    glBegin(GL_QUADS);
    glVertex2i(32, 165);
    glVertex2i(48, 165);
    glVertex2i(48, 230);
    glVertex2i(32, 230);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(32, 165);
    glVertex2i(48, 165);
    glVertex2i(48, 230);
    glVertex2i(32, 230);
    glVertex2i(32, 165);
    glEnd();

    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(1, 230);
    glVertex2i(80, 230);
    glVertex2i(40, 280);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(1, 230);
    glVertex2i(80, 230);
    glVertex2i(40, 280);
    glVertex2i(1, 230);
    glEnd();

    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(5, 255);
    glVertex2i(76, 255);
    glVertex2i(40, 300);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(5, 255);
    glVertex2i(40, 300);
    glVertex2i(76, 255);
    glEnd();


    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(11, 275);
    glVertex2i(70, 275);
    glVertex2i(40, 320);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(11, 275);
    glVertex2i(40, 320);
    glVertex2i(70, 275);
    glEnd();

    glColor3ub (0, 102, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(15, 295);
    glVertex2i(65, 295);
    glVertex2i(40, 330);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(15, 295);
    glVertex2i(40, 330);
    glVertex2i(65, 295);
    glEnd();
}

void SmallJungle()
{
glColor3ub (0, 102, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 155);
    glVertex2i(58, 155);
    glVertex2i(58, 175);
    glVertex2i(45, 180);
    glVertex2i(40, 175);
    glVertex2i(35, 175);
    glVertex2i(25, 185);
    glVertex2i(20, 182);
    glVertex2i(15, 175);
    glVertex2i(10, 178);
    glVertex2i(6, 175);
    glVertex2i(0, 165);
    glEnd();
}

void Straw()
{
glColor3ub (230, 230, 0);
    glBegin(GL_POLYGON);
    glVertex2i(150, 160);
    glVertex2i(205, 160);
    glVertex2i(205, 205);
    glVertex2i(185, 229);
    glVertex2i(175, 232);
    glVertex2i(165, 229);
    glVertex2i(150, 210);
    glVertex2i(150, 180);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(150, 160);
    glVertex2i(205, 160);
    glVertex2i(205, 205);
    glVertex2i(185, 229);
    glVertex2i(175, 232);
    glVertex2i(165, 229);
    glVertex2i(150, 210);
    glVertex2i(150, 180);
    glVertex2i(150, 160);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(195, 175);
    glVertex2i(195, 205);
    glVertex2i(185, 215);
    glEnd();


}


void HouseRoad()
{
glColor3ub (204, 153, 0);
    glBegin(GL_QUADS);
    glVertex2i(0, 100);
    glVertex2i(320, 100);
    glVertex2i(302, 130);
    glVertex2i(0, 130);
    glEnd();
    glColor3ub (204, 153, 0);
    glBegin(GL_QUADS);
    glVertex2i(110, 155);
    glVertex2i(130, 130);
    glVertex2i(160, 130);
    glVertex2i(135, 155);
    glEnd();

}
void house(){
//////////////////////////////////////////////////////////////////////////////left house
//left triangle

    glColor3ub (181, 158, 90);
    glBegin(GL_TRIANGLES);
    glVertex2i(50, 200);
    glVertex2i(90, 200);
    glVertex2i(70, 250);
    glEnd();

    glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 200);
    glVertex2i(90, 200);
    glVertex2i(70, 250);
    glVertex2i(50, 200);

    //glVertex2i(50, 200);
    glEnd();
    //////////////line of chal
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(55, 200);
    glVertex2i(75, 250);
        //glVertex2i(70, 250);
    //glVertex2i(70, 200);

    glEnd();
    ///////////////////right  chal
    glColor3ub (219, 183, 72);
    glBegin(GL_QUADS);
    glVertex2i(90, 200);
    glVertex2i(170, 200);
    glVertex2i(150, 250);
    glVertex2i(70, 250);
    glEnd();
    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(90, 200);
    glVertex2i(170, 200);
    glVertex2i(150, 250);
    glVertex2i(70, 250);
    glVertex2i(90, 200);
    glEnd();

    //glFlush ();
    ////////////////// left body
    glColor3ub (153, 153, 153);
    glBegin(GL_QUADS);
    glVertex2i(55, 150);
    glVertex2i(90, 150);
    glVertex2i(90, 200);
    glVertex2i(55, 200);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(55, 150);
    glVertex2i(90, 150);
    glVertex2i(90, 200);
    glVertex2i(55, 200);
    glVertex2i(55, 150);
    glEnd();


    ///////////right body
    glColor3ub (180, 180, 180);
    glBegin(GL_QUADS);
    glVertex2i(90, 150);
    glVertex2i(165, 150);
    glVertex2i(165, 200);
    glVertex2i(90, 200);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(90, 150);
    glVertex2i(165, 150);
    glVertex2i(165, 200);
    glVertex2i(90, 200);
    glVertex2i(90, 150);
    glEnd();

    ///////////////////right body janala (left)
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(95, 160);
    glVertex2i(110, 160);
    glVertex2i(110, 187);
    glVertex2i(95, 187);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(95, 160);
    glVertex2i(110, 160);
    glVertex2i(110, 187);
    glVertex2i(95, 187);
    glVertex2i(95, 160);
    glEnd();

    /////////////////////right body janala (right)
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(145, 160);
    glVertex2i(160, 160);
    glVertex2i(160, 187);
    glVertex2i(145, 187);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(145, 160);
    glVertex2i(160, 160);
    glVertex2i(160, 187);
    glVertex2i(145, 187);
    glVertex2i(145, 160);
    glEnd();

    ////////////left body janala
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(65, 160);
    glVertex2i(80, 160);
    glVertex2i(80, 187);
    glVertex2i(65, 187);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(65, 160);
    glVertex2i(80, 160);
    glVertex2i(80, 187);
    glVertex2i(65, 187);
    glVertex2i(65, 160);
    glEnd();

    //glFlush ();
    ////right body door
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(120, 155);
    glVertex2i(135, 155);
    glVertex2i(135, 190);
    glVertex2i(120, 190);
    glEnd();

    glLineWidth(2);
    glColor3ub (0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(120, 155);
    glVertex2i(135, 155);
    glVertex2i(135, 190);
    glVertex2i(120, 190);
    glVertex2i(120, 155);
    glEnd();
}

void Human()
{
glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

     //Human
     glColor3ub (233, 203, 203);//Hands
    glBegin(GL_QUADS);
    glVertex2i(232, 148);
    glVertex2i(248, 148);
    glVertex2i(248, 164);
    glVertex2i(232, 164);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(232, 148);
    glVertex2i(248, 148);
    glVertex2i(248, 164);
    glVertex2i(232, 164);
    glVertex2i(232, 148);
    glEnd();

    glColor3ub (102, 102, 255);//Lungi
    glBegin(GL_QUADS);
    glVertex2i(232, 120);
    glVertex2i(250, 120);
    glVertex2i(245, 150);
    glVertex2i(235, 150);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(232, 120);
    glVertex2i(250, 120);
    glVertex2i(245, 150);
    glVertex2i(235, 150);
    glVertex2i(232, 120);
    glEnd();
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(236, 120);
    glVertex2i(242, 150);
    glEnd();



     glColor3ub (255, 255, 153);//Collars
    glBegin(GL_POLYGON);
    glVertex2i(232, 164);
    glVertex2i(248, 164);
    glVertex2i(245, 170);
    glVertex2i(235, 170);
    glEnd();
     glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(232, 164);
    glVertex2i(248, 164);
    glVertex2i(245, 170);
    glVertex2i(235, 170);
    glVertex2i(232, 164);
    glEnd();
    glColor3ub (255, 255, 153);//Body
    glBegin(GL_QUADS);
    glVertex2i(235, 150);
    glVertex2i(245, 150);
    glVertex2i(245, 170);
    glVertex2i(235, 170);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(235, 150);
    glVertex2i(245, 150);
    glVertex2i(245, 170);
    glVertex2i(235, 170);
    glVertex2i(235, 150);
    glEnd();

     glColor3ub (233, 203, 203);
    glBegin(GL_QUADS);
    glVertex2i(238, 170);
    glVertex2i(242, 170);
    glVertex2i(242, 172);
    glVertex2i(238, 172);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(238, 170);
    glVertex2i(242, 170);
    glVertex2i(242, 172);
    glVertex2i(238, 172);
    glVertex2i(238, 170);
    glEnd();
    glColor3ub (233, 203, 203);//Head
    glBegin(GL_POLYGON);
    glVertex2i(238, 172);
    glVertex2i(242, 172);
    glVertex2i(244, 176);
    glVertex2i(244, 182);
    glVertex2i(236, 182);
    glVertex2i(236, 176);
    glVertex2i(238, 172);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(238, 172);
    glVertex2i(242, 172);
    glVertex2i(244, 176);
    glVertex2i(244, 182);
    glVertex2i(236, 182);
    glVertex2i(236, 176);
    glVertex2i(238, 172);
    glVertex2i(238, 172);
    glEnd();
    glColor3ub (26, 0, 26);//Hair
    glBegin(GL_POLYGON);
    glVertex2i(236, 182);
    glVertex2i(244, 182);
    glVertex2i(243, 186);
    glVertex2i(237, 186);
    glEnd();
    glColor3ub (233, 203, 203);//Nose
    glBegin(GL_TRIANGLES);
    glVertex2i(234, 176);
    glVertex2i(236, 176);
    glVertex2i(236, 179);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(234, 176);
    glVertex2i(236, 176);
    glEnd();
    glColor3ub (233, 203, 203);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(236, 176);
    glVertex2i(236, 179);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(236, 179);
    glVertex2i(234, 176);
    glEnd();

    glColor3ub (0, 0, 0);//Shoes
    glBegin(GL_QUADS);
    glVertex2i(230, 117);
    glVertex2i(238, 117);
    glVertex2i(238, 120);
    glVertex2i(234, 120);
    glEnd();
    glColor3ub (0, 0, 0);//Shoes
    glBegin(GL_QUADS);
    glVertex2i(240, 117);
    glVertex2i(248, 117);
    glVertex2i(248, 120);
    glVertex2i(244, 120);
    glEnd();

glPopMatrix();
}

void Human2()
{
glPushMatrix();
    glTranslatef(positionR,0.0f, 0.0f);

     //2nd Human
     glColor3ub (233, 203, 203);//Hands
    glBegin(GL_QUADS);
    glVertex2i(202, 148);
    glVertex2i(218, 148);
    glVertex2i(218, 164);
    glVertex2i(202, 164);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(202, 148);
    glVertex2i(218, 148);
    glVertex2i(218, 164);
    glVertex2i(202, 164);
    glVertex2i(202, 148);
    glEnd();

    glColor3ub (102, 102, 255);//Lungi
    glBegin(GL_QUADS);
    glVertex2i(202, 120);
    glVertex2i(220, 120);
    glVertex2i(215, 150);
    glVertex2i(205, 150);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(202, 120);
    glVertex2i(220, 120);
    glVertex2i(215, 150);
    glVertex2i(205, 150);
    glVertex2i(202, 120);
    glEnd();
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(206, 120);
    glVertex2i(212, 150);
    glEnd();


     glColor3ub (255, 26, 26);//Collars
    glBegin(GL_POLYGON);
    glVertex2i(202, 164);
    glVertex2i(218, 164);
    glVertex2i(215, 170);
    glVertex2i(205, 170);
    glEnd();
     glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(202, 164);
    glVertex2i(218, 164);
    glVertex2i(215, 170);
    glVertex2i(205, 170);
    glVertex2i(202, 164);
    glEnd();
    glColor3ub (255, 26, 26);//Body
    glBegin(GL_QUADS);
    glVertex2i(205, 150);
    glVertex2i(215, 150);
    glVertex2i(215, 170);
    glVertex2i(205, 170);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(205, 150);
    glVertex2i(215, 150);
    glVertex2i(215, 170);
    glVertex2i(205, 170);
    glVertex2i(205, 150);
    glEnd();

     glColor3ub (255, 26, 26);
    glBegin(GL_QUADS);
    glVertex2i(208, 170);
    glVertex2i(212, 170);
    glVertex2i(212, 172);
    glVertex2i(208, 172);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(208, 170);
    glVertex2i(212, 170);
    glVertex2i(212, 172);
    glVertex2i(208, 172);
    glVertex2i(208, 170);
    glEnd();
    glColor3ub (233, 203, 203);//Head
    glBegin(GL_POLYGON);
    glVertex2i(208, 172);
    glVertex2i(212, 172);
    glVertex2i(214, 176);
    glVertex2i(214, 182);
    glVertex2i(206, 182);
    glVertex2i(206, 176);
    glVertex2i(208, 172);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(208, 172);
    glVertex2i(212, 172);
    glVertex2i(214, 176);
    glVertex2i(214, 182);
    glVertex2i(206, 182);
    glVertex2i(206, 176);
    glVertex2i(208, 172);
    glVertex2i(208, 172);
    glEnd();
    glColor3ub (26, 0, 26);//Hair
    glBegin(GL_POLYGON);
    glVertex2i(206, 182);
    glVertex2i(214, 182);
    glVertex2i(213, 186);
    glVertex2i(207, 186);
    glEnd();
    glColor3ub (233, 203, 203);//Nose
    glBegin(GL_TRIANGLES);
    glVertex2i(204, 176);
    glVertex2i(206, 176);
    glVertex2i(206, 179);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(204, 176);
    glVertex2i(206, 176);
    glEnd();
    glColor3ub (233, 203, 203);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(206, 176);
    glVertex2i(206, 179);
    glEnd();
    glColor3ub (0, 0, 0);
    glLineWidth(1);
    glBegin(GL_LINE_STRIP);
    glVertex2i(206, 179);
    glVertex2i(204, 176);
    glEnd();

    glColor3ub (0, 0, 0);//Shoes
    glBegin(GL_QUADS);
    glVertex2i(200, 117);
    glVertex2i(208, 117);
    glVertex2i(208, 120);
    glVertex2i(204, 120);
    glEnd();
    glColor3ub (0, 0, 0);//Shoes
    glBegin(GL_QUADS);
    glVertex2i(210, 117);
    glVertex2i(218, 117);
    glVertex2i(218, 120);
    glVertex2i(214, 120);
    glEnd();

glPopMatrix();
}



void sun(){
///sun
    glPushMatrix();
    glTranslatef(145, 380, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///end of sun
}
void cloud(){
///Cloud

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(100, 400, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(90, 375, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(125, 400, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(115, 375, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

//cloud 2
    glPushMatrix();
    glTranslatef(125, 50, 0);
    glPushMatrix();
    glTranslatef(100, 400, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(90, 375, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(125, 400, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(115, 375, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(115, 400, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(145, 380, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<100;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
//end of cloud
glFlush();
}

void Cart()
{
     ///////////////////////////////////////////road
    glColor3ub (87, 81, 92);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 50);
    glVertex2i(0, 50);
    glEnd();

        glColor3ub (0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 50);
    glVertex2i(0, 50);
    glVertex2i(0, 0);

    glEnd();
    glFlush();
    //////////////////////////////////////roads i-land
    glColor3ub (153, 153, 102);
    glBegin(GL_QUADS);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 60);
    glVertex2i(0, 60);
    glEnd();
    /////////////////////////////////road er majher daag
    glColor3ub (252, 252, 252);
    //glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(0, 25);
    glVertex2i(40, 25);
    glVertex2i(50, 25);
    glVertex2i(90, 25);
    glVertex2i(100, 25);
    glVertex2i(140, 25);
    glVertex2i(150, 25);
    glVertex2i(190, 25);
    glVertex2i(200, 25);
    glVertex2i(240, 25);
    glVertex2i(250, 25);
    glVertex2i(290, 25);
    glVertex2i(300, 25);
    glVertex2i(340, 25);
    glVertex2i(350, 25);
    glVertex2i(390, 25);
    glVertex2i(400, 25);
    glVertex2i(440, 25);
    glVertex2i(450, 25);
    glVertex2i(490, 25);
    glVertex2i(500, 25);
    glVertex2i(540, 25);
    glVertex2i(550, 25);
    glVertex2i(590, 25);
    glVertex2i(600, 25);
    glVertex2i(640, 25);
    glEnd();

glPopMatrix();

 glPushMatrix();

 //CART
glTranslatef(positionC,0.0f, 0.0f);
    glColor3ub (225, 245, 93);
    glBegin(GL_QUADS);
    glVertex2i(50, 50);
    glVertex2i(120, 50);
    glVertex2i(120, 100);
    glVertex2i(50, 100);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 50);
    glVertex2i(120, 50);
    glVertex2i(120, 100);
    glVertex2i(50, 100);
    glVertex2i(50, 50);

    glColor3ub (225,0,225);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 66.66);
    glVertex2i(120, 66.66);
    glEnd();

    glColor3ub (225,0,225);
    glBegin(GL_LINE_STRIP);
    glVertex2i(67.5, 50);
    glVertex2i(67.5, 100);
    glEnd();

    glColor3ub (225,0,225);
    glBegin(GL_LINE_STRIP);
    glVertex2i(85, 50);
    glVertex2i(85, 100);
    glEnd();

    glColor3ub (225,0,225);
    glBegin(GL_LINE_STRIP);
    glVertex2i(102.5, 50);
    glVertex2i(102.5, 100);

    glEnd();


    glColor3ub (225,0,225);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 83.32);
    glVertex2i(120, 83.32);
    glEnd();



//LINES
    glColor3ub (0,0,225);
    glBegin(GL_QUAD_STRIP);
    glVertex2i(50, 50);
    glVertex2i(180, 50);
    glVertex2i(50, 45);
    glVertex2i(180, 45);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 50);
    glVertex2i(180, 50);
    glVertex2i(180, 45);
    glVertex2i(50, 45);
    glVertex2i(50, 50);
    glEnd();


 //cow



    glColor3ub (0,0,0);//COW HORN
    glBegin(GL_LINE_STRIP);
    glVertex2i(176, 50);
    glVertex2i(171, 60);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(178, 50);
    glVertex2i(183, 60);
    glEnd();


    glColor3ub (153,76,0);//COW HORN
    glBegin(GL_LINE_STRIP);
    glVertex2i(177, 50);
    glVertex2i(172, 60);
    glEnd();

    glColor3ub (153,76,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(179, 50);
    glVertex2i(184, 60);
    glEnd();


      glColor3ub (153,76,0);
    glBegin(GL_POLYGON);
    glVertex2i(180, 50);
    glVertex2i(190, 35);
    glVertex2i(187, 33);
    glVertex2i(177, 35);
    glVertex2i(172, 20);
    glVertex2i(172, 15);
    glVertex2i(168, 15);
    glVertex2i(168, 28);
    glVertex2i(168, 20);
    glVertex2i(135, 20);
    glVertex2i(135, 28);
    glVertex2i(131, 15);
    glVertex2i(131, 45);
    glVertex2i(135, 50);

    glEnd();

//kadh
    glColor3ub (153,76,0);
    glBegin(GL_POLYGON);
    glVertex2i(165, 50);
    glVertex2i(170, 54);
    glVertex2i(173, 54);
    glVertex2i(173, 50);
    glVertex2i(180, 50);

    glEnd();


    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(135, 50);
    glVertex2i(165, 50);
    glVertex2i(170, 54);
    glVertex2i(173, 54);
    glVertex2i(173, 50);
    glVertex2i(180, 50);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(180, 50);
    glVertex2i(190, 35);
    glVertex2i(187, 33);
    glVertex2i(177, 35);
    glVertex2i(172, 20);
    glVertex2i(172, 15);
    glVertex2i(168, 15);
    glVertex2i(168, 28);
    glVertex2i(168, 20);
    glVertex2i(135, 20);
    glVertex2i(135, 28);
    glVertex2i(135, 15);
    glVertex2i(131, 15);
    glVertex2i(131, 45);
    glVertex2i(135, 50);

    glEnd();

    //man IN CART
    glColor3ub (0,0,0);//HAIR
    glBegin(GL_QUADS);
    glVertex2i(125, 80);
    glVertex2i(137, 80);
    glVertex2i(137, 76);
    glVertex2i(125, 76);
    glEnd();

    //HEAD
    glColor3ub (255,201,105);
    glBegin(GL_POLYGON);
    glVertex2i(137, 76);
    glVertex2i(137, 72);
    glVertex2i(140, 70);
    glVertex2i(136, 68);
    glVertex2i(135, 64);
    glVertex2i(128, 64);
    glVertex2i(125, 67);
    glVertex2i(125, 76);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
   glVertex2i(137, 76);
    glVertex2i(137, 72);
    glVertex2i(140, 70);
    glVertex2i(136, 68);
    glVertex2i(135, 64);
    glVertex2i(128, 64);
    glVertex2i(125, 67);
    glVertex2i(125, 76);
    glVertex2i(137, 76);
    glEnd();

    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(135, 64);
    glVertex2i(135, 61);
    glVertex2i(128, 61);
    glVertex2i(128, 64);
    glEnd();

    glColor3ub (0,255,0);
    glBegin(GL_POLYGON);
    glVertex2i(135, 64);
    glVertex2i(135, 61);
    glVertex2i(128, 61);
    glVertex2i(128, 64);

    glEnd();

//BODY
    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(125, 61);
    glVertex2i(138, 61);
    glVertex2i(138, 50);
    glVertex2i(125, 50);
    glVertex2i(125, 61);
    glEnd();

    glColor3ub (229,106,118);
    glBegin(GL_POLYGON);
    glVertex2i(125, 61);
    glVertex2i(138, 61);
    glVertex2i(138, 50);
    glVertex2i(125, 50);
    glVertex2i(125, 61);

    glEnd();

    //HANDS
    glColor3ub (0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(138, 57);
    glVertex2i(145, 50);
    glVertex2i(138, 55);

    glEnd();


    glTranslatef(43, 15, 0.0);
    glTranslatef(43, 15, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(156, 143, 6);
	for(int i=0;i<500;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/500;
		float r=18;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
	for(int i=0;i<500;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/500;
		float r=18;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}

    	glEnd();

    	glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
	for(int i=0;i<500;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/500;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();



	glPopMatrix();





}

void update(int value) {

	_run3 += 0.8f;
	if (_run3 > 640)
    {
        _run3 -= 950;
    }


	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}
void Night(int value){

if(night){
    glClearColor(0.0,0.0,0.0,0.0);
    glutTimerFunc(5, Night, 0);
    glFlush();
	glutPostRedisplay();
}
}
void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}

void startscreen(void)
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.000, 0.000, 0.000,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    drawstring(100.0,350.0,0.0,"AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH");
    glColor3f(0,0,1);
    drawstring(100,325,0.0,"FACULTY OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(0.7,0.7,0.7);
    drawstring(225,265,0.0,"PROJECT ON");
    drawstring(125,250,0.0,"COMPUTER GRAPHICS: VILLAGE VIEW");
    glColor3f(1,0.5,0);
    drawstring(50,200,0.0,"SUBMITTED BY:");
    glColor3f(1,1,1);
    drawstring(50,185,0.0,"ZUBAIR AHMED                         (19-39745-1)");
    drawstring(50,145,0.0,"MARUFUL AHMED SAKIL        (19-40038-1)");
    drawstring(50,105,0.0,"LAMEYA RAHMAN                    (19-39795-1)");
    drawstring(50,65,0.0,"MD. ASIF REZA SHAWON         (17-34335-1)");
    glColor3f(1,1,1);
    drawstring(350,185,0.0,"RITU BASAK    (19-40179-1)");
    glColor3f(0,1,0);
    drawstring(200,40,0.0,"PRESS ENTER TO START");
    glFlush();
}
void controlsScreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.000, 0.000, 0.000,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.596, 0.984, 0.596);
    drawstring(185.0,350.0,0.0,"INSTRUCTIONS");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(125.0,320.0,0.0,"DAY MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(300.0,320.0,0.0,"PRESS 'B'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(125.0,320.0,0.0,"DAY MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(300.0,320.0,0.0,"PRESS 'B'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(125.0,300.0,0.0,"NIGHT MODE");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(300.0,300.0,0.0,"PRESS 'N'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(125.0,280.0,0.0,"RAIN");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(300.0,280.0,0.0,"PRESS 'R'");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(125.0,260.0,0.0,"NO RAIN");
    glColor3f(1.000, 0.980, 0.941);
    drawstring(300.0,260.0,0.0,"PRESS 'E'");
    drawstring(180.0,100.0,0.0,"NOW PRESS ENTER");
    glFlush();
}
void display()
{
    river();
    Boat();
    Boat2();
    //grass();
    Grass();
    tree();
    SmallJungle();
    HouseRoad();
    Straw();
    house();
    sun();
    cloud();
    //Grass();
    Farm();
    Human();
    Human2();
    Cart();



}
//Main Display Function
void myDisplay()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(flag==0){

        startscreen();

    }
    if(flag==1)
        controlsScreen();
        //controlsScreen();
    if(flag>1)
        display();

    glFlush();
    glutSwapBuffers();
}
void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{


case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed -= 0.4f;
    glutPostRedisplay();
    break;
case 'q':
    speedR -= 0.4f;
    glutPostRedisplay();
    break;
case 'e':
    speedR = 0.0f;
    break;
case 'c':
    speedB += 0.8f;
    glutPostRedisplay();
    break;
case 'v':
    speedB = 0.0f;
    break;
case 'y':   //c FOR CONTINUE MOVING CART
    speedC += 0.4f;
    glutPostRedisplay();
    break;
case 'u':   //u FOR STOP MOVING CART
    speedC = 0.0f;
    break;
case 'r':
        rainday = true;
        Rain(_rain);
        sndPlaySound("Rain.wav",SND_ASYNC|SND_LOOP);
        sndPlaySound("Rain.wav",SND_MEMORY|SND_ASYNC);
        break;

case 't':
        rainday = false;
		sndPlaySound(NULL,SND_ASYNC);
        break;

case 'n':
        night = true;
        sndPlaySound("Night.wav",SND_ASYNC|SND_LOOP);
        sndPlaySound("Night.wav",SND_MEMORY|SND_ASYNC);
        Night(_nt);
        break;

case 'b':
        night = false;
        sndPlaySound(NULL,SND_ASYNC);
        glClearColor(0.0,0.5,1.0,1.0);
        break;

case 'x':     // ESC key
        exit(0);
        break;

	default:
	break;
	}
	if(key==13)
{
    flag++;
    myDisplay();
}
    else if(key=='h')
{
    flag=1;
    myDisplay();
}

/*case 'd':
    position += 0.2;
    glutPostRedisplay();
    if(position > 1.5)
        position = -1.2f;
    glutPostRedisplay();

    break;

glutPostRedisplay();
*/

}

int main(int argc,char **argv)
{
    cout<<"rain start = r"<<endl;
    cout<<"rain stop = e"<<endl;
    cout<<"night = n"<<endl;
    cout<<"day = b"<<endl;
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Natural View Of A Village");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
        glutTimerFunc(1000, WhiteMan, 0);
        glutTimerFunc(1000, RedMan, 0);
        glutTimerFunc(1000, BoatMove, 0);
        glutTimerFunc(100, CART, 0);

	glutTimerFunc(25, update, 0);
	myInit();
	glutMainLoop();
	return 0;
}
