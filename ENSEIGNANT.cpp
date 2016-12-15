#include "ENSEIGNANT.h"
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
Enseignant:: Enseignant(string nom,string prenom,int cin,int empr): Adherent(nom,prenom,cin,empr)
{
}
void Enseignant::afficher()
{
    cout<<left<<setw(20)<<this->m_nom;
    cout<<left<<setw(20)<<this->m_prenom;
    cout<<left<<setw(20)<<this->m_cin;
    cout<<left<<setw(20)<<this->m_emprunt<<endl;
}
Enseignant::~Enseignant() {};

int Enseignant::bloquer()
{
    int i=1;
    if (this->m_emprunt +1 > 4)
        cout<<"l enseignant ne peut pas emprunter"<<endl;
    i=0;
    return i;
}
