// gcc main.c *.o -lGL -lGLU -lglut -lm -o main

#include <GL/glut.h>    
#include <GL/gl.h>	
#include "cube.1.h"
#include "actions.h"
#include "minotaure.h"
#include "init.h"
#include "VM_init.h"

int window;
GLuint textures[1]; 

GLfloat xtrans = 0.0f; 
GLfloat ytrans = -10.0f;
GLfloat ztrans = -40.0f; 
GLuint  light = 0;
GLfloat yrot = 0.0;

GLfloat xrot_objet = 0.0;
GLfloat yrot_objet = 0.0;
GLfloat zrot_objet = 0.0;

int etat = CAMERA;

bool autoMouv = false;

bool lumPos = true;
bool a = true;

//position minotaure
GLfloat position_z_minotaure = 0.0f;
GLfloat position_x_minotaure = 0.0f;
GLfloat rotation_minotaure = 0.0f;

// jambe droite
GLfloat angle_hanche_droite = 210.0f;
GLfloat angle_genou_droit = -90.0f;
GLfloat angle_cheville_droite = 90.0f;
GLfloat angle_pied_droit = 60.0f;

// jambe gauche
GLfloat angle_hanche_gauche = 210.0f; // 210.0f (base) // 230.0f (limite)
GLfloat angle_genou_gauche = -90.0f;  // -90.0f (base) // -70.0f (limite)
GLfloat angle_cheville_gauche = 90.0f; // 90.0f (base) // 70.0f (limite)
GLfloat angle_pied_gauche = 60.0f; // 60.0f (base) // 40.0f (limite)

// bras gauche
GLfloat angle_epaule_gauche = 190.0f;
GLfloat angle_coude_gauche = 50.0f;

// bras droite
GLfloat angle_epaule_droite = 190.0f;
GLfloat angle_coude_droite = 50.0f;

// main gauche
GLfloat angle_paume_droite = 0.0f;
GLfloat angle_phalange_phalangine_droite = 0.0f;
GLfloat angle_phalangine_phalangette_droite = 0.0f;
GLfloat angle_pouce_paume_droite = 0.0f;
GLfloat angle_pouce_phalange_phalangine_droite = 0.0f;
GLfloat angle_pouce_phalangine_phalangette_droite = 0.0f;

// main droite
GLfloat angle_paume_gauche = 0.0f;
GLfloat angle_phalange_phalangine_gauche = 0.0f;
GLfloat angle_phalangine_phalangette_gauche = 0.0f;
GLfloat angle_pouce_paume_gauche = 0.0f;
GLfloat angle_pouce_phalange_phalangine_gauche = 0.0f;
GLfloat angle_pouce_phalangine_phalangette_gauche = 0.0f;



GLvoid Minotaure(GLfloat position_z_minotaure, GLfloat rotation_minotaure, GLfloat position_x_minotaure)
{
  GLfloat proportionCorps = 20.0f;
  GLfloat tailleCorps = 10.0f;
  GLfloat proportionJambe = 5.0f;
  GLfloat tailleJambe = 2.0f;

  glTranslatef(position_x_minotaure, 0.0f, position_z_minotaure);
  glRotatef(rotation_minotaure, 0.0f, 0.1f, 0.0f);
  
  //jambe gauche
  Jambe(proportionJambe, tailleJambe, angle_hanche_gauche, angle_genou_gauche, angle_cheville_gauche, angle_pied_gauche); 
  glTranslatef(8.0f, 0.0f, 0.0f);
  //jambe droite
  Jambe(proportionJambe, tailleJambe, angle_hanche_droite, angle_genou_droit, angle_cheville_droite, angle_pied_droit); 

  glTranslatef(-4.0f, 0.0f, 0.0f);
  //corps
  Corps(proportionCorps, tailleCorps); //corps

  glTranslatef(6.0f, proportionCorps*1.30f, 0.0f);
  bool i = true;
  //bras droit
  bras(5.0f, 2.0f, 
      angle_epaule_droite, 
      angle_coude_droite, 
      i,
      angle_paume_droite,
      angle_phalange_phalangine_droite,
      angle_phalangine_phalangette_droite,
      angle_pouce_paume_droite,
      angle_pouce_phalange_phalangine_droite,
      angle_pouce_phalangine_phalangette_droite);
  glTranslatef(-12.0f, 0.0f, 0.0f);
  i = false;
  //bras gauche
  bras(5.0f, 2.0f, 
      angle_epaule_gauche, 
      angle_coude_gauche, 
      i,
      angle_paume_gauche,
      angle_phalange_phalangine_gauche,
      angle_phalangine_phalangette_gauche,
      angle_pouce_paume_gauche,
      angle_pouce_phalange_phalangine_gauche,
      angle_pouce_phalangine_phalangette_gauche);

}

