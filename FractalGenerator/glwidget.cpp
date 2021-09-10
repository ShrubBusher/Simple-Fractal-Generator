#include "glwidget.h"

//QObject::connect(horizontalSlider, &QSlider::valueChanged, label_3, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
{
}

static int gIterator = 0;
static int gFractal = 0;

/*DRAWING FUNCTIONS*************************************************************/
void GLWidget::DrawLevyCurve(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int iterator)
{
    std::cout << "Drawing levy curve... " << iterator << "\t" << __TIME__ << std::endl;

    if(iterator == 0)
    {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);

        return;
    }
    else
    {
        GLfloat xNew = (x1 + x2) / 2.0f - (y2 - y1) / 2.0f;
        GLfloat yNew = (y1 + y2) / 2.0f + (x2 - x1) / 2.0f;
        DrawLevyCurve(x1, y1, xNew, yNew, iterator - 1);
        DrawLevyCurve(xNew, yNew, x2, y2, iterator - 1);

        return;
    }
}

void GLWidget::DrawTSquare(GLfloat xCenter, GLfloat yCenter, GLfloat length, int iterator)
{
    std::cout << "Drawing t-square... " << iterator << "\t" << __TIME__ << std::endl;

    GLfloat x1 = xCenter - length / 2.0f;
    GLfloat x2 = xCenter + length / 2.0f;
    GLfloat y1 = yCenter - length / 2.0f;
    GLfloat y2 = yCenter + length / 2.0f;

    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);

    if(iterator > 0)
    {
        DrawTSquare(x1, y1, length / 2.0f, iterator - 1);
        DrawTSquare(x1, y2, length / 2.0f, iterator - 1);
        DrawTSquare(x2, y2, length / 2.0f, iterator - 1);
        DrawTSquare(x2, y1, length / 2.0f, iterator - 1);

        return;
    }

    return;
}

void GLWidget::DrawKochCurve(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLint iterator)
{
    std::cout << "Drawing koch curve... " << iterator << "\t" << __TIME__ << std::endl;

    //useless calculations
    GLfloat length = std::abs(x2-x1);
    GLfloat height = (length * sqrt(3)) / 2.0f;
    height++;

    GLfloat x3 = (2.0f * x1 + x2) / 3.0f;
    GLfloat y3 = (2.0f * y1 + y2) / 3.0f;
    GLfloat x4 = (x1 + 2.0f * x2) / 3.0f;
    GLfloat y4 = (y1 + 2.0f * y2) / 3.0f;

    GLfloat angle = 60.0f * (M_PI / 180.0f);
    GLfloat x = x1;
    GLfloat y = y1;

    if(iterator > 0)
    {
        GLfloat x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
        GLfloat y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

        DrawKochCurve(x1, y1, x3, y3, iterator - 1);
        DrawKochCurve(x3, y3, x, y, iterator - 1);
        DrawKochCurve(x, y, x4, y4, iterator - 1);
        DrawKochCurve(x4, y4, x2, y2, iterator - 1);
    }
    else
    {
        glVertex2f(x1, y1);
        glVertex2f(x3, y3);
        glVertex2f(x, y);
        glVertex2f(x4, y4);
        glVertex2f(x2, y2);

        return;
    }

}

void GLWidget::DrawSierpinskiTriangle(GLfloat *a, GLfloat *b, GLfloat *c, int iterator)
{
    std::cout << "Drawing sierpinski triangle... " << iterator << "\t" << __TIME__ << std::endl;

    GLfloat v0[2]{0}, v1[2]{0}, v2[2]{0};
    if(iterator > 0)
    {
        for(int i = 0; i < 2; i++)
        {
            v0[i] = (a[i] + b[i]) / 2.0f;
            v1[i] = (a[i] + c[i]) / 2.0f;
            v2[i] = (b[i] + c[i]) / 2.0f;
        }

        DrawSierpinskiTriangle(a, v0, v1, iterator - 1);
        DrawSierpinskiTriangle(c, v1, v2, iterator - 1);
        DrawSierpinskiTriangle(b, v2, v0, iterator - 1);

        return;
    }
    else
    {
        glVertex2fv(a);
        glVertex2fv(b);
        glVertex2fv(c);

        return;
    }
}

