#include"EMPRUNT.h"
#include"DATE.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

Emprunt::Emprunt(string nmEmprunt,string prEmprunt,int ci,string titEmprunt,int n_serie,int a,int m,int j)
{
    this->nmEmprunt=nmEmprunt;
    this->prEmprunt=prEmprunt;
    this->ci=ci;
    this->titEmprunt=titEmprunt;
    this->n_serie=n_serie;
    this->dateE=Date(a,m,j);
    this->dateR=retour(15,dateE);

}
void Emprunt::affiche_liste_des_emprunts(){
cout<<left<<setw(10)<<this->nmEmprunt;
cout<<left<<setw(10)<<this->prEmprunt;
cout<<left<<setw(10)<<this->ci;
cout<<left<<setw(15)<<this->titEmprunt;
cout<<left<<setw(9)<<this->n_serie;
cout<<left<<setw(2)<<this->dateE.jour;
cout<<"/";
cout<<left<<setw(2)<<this->dateE.mois;
cout<<"/";
cout<<left<<setw(8)<<this->dateE.annee;


cout<<left<<setw(2)<<dateR.jour;
cout<<"/";
cout<<left<<setw(2)<<dateR.mois;
cout<<"/";
cout<<left<<setw(10)<<dateR.annee;


}

int Emprunt::getM_serie(){

    return n_serie;
}
int Emprunt::getCi()
    {
    return ci;
    }
    int Emprunt::getAn()
    {
        return dateE.annee;
    }
    int Emprunt::getMois()
    {
        return dateE.mois;
    }
    int Emprunt::getJour()
    {
        return dateE.jour;
    }
    string Emprunt::getNM()
    {
        return nmEmprunt;
    }
    string Emprunt::getPR()
    {
        return prEmprunt;
    }
    string Emprunt::getTT()
    {
        return titEmprunt;
    }

Emprunt::~Emprunt(){};
