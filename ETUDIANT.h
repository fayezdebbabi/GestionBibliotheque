#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <string>
#include <iostream>
#include "ADHERENT.h"

class Etudiant : public Adherent
{
public:
    Etudiant(string nom="",string prenom="",int cin=0,int empr=0);
    int bloquer();
    virtual void afficher();
    virtual  ~Etudiant();


};
#endif // ETUDIANT_H_INCLUDED
