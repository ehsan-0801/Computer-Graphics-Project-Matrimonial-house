#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<windows.h>
#include<Windows.h>

#include <iostream>

using namespace std;

float cloud_X=0;
float cloud_Y=0;
float cloud_X2=0;
float cloud_Y2=0;
int cloudStatus=1;

float birds_X=0;
float birds_Y=0;

float bulb_X=0;
float bulb_Y=0;
float bulb_X2=0;
float bulb_Y2=0;
float bulb_X3=0;
float bulb_Y3=0;
float bulb_X4=0;
float bulb_Y4=0;
float bulb_X5=0;
float bulb_Y5=0;
float bulb_X6=0;
float bulb_Y6=0;
float bulb_X7=0;
float bulb_Y7=0;
float bulb_X8=0;
float bulb_Y8=0;
float bulb_X9=0;
float bulb_Y9=0;
float bulb_X10=0;
float bulb_Y10=0;
float bulb_X11=0;
float bulb_Y11=0;
float bulb_X12=0;
float bulb_Y12=0;
float bulb_X13=0;
float bulb_Y13=0;
int bulbStatus=1;

float amb_X=0;
float amb_Y=0;

float Car_X=0;
float Car_Y=0;

int tforward=1;
float train_X=0;
float train_Y=0;
int trainstatus=0;
float train_Speed=1.0;

int nightstatus=1;
float _rain = 0.0;
bool rainday = false;
int GarageStatus=1;
char text[] = "MATRIMONIAL HOUSE";
char text1[] = "GARAGE";
char text2[] = "Mr. A & Mrs. A WEDDING";
void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3ub(255,69,0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }
}

void Sprint1( float xy, float yx, char *str)
{
    int m,n;


    m=strlen( str ); // see how many characters are in text string.
    glColor3ub(0,0,0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( xy, yx); // location to start printing text
    for( n=0; n < m; n++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[n]);

    }
}

void Sprint2( float xy, float yx, char *str)
{
    int m,n;


    m=strlen( str ); // see how many characters are in text string.
    glColor3ub(255,255,255);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( xy, yx); // location to start printing text
    for( n=0; n < m; n++) // loop until i is greater then l
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[n]);

    }
}

void DrawCircle(float cx, float cy, float r, int num_segment)
{
    glBegin(GL_POLYGON);
    for(int ii=0; ii<num_segment; ii++)
    {
        float theta=2.0f*3.1415926f*float(ii)/float(num_segment);
        float x=r*cosf(theta);
        float y=r*sinf(theta);

        glVertex2f(x+cx, y+cy);
    }
    glEnd();
}

void drawCloud()
{
    glPushMatrix();

    glColor3f(0.8,0.8,0.8);
    DrawCircle(200, 690, 25, 1000);  //1st cloud
    DrawCircle(230, 700, 25, 1000);
    DrawCircle(180, 700, 25, 1000);
    DrawCircle(210, 720, 25, 1000);
    DrawCircle(600, 590, 25, 1000);
    DrawCircle(630, 600, 25, 1000);
    DrawCircle(580, 600, 25, 1000);
    DrawCircle(610, 620, 25, 1000);

    glPopMatrix();
}

void cloud()
{
    if(cloudStatus==1)
    {
        cloud_X+=0.5;
    }
    if(cloud_X>1400)
    {
        cloud_X=-600;
    }
    glPushMatrix();
    glTranslatef(cloud_X,cloud_Y+40,0.0);
    drawCloud();
    glPopMatrix();
}

void cloud2()
{
    if(cloudStatus==1)
    {
        cloud_X2+=0.3;
    }
    if(cloud_X2>800)
    {
        cloud_X2=-1400;
    }
    glPushMatrix();
    glTranslatef(cloud_X2+500, cloud_Y2+50, 0.0);
    drawCloud();
    glPopMatrix();
}


void Rain(int value)
{

    if(rainday)
    {

        _rain += 0.01f;

        glBegin(GL_POINTS);
        for(int i=1; i<=1000; i++)
        {
            int x=rand();
            int y=rand();
            x%=1400;
            y%=800;
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
void GarageFunc()
{
    if(GarageStatus==1)
    {
        glColor3ub(0,0,0);//Garage
        glLineWidth(3.0);
        glBegin(GL_QUADS);

        glVertex2i(675,150);
        glVertex2i(850,150);
        glVertex2i(850,270);
        glVertex2i(675,270);
        glEnd();

        glColor3ub(255, 255, 255);//Garage
        glLineWidth(3.0);
        glBegin(GL_QUADS);

        glVertex2i(679,150);
        glVertex2i(847,150);
        glVertex2i(847,267);
        glVertex2i(679,267);
        glEnd();

        glPushMatrix();    // Garage string
        glTranslatef(695,205, 0);
        Sprint1(15.0,0,text1);
        glPopMatrix();

        glColor3ub(0,128,128);//Garage
        glLineWidth(3.0);
        glBegin(GL_LINES);

        glVertex2i(679,155);
        glVertex2i(847,155);

        glVertex2i(679,165);
        glVertex2i(847,165);

        glVertex2i(679,175);
        glVertex2i(847,175);

        glVertex2i(679,185);
        glVertex2i(847,185);

        glVertex2i(679,195);
        glVertex2i(847,195);

        glVertex2i(679,205);
        glVertex2i(847,205);

        glVertex2i(679,215);
        glVertex2i(847,215);

        glVertex2i(679,225);
        glVertex2i(847,225);

        glVertex2i(679,235);
        glVertex2i(847,235);

        glVertex2i(679,245);
        glVertex2i(847,245);

        glVertex2i(679,255);
        glVertex2i(847,255);

        glVertex2i(679,265);
        glVertex2i(847,265);



        glEnd();
    }
    else
    {
        glColor3ub(0,0,0);//Garage
        glPointSize(5.0);
        glBegin(GL_QUADS);

        glVertex2i(675,150);
        glVertex2i(850,150);
        glVertex2i(850,270);
        glVertex2i(675,270);
        glEnd();

        glColor3ub(255, 255, 255);//Garage
        glPointSize(5.0);
        glBegin(GL_QUADS);

        glVertex2i(679,150);
        glVertex2i(847,150);
        glVertex2i(847,267);
        glVertex2i(679,267);
        glEnd();

        glColor3ub(40, 55, 71);//Garage Car
        glPointSize(3.0);
        glBegin(GL_QUADS);

        glVertex2i(713,165);
        glVertex2i(813,165);
        glVertex2i(813,195);
        glVertex2i(713,195);
        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_LINE_STRIP);

        glVertex2i(713,165);
        glVertex2i(813,165);
        glVertex2i(813,195);
        glVertex2i(713,195);
        glVertex2i(713,165);
        glEnd();

        glColor3ub(170, 183, 184);//Garage Car
        glPointSize(3.0);
        glBegin(GL_QUADS);

        glVertex2i(743,170);
        glVertex2i(783,170);
        glVertex2i(783,190);
        glVertex2i(743,190);
        glEnd();
        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_LINE_STRIP);

        glVertex2i(743,170);
        glVertex2i(783,170);
        glVertex2i(783,190);
        glVertex2i(743,190);
        glVertex2i(743,170);
        glEnd();

        glColor3ub(40, 55, 71);//Garage Car
        glPointSize(3.0);
        glBegin(GL_QUADS);
        glVertex2i(813,195);
        glVertex2i(803,205);
        glVertex2i(723,205);
        glVertex2i(713,195);

        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(813,195);
        glVertex2i(803,205);
        glVertex2i(723,205);
        glVertex2i(713,195);
        glVertex2i(813,195);
        glEnd();

        glColor3ub(40, 55, 71);//Garage Car
        glPointSize(3.0);
        glBegin(GL_POLYGON);
        glVertex2i(803,205);
        glVertex2i(801,233);
        glVertex2i(799,235);
        glVertex2i(727,235);
        glVertex2i(725,233);
        glVertex2i(723,205);
        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(803,205);
        glVertex2i(801,233);
        glVertex2i(799,235);
        glVertex2i(727,235);
        glVertex2i(725,233);
        glVertex2i(723,205);
        glVertex2i(803,205);
        glEnd();

        glColor3ub(242, 243, 244);//Garage Car
        glPointSize(3.0);
        glBegin(GL_POLYGON);
        glVertex2i(798,205);
        glVertex2i(796,228);
        glVertex2i(794,230);
        glVertex2i(732,230);
        glVertex2i(730,228);
        glVertex2i(728,205);
        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_LINE_STRIP);
        glVertex2i(798,205);
        glVertex2i(796,228);
        glVertex2i(794,230);
        glVertex2i(732,230);
        glVertex2i(730,228);
        glVertex2i(728,205);
        glVertex2i(798,205);
        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_QUADS);

        glVertex2i(713,165);
        glVertex2i(728,165);
        glVertex2i(728,150);
        glVertex2i(713,150);
        glEnd();

        glColor3ub(0,0,0);//Garage Car
        glPointSize(3.0);
        glBegin(GL_QUADS);

        glVertex2i(813,165);
        glVertex2i(798,165);
        glVertex2i(798,150);
        glVertex2i(813,150);
        glEnd();
        glColor3ub(231, 76, 60);//Garage Car
        glPointSize(3.0);
        DrawCircle(800,170,5,1000);


        glColor3ub(231, 76, 60);//Garage Car
        glPointSize(3.0);
        DrawCircle(790,170,5,1000);

        glColor3ub(0,0,0);//Garage Car  glass
        glPointSize(3.0);
        glBegin(GL_QUADS);
        glVertex2i(803,205);
        glVertex2i(803,220);
        glVertex2i(815,220);
        glVertex2i(812,205);

        glEnd();
        glColor3ub(244, 246, 247);//Garage Car glass
        glPointSize(3.0);
        glBegin(GL_QUADS);
        glVertex2i(805,207);
        glVertex2i(805,218);
        glVertex2i(813,218);
        glVertex2i(810,207);

        glEnd();

        glColor3ub(0,0,0);//Garage Car glass
        glPointSize(3.0);
        glBegin(GL_QUADS);
        glVertex2i(723,205);
        glVertex2i(723,220);
        glVertex2i(711,220);
        glVertex2i(714,205);

        glEnd();
        glColor3ub(244, 246, 247);//Garage Car glass
        glPointSize(3.0);
        glBegin(GL_QUADS);
        glVertex2i(721,207);
        glVertex2i(721,218);
        glVertex2i(713,218);
        glVertex2i(716,205);

        glEnd();
    }
}

