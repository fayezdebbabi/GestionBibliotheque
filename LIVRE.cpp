#include<iostream>
#include"LIVRE.h"
#include<string>
#include"DOCUMENT.h"
#include<iomanip>
using namespace std;


Livre::Livre(string titre,string auteur,int m_serie,int ex,string collection,int nbrePage,string genre):Document(titre,auteur,m_serie,ex,collection)
{
    this->nbrePage=nbrePage;
    this->genre=genre;
}
void Livre::affiche_document()
{
    Document::affiche_document();
    cout<<left<<setw(9)<<this->nbrePage;
    cout<<left<<setw(10)<<this->genre<<endl;
    cout<<endl;

}
int Livre::getNbrepage()
{
    return nbrePage;
}
string Livre::getGenre()
{
    return genre;
}
void Livre::setNbrepage(int age)
{
    nbrePage=age;
}
void Livre::setGenre(string geenre)
{
    genre=geenre;
}
Livre::~Livre()
{
}