GLvoid autoMouvement()
{
  if(a == true){
            if(angle_hanche_gauche < 230.0f) angle_hanche_gauche += 1.0f;
            if(angle_genou_gauche < -70.0f) angle_genou_gauche += 1.0f;
            if(angle_cheville_gauche > 70.0f) angle_cheville_gauche -= 1.0f;
            if(angle_pied_gauche > 40.0f) angle_pied_gauche -= 2.0f;

            if(angle_epaule_gauche < 230.0f) angle_epaule_gauche += 3.0f;

            if(angle_hanche_droite > 210.0f) angle_hanche_droite -= 1.0f;
            if(angle_genou_droit > -90.0f) angle_genou_droit -= 1.0f;
            if(angle_cheville_droite < 90.0f) angle_cheville_droite += 1.0f;
            if(angle_pied_droit < 60.0f) angle_pied_droit += 1.0f;

            if(angle_epaule_droite > 150.0f) angle_epaule_droite -= 3.0f;

            if(rotation_minotaure == 0.0f && position_z_minotaure > -93.0f) position_z_minotaure -= 0.2f;
            if((rotation_minotaure == -90.0f || rotation_minotaure == 270.0f) && position_x_minotaure < 93.0f) position_x_minotaure += 0.2f;
            if((rotation_minotaure == -180.0f || rotation_minotaure == 180.0f) && position_z_minotaure < 93.0f) position_z_minotaure += 0.2f;
            if((rotation_minotaure == -270.0f || rotation_minotaure == 90.0f) && position_x_minotaure > -93.0f) position_x_minotaure -= 0.2f;

            if(position_z_minotaure <= -93.0f) rotation_minotaure = 180.0f;
            if(position_z_minotaure >= 93.0f) rotation_minotaure = 0.0f;
            if(position_x_minotaure >= 93.0f) rotation_minotaure = 90.0f;
            if(position_x_minotaure <= -93.0f) rotation_minotaure = 270.0f;

            if(angle_hanche_gauche == 230.0f && angle_genou_gauche == -70.0f && angle_cheville_gauche == 70.0f && angle_pied_gauche == 40.0f){
              a = false;          
            }

  }else{
            if(angle_hanche_droite < 230.0f) angle_hanche_droite += 1.0f;
            if(angle_genou_droit < -70.0f) angle_genou_droit += 1.0f;
            if(angle_cheville_droite > 70.0f) angle_cheville_droite -= 1.0f;
            if(angle_pied_droit > 40.0f) angle_pied_droit -= 1.0f;

            if(angle_epaule_droite < 230.0f) angle_epaule_droite += 3.0f;
              
            if(angle_hanche_gauche > 210.0f) angle_hanche_gauche -= 1.0f;
            if(angle_genou_gauche > -90.0f) angle_genou_gauche -= 1.0f;
            if(angle_cheville_gauche < 90.0f) angle_cheville_gauche += 1.0f;
            if(angle_pied_gauche < 60.0f) angle_pied_gauche += 1.0f;

            if(angle_epaule_gauche > 150.0f) angle_epaule_gauche -= 3.0f;

            if(rotation_minotaure == 0.0f && position_z_minotaure > -93.0f) position_z_minotaure -= 0.2f;
            if((rotation_minotaure == -90.0f || rotation_minotaure == 270.0f) && position_x_minotaure < 93.0f) position_x_minotaure += 0.2f;
            if((rotation_minotaure == -180.0f || rotation_minotaure == 180.0f) && position_z_minotaure < 93.0f) position_z_minotaure += 0.2f;
            if((rotation_minotaure == -270.0f || rotation_minotaure == 90.0f) && position_x_minotaure > -93.0f) position_x_minotaure -= 0.2f;

            if(position_z_minotaure <= -93.0f) rotation_minotaure = 180.0f;
            if(position_z_minotaure >= 93.0f) rotation_minotaure = 0.0f;
            if(position_x_minotaure >= 93.0f) rotation_minotaure = 90.0f;
            if(position_x_minotaure <= -93.0f) rotation_minotaure = 270.0f;

            if(angle_hanche_droite == 230.0f && angle_genou_droit == -70.0f && angle_cheville_droite == 70.0f && angle_pied_droit == 40.0f){
              a = true;
            }
  }
}

GLvoid Modelisation()
{
  VM_init();

  glMatrixMode(GL_MODELVIEW);

  glTranslatef(xtrans, ytrans, ztrans);   
  glRotatef(yrot, 0.0f, 0.1f, 0.0f);
	
  GLfloat largeur_sol = 200.0;
  GLfloat longueur_sol = 200.0;

  //sol
  glPushMatrix();
  { 
    sol(longueur_sol, 1.0, largeur_sol);
  }
  glPopMatrix();

  if(autoMouv == true){ autoMouvement(); }
        
  //Minotaure
  glRotatef(180.0f, 0.0f, 0.1f, 0.0f);
  glTranslatef(0.0f, 1.0f, 0.0f);
  glPushMatrix();
  {
    glRotatef(xrot_objet,1.0f,0.0f,0.0f);
    glRotatef(yrot_objet,0.0f,1.0f,0.0f);
    glRotatef(zrot_objet,0.0f,0.0f,1.0f);

    Minotaure(position_z_minotaure, rotation_minotaure, position_x_minotaure);
  }
  glPopMatrix();

  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
