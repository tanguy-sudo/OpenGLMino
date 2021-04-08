
#ifndef __MINOTAURE
#define __MINOTAURE

#include <GL/gl.h>
#include <math.h>
#include <stdbool.h>
#include <GL/glut.h>
#include "cube.1.h"

#define SOLID_CLOSED_CYLINDER(QUAD, BASE, TOP, HEIGHT, SLICES, STACKS) \
gluCylinder(QUAD, BASE, TOP, HEIGHT, SLICES, STACKS); \
glRotatef(180, 1,0,0); \
gluDisk(QUAD, 0.0f, BASE, SLICES, 1); \
glRotatef(180, 1,0,0); \
glTranslatef(0.0f, 0.0f, HEIGHT); \
gluDisk(QUAD, 0.0f, TOP, SLICES, 1); \
glTranslatef(0.0f, 0.0f, -HEIGHT);

GLvoid Rectangle(GLfloat x, GLfloat y, GLfloat z);
GLvoid Cylindre(GLfloat x, GLfloat y, GLfloat z);
GLvoid sol(GLfloat x, GLfloat y, GLfloat z);
GLvoid Jambe(GLfloat proportion, GLfloat taille_jambe, GLfloat angle_hanche, GLfloat angle_genou, GLfloat angle_cheville, GLfloat angle_pied);
GLvoid Paume(GLfloat x, GLfloat y, GLfloat z);
GLvoid Doigt(GLfloat angle,
             GLfloat angle_phalange_phalangine,
             GLfloat angle_phalangine_phalangette,
             GLfloat proportion,
             GLfloat taille_doigt);
GLvoid Pouce(GLfloat angle,
             GLfloat angle_phalange_phalangine,
             GLfloat angle_phalangine_phalangette,
             GLfloat proportion,
             GLfloat taille_doigt);
GLvoid hand(GLfloat largeur_paume, 
            GLfloat longueur_paume, 
            GLfloat taille_doigt, 
            bool i, 
            GLfloat angle_paume, 
            GLfloat angle_phalange_phalangine, 
            GLfloat angle_phalangine_phalangette,
            GLfloat angle_pouce_paume, 
            GLfloat angle_pouce_phalange_phalangine, 
            GLfloat angle_pouce_phalangine_phalangette);
GLvoid bras(GLfloat proportion, 
            GLfloat taille_bras, 
            GLfloat angle_epaule, 
            GLfloat angle_coude, 
            bool i,
            GLfloat angle_paume,
            GLfloat angle_phalange_phalangine,
            GLfloat angle_phalangine_phalangette,
            GLfloat angle_pouce_paume,
            GLfloat angle_pouce_phalange_phalangine,
            GLfloat angle_pouce_phalangine_phalangette
);
GLvoid Corps(GLfloat proportion, GLfloat taille_corps);

#endif
