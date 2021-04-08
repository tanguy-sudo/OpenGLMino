#include "actions.h"


extern bool lumPos;
extern bool autoMouv;

extern GLfloat xtrans;  
extern GLfloat ytrans; 
extern GLfloat ztrans; 

extern GLfloat xrot_objet;   
extern GLfloat yrot_objet;    
extern GLfloat zrot_objet;   

extern GLfloat yrot;

extern int etat; 
// Minotaure
extern GLfloat position_z_minotaure;
extern GLfloat position_x_minotaure;
extern GLfloat rotation_minotaure;

// jambe droite
extern GLfloat angle_hanche_droite; //E
extern GLfloat angle_genou_droit; 
extern GLfloat angle_cheville_droite;
extern GLfloat angle_pied_droit;

// jambe gauche
extern GLfloat angle_hanche_gauche; //A
extern GLfloat angle_genou_gauche; 
extern GLfloat angle_cheville_gauche;
extern GLfloat angle_pied_gauche;

extern GLfloat angle_epaule_droite; //X
extern GLfloat angle_epaule_gauche; //V
extern GLfloat angle_coude_droite; //W
extern GLfloat angle_coude_gauche; //C

// main gauche                     //B
extern GLfloat angle_paume_gauche;
extern GLfloat angle_phalange_phalangine_gauche;
extern GLfloat angle_phalangine_phalangette_gauche;
extern GLfloat angle_pouce_paume_gauche;
extern GLfloat angle_pouce_phalange_phalangine_gauche;
extern GLfloat angle_pouce_phalangine_phalangette_gauche;

// main droite                     // N
extern GLfloat angle_paume_droite;
extern GLfloat angle_phalange_phalangine_droite;
extern GLfloat angle_phalangine_phalangette_droite;
extern GLfloat angle_pouce_paume_droite;
extern GLfloat angle_pouce_phalange_phalangine_droite;
extern GLfloat angle_pouce_phalangine_phalangette_droite;

bool i = true;


