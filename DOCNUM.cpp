#include"DOCNUM.h"
#include"DOCUMENT.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;


DocNum::DocNum(string titre,string auteur,int m_serie,int ex,string collection,string type_du_document,string type_du_disque,int taille_sur_disque):Document(titre,auteur,m_serie,ex,collection)
{
    this->type_du_document=type_du_document;
    this->type_du_disque=type_du_disque;
    this->taille_sur_disque=taille_sur_disque;

}

void DocNum::affiche_document()
{
    Document::affiche_document();

    cout<<left<<setw(10)<<this->type_du_document;
    cout<<left<<setw(10)<<this->type_du_disque;
    cout<<"\n"<<endl;
}
string DocNum::getType_Du_Document()
{
    return type_du_document;
}
string DocNum::getType_Du_Disque()
{
    return type_du_disque;
}
int DocNum::getTaille_Sur_Disque()
{
    return taille_sur_disque;
}
void DocNum::setType_Du_Document(string typedocument)
{
    type_du_document=typedocument;
}
void DocNum::setType_Du_Disque(string typedisque)
{
    type_du_disque=typedisque;
}
void DocNum::setTaille_Sur_Disque(int taille)
{
    taille_sur_disque=taille;
}
DocNum::~DocNum()
{}
