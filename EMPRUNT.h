#ifndef EMPRUNT_H_INCLUDED
#define EMPRUNT_H_INCLUDED
#include<string>
#include<iostream>
#include"DATE.h"
class Emprunt
{
public:
    string nmEmprunt;
    string prEmprunt;
    int ci;
    string titEmprunt;
    int n_serie;
    Date dateE;
    Date dateR;
public:
    Emprunt(string nmEmprunt="",string prEmprunt="",int ci=0,string titEmprunt="",int n_serie=0,int a=0,int m=0,int j=0);
    ~Emprunt();


    void affiche_liste_des_emprunts();
    int getM_serie();
    int getCi();
    int getAn();
    int getMois();
    int getJour();
    string getNM();
    string getPR();
    string getTT();
};

#endif // EMPRUNT_H_INCLUDED
