// gcc VM_init.c -c -o VM_init.o
#include "VM_init.h"

//extern GLfloat xtrans; // translation x
//extern GLfloat ytrans;  // translation y
//extern GLfloat ztrans;  // translation z

void VM_init()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 100.0f, 255.0f, 0);
    glLoadIdentity();
}