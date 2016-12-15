#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
#include"DOCUMENT.h"
#include<iostream>
class Livre:public Document
{
private:
    int nbrePage;
    string genre;
public:
    Livre(string titre="",string auteur="",int m_serie=0,int ex=0,string collection="",int nbrePage=0,string genre="");
    void affiche_document();
    int getNbrepage();
    string getGenre();
    void setNbrepage(int);
    void setGenre(string);
    virtual ~Livre();
};
#endif // LIVRE_H_INCLUDED
