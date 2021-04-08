// gcc init.c -c -o init.o
#include "init.h"


extern GLfloat z;
extern GLfloat xrot;   
extern GLfloat yrot; 
GLuint blend = 1;
extern GLuint light;
extern GLuint textures[]; 
extern bool lumPos;

int window;

GLvoid redimensionnement(GLsizei Width, GLsizei Height)
{
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0f, (GLfloat)Width/(GLfloat)Height, 1.0f, 300.0f);
    glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char** argv, void (*Modelisation)())
{
    glutInit(&argc ,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    //glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    window = glutCreateWindow("openGL");
    glutFullScreen();

    glutDisplayFunc(Modelisation);
    glutIdleFunc(Modelisation); 
    glutReshapeFunc(&redimensionnement);
    glutKeyboardFunc(&touche_pressee);
    glutSpecialFunc(&touche_speciale_pressee);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHT5);
    glDisable(GL_LIGHT6);
    glDisable(GL_LIGHT7);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHT0);
    GLfloat bleu[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, bleu);

    glEnable(GL_LIGHT1);
    GLfloat LampeDirectionnelle[4];
    LampeDirectionnelle[0] = 0.0; LampeDirectionnelle[1] = 0.0f; LampeDirectionnelle[2] = 0.0f;
    LampeDirectionnelle[3] = 0.0f;
    glLightfv(GL_LIGHT1, GL_POSITION, LampeDirectionnelle);

    if(lumPos == true){
        glEnable(GL_LIGHT2);
        GLfloat directionPositionnelle[4];
        directionPositionnelle[0] = 5.0; directionPositionnelle[1] = 1.0f; directionPositionnelle[2] = 0.0f;
        directionPositionnelle[3] = 1.0f;
        glLightfv(GL_LIGHT2, GL_POSITION, directionPositionnelle);
    }
    
    glGenTextures(1, textures);
    {
        TEXTURE_STRUCT * brown = readPpm("brown.ppm");
        glBindTexture(GL_TEXTURE_2D, textures[0]);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, brown->width, brown->height, 0, GL_RGB, GL_UNSIGNED_BYTE,  brown->data);
        free(brown->data);
        free(brown);
    }

    glutMainLoop();

    return 1;
}