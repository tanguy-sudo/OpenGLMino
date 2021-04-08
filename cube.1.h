#ifndef __CUBE1
#define __CUBE1

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern GLuint textures[]; 

// 0 : avant, 1 : arriere, 2 : droit, 3 : gauche, 4 : dessus, 5 : dessous
static int faces[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}};
static int sommets[][3] = {{0, 3, 5}, {0, 2, 5}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {1, 3, 4}, {1, 2, 4}};

struct coordonnees {
  float x;
  float y;
  float z;
  
};

struct couleur {
  float r;
  float v;
  float b;
  float alpha;
};


struct sommet {
  struct coordonnees coordonnees;
};

struct face {
  struct couleur couleur;
};

struct cube {
  float longueur_arrete;
  struct sommet * sommets[8];
  struct face * faces[6];
};


struct cube * charge_cube(float longueur_arrete, struct cube * un_cube);

struct cube * cree_cube(float longueur_arrete);

void affiche_cube(struct cube * un_cube);
#endif
