#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED
#include <string>
using namespace std;
class Document
{
private:
    string titre;
    string auteur;
    int m_serie;
    string collection;
    int ex;
public:
    Document(string titre="",string auteur="" ,int m_serie=0,int ex=0,string collection="");
    virtual void affiche_document();
    string getTitre();
    string getAuteur();
    int getM_serie();
    string getCollection();
    int getEx();
    void setTitre(string);
    void setAuteur(string);
    void setM_serie(int);
    void setCollection(string);
    void setEx(int);
    virtual~Document();
};

#endif // DOCUMENT_H_INCLUDED
