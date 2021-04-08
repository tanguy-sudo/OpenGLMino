#include "minotaure.h"

GLvoid Rectangle(GLfloat x, GLfloat y, GLfloat z)
{
  glPushMatrix();
  {
    glScalef(x, y, z);
    struct cube * mon_cube;
    mon_cube = cree_cube(1.0f);
    affiche_cube(mon_cube);
    //glutSolidCube(1.0f);
  }
  glPopMatrix();
}

GLvoid Cylindre(GLfloat x, GLfloat y, GLfloat z)
{
  glPushMatrix();
  {
    glScalef(x, y, z);
    GLUquadric *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    SOLID_CLOSED_CYLINDER(quadric, 1.0f, 1.0f, 1.0f, 20, 20)
    gluDeleteQuadric(quadric);
  }
  glPopMatrix();
}

GLvoid sol(GLfloat x, GLfloat y, GLfloat z)
{
  glPushMatrix();
  {
    glColor3f(1.0f, 1.0f, 1.0f);
    glScalef(x, y, z);
    glutSolidCube(1.0f);
  }
  glPopMatrix();
}

GLvoid Jambe(GLfloat proportion, GLfloat taille_jambe, GLfloat angle_hanche, GLfloat angle_genou, GLfloat angle_cheville, GLfloat angle_pied)
{
  glPushMatrix();
  {
    glTranslatef(0.0f, proportion * 3.1f, 0.0f);
    
    glRotatef(angle_hanche, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.9f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_jambe*1.5f, proportion * 1.4f, taille_jambe*1.5f); 
    glTranslatef(0.0f, proportion * 0.9f, 0.0f);

    glRotatef(angle_genou, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.6f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_jambe*1.2, proportion * 1.6f, taille_jambe*1.2);
    glTranslatef(0.0f, proportion * 0.9f, 0.0f);

    glRotatef(angle_cheville, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.3f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_jambe*1.1f, proportion * 1.0f, (taille_jambe/2)*1.1f);
    glTranslatef(0.0f, proportion * 0.45f, 0.0f);

    glRotatef(angle_pied, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.3f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_jambe*1.0f, proportion * 0.72f, (taille_jambe/2)*1.0f);
    glTranslatef(0.0f, proportion * 0.3f, -0.5f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    Cylindre(1.0f, proportion * 0.2f, 1.0f);
  }
  glPopMatrix();
}

GLvoid Paume(GLfloat x, GLfloat y, GLfloat z)
{
  Rectangle(x, y, z);
}

GLvoid Doigt(GLfloat angle,
             GLfloat angle_phalange_phalangine,
             GLfloat angle_phalangine_phalangette,
             GLfloat proportion,
             GLfloat taille_doigt)
{
  glPushMatrix();
  {
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 1.0f, 0.0f, 0.0f);
    Rectangle(proportion * 2.0f, taille_doigt, taille_doigt);

    glTranslatef(proportion * 1.0f, 0.0f, 0.0f);
    glRotatef(angle_phalange_phalangine, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.7f, 0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(proportion * 1.4f, taille_doigt, taille_doigt);

    glTranslatef(proportion * 1.1f, 0.0f, 0.0f);
    glRotatef(angle_phalangine_phalangette, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.1f, 0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(proportion * 1.0f, taille_doigt, taille_doigt);
  }
  glPopMatrix();
}

GLvoid Pouce(GLfloat angle,
             GLfloat angle_phalange_phalangine,
             GLfloat angle_phalangine_phalangette,
             GLfloat proportion,
             GLfloat taille_doigt)
{
  glPushMatrix();
  {
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(proportion * 0.5f, 0.0f, 0.0f);
    Rectangle(proportion * 1.0f, taille_doigt, taille_doigt*1.5);

    glTranslatef(proportion * 0.5f, 0.0f, 0.0f);
    glRotatef(angle_phalange_phalangine, 0.0f, -1.0f, 0.0f);
    glTranslatef(proportion * 0.4f, 0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(proportion * 0.8f, taille_doigt, taille_doigt*1.2);

    glTranslatef(proportion * 0.4f, 0.0f, 0.0f);
    glRotatef(angle_phalangine_phalangette, 0.0f, -1.0f, 0.0f);
    glTranslatef(proportion * 0.3f, 0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(proportion * 0.6f, taille_doigt, taille_doigt);
  }
  glPopMatrix();
}

GLvoid hand(GLfloat largeur_paume, 
            GLfloat longueur_paume, 
            GLfloat taille_doigt, 
            bool i, 
            GLfloat angle_paume, 
            GLfloat angle_phalange_phalangine, 
            GLfloat angle_phalangine_phalangette,
            GLfloat angle_pouce_paume, 
            GLfloat angle_pouce_phalange_phalangine, 
            GLfloat angle_pouce_phalangine_phalangette)
{
    glPushMatrix();
  {
    glRotatef(90.0f, 0.0f, 0.0f, 0.1f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Paume(longueur_paume, 0.8, largeur_paume*1.5);

    //auriculaire
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(longueur_paume/2.0, 0.0, largeur_paume/1.6);
    Doigt(angle_paume, angle_phalange_phalangine, angle_phalangine_phalangette, 0.3, taille_doigt);
    
    //annulaire
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0, 0.0, -(largeur_paume/2.5));
    Doigt(angle_paume, angle_phalange_phalangine, angle_phalangine_phalangette, 0.45, taille_doigt);

    //majeur
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0, 0.0, -(largeur_paume/2.5));
    Doigt(angle_paume, angle_phalange_phalangine, angle_phalangine_phalangette, 0.5, taille_doigt);

    //index
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0, 0.0, -(largeur_paume/2.5));
    Doigt(angle_paume, angle_phalange_phalangine, angle_phalangine_phalangette, 0.4, taille_doigt);

    //pouce
    glColor3f(1.0f, 1.0f, 1.0f);
    if(i == true){
          glTranslatef(-longueur_paume+0.03, -0.55, 0.0);
          Pouce(angle_pouce_paume, angle_pouce_phalange_phalangine, angle_pouce_phalangine_phalangette, 0.8, taille_doigt);
    }else{
          glTranslatef(-longueur_paume+0.03, 0.55, 0.0);
          Pouce(angle_pouce_paume, angle_pouce_phalange_phalangine, angle_pouce_phalangine_phalangette, 0.8, taille_doigt);
    }
  }
  glPopMatrix();
}

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
)
{
  glPushMatrix();
  {
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(1.6f, 7, 7);

    glRotatef(angle_epaule, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_bras, proportion*1.5f, taille_bras);
    glTranslatef(0.0f, proportion * 0.8f, 0.0f);

    glRotatef(angle_coude, 0.1f, 0.0f, 0.0f);
    glTranslatef(0.0f, proportion * 0.7f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_bras*0.9f, proportion*1.5f, taille_bras*0.9f);
    glTranslatef(0.0f, proportion * 0.9f, 0.0f);

    GLfloat largeur_paume = 1.0;
    GLfloat longueur_paume = 1.5;
    GLfloat taille_doigt = 0.3;

    glRotatef(180.0f, 0.0f, 0.1f, 0.0f);

    hand(largeur_paume, longueur_paume, taille_doigt, i, angle_paume, angle_phalange_phalangine, 
         angle_phalangine_phalangette, angle_pouce_paume, angle_pouce_phalange_phalangine, 
         angle_pouce_phalangine_phalangette);
  }
  glPopMatrix();
}

GLvoid Corps(GLfloat proportion, GLfloat taille_corps)
{
  glPushMatrix();
  {
    glTranslatef(0.0f, proportion * 1.05f, -1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Rectangle(taille_corps, proportion * 0.7f, taille_corps*0.4f);
  }
  glPopMatrix();
}