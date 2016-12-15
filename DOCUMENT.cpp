#include "DOCUMENT.h"
#include <iostream>
#include <iomanip>
Document::Document(string titre,string auteur,int m_serie,int ex,string collection)
{
    this->titre=titre;
    this->auteur=auteur;
    this->m_serie=m_serie;
    this->collection=collection;
    this->ex=ex;
}
void Document::affiche_document()
{
    cout<<left<<setw(15)<<this->titre;
    cout<<left<<setw(13)<<this->auteur;
    cout<<left<<setw(10)<<this->m_serie;
    cout<<left<<setw(7)<<this->ex;
    cout<<left<<setw(15)<<this->collection;

}
string Document::getTitre()
{
    return titre;
}
string Document::getAuteur()
{
    return auteur;
}
int Document::getM_serie()
{
    return m_serie;
}
string Document::getCollection()
{
    return collection;
}
int Document::getEx()
{
    return ex;
}
void Document::setTitre(string le_titre)
{
    titre=le_titre;
}
void Document::setAuteur(string le_auteur)
{
    auteur=le_auteur;
}
void Document::setM_serie(int serie)
{
    m_serie=serie;
}
void Document::setCollection(string la_collection)
{
    collection=la_collection;
}
void Document::setEx(int exemplaire)
{
    ex=exemplaire;
}
Document::~Document()
{
}
