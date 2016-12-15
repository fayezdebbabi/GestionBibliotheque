#ifndef ADHERENT_H_INCLUDED
#define ADHERENT_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Adherent
{
protected:
    string m_nom;
    string m_prenom;
    int m_cin;
    int m_emprunt;
public:
    Adherent(string nom="",string prenom="",int cin=0,int empr=0);
    virtual void afficher();
    virtual ~Adherent();
    virtual string getNom();
    virtual string getPrenom();
    virtual int getCin();
    virtual int getEmprunt();
    virtual void setNom(string);
    virtual void setPrenom(string);
    virtual void setCin(int);
    virtual void setEmprunt(int);
};
#endif // ADHERENT_H_INCLUDED
