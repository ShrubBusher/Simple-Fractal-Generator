#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "main.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{

    Q_OBJECT

public:
    GLWidget(QWidget *parent=nullptr);

    /*OPENGL FUNCTIONS**********************************************************/
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void paint(int iterator, int fractal);

    /*DRAW FUNCTIONS************************************************************/
    void DrawLevyCurve(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, int iterator);
    void DrawTSquare(GLfloat xCenter, GLfloat yCenter, GLfloat length, int iterator);
    void DrawKochCurve(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLint iterator);
    void DrawSierpinskiTriangle(GLfloat *a, GLfloat *b, GLfloat *c, int iterator);
    void DrawSierpinskiCarpet(GLfloat xCenter, GLfloat yCenter, GLfloat length, int iterator);

private slots:
    void Change_Iterator(int value);
    void Change_Fractal(int value);  
};

#endif // GLWIDGET_H
