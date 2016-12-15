#include "ADHERENT.h"
#include <iostream>
#include <string>
using namespace std;
Adherent::Adherent(string nom,string prenom,int cin,int empr)
{
    this->m_nom=nom;
    this->m_prenom=prenom;
    this->m_cin=cin;
    this->m_emprunt=empr;
}
string Adherent::getNom()
{
    return m_nom;
}
string Adherent::getPrenom()
{
    return m_prenom;
}
int Adherent::getCin()
{
    return m_cin;
}
int Adherent::getEmprunt()
{
    return m_emprunt;
}
void Adherent::setNom(string name)
{
    this->m_nom=name;
}
void Adherent::setPrenom(string prenom)
{
    m_prenom=prenom;
}
void Adherent::setCin(int ciin)
{
    m_cin=ciin;
}
void Adherent::setEmprunt(int emprunt)
{
    m_emprunt=emprunt;
}
void Adherent::afficher()
{
    cout <<"\n le nom du l adherent est"<<this->m_nom<<endl;
    cout <<"\n le prenom du l adherent est"<<this->m_prenom<<endl;
    cout <<"\n le numero de carte cin du l adherent est"<<this->m_cin<<endl;
}
Adherent::~Adherent()
{
}
