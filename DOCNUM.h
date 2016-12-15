#ifndef DOCNUM_H_INCLUDED
#define DOCNUM_H_INCLUDED
#include<iostream>
#include<string>
#include"DOCUMENT.h"
using namespace std;

class DocNum:public Document
{
private:
    string type_du_document;
    string type_du_disque;
    int taille_sur_disque;
public:
    DocNum(string titre="",string auteur="" ,int m_serie=0,int ex=0,string collection="",string type_du_document="",string type_du_disque="",int taille_sur_disque=0);
    virtual void affiche_document();
    virtual ~DocNum();
    string getType_Du_Document();
    string getType_Du_Disque();
    int getTaille_Sur_Disque();
    void setType_Du_Document(string);
    void setType_Du_Disque(string);
    void setTaille_Sur_Disque(int);
};
#endif // DOCNUM_H_INCLUDED