void GLWidget::DrawSierpinskiCarpet(GLfloat xCenter, GLfloat yCenter, GLfloat length, int iterator)
{
    std::cout << "Drawing sierpinski carpet... " << iterator << "\t" << __TIME__ << std::endl;

    GLfloat x1 = xCenter - length / 2.0f;
    GLfloat x2 = xCenter + length / 2.0f;
    GLfloat y1 = yCenter - length / 2.0f;
    GLfloat y2 = yCenter + length / 2.0f;

    glVertex2f(x1,y1);
    glVertex2f(x1,y2);
    glVertex2f(x2,y2);
    glVertex2f(x2,y1);

    if(iterator > 0)
    {
        DrawSierpinskiCarpet(xCenter, yCenter + length, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter + length, yCenter, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter, yCenter - length, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter - length, yCenter, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter + length, yCenter + length, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter + length, yCenter - length, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter - length, yCenter - length, length / 3.0f, iterator - 1);
        DrawSierpinskiCarpet(xCenter - length, yCenter + length, length / 3.0f, iterator - 1);

        return;
    }
}

/*OPENGL FUNCTIONS**************************************************************/
void GLWidget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400);
}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    paint(gIterator, gFractal);
    glFlush();
}

void GLWidget::resizeGL(int width, int height){
    resize(width,height);
}

void GLWidget::paint(int iterator, int fractal){

    GLfloat STcoordinates[3][2] ={ {-400, -400}, {0, 400}, {400, -400} };

    switch(fractal)
    {
    default:
        break;

    case 0:
        glBegin(GL_LINES);
        DrawLevyCurve(-200, 0, 200, 0, iterator);
        glEnd();
        break;

    case 1:
        glBegin(GL_LINES);
        DrawLevyCurve(-200, 0, 200, 0, iterator);
        DrawLevyCurve(200, 0, -200, 0, iterator);
        glEnd();
        break;

    case 2:
        glBegin(GL_QUADS);
        DrawTSquare(0, 0, 400, iterator);
        glEnd();
        break;

    case 3:
        glBegin(GL_LINE_STRIP);
        DrawKochCurve(400, 0, -400, 0, iterator);
        glEnd();
        break;

    case 4:
        glBegin(GL_LINE_STRIP);
        DrawKochCurve(400, 0, -400, 0, iterator);
        DrawKochCurve(-400, 0, 400, 0, iterator);
        glEnd();
        break;

    case 5:
        glBegin(GL_LINE_STRIP);
        DrawKochCurve(-325, 201.4582562299425601982100304947, 0, -361.4582562299425601982100304947, iterator);
        DrawKochCurve(0, -361.4582562299425601982100304947, 325, 201.4582562299425601982100304947, iterator);
        DrawKochCurve(325, 201.4582562299425601982100304947, -325, 201.4582562299425601982100304947, iterator);
        glEnd();
        break;

    case 6:
        //glPointSize(1.0f);
        //glEnable(GL_PROGRAM_POINT_SIZE);
        //glBegin(GL_POINTS);
        glBegin(GL_LINE_STRIP);
        //for length = 200 -> height = 173.20508075688772935274463415059
        //for length = 200 -> half-height = 86.602540378443864676372317075295

        //for length = 300 -> height = 259.80762113533159402911695122588
        //for length = 300 -> half-height = 129.90381056766579701455847561294

        //for length = 325 -> height = 281.4582562299425601982100304947
        //for length = 325 -> half-height = 140.72912811497128009910501524735

        //for length = 350 -> height = 303.10889132455352636730310976353
        //for length = 350 -> half-height = 151.55444566227676318365155488176

        //for length = 400 -> height = 346.41016151377545870548926830117
        //for length = 400 -> half-height = 173.20508075688772935274463415059

        //all Y coordinates are lowered by *** pixels (only for main snowflake, not inverse one)
        DrawKochCurve(-400, 346.41016151377545870548926830117, 400, 346.41016151377545870548926830117, iterator);
        DrawKochCurve(400, 346.41016151377545870548926830117, 0, -346.41016151377545870548926830117, iterator);
        DrawKochCurve(0, -346.41016151377545870548926830117, -400, 346.41016151377545870548926830117, iterator);
        glEnd();
        break;

    case 7:
        glBegin(GL_TRIANGLES);
        DrawSierpinskiTriangle(STcoordinates[0], STcoordinates[1], STcoordinates[2], iterator);
        glEnd();
        break;

    case 8:
        glBegin(GL_QUADS);
        DrawSierpinskiCarpet(0, 0, 266, iterator);
        glEnd();
        break;
    }

    return;
}

void GLWidget::Change_Iterator(int value)
{
    gIterator = value;

    return;
}

void GLWidget::Change_Fractal(int value)
{
    gFractal = value;

    return;
}
