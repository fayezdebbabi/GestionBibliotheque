#ifndef ENSEIGNANT_H_INCLUDED
#define ENSEIGNANT_H_INCLUDED
#include <string>
#include <iostream>
#include "ADHERENT.h"
using namespace std;

class Enseignant : public Adherent
{
public:
    Enseignant(string nom="",string prenom="",int cin=0,int empr=0);
    int bloquer();
    virtual void afficher();
    virtual ~Enseignant();

};
#endif // ENSEIGNANT_H_INCLUDED
