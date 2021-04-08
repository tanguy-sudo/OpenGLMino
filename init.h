#ifndef __INIT
#define __INIT

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "touches.h"
#include "lumiere.h"
#include "actions.h"
#include "ppm.h"


int notre_init(int argc, char** argv, void (*DrawGLScene)());
GLvoid redimensionnement(GLsizei Width, GLsizei Height);
int notre_init(int argc, char** argv, void (*Modelisation)());
#endif
