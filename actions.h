#ifndef __ACTIONS
#define __ACTIONS

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "touches.h"
#include <stdbool.h>

#define OBJET 1
#define CAMERA 2

void touche_pressee(unsigned char key, int x, int y);
void touche_speciale_pressee(int key, int x, int y);
#endif