void nightMode()
{
    if(nightstatus==0)
    {

        glColor3ub (0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(1400, 0);
        glVertex2i(1400,800);
        glVertex2i(0,800);
        glVertex2i(0,0);
        glEnd();

        glColor3ub(247, 247, 247);
        DrawCircle(200, 690, 45, 1000);
        glColor3f(0,0,0 );
        DrawCircle(230, 690, 45, 1000);

        glColor3ub(247, 247, 247);
        glPointSize(2.0);
        glBegin(GL_POINTS);
        glVertex2i(230, 600);
        glVertex2i(235, 607);
        glVertex2i(280, 617);
        glVertex2i(278, 621);
        glVertex2i(269, 527);
        glVertex2i(366, 624);
        glVertex2i(219, 513);
        glVertex2i(411, 632);
        glVertex2i(422, 438);
        glVertex2i(351, 535);
        glVertex2i(256, 541);
        glVertex2i(359, 445);
        glVertex2i(249, 650);
        glVertex2i(343, 441);
        glVertex2i(239, 658);
        glVertex2i(433, 560);
        glVertex2i(200, 690);
        glVertex2i(401, 468);
        glVertex2i(205, 671);
        glVertex2i(409, 775);
        glVertex2i(310, 678);
        glVertex2i(217, 781);
        glVertex2i(214, 685);
        glVertex2i(321, 688);
        glVertex2i(213, 599);
        glVertex2i(327, 694);
        glVertex2i(329, 491);
        glVertex2i(437, 692);
        glVertex2i(233, 597);
        glVertex2i(442, 589);
        glVertex2i(541, 685);
        glVertex2i(447, 481);
        glVertex2i(347, 575);
        glVertex2i(152, 470);
        glVertex2i(355, 567);
        glVertex2i(260, 459);
        glVertex2i(360, 754);
        glVertex2i(275, 642);
        glVertex2i(370, 548);
        glVertex2i(480, 439);
        glVertex2i(185, 625);
        glVertex2i(490, 520);
        glVertex2i(590, 410);
        glVertex2i(210, 553);
        glVertex2i(85, 625);
        glVertex2i(90, 520);
        glVertex2i(190, 410);
        glVertex2i(210, 553);
        glVertex2i(185, 625);
        glVertex2i(290, 520);
        glVertex2i(75, 410);
        glVertex2i(210, 553);
        glVertex2i(185, 625);
        glVertex2i(320, 520);
        glVertex2i(190, 410);
        glVertex2i(210, 553);
        glVertex2i(185, 625);
        glVertex2i(490, 520);
        glVertex2i(590, 410);
        glVertex2i(210, 553);
        glVertex2i(185, 525);
        glVertex2i(390, 620);
        glVertex2i(240, 410);
        glVertex2i(210, 543);
        glVertex2i(385, 729);
        glVertex2i(390, 720);
        glVertex2i(440, 610);
        glVertex2i(510, 543);
        glVertex2i(85, 729);
        glVertex2i(40, 420);
        glVertex2i(50, 410);
        glVertex2i(10, 543);
        glVertex2i(385, 729);
        glVertex2i(350, 520);
        glVertex2i(340, 410);
        glVertex2i(320, 543);
        glVertex2i(15, 529);
        glVertex2i(40, 632);
        glVertex2i(50, 690);
        glVertex2i(19, 543);
        glVertex2i(35, 629);
        glVertex2i(70, 632);
        glVertex2i(115, 490);
        glVertex2i(150, 400);
        glVertex2i(215, 729);
        glVertex2i(40, 632);
        glVertex2i(50, 690);
        glVertex2i(19, 543);
        glVertex2i(440, 729);
        glVertex2i(410, 532);
        glVertex2i(420, 690);
        glVertex2i(480, 443);
        glVertex2i(240, 429);
        glVertex2i(210, 532);
        glVertex2i(220, 490);
        glVertex2i(280, 443);
        glVertex2i(140, 629);
        glVertex2i(160, 632);
        glVertex2i(180, 590);
        glVertex2i(200, 643);
        glVertex2i(140, 529);
        glVertex2i(160, 532);
        glVertex2i(180, 500);
        glVertex2i(200, 510);
        glVertex2i(185, 569);
        glVertex2i(160, 582);
        glVertex2i(190, 590);
        glVertex2i(200, 570);
        glVertex2i(115, 569);
        glVertex2i(100, 582);
        glVertex2i(105, 590);
        glVertex2i(127, 570);
        glVertex2i(85, 669);
        glVertex2i(100, 682);
        glVertex2i(65, 690);
        glVertex2i(47, 670);
        glVertex2i(85, 769);
        glVertex2i(90, 782);
        glVertex2i(55, 790);
        glVertex2i(47, 770);
        glVertex2i(385, 669);
        glVertex2i(390, 682);
        glVertex2i(355, 690);
        glVertex2i(347, 570);
        glVertex2i(410, 769);
        glVertex2i(425, 700);
        glVertex2i(417, 710);
        glVertex2i(447, 720);
        glVertex2i(385, 712);
        glVertex2i(390, 732);
        glVertex2i(355, 707);
        glVertex2i(347, 742);
        glVertex2i(285, 669);
        glVertex2i(290, 682);
        glVertex2i(310, 690);
        glVertex2i(320, 570);
        glVertex2i(320, 769);
        glVertex2i(350, 782);
        glVertex2i(325, 790);
        glVertex2i(311, 770);
        glVertex2i(690, 669);
        glVertex2i(680, 682);
        glVertex2i(585, 690);
        glVertex2i(671, 770);
        glVertex2i(620, 669);
        glVertex2i(650, 682);
        glVertex2i(699, 790);
        glVertex2i(691, 770);
        glVertex2i(627, 669);
        glVertex2i(688, 582);
        glVertex2i(699, 690);
        glVertex2i(693, 470);
        glVertex2i(620, 669);
        glVertex2i(650, 682);
        glVertex2i(625, 690);
        glVertex2i(611, 670);
        glVertex2i(610, 759);
        glVertex2i(613, 742);
        glVertex2i(621, 720);
        glVertex2i(624, 623);
        glVertex2i(590, 669);
        glVertex2i(550, 782);
        glVertex2i(585, 690);
        glVertex2i(581, 770);
        glVertex2i(520, 669);
        glVertex2i(525, 642);
        glVertex2i(524, 621);
        glVertex2i(547, 699);
        glVertex2i(510, 645);
        glVertex2i(500, 788);
        glVertex2i(502, 710);
        glVertex2i(507, 725);
        glVertex2i(145, 769);
        glVertex2i(148, 682);
        glVertex2i(155, 690);
        glVertex2i(161, 670);
        glVertex2i(25, 769);
        glVertex2i(38, 782);
        glVertex2i(15, 790);
        glVertex2i(11, 670);
        glVertex2i(265, 709);
        glVertex2i(268, 702);
        glVertex2i(275, 720);
        glVertex2i(261, 716);
        glVertex2i(165, 709);
        glVertex2i(168, 702);
        glVertex2i(175, 720);
        glVertex2i(161, 716);
        glVertex2i(110, 769);
        glVertex2i(120, 732);
        glVertex2i(133, 740);
        glVertex2i(101, 786);
        glVertex2i(550, 609);
        glVertex2i(560, 602);
        glVertex2i(563, 604);
        glVertex2i(581, 599);
        glVertex2i(130, 759);
        glVertex2i(140, 732);
        glVertex2i(113, 740);
        glVertex2i(121, 716);
        glVertex2i(690, 769);
        glVertex2i(680, 742);
        glVertex2i(683, 770);
        glVertex2i(688, 786);
        glVertex2i(290, 769);
        glVertex2i(293, 742);
        glVertex2i(296, 770);
        glVertex2i(299, 786);
        glVertex2i(350, 769);
        glVertex2i(352, 742);
        glVertex2i(356, 770);
        glVertex2i(360, 786);
        glVertex2i(310, 769);
        glVertex2i(305, 742);
        glVertex2i(300, 770);
        glVertex2i(302, 786);
        glVertex2i(240, 759);
        glVertex2i(242, 732);
        glVertex2i(243, 740);
        glVertex2i(248, 706);

        glVertex2i(767, 807);
        glVertex2i(880, 999);
        glVertex2i(914, 510);
        glVertex2i(1115, 478);
        glVertex2i(818, 615);
        glVertex2i(920, 867);
        glVertex2i(824, 520);
        glVertex2i(1028, 723);
        glVertex2i(930, 925);
        glVertex2i(832, 827);
        glVertex2i(735, 730);
        glVertex2i(938, 933);

        glVertex2i(740, 1037);
        glVertex2i(743, 539);
        glVertex2i(744, 940);
        glVertex2i(746, 442);
        glVertex2i(748, 445);
        glVertex2i(750, 447);
        glVertex2i(754, 450);
        glVertex2i(758, 453);
        glVertex2i(760, 455);
        glVertex2i(762, 457);
        glVertex2i(765, 460);
        glVertex2i(768, 463);

        glVertex2i(770, 467);
        glVertex2i(773, 469);
        glVertex2i(775, 470);
        glVertex2i(777, 472);
        glVertex2i(778, 475);
        glVertex2i(780, 477);
        glVertex2i(784, 480);
        glVertex2i(788, 483);
        glVertex2i(790, 485);
        glVertex2i(792, 487);
        glVertex2i(795, 490);
        glVertex2i(798, 493);

        glVertex2i(805, 507);
        glVertex2i(810, 509);
        glVertex2i(814, 510);
        glVertex2i(815, 512);
        glVertex2i(818, 515);
        glVertex2i(820, 517);
        glVertex2i(824, 520);
        glVertex2i(828, 523);
        glVertex2i(830, 525);
        glVertex2i(832, 527);
        glVertex2i(835, 530);
        glVertex2i(838, 533);

        glVertex2i(1432, 537);
        glVertex2i(1383, 630);
        glVertex2i(844, 441);
        glVertex2i(846, 542);
        glVertex2i(1299, 632);
        glVertex2i(1134, 547);
        glVertex2i(943, 550);
        glVertex2i(1001, 635);
        glVertex2i(860, 555);
        glVertex2i(1378, 441);
        glVertex2i(994, 560);
        glVertex2i(868, 471);

        glVertex2i(1345, 567);
        glVertex2i(1278, 676);
        glVertex2i(1189, 498);
        glVertex2i(877, 654);
        glVertex2i(878, 523);
        glVertex2i(1098, 432);
        glVertex2i(1287, 580);
        glVertex2i(721, 467);
        glVertex2i(943, 660);
        glVertex2i(1065, 587);
        glVertex2i(895, 465);
        glVertex2i(832, 593);


        glVertex2i(905, 513);
        glVertex2i(987, 506);
        glVertex2i(769, 640);
        glVertex2i(1256, 470);
        glVertex2i(918, 615);
        glVertex2i(878, 617);
        glVertex2i(919, 616);
        glVertex2i(1234, 565);
        glVertex2i(890, 524);
        glVertex2i(976, 627);
        glVertex2i(765, 497);
        glVertex2i(876, 633);

        glVertex2i(843, 456);
        glVertex2i(943, 498);
        glVertex2i(1212, 678);
        glVertex2i(836, 642);
        glVertex2i(948, 521);
        glVertex2i(813, 567);
        glVertex2i(954, 650);
        glVertex2i(1378, 654);
        glVertex2i(930, 457);
        glVertex2i(865, 657);
        glVertex2i(965, 431);
        glVertex2i(884, 663);

        glVertex2i(970, 430);
        glVertex2i(1021, 569);
        glVertex2i(742, 670);
        glVertex2i(764, 419);
        glVertex2i(873, 675);
        glVertex2i(1023, 563);
        glVertex2i(1123, 448);
        glVertex2i(988, 678);
        glVertex2i(853, 474);
        glVertex2i(876, 595);
        glVertex2i(954, 690);
        glVertex2i(1254, 465);

        glVertex2i(820, 407);
        glVertex2i(1110, 467);
        glVertex2i(1289, 620);
        glVertex2i(1267, 652);
        glVertex2i(918, 532);
        glVertex2i(1020, 517);
        glVertex2i(827, 433);
        glVertex2i(976, 490);
        glVertex2i(715, 654);
        glVertex2i(1032, 450);
        glVertex2i(780, 730);
        glVertex2i(1038, 733);

        glVertex2i(1256, 444);
        glVertex2i(934, 506);
        glVertex2i(811, 610);
        glVertex2i(1046, 536);
        glVertex2i(723, 478);
        glVertex2i(900, 645);
        glVertex2i(818, 500);
        glVertex2i(1212, 615);
        glVertex2i(910, 434);
        glVertex2i(1062, 612);
        glVertex2i(777, 534);
        glVertex2i(856, 598);

        glVertex2i(812, 534);
        glVertex2i(789, 456);
        glVertex2i(1123, 666);
        glVertex2i(798, 534);
        glVertex2i(1078, 412);
        glVertex2i(934, 654 );
        glVertex2i(1084, 555);
        glVertex2i(882, 476);
        glVertex2i(896, 690);
        glVertex2i(992, 681);
        glVertex2i(1195, 561);
        glVertex2i(778, 483);

        glEnd();

    }
    else if(nightstatus==1)
    {
        glColor3ub (63, 140, 172 );
        glBegin(GL_QUADS);
        glVertex2i(1400, 0);
        glVertex2i(1400,800);
        glVertex2i(0,800);
        glVertex2i(0,0);
        glEnd();

        glColor3f(1.0,1.0,0.0);
        DrawCircle(1250,700,50,2000);
    }
}
void lightBuib()
{
    glColor3ub(255,215,0);
    DrawCircle(530, 150, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(530, 160, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(530, 170, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(530, 180, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(530, 190, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(530, 200, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(530, 210, 3, 500);
    glColor3ub(135,206,235);
    DrawCircle(530, 220, 3, 500);
    glColor3ub(72,61,139);
    DrawCircle(530, 230, 3, 500);
}

void lightBuib2()
{
    glColor3ub(255,215,0);
    DrawCircle(550, 520, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(550, 510, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(550, 500, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(550, 490, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(550, 480, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(550, 470, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(550, 460, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(550, 450, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(550, 440, 3, 500);
}

void lightBuib3()
{
    glColor3ub(255,215,0);
    DrawCircle(570, 150, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(570, 160, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(570, 170, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(570, 180, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(570, 190, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(570, 200, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(570, 210, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(570, 220, 3, 500);
    glColor3ub(0,255,0);
    DrawCircle(570, 230, 3, 500);
}

void lightBuib4 ()
{
    glColor3ub(255,215,0);
    DrawCircle(590, 520, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(590, 510, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(590, 500, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(590, 490, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(590, 480, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(590, 470, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(590, 460, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(590, 450, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(590, 440, 3, 500);
}

void lightBuib5 ()
{
    glColor3ub(255,215,0);
    DrawCircle(840, 520, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(840, 510, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(840, 500, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(840, 490, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(840, 480, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(840, 470, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(840, 460, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(840, 450, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(840, 440, 3, 500);
}

void lightBuib6 ()
{
    glColor3ub(255,215,0);
    DrawCircle(865, 150, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(865, 160, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(865, 170, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(865, 180, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(865, 190, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(865, 200, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(865, 210, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(865, 220, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(865, 230, 3, 500);
}

void lightBuib7 ()
{
    glColor3ub(255,215,0);
    DrawCircle(882, 152, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(882, 162, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(882, 172, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(882, 182, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(882, 192, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(882, 202, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(882, 212, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(882, 222, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(882, 232, 3, 500);
}

void lightBuib8 ()
{
    glColor3ub(255,215,0);
    DrawCircle(905, 540, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(905, 530, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(905, 520, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(905, 510, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(905, 500, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(905, 490, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(905, 480, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(905, 470, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(905, 460, 3, 500);
}

void lightBuib9 ()
{
    glColor3ub(255,215,0);
    DrawCircle(930, 180, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(930, 190, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(930, 200, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(930, 210, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(930, 220, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(930, 230, 3, 500);
    glColor3ub(255,215,0);
    DrawCircle(930, 240, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(930, 250, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(930, 260, 3, 500);
}

void lightBuib10 ()
{
    glColor3ub(255,215,0);
    DrawCircle(500, 290, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(500, 280, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(500, 270, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(500, 260, 3, 500);
}

void lightBuib11 ()
{
    glColor3ub(255,215,0);
    DrawCircle(880, 290, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(880, 280, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(880, 270, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(880, 260, 3, 500);
}

void lightBuib12 ()
{
    glColor3ub(255,215,0);
    DrawCircle(505, 280, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(515, 280, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(525, 280, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(525, 280, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(535, 280, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(545, 280, 3, 500);
}
void lightBuib13 ()
{
    glColor3ub(255,215,0);
    DrawCircle(600, 380, 3, 500);
    glColor3ub(0,0,139);
    DrawCircle(610, 380, 3, 500);
    glColor3ub(0,255,255);
    DrawCircle(620, 380, 3, 500);
    glColor3ub(255,69,0);
    DrawCircle(630, 380, 3, 500);
    glColor3ub(199,21,133);
    DrawCircle(640, 380, 3, 500);
    glColor3ub(34,139,34);
    DrawCircle(650, 380, 3, 500);
}

void bulbAnimation()
{
    if(bulbStatus==1)
    {
        bulb_Y+=5.9;
    }
    if(bulb_Y>300)
    {
        bulb_Y=0;
    }
    glPushMatrix();
    glTranslatef(bulb_X,bulb_Y,0.0);
    lightBuib();
    glPopMatrix();
}

void bulbAnimation2()
{
    if(bulbStatus==1)
    {
        bulb_Y2-=6.9;
    }
    if(bulb_Y2<150)
    {
        bulb_Y2=430;
    }
    glPushMatrix();
    glTranslatef(bulb_X2,bulb_Y2-440,0.0);
    lightBuib2();
    glPopMatrix();
}

void bulbAnimation3()
{
    if(bulbStatus==1)
    {
        bulb_Y3+=4.9;
    }
    if(bulb_Y3>300)
    {
        bulb_Y3=0;
    }
    glPushMatrix();
    glTranslatef(bulb_X3,bulb_Y3,0.0);
    lightBuib3();
    glPopMatrix();
}

void bulbAnimation4()
{
    if(bulbStatus==1)
    {
        bulb_Y4-=6.9;
    }
    if(bulb_Y4<150)
    {
        bulb_Y4=430;
    }
    glPushMatrix();
    glTranslatef(bulb_X4,bulb_Y4-440,0.0);
    lightBuib4();
    glPopMatrix();
}

void bulbAnimation5()
{
    if(bulbStatus==1)
    {
        bulb_Y5-=4.5;
    }
    if(bulb_Y5<150)
    {
        bulb_Y5=430;
    }
    glPushMatrix();
    glTranslatef(bulb_X5,bulb_Y5-440,0.0);
    lightBuib5();
    glPopMatrix();
}

void bulbAnimation6()
{
    if(bulbStatus==1)
    {
        bulb_Y6+=5.4;
    }
    if(bulb_Y6>300)
    {
        bulb_Y6=0;
    }
    glPushMatrix();
    glTranslatef(bulb_X6,bulb_Y6,0.0);
    lightBuib6();
    glPopMatrix();
}

void bulbAnimation7()
{
    if(bulbStatus==1)
    {
        bulb_Y7+=6.9;
    }
    if(bulb_Y7>300)
    {
        bulb_Y7=0;
    }
    glPushMatrix();
    glTranslatef(bulb_X7,bulb_Y7,0.0);
    lightBuib7();
    glPopMatrix();
}

void bulbAnimation8()
{
    if(bulbStatus==1)
    {
        bulb_Y8-=4.9;
    }
    if(bulb_Y8<170)
    {
        bulb_Y8=450;
    }
    glPushMatrix();
    glTranslatef(bulb_X8,bulb_Y8-440,0.0);
    lightBuib8();
    glPopMatrix();
}

void bulbAnimation9()
{
    if(bulbStatus==1)
    {
        bulb_Y9+=6.9;
    }
    if(bulb_Y9>305)
    {
        bulb_Y9=10;
    }
    glPushMatrix();
    glTranslatef(bulb_X9,bulb_Y9,0.0);
    lightBuib9();
    glPopMatrix();
}
void bulbAnimation10()
{
    if(bulbStatus==1)
    {
        bulb_Y10-=5.6;
    }
    if(bulb_Y10<185)
    {
        bulb_Y10=290;
    }
    glPushMatrix();
    glTranslatef(bulb_X10,bulb_Y10-300,0.0);
    lightBuib10();
    glPopMatrix();
}
void bulbAnimation11()
{
    if(bulbStatus==1)
    {
        bulb_Y11-=4.3;
    }
    if(bulb_Y11<185)
    {
        bulb_Y11=290;
    }
    glPushMatrix();
    glTranslatef(bulb_X10,bulb_Y11-300,0.0);
    lightBuib11();
    glPopMatrix();
}

void bulbAnimation12()
{
    if(bulbStatus==1)
    {
        bulb_X12+=5.5;
    }
    if(bulb_X12>350)
    {
        bulb_X12=20;
    }
    glPushMatrix();
    glTranslatef(bulb_X12-20,bulb_Y12,0.0);
    lightBuib12();
    glPopMatrix();
}
void bulbAnimation13()
{
    if(bulbStatus==1)
    {
        bulb_X13+=6.9;
    }
    if(bulb_X13>160)
    {
        bulb_X13=5;
    }
    glPushMatrix();
    glTranslatef(bulb_X13-20,bulb_Y13,0.0);
    lightBuib13();
    glPopMatrix();
}

void light()
{
    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(530,530);
    glVertex2i(530,150);
    glEnd();



    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(550,530);
    glVertex2i(550,150);
    glEnd();



    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(570,530);
    glVertex2i(570,150);
    glEnd();


    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(590,530);
    glVertex2i(590,150);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(840,530);
    glVertex2i(840,150);
    glEnd();

    glColor3ub(0, 0, 0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(865,530);
    glVertex2i(865,150);
    glEnd();

    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(880,532);
    glVertex2i(880,152);
    glEnd();

    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(905,547);
    glVertex2i(905,167);
    glEnd();

    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(930,565);
    glVertex2i(930,185);
    glEnd();




}
void AmBulance()
{

    ///car up alarm red light
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (150, 130);
    glVertex2f (142, 130);
    glVertex2f (142, 137);
    glVertex2f (150, 137);
    glEnd();

    ///car up alarm blue light
    glBegin(GL_POLYGON);
    glColor3ub (0.118, 0.565, 1.000);
    glVertex2f (142, 130);
    glVertex2f (134, 130);
    glVertex2f (134, 138);
    glVertex2f (142, 138);
    glEnd();


///car up body
    glBegin(GL_POLYGON);
    glColor3f (1.0, 1.0, 1.0);
    glVertex2f (190, 97);
    glVertex2f (70, 97);
    glVertex2f (70, 130);
    glVertex2f (160, 130);
    glEnd();

    /// blue rec_2

 glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (178, 101);
    glVertex2f (137, 101);
    glVertex2f (137, 125);
    glVertex2f (158, 125);
    glEnd();

/// blue rec_1

    glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (132, 101);
    glVertex2f (108, 101);
    glVertex2f (108, 125);
    glVertex2f (132, 125);
    glEnd();

    /// red plus 1

    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (104, 110);
    glVertex2f (80, 110);
    glVertex2f (80, 115);
    glVertex2f (104, 115);
    glEnd();

    /// red plus 2

    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (94,99);
    glVertex2f (89, 99);
    glVertex2f (89, 124);
    glVertex2f (94, 124);
    glEnd();


    ///car down body
    glBegin(GL_POLYGON);
    glColor3f (1.0, 1.0, 1.0);
    glVertex2f (205, 67);
    glVertex2f (70, 67);
    glVertex2f (70, 102);
    glVertex2f (205, 102);
    glEnd();

    ///car down body small corner rec
    glBegin(GL_POLYGON);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f (205, 67);
    glVertex2f (183, 67);
    glVertex2f (183, 73);
    glVertex2f (205, 73);
    glEnd();

    ///red rec in down body
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f (205, 80);
    glVertex2f (70, 80);
    glVertex2f (70, 87);
    glVertex2f (205, 87);
    glEnd();

    ///car yellow light back
    glBegin(GL_POLYGON);
    glColor3f (255, 165, 0);
    glVertex2f (83,70);
    glVertex2f (70,70);
    glVertex2f (70,77);
    glVertex2f (83,77);
    glEnd();

    ///car yellow light front
    glBegin(GL_POLYGON);
    glColor3f (255, 165, 0);
    glVertex2f (205, 70);
    glVertex2f (191,70);
    glVertex2f (191,77);
    glVertex2f (205,77);
    glEnd();




    ///Wheel_1
    glColor3f (1.000, 1.000, 1.000);
    float x1,y1,x2,y2;
    float angle;
    double radius=12; // Radius

    x1 = 104,y1=63; // Center
    glColor3f(0.4, 0.3, 0.2);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex2f(x2,y2);
    }

    glEnd();


    ///wheel_2

    glColor3f (1.000, 1.000, 1.000);
///  float x1,y1,x2,y2;
///    float angle;
    radius=12; // Radius

    x1 = 164,y1=63; // Center
    glColor3f(0.4, 0.3, 0.2);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex2f(x2,y2);
    }

    glEnd();


    //tyre rec 21

    glBegin(GL_POLYGON);
    glColor3f (0.000, 0.000, 0.000);
    glVertex2f (100, 67);
    glVertex2f (107, 67);
    glVertex2f (107, 53);
    glVertex2f (100, 53);
    glEnd();

    //tyre rec22

    glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (107, 67);
    glVertex2f (107, 62);
    glVertex2f (115, 62);
    glVertex2f (115, 67);
    glEnd();

    //tyre rec23

    glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (100, 67);
    glVertex2f (100, 62);
    glVertex2f (92, 62);
    glVertex2f (92, 67);
    glEnd();

//tyre rec 11

    glBegin(GL_POLYGON);
    glColor3f (0.000, 0.000, 0.000);
    glVertex2f (160, 67);
    glVertex2f (167, 67);
    glVertex2f (167, 53);
    glVertex2f (160, 53);
    glEnd();


    //tyre rec 12

    glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (167, 67);
    glVertex2f (167,62);
    glVertex2f (175,62);
    glVertex2f (175,67);
    glEnd();


    // tyre rec13
    glBegin(GL_POLYGON);
    glColor3f (0.118, 0.565, 1.000);
    glVertex2f (160, 67);
    glVertex2f (160, 62);
    glVertex2f (152, 62);
    glVertex2f (152, 67);
    glEnd();



}
void AmbuAnim()
{
    amb_X+=6.7;

    if(amb_X>1400)
    {
        amb_X=-600;
    }
    glPushMatrix();
    glTranslatef(amb_X,amb_Y+40,0.0);
    AmBulance();
    glPopMatrix();
}

void HouseBuildup()
{
    glColor3ub(235, 152, 78);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(525,150);
    glVertex2i(875,150);
    glVertex2i(935,190);
    glVertex2i(935,570);
    glVertex2i(585,570);
    glVertex2i(525,530);
    glEnd();

    glColor3ub(0,0,0);//Main Door
    glLineWidth(3.0);
    glBegin(GL_QUADS);

    glVertex2i(665,150);
    glVertex2i(665,265);
    glVertex2i(535,265);
    glVertex2i(535,150);
    glEnd();

    glColor3ub(139,69,19);
    glLineWidth(3.0);
    glBegin(GL_QUADS);

    glVertex2i(663,150);
    glVertex2i(663,263);
    glVertex2i(537,263);
    glVertex2i(537,150);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);

    glVertex2i(600,150);
    glVertex2i(600,265);
    glEnd();
    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);//Roof Raling 1
    glVertex2i(875,530);
    glVertex2i(935,570);
    glVertex2i(935,590);
    glVertex2i(875,550);
    glVertex2i(875,530);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);//Roof Raling 1 STRIP
    glVertex2i(885,533);
    glVertex2i(885,556);

    glVertex2i(895,536);
    glVertex2i(895,562);

    glVertex2i(905,546);
    glVertex2i(905,569);


    glVertex2i(915,556);
    glVertex2i(915,576);

    glVertex2i(925,565);
    glVertex2i(925,583);

    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);//Roof Raling 2
    glVertex2i(875,530);
    glVertex2i(875,550);
    glVertex2i(525,550);
    glVertex2i(525,530);
    glVertex2i(875,530);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);//Roof Raling 2 STRIP

    glVertex2i(535,530);
    glVertex2i(535,550);

    glVertex2i(555,530);
    glVertex2i(555,550);

    glVertex2i(575,530);
    glVertex2i(575,550);


    glVertex2i(595,530);
    glVertex2i(595,550);

    glVertex2i(615,530);
    glVertex2i(615,550);

    glVertex2i(635,530);
    glVertex2i(635,550);

    glVertex2i(655,530);
    glVertex2i(655,550);

    glVertex2i(675,530);
    glVertex2i(675,550);


    glVertex2i(695,530);
    glVertex2i(695,550);

    glVertex2i(715,530);
    glVertex2i(715,550);

    glVertex2i(735,530);
    glVertex2i(735,550);

    glVertex2i(755,530);
    glVertex2i(755,550);

    glVertex2i(775,530);
    glVertex2i(775,550);


    glVertex2i(795,530);
    glVertex2i(795,550);

    glVertex2i(815,530);
    glVertex2i(815,550);

    glVertex2i(835,530);
    glVertex2i(835,550);

    glVertex2i(855,530);
    glVertex2i(855,550);

    glVertex2i(875,530);
    glVertex2i(875,550);


    glVertex2i(895,530);
    glVertex2i(895,550);

    glVertex2i(915,530);
    glVertex2i(915,550);

    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);//Roof Raling 3
    glVertex2i(525,530);
    glVertex2i(525,550);
    glVertex2i(585,590);
    glVertex2i(585,570);
    glVertex2i(525,530);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);//Roof Raling 1 STRIP
    glVertex2i(535,535);
    glVertex2i(535,556);

    glVertex2i(545,540);
    glVertex2i(545,562);

    glVertex2i(555,548);
    glVertex2i(555,569);


    glVertex2i(565,558);
    glVertex2i(565,576);

    glVertex2i(575,565);
    glVertex2i(575,583);

    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);//Roof Raling 4
    glVertex2i(585,570);
    glVertex2i(585,590);
    glVertex2i(935,590);
    glVertex2i(935,570);
    glVertex2i(585,570);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(3.0);
    glBegin(GL_LINES);//Roof Raling 2 STRIP

    glVertex2i(595,570);
    glVertex2i(595,590);

    glVertex2i(615,570);
    glVertex2i(615,590);

    glVertex2i(635,570);
    glVertex2i(635,590);


    glVertex2i(655,570);
    glVertex2i(655,590);

    glVertex2i(675,570);
    glVertex2i(675,590);

    glVertex2i(695,570);
    glVertex2i(695,590);

    glVertex2i(715,570);
    glVertex2i(715,590);

    glVertex2i(735,570);
    glVertex2i(735,590);

    glVertex2i(755,570);
    glVertex2i(755,590);

    glVertex2i(775,570);
    glVertex2i(775,590);

    glVertex2i(795,570);
    glVertex2i(795,590);

    glVertex2i(815,570);
    glVertex2i(815,590);

    glVertex2i(835,570);
    glVertex2i(835,590);


    glVertex2i(855,570);
    glVertex2i(855,590);

    glVertex2i(875,570);
    glVertex2i(875,590);

    glVertex2i(895,570);
    glVertex2i(895,590);

    glVertex2i(915,570);
    glVertex2i(915,590);

    glVertex2i(935,570);
    glVertex2i(935,590);

    glEnd();
    glColor3ub(220,20,60);
    glLineWidth(3.0);
    glBegin(GL_QUADS);//Roof Umbrella Stand
    glVertex2i(595,555);
    glVertex2i(595,640);
    glVertex2i(615,640);
    glVertex2i(615,555);
    glEnd();

    glColor3ub(220,20,60);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);//Roof Umbrella
    glVertex2i(690,640);
    glVertex2i(650,690);
    glVertex2i(600,710);
    glVertex2i(560,690);
    glVertex2i(520,640);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);//Roof BED
    glVertex2i(770,565);
    glVertex2i(670,565);
    glVertex2i(670,585);
    glVertex2i(770,585);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);//Roof BED
    glVertex2i(770,565);
    glVertex2i(670,565);
    glVertex2i(670,585);
    glVertex2i(770,585);
    glVertex2i(770,565);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(3.0);
    glBegin(GL_QUADS);//Roof BED
    glVertex2i(670,565);
    glVertex2i(670,585);
    glVertex2i(640,612);
    glVertex2i(640,590);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);//Roof BED

    glVertex2i(670,585);
    glVertex2i(640,612);
    glVertex2i(640,590);
    glVertex2i(670,565);
    glEnd();

    glColor3ub(255,255,255);
    glLineWidth(4.0);
    glBegin(GL_LINES);//Roof BED
    glVertex2i(670,565);
    glVertex2i(660,555);
    glVertex2i(768,565);
    glVertex2i(775,555);
    glEnd();


    glColor3ub(210,105,30);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);//Roof Umbrella
    glVertex2i(660,640);
    glVertex2i(625,690);
    glVertex2i(600,710);
    glVertex2i(575,690);
    glVertex2i(550,640);
    glEnd();

    glColor3ub(244,164,96);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);//Roof Umbrella
    glVertex2i(640,640);
    glVertex2i(615,690);
    glVertex2i(600,710);
    glVertex2i(585,690);
    glVertex2i(560,640);
    glEnd();

    glColor3ub(199,21,133);
    glLineWidth(3.0);
    glBegin(GL_TRIANGLES);//Roof Umbrella
    glVertex2i(625,640);
    glVertex2i(600,710);
    glVertex2i(575,640);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);//Roof Umbrella
    glVertex2i(690,640);
    glVertex2i(650,690);
    glVertex2i(600,710);
    glVertex2i(560,690);
    glVertex2i(520,640);
    glVertex2i(690,640);
    glEnd();

    glColor3ub(210,105,30);
    glLineWidth(3.0);
    glBegin(GL_QUADS);//Roof Raling 4
    glVertex2i(600,555);
    glVertex2i(600,640);
    glVertex2i(610,640);
    glVertex2i(610,555);
    glEnd();

    glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);//Roof Raling 4
    glVertex2i(595,555);
    glVertex2i(595,640);
    glVertex2i(615,640);
    glVertex2i(615,555);
    glVertex2i(595,555);
    glEnd();

    glColor3ub(0,0,0);
    DrawCircle(590.0,207.0,3.0,200);
    glColor3ub(28, 40, 51);//First Strip
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(935,530);
    glVertex2i(935,570);
    glVertex2i(875,530);
    glVertex2i(523,530);
    glVertex2i(523,490);
    glVertex2i(875,490);
    glEnd();

    glPushMatrix();
    glTranslatef(585,505, 0);
    Sprint2(15.0,0,text2);
    glPopMatrix();

    glColor3ub(28, 40, 51);//Second Strip
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(935,330);
    glVertex2i(935,370);
    glVertex2i(875,330);
    glVertex2i(523,330);
    glVertex2i(523,290);
    glVertex2i(875,290);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2i(875,530);
    glVertex2i(875,150);
    glEnd();
    glColor3ub(139,69,19);//door
    glBegin(GL_POLYGON);
    glVertex2i(670,350);
    glVertex2i(730,350);
    glVertex2i(730,440);
    glVertex2i(670,440);
    glEnd();

    glColor3ub(139,69,19);//door
    glBegin(GL_POLYGON);
    glVertex2i(670,350);
    glVertex2i(730,350);
    glVertex2i(730,440);
    glVertex2i(670,440);
    glEnd();

    glColor3ub(0,0,0);//door Strip
    glBegin(GL_LINE_STRIP);
    glVertex2i(670,350);
    glVertex2i(730,350);
    glVertex2i(730,440);
    glVertex2i(670,440);
    glVertex2i(670,350);
    glEnd();

    glColor3ub(0,0,0);//door knob
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2i(680,385);
    glEnd();

    glColor3ub(255,245,238);//Veranda Surface
    glBegin(GL_POLYGON);
    glVertex2i(600,330);
    glVertex2i(620,350);
    glVertex2i(800,350);
    glVertex2i(800,330);
    glEnd();

    glColor3ub(0,0,0);//Window 1
    glBegin(GL_QUADS);
    glVertex2i(765,405);
    glVertex2i(835,405);
    glVertex2i(835,460);
    glVertex2i(765,460);
    glEnd();
    glColor3ub(255,245,238);
    glBegin(GL_QUADS);
    glVertex2i(767,407);
    glVertex2i(833,407);
    glVertex2i(833,458);
    glVertex2i(767,458);
    glEnd();
    glColor3ub(0,0,0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(800,407);
    glVertex2i(800,458);
    glEnd();
    glColor3ub(0,0,0);//Window 2
    glBegin(GL_QUADS);
    glVertex2i(565,405);
    glVertex2i(635,405);
    glVertex2i(635,460);
    glVertex2i(565,460);
    glEnd();
    glColor3ub(255,245,238);
    glBegin(GL_QUADS);
    glVertex2i(567,407);
    glVertex2i(633,407);
    glVertex2i(633,458);
    glVertex2i(567,458);
    glEnd();
    glColor3ub(0,0,0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(600,407);
    glVertex2i(600,458);
    glEnd();

    glColor3ub(0,0,0);//Window 3
    glBegin(GL_QUADS);
    glVertex2i(895,460);
    glVertex2i(915,475);
    glVertex2i(915,420);
    glVertex2i(895,405);
    glEnd();
    glColor3ub(255,245,238);
    glBegin(GL_QUADS);
    glVertex2i(897,458);
    glVertex2i(913,471);
    glVertex2i(913,422);
    glVertex2i(897,409);
    glEnd();
    glColor3ub(0,0,0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(905,411);
    glVertex2i(905,465);
    glEnd();

    glColor3f(0.0,0.0,0.0);//Veranda
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glVertex2i(600,330);
    glVertex2i(800,330);
    glVertex2i(800,380);
    glVertex2i(600,380);
    glVertex2i(600,330);
    glEnd();



    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(620,330);
    glVertex2i(620,380);
    glVertex2i(640,330);
    glVertex2i(640,380);
    glVertex2i(660,330);
    glVertex2i(660,380);
    glVertex2i(680,330);
    glVertex2i(680,380);
    glVertex2i(700,330);
    glVertex2i(700,380);
    glVertex2i(720,330);
    glVertex2i(720,380);
    glVertex2i(740,330);
    glVertex2i(740,380);
    glVertex2i(760,330);
    glVertex2i(760,380);
    glVertex2i(780,330);
    glVertex2i(780,380);
    glEnd();

    glBegin(GL_QUADS);

    glVertex2i(800,380);
    glVertex2i(820,400);
    glVertex2i(820,350);
    glVertex2i(800,330);
    glEnd();

    glBegin(GL_LINES);

    glVertex2i(820,350);
    glVertex2i(820,400);
    glEnd();

    glBegin(GL_QUADS);

    glVertex2i(600,380);
    glVertex2i(620,400);
    glVertex2i(620,350);
    glVertex2i(600,330);
    glEnd();


}

void Tree ()
{
    glColor3ub(139,69,19);//Tree 1 Wood
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1160,180);
    glVertex2i(1150,170);
    glVertex2i(1200,170);
    glVertex2i(1190,180);
    glVertex2i(1190,280);
    glVertex2i(1160,280);
    glEnd();

    glColor3f(0.0,1.0,0.0);// Tree 1 Green
    DrawCircle(1210, 290, 35, 1000);
    DrawCircle(1150, 290, 45, 1000);
    DrawCircle(1170, 340, 45, 1000);

    glColor3ub(139,69,19);//Tree 2 Wood
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(60,240);
    glVertex2i(50,230);
    glVertex2i(100,230);
    glVertex2i(90,240);
    glVertex2i(90,300);
    glVertex2i(60,300);
    glEnd();

    glColor3f(0.0,1.0,0.0);// Tree 2 Green
    DrawCircle(100, 310, 30, 1000);
    DrawCircle(60, 310, 40, 1000);
    DrawCircle(110, 360, 48, 1000);
    DrawCircle(40, 370, 30, 1000);
    DrawCircle(70, 400, 30, 1000);

}


void MetroRailBridge()//Bridge
{
    glColor3ub (229, 232, 232);// Bridge Surface
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 435);
    glVertex2i(1400, 450);
    glVertex2i(0, 450);
    glVertex2i(0, 435);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(200, 435);
    glVertex2i(220, 435);
    glVertex2i(220, 320);
    glVertex2i(200, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(240, 340);
    glVertex2i(180, 340);
    glVertex2i(180, 320);
    glVertex2i(240, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand  carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(235, 360);
    glVertex2i(185, 360);
    glVertex2i(185, 340);
    glVertex2i(235, 340);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(400, 435);
    glVertex2i(420, 435);
    glVertex2i(420, 320);
    glVertex2i(400, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(440, 340);
    glVertex2i(380, 340);
    glVertex2i(380, 320);
    glVertex2i(440, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(435, 360);
    glVertex2i(385, 360);
    glVertex2i(385, 340);
    glVertex2i(435, 340);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1050, 435);
    glVertex2i(1070, 435);
    glVertex2i(1070, 320);
    glVertex2i(1050, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1090, 340);
    glVertex2i(1030, 340);
    glVertex2i(1030, 320);
    glVertex2i(1090, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1085, 360);
    glVertex2i(1035, 360);
    glVertex2i(1035, 340);
    glVertex2i(1085, 340);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1250, 435);
    glVertex2i(1270, 435);
    glVertex2i(1270, 320);
    glVertex2i(1250, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1290, 340);
    glVertex2i(1230, 340);
    glVertex2i(1230, 320);
    glVertex2i(1290, 320);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge Stand carrier
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1285, 360);
    glVertex2i(1235, 360);
    glVertex2i(1235, 340);
    glVertex2i(1285, 340);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(350, 450);
    glVertex2i(300, 550);
    glVertex2i(295, 540);
    glVertex2i(340, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(300, 550);
    glVertex2i(50, 550);

    glVertex2i(55, 540);
    glVertex2i(295, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(50, 550);
    glVertex2i(0, 450);
    glVertex2i(10, 450);
    glVertex2i(55, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(55, 540);
    glVertex2i(65, 540);
    glVertex2i(65, 450);
    glVertex2i(55, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(127, 540);
    glVertex2i(137, 540);
    glVertex2i(137, 450);
    glVertex2i(127, 450);
    glEnd();


    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(209, 540);
    glVertex2i(219, 540);
    glVertex2i(219, 450);
    glVertex2i(209, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover1
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(285, 540);
    glVertex2i(295, 540);
    glVertex2i(295, 450);
    glVertex2i(285, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(350, 450);
    glVertex2i(400, 550);
    glVertex2i(405, 540);
    glVertex2i(360, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(400, 550);
    glVertex2i(650, 550);
    glVertex2i(645, 540);
    glVertex2i(405, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(650, 550);
    glVertex2i(700, 450);
    glVertex2i(695, 440);
    glVertex2i(645, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(405, 540);
    glVertex2i(415, 540);
    glVertex2i(415, 450);
    glVertex2i(405, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(487, 540);
    glVertex2i(497, 540);
    glVertex2i(497, 450);
    glVertex2i(487, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(569, 540);
    glVertex2i(579, 540);
    glVertex2i(579, 450);
    glVertex2i(569, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover2
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(650, 540);
    glVertex2i(640, 540);
    glVertex2i(640, 450);
    glVertex2i(650, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(700, 450);
    glVertex2i(750, 550);
    glVertex2i(755, 540);
    glVertex2i(710, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(750, 550);
    glVertex2i(1000, 550);
    glVertex2i(995, 540);
    glVertex2i(755, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1000, 550);
    glVertex2i(1050, 450);
    glVertex2i(1040, 450);

    glVertex2i(995, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(755, 540);
    glVertex2i(765, 540);
    glVertex2i(765, 450);

    glVertex2i(755, 450);
    glEnd();


    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(837, 540);
    glVertex2i(847, 540);
    glVertex2i(847, 450);

    glVertex2i(837, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(919, 540);
    glVertex2i(929, 540);
    glVertex2i(929, 450);

    glVertex2i(919, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover3
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(985, 540);
    glVertex2i(995, 540);
    glVertex2i(995, 450);

    glVertex2i(985, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1050, 450);
    glVertex2i(1100, 550);
    glVertex2i(1105, 540);
    glVertex2i(1060, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1100, 550);
    glVertex2i(1350, 550);
    glVertex2i(1345, 540);
    glVertex2i(1105, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1350, 550);
    glVertex2i(1400, 450);
    glVertex2i(1390, 450);
    glVertex2i(1345, 540);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1105, 540);
    glVertex2i(1115, 540);
    glVertex2i(1115, 450);
    glVertex2i(1105, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1187, 540);
    glVertex2i(1197, 540);
    glVertex2i(1197, 450);
    glVertex2i(1187, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1269, 540);
    glVertex2i(1279, 540);
    glVertex2i(1279, 450);
    glVertex2i(1269, 450);
    glEnd();

    glColor3ub (229, 232, 232);// Bridge cover4
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(1340, 540);
    glVertex2i(1350, 540);
    glVertex2i(1350, 450);
    glVertex2i(1340, 450);
    glEnd();

}

void Train()//Train Build up
{
    glColor3ub(105,105,105);
    DrawCircle(40.0,455.0,10.0,200.0);
    DrawCircle(70.0,455.0,10.0,200.0);
    DrawCircle(100.0,455.0,10.0,200.0);
    DrawCircle(130.0,455.0,10.0,200.0);
    glColor3ub(0,128,128); //Bogi 1
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(25,460);
    glVertex2i(150,460);
    glVertex2i(155,465);
    glVertex2i(155,520);
    glVertex2i(30,520);
    glVertex2i(25,515);
    glVertex2i(25,460);
    glEnd();

    glColor3ub(255,0,0);//Bogi 1 body stripe
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(25,470);
    glVertex2i(149,470);
    glVertex2i(25,465);
    glVertex2i(149,465);
    glEnd();


    glColor3ub(0,0,0); //Line
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(25,515);
    glVertex2i(150,515);

    glVertex2i(156,520);
    glVertex2i(150,515);

    glVertex2i(150,515);
    glVertex2i(150,460);
    glEnd();


    glColor3ub(0,0,0); //Window 1
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(45,480);
    glVertex2i(65,480);
    glVertex2i(65,500);
    glVertex2i(45,500);
    glEnd();

    glColor3ub(255,255,255); //Window 1 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(47,482);
    glVertex2i(63,482);
    glVertex2i(63,498);
    glVertex2i(47,498);
    glEnd();

    glColor3ub(0,0,0); //Window 2
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(75,480);
    glVertex2i(95,480);
    glVertex2i(95,500);
    glVertex2i(75,500);
    glEnd();

    glColor3ub(255,255,255); //Window 2 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(77,482);
    glVertex2i(93,482);
    glVertex2i(93,498);
    glVertex2i(77,498);
    glEnd();

    glColor3ub(0,0,0); //Window 3
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(105,480);
    glVertex2i(125,480);
    glVertex2i(125,500);
    glVertex2i(105,500);
    glEnd();

    glColor3ub(255,255,255); //Window 3 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(107,482);
    glVertex2i(123,482);
    glVertex2i(123,498);
    glVertex2i(107,498);
    glEnd();

    glColor3ub(0,0,0);//Hook 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(153,475);
    glVertex2i(163,475);
    glEnd();

    glColor3ub(105,105,105);
    DrawCircle(178.0,455.0,10.0,200.0);
    DrawCircle(208.0,455.0,10.0,200.0);
    DrawCircle(238.0,455.0,10.0,200.0);
    DrawCircle(268.0,455.0,10.0,200.0);
    glColor3ub(0,128,128); //Bogi 2
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(163,460);
    glVertex2i(288,460);
    glVertex2i(293,465);
    glVertex2i(293,520);
    glVertex2i(168,520);
    glVertex2i(163,515);
    glVertex2i(163,460);
    glEnd();

    glColor3ub(255,0,0);//Bogi 2 body stripe
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(163,470);
    glVertex2i(287,470);
    glVertex2i(163,465);
    glVertex2i(287,465);
    glEnd();

    glColor3ub(0,0,0); //Line
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(163,515);
    glVertex2i(288,515);

    glVertex2i(294,520);
    glVertex2i(288,515);

    glVertex2i(288,515);
    glVertex2i(288,460);
    glEnd();

    glColor3ub(0,0,0); //Window 1
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(183,480);
    glVertex2i(203,480);
    glVertex2i(203,500);
    glVertex2i(183,500);
    glEnd();

    glColor3ub(255,255,255); //Window 1 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(185,482);
    glVertex2i(201,482);
    glVertex2i(201,498);
    glVertex2i(185,498);
    glEnd();

    glColor3ub(0,0,0); //Window 2
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(215,480);
    glVertex2i(235,480);
    glVertex2i(235,500);
    glVertex2i(215,500);
    glEnd();

    glColor3ub(255,255,255); //Window 2 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(217,482);
    glVertex2i(233,482);
    glVertex2i(233,498);
    glVertex2i(217,498);
    glEnd();

    glColor3ub(0,0,0); //Window 3
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(245,480);
    glVertex2i(265,480);
    glVertex2i(265,500);
    glVertex2i(245,500);
    glEnd();

    glColor3ub(255,255,255); //Window 3 border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(247,482);
    glVertex2i(263,482);
    glVertex2i(263,498);
    glVertex2i(247,498);
    glEnd();

    glColor3ub(0,0,0);//Hook 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(291,475);
    glVertex2i(301,475);
    glEnd();

    glColor3ub(105,105,105);
    DrawCircle(316.0,455.0,10.0,200.0);
    DrawCircle(346.0,455.0,10.0,200.0);
    DrawCircle(386.0,455.0,10.0,200.0);
    DrawCircle(424.0,455.0,10.0,200.0);
    glColor3ub(0,128,128); //Engine
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(301,460);
    glVertex2i(436,460);
    glVertex2i(446,480);
    glVertex2i(426,520);
    glVertex2i(316,520);
    glVertex2i(301,515);
    glVertex2i(301,460);
    glEnd();

    glColor3ub(0,0,0); //Line
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(421,515);
    glVertex2i(302,515);
    glVertex2i(421,515);
    glVertex2i(426,520);
    glEnd();

    glColor3ub(0,0,0); //Border
    glPointSize(3);
    glBegin(GL_POLYGON);
    glVertex2i(440,490);
    glVertex2i(426,520);
    glVertex2i(421,515);
    glVertex2i(420,510);
    glVertex2i(430,485);
    glEnd();

    glColor3ub(135,206,250); //Glass
    glPointSize(3);
    glBegin(GL_POLYGON);
    glVertex2i(438,492);
    glVertex2i(424,518);
    glVertex2i(423,513);
    glVertex2i(422,512);
    glVertex2i(432,487);
    glEnd();

    glColor3ub(0,0,0); //Window
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(321,483);
    glVertex2i(361,483);
    glVertex2i(361,503);
    glVertex2i(321,503);
    glEnd();

    glColor3ub(255,255,255); //Window border
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(323,485);
    glVertex2i(359,485);
    glVertex2i(359,501);
    glVertex2i(323,501);
    glEnd();

    glColor3ub(255,0,0);// Engine body stripe
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(301,470);
    glVertex2i(440,470);
    glVertex2i(301,465);
    glVertex2i(437,465);
    glEnd();

    glColor3ub(255,255,0);
    DrawCircle(438.0,480.0,5.0,200.0);//light

    glColor3ub(0,139,139); //chimney1
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(385,520);
    glVertex2i(410,520);
    glVertex2i(410,526);
    glVertex2i(385,526);
    glEnd();
    glColor3ub(0,139,139); //chimney2
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(410,523);
    glVertex2i(415,535);
    glVertex2i(380,535);
    glVertex2i(385,523);
    glEnd();

    glColor3ub(0,0,0); //chimney border
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(409,520);
    glVertex2i(409,526);

    glVertex2i(409,526);
    glVertex2i(384,526);

    glVertex2i(409,526);
    glVertex2i(414,535);

    glVertex2i(414,535);
    glVertex2i(380,535);

    glVertex2i(380,535);
    glVertex2i(385,523);

    glVertex2i(385,523);
    glVertex2i(385,520);
    glEnd();

    glColor3ub(169,169,169);
    DrawCircle(396, 550, 5, 1000);  //1st steam
    DrawCircle(401, 555, 5, 1000);
    DrawCircle(390, 553, 6, 1000);
    DrawCircle(394, 558, 6, 1000);

    DrawCircle(376, 572, 5, 1000);  //2nd steam
    DrawCircle(381, 575, 5, 1000);
    DrawCircle(370, 573, 6, 1000);
    DrawCircle(374, 578, 6, 1000);

    DrawCircle(346, 590, 5, 1000);  //3rd steam
    DrawCircle(351, 595, 5, 1000);
    DrawCircle(340, 593, 6, 1000);
    DrawCircle(344, 598, 6, 1000);


}
void TrainForwardMove()
{

    if(trainstatus==1)
    {
        train_X+=train_Speed;
    }
    if(train_X>1700)
    {
        train_X=-500;
    }
    glPushMatrix();
    glTranslatef(train_X,train_Y,0.0);
    Train();
    glPopMatrix();
}

void TrainBackwardMove()
{
    if(trainstatus==2)
    {
        train_X-=train_Speed;
    }
    if(train_X<-500)
    {
        train_X=1700;
    }
    glPushMatrix();
    glTranslatef(train_X,train_Y,0.0);
    Train();
    glPopMatrix();
}
void Wall()
{
    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 130);
    glVertex2i(20, 130);
    glVertex2i(20, 170);
    glVertex2i(10, 190);
    glVertex2i(0, 170);
    glVertex2i(0, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(40, 130);
    glVertex2i(60, 130);
    glVertex2i(60, 170);
    glVertex2i(50, 190);
    glVertex2i(40, 170);
    glVertex2i(40, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(80, 130);
    glVertex2i(100, 130);
    glVertex2i(100, 170);
    glVertex2i(90, 190);
    glVertex2i(80, 170);
    glVertex2i(80, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 130);
    glVertex2i(140, 130);
    glVertex2i(140, 170);
    glVertex2i(130, 190);
    glVertex2i(120, 170);
    glVertex2i(120, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(160, 130);
    glVertex2i(180, 130);
    glVertex2i(180, 170);
    glVertex2i(170, 190);
    glVertex2i(160, 170);
    glVertex2i(160, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(200, 130);
    glVertex2i(220, 130);
    glVertex2i(220, 170);
    glVertex2i(210, 190);
    glVertex2i(200, 170);
    glVertex2i(200, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 130);
    glVertex2i(260, 130);
    glVertex2i(260, 170);
    glVertex2i(250, 190);
    glVertex2i(240, 170);
    glVertex2i(240, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(280, 130);
    glVertex2i(300, 130);
    glVertex2i(300, 170);
    glVertex2i(290, 190);
    glVertex2i(280, 170);
    glVertex2i(280, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 130);
    glVertex2i(340, 130);
    glVertex2i(340, 170);
    glVertex2i(330, 190);
    glVertex2i(320, 170);
    glVertex2i(320, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(360, 130);
    glVertex2i(380, 130);
    glVertex2i(380, 170);
    glVertex2i(370, 190);
    glVertex2i(360, 170);
    glVertex2i(360, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 130);
    glVertex2i(420, 130);
    glVertex2i(420, 170);
    glVertex2i(410, 190);
    glVertex2i(400, 170);
    glVertex2i(400, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(440, 130);
    glVertex2i(460, 130);
    glVertex2i(460, 170);
    glVertex2i(450, 190);
    glVertex2i(440, 170);
    glVertex2i(440, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(480, 130);
    glVertex2i(500, 130);
    glVertex2i(500, 170);
    glVertex2i(490, 190);
    glVertex2i(480, 170);
    glVertex2i(480, 130);
    glEnd();


    //Gate

    glColor3ub (255, 255, 255);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex2i(500, 130);
    glVertex2i(500, 280);
    glEnd();

    glColor3ub (255, 255, 255);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex2i(880, 130);
    glVertex2i(880, 280);
    glEnd();

    glColor3ub (255, 255, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(885, 270);
    glVertex2i(885, 300);
    glVertex2i(690, 320);
    glVertex2i(495, 300);
    glVertex2i(495, 270);
    glEnd();

    glPushMatrix();
    glTranslatef(590, 285, 0);
    Sprint(5.0,0,text);
    glPopMatrix();

    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(500,150);
    glVertex2i(500,300);
    glEnd();

    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(880,150);
    glVertex2i(880,300);
    glEnd();
    glColor3ub(0,0,0);
    glPointSize(1.0);
    glLineWidth(.1);
    glBegin(GL_LINES);
    glVertex2i(500,280);
    glVertex2i(880,280);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(880, 130);
    glVertex2i(900, 130);
    glVertex2i(900, 170);
    glVertex2i(890, 190);
    glVertex2i(880, 170);
    glVertex2i(880, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(920, 130);
    glVertex2i(940, 130);
    glVertex2i(940, 170);
    glVertex2i(930, 190);
    glVertex2i(920, 170);
    glVertex2i(920, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(960, 130);
    glVertex2i(980, 130);
    glVertex2i(980, 170);
    glVertex2i(970, 190);
    glVertex2i(960, 170);
    glVertex2i(960, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 130);
    glVertex2i(1020, 130);
    glVertex2i(1020, 170);
    glVertex2i(1010, 190);
    glVertex2i(1000, 170);
    glVertex2i(1000, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1040, 130);
    glVertex2i(1060, 130);
    glVertex2i(1060, 170);
    glVertex2i(1050, 190);
    glVertex2i(1040, 170);
    glVertex2i(1040, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1080, 130);
    glVertex2i(1100, 130);
    glVertex2i(1100, 170);
    glVertex2i(1090, 190);
    glVertex2i(1080, 170);
    glVertex2i(1080, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1120, 130);
    glVertex2i(1140, 130);
    glVertex2i(1140, 170);
    glVertex2i(1130, 190);
    glVertex2i(1120, 170);
    glVertex2i(1120, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1160, 130);
    glVertex2i(1180, 130);
    glVertex2i(1180, 170);
    glVertex2i(1170, 190);
    glVertex2i(1160, 170);
    glVertex2i(1160, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1200, 130);
    glVertex2i(1220, 130);
    glVertex2i(1220, 170);
    glVertex2i(1210, 190);
    glVertex2i(1200, 170);
    glVertex2i(1200, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1240, 130);
    glVertex2i(1260, 130);
    glVertex2i(1260, 170);
    glVertex2i(1250, 190);
    glVertex2i(1240, 170);
    glVertex2i(1240, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1280, 130);
    glVertex2i(1300, 130);
    glVertex2i(1300, 170);
    glVertex2i(1290, 190);
    glVertex2i(1280, 170);
    glVertex2i(1280, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1320, 130);
    glVertex2i(1340, 130);
    glVertex2i(1340, 170);
    glVertex2i(1330, 190);
    glVertex2i(1320, 170);
    glVertex2i(1320, 130);
    glVertex2i(1320, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1360, 130);
    glVertex2i(1380, 130);
    glVertex2i(1380, 170);
    glVertex2i(1370, 190);
    glVertex2i(1360, 170);
    glVertex2i(1360, 130);
    glVertex2i(1360, 130);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 130);
    glVertex2i(1420, 130);
    glVertex2i(1420, 170);
    glVertex2i(1410, 190);
    glVertex2i(1400, 170);
    glVertex2i(1400, 130);
    glVertex2i(1400, 130);
    glEnd();

    glColor3ub (255, 255, 255);       //wall strip1
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(0, 165);
    glVertex2i(500, 165);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(0, 150);
    glVertex2i(500, 150);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(0, 135);
    glVertex2i(500, 135);
    glEnd();


//
    glColor3ub (255, 255, 255);       //wall strip2
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(880, 165);
    glVertex2i(1400, 165);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(880, 150);
    glVertex2i(1400, 150);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(880, 135);
    glVertex2i(1400, 135);
    glEnd();
}
void birds()
{
    glColor3ub (47,79,79);
    glPointSize(5.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1300, 600);
    glVertex2i(1320, 600);
    glVertex2i(1303, 600);
    glVertex2i(1315, 605);
    glVertex2i(1303, 600);
    glVertex2i(1298, 605);
    glEnd();

    glColor3ub (47,79,79);
    glPointSize(5.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1340, 620);
    glVertex2i(1360, 620);
    glVertex2i(1343, 620);
    glVertex2i(1355, 625);
    glVertex2i(1343, 620);
    glVertex2i(1338, 625);
    glEnd();

    glColor3ub (47,79,79);
    glPointSize(5.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1280, 620);
    glVertex2i(1300, 620);
    glVertex2i(1283, 620);
    glVertex2i(1295, 625);
    glVertex2i(1283, 620);
    glVertex2i(1278, 625);
    glEnd();

    glColor3ub (47,79,79);
    glPointSize(5.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1370, 600);
    glVertex2i(1390, 600);
    glVertex2i(1373, 600);
    glVertex2i(1385, 605);
    glVertex2i(1373, 600);
    glVertex2i(1368, 605);
    glEnd();

    glColor3ub (47,79,79);
    glPointSize(5.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(1320, 580);
    glVertex2i(1340, 580);
    glVertex2i(1323, 580);
    glVertex2i(1335, 585);
    glVertex2i(1323, 580);
    glVertex2i(1318, 585);
    glEnd();
}

void BirdMoving()
{

    birds_X-=2.0;

    if(birds_X<-1400)
    {
        birds_X=1401;
    }
    glPushMatrix();
    glTranslatef(birds_X,birds_Y,0.0);
    birds();
    glPopMatrix();
}

void table()
{
    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(285, 200);
    glVertex2i(295, 200);    //base
    glVertex2i(295, 230);
    glVertex2i(285, 230);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 230);
    glVertex2i(340, 230);    //upper-table part
    glVertex2i(355, 250);
    glVertex2i(255, 250);
    glEnd();

    glColor3ub (255, 255, 255);     //chair
    glPointSize(5.0);
    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2i(350, 200);
    glVertex2i(370, 230);
    glVertex2i(400, 230);
    glVertex2i(400, 200);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(400, 230);
    glVertex2i(420, 260);
    glEnd();


    glColor3ub (255, 255, 255);     //chair2
    glPointSize(5.0);
    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2i(230, 200);
    glVertex2i(210, 230);
    glVertex2i(180, 230);
    glVertex2i(180, 200);
    glEnd();

    glColor3ub (255, 255, 255);
    glPointSize(5.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(180, 230);
    glVertex2i(160, 260);
    glEnd();
}

void car()
{
    glColor3ub (105, 0, 105);// Car 1
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(90, 25);
    glVertex2i(240, 25);
    glVertex2i(240, 40);
    glVertex2i(215, 45);
    glVertex2i(190, 65);
    glVertex2i(116, 65);
    glVertex2i(100, 45);
    glVertex2i(90, 45);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(130,25,15,2000);

    glColor3f(0.0,0.0,0.0);
    DrawCircle(200,25,15,2000);

    glColor3ub (0, 0, 0);// Car glass
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 55);
    glVertex2i(205, 55);
    glVertex2i(185, 70);
    glVertex2i(126, 70);
    glEnd();
    glColor3ub (105, 0, 105);// Car 2
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(90, 25);
    glVertex2i(240, 25);
    glVertex2i(240, 50);
    glVertex2i(215, 55);
    glVertex2i(190, 75);
    glVertex2i(116, 75);
    glVertex2i(100, 55);
    glVertex2i(90, 55);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(130,25,15,2000);

    glColor3f(0.0,0.0,0.0);
    DrawCircle(200,25,15,2000);

    glColor3ub (0, 0, 0);// Car glass
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(110, 55);
    glVertex2i(205, 55);
    glVertex2i(185, 70);
    glVertex2i(126, 70);
    glEnd();
}

void CarMoving()
{
    Car_X+=5.7;

    if(Car_X>1400)
    {
        Car_X=-600;
    }
    glPushMatrix();
    glTranslatef(Car_X,Car_Y+40,0.0);
    car();
    glPopMatrix();

}

void myDisplay(void)
{

    glClear (GL_COLOR_BUFFER_BIT);

    nightMode();

    glColor3ub (0, 100, 0);// Nicher grass
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(1400, 0);
    glVertex2i(1400, 50);
    glVertex2i(0, 50);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 1
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 10);
    glVertex2i(55, 20);
    glVertex2i(45, 15);
    glVertex2i(40, 30);
    glVertex2i(35, 15);
    glVertex2i(25, 20);
    glVertex2i(30, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 2
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(130, 25);
    glVertex2i(135, 35);
    glVertex2i(125, 30);
    glVertex2i(120, 45);
    glVertex2i(115, 30);
    glVertex2i(105, 35);
    glVertex2i(110, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 3
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(240, 10);
    glVertex2i(245, 20);
    glVertex2i(235, 15);
    glVertex2i(230, 30);
    glVertex2i(225, 15);
    glVertex2i(215, 20);
    glVertex2i(220, 10);
    glEnd();


    glColor3ub (0, 255, 0);// boro grass 4
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 25);
    glVertex2i(325, 35);
    glVertex2i(315, 30);
    glVertex2i(310, 45);
    glVertex2i(305, 30);
    glVertex2i(295, 35);
    glVertex2i(300, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 5
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(410, 10);
    glVertex2i(415, 20);
    glVertex2i(405, 15);
    glVertex2i(400, 30);
    glVertex2i(395, 15);
    glVertex2i(385, 20);
    glVertex2i(390, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 6
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(490, 25);
    glVertex2i(495, 35);
    glVertex2i(485, 30);
    glVertex2i(480, 45);
    glVertex2i(475, 30);
    glVertex2i(465, 35);
    glVertex2i(470, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 7
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(570, 10);
    glVertex2i(575, 20);
    glVertex2i(565, 15);
    glVertex2i(560, 30);
    glVertex2i(555, 15);
    glVertex2i(545, 20);
    glVertex2i(550, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 8
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(660, 25);
    glVertex2i(665, 35);
    glVertex2i(655, 30);
    glVertex2i(650, 45);
    glVertex2i(645, 30);
    glVertex2i(635, 35);
    glVertex2i(640, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 9
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(750, 10);
    glVertex2i(755, 20);
    glVertex2i(745, 15);
    glVertex2i(740, 30);
    glVertex2i(735, 15);
    glVertex2i(725, 20);
    glVertex2i(730, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 10
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(830, 25);
    glVertex2i(835, 35);
    glVertex2i(825, 30);
    glVertex2i(820, 45);
    glVertex2i(815, 30);
    glVertex2i(805, 35);
    glVertex2i(810, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 11
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(910, 10);
    glVertex2i(915, 20);
    glVertex2i(905, 15);
    glVertex2i(900, 30);
    glVertex2i(895, 15);
    glVertex2i(885, 20);
    glVertex2i(890, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 12
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 25);
    glVertex2i(1005, 35);
    glVertex2i(995, 30);
    glVertex2i(990, 45);
    glVertex2i(985, 30);
    glVertex2i(975, 35);
    glVertex2i(980, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 13
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1090, 10);
    glVertex2i(1095, 20);
    glVertex2i(1085, 15);
    glVertex2i(1080, 30);
    glVertex2i(1075, 15);
    glVertex2i(1065, 20);
    glVertex2i(1070, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 14
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1180, 25);
    glVertex2i(1185, 35);
    glVertex2i(1175, 30);
    glVertex2i(1170, 45);
    glVertex2i(1165, 30);
    glVertex2i(1155, 35);
    glVertex2i(1160, 25);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 15
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1270, 10);
    glVertex2i(1275, 20);
    glVertex2i(1265, 15);
    glVertex2i(1260, 30);
    glVertex2i(1255, 15);
    glVertex2i(1245, 20);
    glVertex2i(1250, 10);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 16
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 25);
    glVertex2i(1355, 35);
    glVertex2i(1345, 30);
    glVertex2i(1340, 45);
    glVertex2i(1335, 30);
    glVertex2i(1325, 35);
    glVertex2i(1330, 25);
    glEnd();

    glColor3ub (0, 100, 0);// Field
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 130);
    glVertex2i(1400, 400);
    glVertex2i(0, 400);
    glVertex2i(0, 130);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 17
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 225);
    glVertex2i(1355, 235);
    glVertex2i(1345, 230);
    glVertex2i(1340, 245);
    glVertex2i(1335, 230);
    glVertex2i(1325, 235);
    glVertex2i(1330, 225);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 18
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1270, 210);
    glVertex2i(1275, 220);
    glVertex2i(1265, 215);
    glVertex2i(1260, 230);
    glVertex2i(1255, 215);
    glVertex2i(1245, 220);
    glVertex2i(1250, 210);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 19
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1090, 210);
    glVertex2i(1095, 220);
    glVertex2i(1085, 215);
    glVertex2i(1080, 230);
    glVertex2i(1075, 215);
    glVertex2i(1065, 220);
    glVertex2i(1070, 210);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 20
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 225);
    glVertex2i(1005, 235);
    glVertex2i(995, 230);
    glVertex2i(990, 245);
    glVertex2i(985, 230);
    glVertex2i(975, 235);
    glVertex2i(980, 225);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 21
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1350, 370);
    glVertex2i(1355, 380);
    glVertex2i(1345, 375);
    glVertex2i(1340, 390);
    glVertex2i(1335, 375);
    glVertex2i(1325, 380);
    glVertex2i(1330, 370);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 22
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1240, 370);
    glVertex2i(1245, 380);
    glVertex2i(1235, 375);
    glVertex2i(1230, 390);
    glVertex2i(1225, 375);
    glVertex2i(1215, 380);
    glVertex2i(1220, 370);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 23
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1110, 370);
    glVertex2i(1115, 380);
    glVertex2i(1105, 375);
    glVertex2i(1100, 390);
    glVertex2i(1095, 375);
    glVertex2i(1085, 380);
    glVertex2i(1090, 370);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 24
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 370);
    glVertex2i(1005, 380);
    glVertex2i(995, 375);
    glVertex2i(990, 390);
    glVertex2i(985, 375);
    glVertex2i(975, 380);
    glVertex2i(980, 370);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 25
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(490, 370);
    glVertex2i(495, 380);
    glVertex2i(485, 375);
    glVertex2i(480, 390);
    glVertex2i(475, 375);
    glVertex2i(465, 380);
    glVertex2i(470, 370);
    glEnd();

    glColor3ub (0, 255, 0);// boro grass 26
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 370);
    glVertex2i(325, 380);
    glVertex2i(315, 375);
    glVertex2i(310, 390);
    glVertex2i(305, 375);
    glVertex2i(295, 380);
    glVertex2i(300, 370);
    glEnd();


    TrainForwardMove();
    TrainBackwardMove();

    glColor3ub (105, 105, 105);// Garage road
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(645, 130);
    glVertex2i(820, 130);
    glVertex2i(850, 150);
    glVertex2i(675, 150);
    glEnd();

    glColor3ub (210,180,140);// Main Door road
    glPointSize(5.0);
    glBegin(GL_QUADS);
    glVertex2i(510, 130);
    glVertex2i(635, 130);
    glVertex2i(665, 150);
    glVertex2i(535, 150);

    glEnd();

    glColor3ub (105, 105, 105);// Road Behind
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(1400, 295);
    glVertex2i(1400, 355);
    glVertex2i(0, 355);
    glVertex2i(0, 295);
    glEnd();

    glColor3ub (255, 255, 255);// Road divider Behind
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(0, 330);
    glVertex2i(50, 330);

    glVertex2i(100, 330);
    glVertex2i(150, 330);

    glVertex2i(200, 330);
    glVertex2i(250, 330);

    glVertex2i(300, 330);
    glVertex2i(350, 330);

    glVertex2i(400, 330);
    glVertex2i(450, 330);

    glVertex2i(500, 330);
    glVertex2i(550, 330);

    glVertex2i(600, 330);
    glVertex2i(650, 330);

    glVertex2i(700, 330);
    glVertex2i(750, 330);

    glVertex2i(800, 330);
    glVertex2i(850, 330);

    glVertex2i(900, 330);
    glVertex2i(950, 330);

    glVertex2i(1000, 330);
    glVertex2i(1050, 330);

    glVertex2i(1100, 330);
    glVertex2i(1150, 330);

    glVertex2i(1200,330);
    glVertex2i(1250, 330);


    glVertex2i(1300, 330);
    glVertex2i(1350,330);


    glVertex2i(1400, 330);
    glVertex2i(1450, 330);
    glEnd();
    MetroRailBridge();//Bridge Implement


    glColor3ub (105, 105, 105);// Road
    glPointSize(5.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 50);
    glVertex2i(1400, 50);
    glVertex2i(1400, 130);
    glVertex2i(0, 130);
    glEnd();



    glColor3ub (255, 255, 255);// Road divider 1
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2i(0, 90);
    glVertex2i(50, 90);

    glVertex2i(100, 90);
    glVertex2i(150, 90);

    glVertex2i(200, 90);
    glVertex2i(250, 90);

    glVertex2i(300, 90);
    glVertex2i(350, 90);

    glVertex2i(400, 90);
    glVertex2i(450, 90);

    glVertex2i(500, 90);
    glVertex2i(550, 90);

    glVertex2i(600, 90);
    glVertex2i(650, 90);

    glVertex2i(700, 90);
    glVertex2i(750, 90);

    glVertex2i(800, 90);
    glVertex2i(850, 90);

    glVertex2i(900, 90);
    glVertex2i(950, 90);

    glVertex2i(1000, 90);
    glVertex2i(1050, 90);

    glVertex2i(1100, 90);
    glVertex2i(1150, 90);

    glVertex2i(1200, 90);
    glVertex2i(1250, 90);


    glVertex2i(1300, 90);
    glVertex2i(1350, 90);


    glVertex2i(1400, 90);
    glVertex2i(1450, 90);
    glEnd();

    cloud();
    cloud2();
    if(nightstatus==1)
    {
        BirdMoving();
    }
    HouseBuildup();
    GarageFunc();
    light();
    Tree();
    bulbAnimation();
    bulbAnimation2();
    bulbAnimation3();
    bulbAnimation4();
    bulbAnimation5();
    bulbAnimation6();
    bulbAnimation7();
    bulbAnimation8();
    bulbAnimation9();
    table();
    Wall();

    bulbAnimation10();
    bulbAnimation11();
    bulbAnimation12();
    bulbAnimation13();
    AmbuAnim();
    CarMoving();

    glFlush ();

    glutPostRedisplay();
    glutSwapBuffers();
}

void myInit (void)
{
    glClearColor(0.0, 0.4, 0.7, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1400.0, 0.0, 800.0);
}

void KeyBoard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'n':    //n for day/night
        if(nightstatus==1)
        {
            nightstatus=0;
        }
        else
        {
            nightstatus=1;
        }
        break;
    case 'g':    //n for day/night
        if(GarageStatus==1)
        {
            GarageStatus=0;
        }
        else
        {
            GarageStatus=1;
        }
        break;

    case 'c':
        if(cloudStatus==1)
        {
            cloudStatus=0;
        }
        else
        {
            cloudStatus=1;
        }
        break;
    case 'd':
        if(trainstatus==0||trainstatus==2)
        {
            trainstatus=1;
        }
        train_Speed+=.5;

        sndPlaySound("2.wav",SND_ASYNC);

        break;

    case 's':
        if(trainstatus==1||trainstatus==2)
        {
            trainstatus=0;
        }
        sndPlaySound(NULL,SND_ASYNC);
        break;

    case 'a':
        if(trainstatus==0||trainstatus==1)
        {
            trainstatus=2;
        }

        train_Speed+=0.5;
        break;
    case 'r':
        rainday = true;
        Rain(_rain);
        sndPlaySound("rain.wav",SND_ASYNC);
        break;
    case 'p':
        sndPlaySound("3.wav",SND_ASYNC);
        break;

    case 't':
        rainday = false;
        sndPlaySound(NULL,SND_ASYNC);
        break;

    default:
        break;
    }
}


int main(int argc, char** argv)
{
    cout<<"Press n : For day & night mode"<<endl;
    cout<<"Press r : For rain"<<endl;
    cout<<"Press t : For stop raining"<<endl;
    cout<<"Press c : cloud control"<<endl;
    cout<<"Press g : Garage open and close"<<endl;
    cout<<"Press d : Train Move Forward "<<endl;
    cout<<"Press a : Train Move Backward "<<endl;
    cout<<"Press s : Stop Train"<<endl;
    cout<<"Press p : Vehicle Horn."<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1400, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Matrimonial House");
    glutKeyboardFunc(KeyBoard);
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