void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    switch (key) {   
    
    case TOUCHE_MIN_L:
      if(lumPos == true) lumPos = false;
      if(lumPos == false) lumPos = true;
      break;

    case TOUCHE_MIN_M:
      if(autoMouv == true){
        autoMouv = false;
      } 
      else if(autoMouv == false){
        autoMouv = true;
      }
      break;

    case ESCAPE: 
      exit(1);                   	
      break; 

    case ESPACE:
      switch(etat) {
        case OBJET :
          etat = CAMERA;
          break;
        case CAMERA :
          etat = OBJET;
          break;
      }
      break;

    case TOUCHE_MIN_A:
      if(angle_hanche_gauche < 270.0) angle_hanche_gauche += 1.0f;
      break;
    case TOUCHE_MAJ_A:
      if(angle_hanche_gauche > 210.0) angle_hanche_gauche -= 1.0f;
      break;

    case TOUCHE_MIN_E:
      if(angle_hanche_droite < 270.0) angle_hanche_droite += 1.0f;
      break;
    case TOUCHE_MAJ_E:
      if(angle_hanche_droite > 210.0) angle_hanche_droite -= 1.0f;
      break;

    case TOUCHE_MIN_S:
        if(i == true){
          if(angle_hanche_gauche < 230.0f) angle_hanche_gauche += 1.0f;
          if(angle_genou_gauche < -70.0f) angle_genou_gauche += 1.0f;
          if(angle_cheville_gauche > 70.0f) angle_cheville_gauche -= 1.0f;
          if(angle_pied_gauche > 40.0f) angle_pied_gauche -= 1.0f;

          if(angle_epaule_gauche < 230.0f) angle_epaule_gauche += 3.0f;

          if(angle_hanche_droite > 210.0f) angle_hanche_droite -= 1.0f;
          if(angle_genou_droit > -90.0f) angle_genou_droit -= 1.0f;
          if(angle_cheville_droite < 90.0f) angle_cheville_droite += 1.0f;
          if(angle_pied_droit < 60.0f) angle_pied_droit += 1.0f;

          if(angle_epaule_droite > 150.0f) angle_epaule_droite -= 3.0f;

          if(rotation_minotaure == 0.0f && position_z_minotaure < 93.0f) position_z_minotaure += 0.2f;
          if((rotation_minotaure == -90.0f || rotation_minotaure == 270.0f) && position_x_minotaure > -93.0f) position_x_minotaure -= 0.2f;
          if((rotation_minotaure == -180.0f || rotation_minotaure == 180.0f) && position_z_minotaure > -93.0f) position_z_minotaure -= 0.2f;
          if((rotation_minotaure == -270.0f || rotation_minotaure == 90.0f) && position_x_minotaure < 93.0f) position_x_minotaure += 0.2f;

          if(angle_hanche_gauche == 230.0f && angle_genou_gauche == -70.0f && angle_cheville_gauche == 70.0f && angle_pied_gauche == 40.0f){
              i = false;          
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

            if(rotation_minotaure == 0.0f && position_z_minotaure < 93.0f) position_z_minotaure += 0.2f;
            if((rotation_minotaure == -90.0f || rotation_minotaure == 270.0f) && position_x_minotaure > -93.0f) position_x_minotaure -= 0.2f;
            if((rotation_minotaure == -180.0f || rotation_minotaure == 180.0f) && position_z_minotaure > -93.0f) position_z_minotaure -= 0.2f;
            if((rotation_minotaure == -270.0f || rotation_minotaure == 90.0f) && position_x_minotaure < 93.0f) position_x_minotaure += 0.2f;

            if(angle_hanche_droite == 230.0f && angle_genou_droit == -70.0f && angle_cheville_droite == 70.0f && angle_pied_droit == 40.0f){
              i = true;
            }
        }
      break;

    case TOUCHE_MIN_Z:
        if(i == true){
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


          if(angle_hanche_gauche == 230.0f && angle_genou_gauche == -70.0f && angle_cheville_gauche == 70.0f && angle_pied_gauche == 40.0f){
              i = false;          
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

            if(angle_hanche_droite == 230.0f && angle_genou_droit == -70.0f && angle_cheville_droite == 70.0f && angle_pied_droit == 40.0f){
              i = true;
            }
        }
      break;

    case TOUCHE_MIN_D:
      rotation_minotaure -= 90.0f;
      if(rotation_minotaure == -360.0f) rotation_minotaure = 0.0f;
      break;
    case TOUCHE_MIN_Q:
      rotation_minotaure += 90.0f;
       if(rotation_minotaure == 360.0f) rotation_minotaure = 0.0f;
      break;
    
    case TOUCHE_MIN_V:
      if(angle_epaule_droite < 300.0f) angle_epaule_droite += 1.0f;
      break;
    case TOUCHE_MAJ_V:
      if(angle_epaule_droite > 150.0f) angle_epaule_droite -= 1.0f;
      break;

    case TOUCHE_MIN_X:
      if(angle_epaule_gauche < 300.0f) angle_epaule_gauche += 1.0f;
      break;
    case TOUCHE_MAJ_X:
      if(angle_epaule_gauche > 150.0f) angle_epaule_gauche -= 1.0f;
      break;
    
    case TOUCHE_MIN_C:
      if(angle_coude_droite < 140.0f) angle_coude_droite += 1.0f;
      break;
    case TOUCHE_MAJ_C:
      if(angle_coude_droite > 0.0f) angle_coude_droite -= 1.0f;
      break;

    case TOUCHE_MIN_W:
      if(angle_coude_gauche < 140.0f) angle_coude_gauche += 1.0f;
      break;
    case TOUCHE_MAJ_W:
      if(angle_coude_gauche > 0.0f) angle_coude_gauche -= 1.0f;
      break;
    
    case TOUCHE_MIN_N:
      // main droite
      if(angle_paume_droite > -90.0) angle_paume_droite -= 1.0f;
      if(angle_phalange_phalangine_droite > -90.0) angle_phalange_phalangine_droite -= 1.0f;   
      if(angle_phalangine_phalangette_droite > -90.0) angle_phalangine_phalangette_droite -= 1.0f; 
      if(angle_paume_droite < -20.0f){
              if(angle_pouce_paume_droite > -40.0) angle_pouce_paume_droite -= 1.0f;
              if(angle_pouce_phalange_phalangine_droite < 70.0) angle_pouce_phalange_phalangine_droite += 1.0f;
              if(angle_pouce_phalangine_phalangette_droite < 50.0) angle_pouce_phalangine_phalangette_droite += 1.0f;
      }
      break;
    case TOUCHE_MAJ_N:
      // main droite
      if(angle_paume_droite < 0.0f) angle_paume_droite += 1.0f;
      if(angle_phalange_phalangine_droite < 0.0f) angle_phalange_phalangine_droite += 1.0f;   
      if(angle_phalangine_phalangette_droite < 0.0f) angle_phalangine_phalangette_droite += 1.0f; 
      if(angle_pouce_paume_droite < 0.0f) angle_pouce_paume_droite += 1.0f;
      if(angle_pouce_phalange_phalangine_droite > 0.0f) angle_pouce_phalange_phalangine_droite -= 1.0f;
      if(angle_pouce_phalangine_phalangette_droite > 0.0f) angle_pouce_phalangine_phalangette_droite -= 1.0f;
      break;

    case TOUCHE_MIN_B:
      // main gauche
      if(angle_paume_gauche < 90.0) angle_paume_gauche += 1.0f;
      if(angle_phalange_phalangine_gauche < 90.0) angle_phalange_phalangine_gauche += 1.0f;   
      if(angle_phalangine_phalangette_gauche < 90.0) angle_phalangine_phalangette_gauche += 1.0f; 
      if(angle_paume_gauche > 20.0f){
              if(angle_pouce_paume_gauche < 40.0) angle_pouce_paume_gauche += 1.0f;
              if(angle_pouce_phalange_phalangine_gauche < 70.0) angle_pouce_phalange_phalangine_gauche += 1.0f;
              if(angle_pouce_phalangine_phalangette_gauche < 50.0) angle_pouce_phalangine_phalangette_gauche += 1.0f;
      }
      break;
    case TOUCHE_MAJ_B:
      // main gauche
      if(angle_paume_gauche > 0.0) angle_paume_gauche -= 1.0f;
      if(angle_phalange_phalangine_gauche > 0.0) angle_phalange_phalangine_gauche -= 1.0f;   
      if(angle_phalangine_phalangette_gauche > 0.0) angle_phalangine_phalangette_gauche -= 1.0f; 
      if(angle_pouce_paume_gauche > 0.0) angle_pouce_paume_gauche -= 1.0f;
      if(angle_pouce_phalange_phalangine_gauche > 0.0) angle_pouce_phalange_phalangine_gauche -= 1.0f;
      if(angle_pouce_phalangine_phalangette_gauche > 0.0) angle_pouce_phalangine_phalangette_gauche -= 1.0f;
      break;

    }	
}
void touche_speciale_pressee(int key, int x, int y) 
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {    
    case GLUT_KEY_PAGE_UP:
      if(ytrans > -95.0f) ytrans -= 5.0f;
      break;
    
    case GLUT_KEY_PAGE_DOWN:
      if(ytrans < -5.0f) ytrans += 5.0f;
      break;

    case GLUT_KEY_UP:
      switch (etat) {
        case OBJET : 
	        xrot_objet -=5.0f; 
	        break;
        case CAMERA :
	        if(ztrans < 95.0f) ztrans +=5.0f; 
	        break;
      }
      break;

    case GLUT_KEY_DOWN:
      switch (etat) {
        case OBJET : 
	        xrot_objet +=5.0f; 
	        break;
        case CAMERA :
	        if(ztrans > -95.0f) ztrans -=5.0f; 
	        break;
      }
      break;

    case GLUT_KEY_LEFT:
      switch (etat) {
        case OBJET : 
          yrot_objet -=5.0f; 
          break;
        case CAMERA :
          if(xtrans < 95.0f) xtrans +=5.0f; 
          break;
      }
      break;
    
    case GLUT_KEY_RIGHT:
      switch (etat) {
        case OBJET : 
	        yrot_objet +=5.0f; 
	        break;
        case CAMERA :
	        if(xtrans > -95.0f) xtrans -=5.0f; 
	        break;
      }
      break;

    case GLUT_KEY_HOME:
      switch (etat) {
        case OBJET : 
          zrot_objet -=5.0f; 
          break;
        case CAMERA :
          yrot += 5.0f;
          break;
      }
      break;
    
    case GLUT_KEY_END:
      switch (etat) {
        case OBJET : 
	        zrot_objet +=5.0f; 
	        break;
        case CAMERA :
	        yrot -= 5.0f;
	        break;
      }
      break;

    default:
      break;

    }	
}
