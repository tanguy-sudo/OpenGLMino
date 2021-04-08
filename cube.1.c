#include "cube.1.h"

struct cube * charge_cube(float longueur_arrete, struct cube * un_cube) {
  float demi_longueur_arrete = longueur_arrete/2;

  un_cube->longueur_arrete = longueur_arrete;

  {
    int i = 0;
    for (i = 0; i <= 7; i++) {
      un_cube->sommets[i] = (struct sommet *)malloc(sizeof(struct sommet));
    }
  }
  {
    int i = 0;
    for (i = 0; i <= 5; i++) {
      un_cube->faces[i] = (struct face *)malloc(sizeof(struct face));
    }
  }


  un_cube->faces[0]->couleur.r = 1.0;  
  un_cube->faces[0]->couleur.v = 0.0;  
  un_cube->faces[0]->couleur.b = 0.0;   
  un_cube->faces[0]->couleur.alpha = 0.5;

  un_cube->faces[1]->couleur.r = 0.0;  
  un_cube->faces[1]->couleur.v = 1.0;  
  un_cube->faces[1]->couleur.b = 0.0;   
  un_cube->faces[1]->couleur.alpha = 0.5;

  un_cube->faces[2]->couleur.r = 0.0;  
  un_cube->faces[2]->couleur.v = 0.0;  
  un_cube->faces[2]->couleur.b = 1.0;   
  un_cube->faces[2]->couleur.alpha = 0.5;

  un_cube->faces[3]->couleur.r = 1.0;  
  un_cube->faces[3]->couleur.v = 1.0;  
  un_cube->faces[3]->couleur.b = 0.0;   
  un_cube->faces[3]->couleur.alpha = 0.5;

  un_cube->faces[4]->couleur.r = 1.0;  
  un_cube->faces[4]->couleur.v = 0.0;  
  un_cube->faces[4]->couleur.b = 1.0;   
  un_cube->faces[4]->couleur.alpha = 0.5;

  un_cube->faces[5]->couleur.r = 0.0;  
  un_cube->faces[5]->couleur.v = 1.0;  
  un_cube->faces[5]->couleur.b = 1.0;   
  un_cube->faces[5]->couleur.alpha = 0.5;

  un_cube->sommets[0]->coordonnees.x = -demi_longueur_arrete;
  un_cube->sommets[0]->coordonnees.y = -demi_longueur_arrete;
  un_cube->sommets[0]->coordonnees.z = demi_longueur_arrete;
  
  un_cube->sommets[1]->coordonnees.x = demi_longueur_arrete; 
  un_cube->sommets[1]->coordonnees.y = -demi_longueur_arrete; 
  un_cube->sommets[1]->coordonnees.z = demi_longueur_arrete; 

  un_cube->sommets[2]->coordonnees.x = demi_longueur_arrete; 
  un_cube->sommets[2]->coordonnees.y = demi_longueur_arrete; 
  un_cube->sommets[2]->coordonnees.z = demi_longueur_arrete; 

  un_cube->sommets[3]->coordonnees.x = -demi_longueur_arrete; 
  un_cube->sommets[3]->coordonnees.y = demi_longueur_arrete; 
  un_cube->sommets[3]->coordonnees.z = demi_longueur_arrete; 

  un_cube->sommets[4]->coordonnees.x = demi_longueur_arrete; 
  un_cube->sommets[4]->coordonnees.y = -demi_longueur_arrete; 
  un_cube->sommets[4]->coordonnees.z = -demi_longueur_arrete; 

  un_cube->sommets[5]->coordonnees.x = -demi_longueur_arrete; 
  un_cube->sommets[5]->coordonnees.y = -demi_longueur_arrete; 
  un_cube->sommets[5]->coordonnees.z = -demi_longueur_arrete; 

  un_cube->sommets[6]->coordonnees.x = -demi_longueur_arrete; 
  un_cube->sommets[6]->coordonnees.y = demi_longueur_arrete; 
  un_cube->sommets[6]->coordonnees.z = -demi_longueur_arrete;  

  un_cube->sommets[7]->coordonnees.x = demi_longueur_arrete; 
  un_cube->sommets[7]->coordonnees.y = demi_longueur_arrete; 
  un_cube->sommets[7]->coordonnees.z = -demi_longueur_arrete; 
  
}


struct cube * cree_cube(float longueur_arrete) {

  struct cube * un_cube = (struct cube *)malloc(sizeof(struct cube));
  charge_cube(longueur_arrete, un_cube);
  return un_cube;
}


void affiche_cube(struct cube * un_cube) {
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture (GL_TEXTURE_2D, textures[0]);

  glBegin(GL_QUADS);
  {
    int j = 0;
    for (j = 0; j <= 5; j++) {
      //glColor4f(un_cube->faces[j]->couleur.r, un_cube->faces[j]->couleur.v, un_cube->faces[j]->couleur.b, un_cube->faces[j]->couleur.alpha);
      
        //int i = 0;
        //for (i = 0; i <= 3; i++) {
          glNormal3f(0.0,0.0,1.0);
          
          glTexCoord2f(0.0f, 1.0f); 
          glVertex3f(un_cube->sommets[faces[j][0]]->coordonnees.x,un_cube->sommets[faces[j][0]]->coordonnees.y,un_cube->sommets[faces[j][0]]->coordonnees.z);

          glTexCoord2f(1.0f, 1.0f); 
          glVertex3f(un_cube->sommets[faces[j][1]]->coordonnees.x,un_cube->sommets[faces[j][1]]->coordonnees.y,un_cube->sommets[faces[j][1]]->coordonnees.z);

          glTexCoord2f(1.0f, 0.0f); 
          glVertex3f(un_cube->sommets[faces[j][2]]->coordonnees.x,un_cube->sommets[faces[j][2]]->coordonnees.y,un_cube->sommets[faces[j][2]]->coordonnees.z);

          glTexCoord2f(0.0f, 0.0f); 
          glVertex3f(un_cube->sommets[faces[j][3]]->coordonnees.x,un_cube->sommets[faces[j][3]]->coordonnees.y,un_cube->sommets[faces[j][3]]->coordonnees.z);
        //}
      
    }
  }
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
  glPopMatrix();
}
