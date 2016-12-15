#include "ETUDIANT.h"
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
Etudiant ::Etudiant(string nom,string prenom,int cin,int empr): Adherent(nom,prenom,cin,empr) {};

void Etudiant::afficher()
{
    cout<<left<<setw(20)<<this->m_nom;
    cout<<left<<setw(20)<<this->m_prenom;
    cout<<left<<setw(20)<<this->m_cin;
    cout<<left<<setw(20)<<this->m_emprunt<<endl;;
}
Etudiant::~Etudiant() {};

int Etudiant::bloquer()
{
    int i=1;
    if (this->m_emprunt +1 > 1)
        cout<<"l etudiant ne peut pas emprunter"<<endl;
    i=0;
    return i;
}
