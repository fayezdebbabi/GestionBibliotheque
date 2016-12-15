#include <iostream>
#include<string>
#include <memory>
#include <vector>
#include <cstdlib>
#include "Menu.h"
#include "MenuAD.h"
#include "ADHERENT.h"
#include "ENSEIGNANT.h"
#include "ETUDIANT.h"
#include"LIVRE.h"
#include"DOCNUM.h"
#include"EMPRUNT.h"
#include"DATE.h"
#include"DOCUMENT.h"
#include<iomanip>
#include<fstream>
#include"menu1.h"
#include"menu2.h"
#include"menu3.h"
#include <ctime>
template <class T>
class Node
{
public:
    T data;
    Node *next;
public:
    Node(void)
    {
        next=NULL;
    };
    Node(T d, Node *n=NULL)
    {
        data=d;
        next=n;
    };
    void setNext(Node *n)
    {
        next=n;
    };
    Node *getNext(void)
    {
        return(next);
    };
    void setData(T d)
    {
        data=d;
    };
    T getData(void)
    {
        return(data);
    };

};

template <class T>
int Length(Node<T> *head);

template <class T>
void printList(Node<T> *head);

template <class T>
void addToStart(Node<T> *&head, T Data);

template <class T>
void addToEnd(Node<T> *&head, T Data);
template <class T>
void supprim(Node<T> *&headRef, int position);
Node<Emprunt> *supprimer_emprunt(Node<Emprunt> *emprunts,int numero_serie,int carteIN);
Node<DocNum> *supprimer_doc_num(Node<DocNum> *docnumeriques, int NumSerie);
Node<Livre> *supprimer_doc_livres(Node<Livre> *livres, int NumSerie);
int recherche_particuliere(string mot_cle,string titre);
Node<Etudiant> *supprimer_etud(Node<Etudiant> *etudiants, int NumCIN);
Node<Enseignant> *supprimer_ens(Node<Enseignant> *enseignants, int NumCIN);


using namespace std;

int main()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int YY=now->tm_year + 1900;
    int MM=now->tm_mon +1;
    int DD=now->tm_mday;

    Node<Enseignant>*enseignants=NULL;
    Node<Etudiant> *etudiants=NULL;
    Node<Livre> *livres=NULL;
    Node<DocNum> *docnumeriques=NULL;
    Node<Emprunt> *emprunts=NULL;
    int a,carteIN,d,position,m1,m2,m3,m4,x,TypeDoc,NumSerie,case7,case3,case4,cn,choix;
    int e,em,exem,supp,verif,s,z;
    string ch1,ch2,ch3,ch4,ch5,ch11,tit,ch7;
    ifstream fichier("etudiant.txt");
    if (fichier)
    {
        string ligne;
        while(getline(fichier,ligne))
        {
            ch1=ligne;
            getline(fichier,ligne);
            ch2=ligne;
            getline(fichier,ligne);
            a=atoi(ligne.c_str());
            getline(fichier,ligne);
            m1=atoi(ligne.c_str());

            Etudiant nouv(ch1,ch2,a,m1);
            addToEnd(etudiants,nouv);

        }
    }

    ifstream fich("enseignant.txt");
    if (fich)
    {
        string ligne;
        while(getline(fich,ligne))
        {
            ch1=ligne;
            getline(fich,ligne);
            ch2=ligne;
            getline(fich,ligne);
            a=atoi(ligne.c_str());
            getline(fich,ligne);
            m1=atoi(ligne.c_str());

            Enseignant nouv(ch1,ch2,a,m1);
            addToEnd(enseignants,nouv);

        }
    }
    ifstream fic("livre.txt");
    if (fic)
    {
        string ligne;
        while(getline(fic,ligne))
        {
            ch1=ligne;
            getline(fic,ligne);
            ch2=ligne;
            getline(fic,ligne);
            a=atoi(ligne.c_str());
            getline(fic,ligne);
            m1=atoi(ligne.c_str());
            getline(fic,ligne);
            ch3=ligne;
            getline(fic,ligne);
            em=atoi(ligne.c_str());
            getline(fic,ligne);
            ch4=ligne;

            Livre nouv(ch1,ch2,a,m1,ch3,em,ch4);
            addToEnd(livres,nouv);

        }
    }
    ifstream fice("docnum.txt");
    if (fice)
    {
        string ligne;
        while(getline(fice,ligne))
        {
            ch1=ligne;
            getline(fice,ligne);
            ch2=ligne;
            getline(fice,ligne);
            a=atoi(ligne.c_str());
            getline(fice,ligne);
            m1=atoi(ligne.c_str());
            getline(fice,ligne);
            ch3=ligne;
            getline(fice,ligne);
            ch4=ligne;
            getline(fice,ligne);
            ch5=ligne;
            getline(fice,ligne);
            s=atoi(ligne.c_str());

            DocNum nouv(ch1,ch2,a,m1,ch3,ch4,ch5,s);
            addToEnd(docnumeriques,nouv);

        }
    }
    ifstream fih("emprunt.txt");
    if (fih)
    {
        string ligne;
        while(getline(fih,ligne))
        {
            ch1=ligne;
            getline(fih,ligne);
            ch2=ligne;
            getline(fih,ligne);
            m1=atoi(ligne.c_str());
            getline(fih,ligne);
            ch3=ligne;
            getline(fih,ligne);
            m2=atoi(ligne.c_str());
            getline(fih,ligne);
            m3=atoi(ligne.c_str());
            getline(fih,ligne);
            m4=atoi(ligne.c_str());
            getline(fih,ligne);
            x=atoi(ligne.c_str());
            Emprunt nouv(ch1,ch2,m1,ch3,m2,m3,m4,x);
            addToEnd(emprunts,nouv);

        }
    }

    do
    {

        system("cls");
        cout<<"\n\n\n";
        cout<<"                  *********************************************"<<endl;
        cout<<"                  *                 BIENVENUE                 *"<<endl;
        cout<<"                  *********************************************"<<endl;


        menu();
        cin>>a;
        switch(a)
        {
        case 1 :
        {
            do
            {
                menu1();
                cin>>choix;
                switch(choix)
                {

                case 1 :
                {
                    system("cls");
                    cout<<"                           Inscription d'un adherent       "<<endl;
                    cout<<"________________________________________________________________________________"<<endl;
                    cout<<"\n\n               Inscription d un enseignant ou d un etudiant"<<endl;
                    cout<<"\n\n           vous voulez  1.etudiant   ou    2.enseignant"<<endl;
                    cin>>e;
                    if (e==1)
                    {

                        cout<<"\n\ndonner le nom etudiant"<<endl;


                        fflush(stdin);
                        getline(cin, ch7);


                        cout<<"\n\n donner le prenom"<<endl;
                        getline(cin, ch2);
                        fflush(stdin);
                        cout<<"donner le num de la carte d identite"<<endl;

                        cin>>em;
                        fflush(stdin);
                        Node<Etudiant>*E=etudiants;
                        while(E!=NULL&&(E->getData().getCin()!=em))
                        {
                            E=E->getNext();
                        }
                        if(E!=NULL)
                        {
                            cout<<"\n             !!! CIN deja utulise!!!\n"<<endl;
                            system("pause");
                            break;
                        }
                        Etudiant nouveau(ch7,ch2,em,0);
                        addToEnd(etudiants,nouveau);
                    }
                    else if (e==2)
                    {
                        cout<<"\n\n donner le nom enseignant"<<endl;
                        fflush(stdin);
                        getline(cin,ch1);

                        cout<<"\n\n donner le prenom"<<endl;
                        fflush(stdin);
                        getline(cin,ch2);
                        cout<<"donner le num de la carte d identite"<<endl;
                        fflush(stdin);
                        cin>>em;
                        Node<Enseignant>*E=enseignants;
                        while(E!=NULL&&(E->getData().getCin()!=em))
                        {
                            E=E->getNext();
                        }
                        if(E!=NULL)
                        {
                            cout<<"\n         !!! CIN deja utulise!!! \n"<<endl;
                            system("pause");
                            break;
                        }
                        Enseignant nouveau(ch1,ch2,em,0);
                        addToEnd(enseignants,nouveau);

                    }
                    else
                    {
                        cout<<"          votre choix n'est pas valide\n"<<endl;
                        system("pause");
                    }

                }
                break;
                case 2 :
                {
                    system("cls");
                    cout<<"\n\n                                     Suppression"<<endl;
                    cout<<"\n\n            vous voulez supprimer     1.un etudiant    ou     2.un enseignant"<<endl;
                    cin>>supp;
                    position=1;


                    if(supp==1)
                    {

                        if (etudiants==NULL)
                        {
                            cout<<"       la liste est vide \n"<<endl;
                            system("pause");
                        }

                        else
                        {
                            cout<<"\n        donner le numero de la carte cin"<<endl;
                            cin>>carteIN;

                            etudiants=supprimer_etud(etudiants,carteIN);
                            cout<<"\n\n   element supprime \n\n"<<endl;
                            system("pause");



                        }

                    }
                    else if (supp==2)
                    {

                        position=1;

                        if (enseignants==NULL)
                        {
                            cout<<"\n        la liste est vide\n"<<endl;
                            system("pause");
                        }
                        else
                        {
                            cout<<"\n      donner le numero de la carte cin"<<endl;
                            cin>>carteIN;
                            enseignants=supprimer_ens(enseignants,carteIN);

                            cout<<"       enseignant supprime"<<endl;
                            system("pause");
                        }
                    }
                }
                break;
                case 3 :

                {
                    system("cls");
                    cout<<"\n\n                                  Liste des adherents\n\n"<<endl;
                    cout<<"                   Voir la liste   1.des Etudiants     2.des Enseignants "<<endl;
                    cin>>case7;
                    if(case7==1)
                    {
                        system("cls");
                        cout<<"\n                              Liste des Etudiant \n\n"<<endl;
                        Node<Etudiant>*tmp=etudiants;
                        if(tmp==NULL)
                        {
                            cout<<"\n\n               la liste est vide \n"<<endl;
                            system("pause");
                            break;
                        }
                        cout<<left<<setw(20)<<"NomEtudiant";
                        cout<<left<<setw(20)<<"PrenomEtudiant";
                        cout<<left<<setw(20)<<"NumCarteNational";
                        cout<<left<<setw(20)<<"NombreEmprunt"<<endl;
                        cout<<"________________________________________________________________________________"<<endl;

                        while(tmp!=NULL)
                        {
                            (tmp->data).afficher();
                            tmp=(tmp->getNext());
                        }
                        cout<<"________________________________________________________________________________"<<endl;
                        system("pause");

                    }
                    else if(case7==2)
                    {
                        system("cls");
                        cout<<"\n                          Liste des Enseignants\n"<<endl;
                        Node<Enseignant>*tmp=enseignants;
                        if(tmp==NULL)
                        {
                            cout<<"la liste est vide \n"<<endl;
                            system("pause");
                            break;
                        }
                        cout<<left<<setw(20)<<"NomEnseignant";
                        cout<<left<<setw(20)<<"PrenomEnseignant";
                        cout<<left<<setw(20)<<"NumCarteNational";
                        cout<<left<<setw(20)<<"NombreEmprunt"<<endl;

                        cout<<"________________________________________________________________________________"<<endl;
                        while(tmp!=NULL)
                        {
                            (tmp->data).afficher();
                            tmp=(tmp->getNext());
                        }
                        cout<<"________________________________________________________________________________"<<endl;

                        system("pause");


                    }
                    else
                    {
                        cout<<"votre choix n'est pas valide\n"<<endl;
                        system("pause");
                    }
                }
                break;
                case 4 :
                {
                    system("cls");
                    cout<<"\n\n                                  Modification des adherents\n\n"<<endl;
                    cout<<"                   Modifier   1. Enseignant    2.Etudiant "<<endl;
                    cin>>case7;
                    if(case7==1)
                    {

                        cout<<"donner le num cIN de l enseignant"<<endl;
                        cin>>cn;
                        fflush(stdin);
                        Node<Enseignant>*EA=enseignants;

                        while((EA!=NULL)&&(EA->getData().getCin()!=cn))
                        {
                            EA=EA->getNext();
                        }

                        if(EA==NULL)
                        {
                            cout<<"\n             !!!n'existe pas!!!\n"<<endl;
                            system("pause");
                            break;
                        }
                        Node<Enseignant> *gh=enseignants;


                        while((gh!=NULL)&&(gh->getData().getCin() !=cn))
                        {

                            gh=gh->getNext();
                        }

                        if (gh->getData().getCin()==cn)
                        {
                            cout<<"     1.Nom"<<endl;
                            cout<<"     2.Prenom"<<endl;
                            cin>>x;
                            if(x==1)
                            {
                                cout<<"donner le nouveau nom"<<endl;

                                fflush(stdin);
                                getline(cin, ch1);

                                gh->data.setNom(ch1);
                            }
                            else if (x==2)
                            {
                                cout<<"donner le nouveau prenom"<<endl;
                                fflush(stdin);
                                getline(cin, ch1);
                                gh->data.setPrenom(ch1);
                            }
                        }
                    }
                    else if(case7==2)
                    {
                        cout<<"donner le num CIN de l'etudiant"<<endl;
                        cin>>cn;
                        fflush(stdin);
                        Node<Etudiant>*EA=etudiants;

                        while((EA!=NULL)&&(EA->getData().getCin()!=cn))
                        {
                            EA=EA->getNext();
                        }

                        if(EA==NULL)
                        {
                            cout<<"\n             !!!CIN n'existe pas!!!\n"<<endl;
                            system("pause");
                            break;
                        }
                        Node<Etudiant> *gh=etudiants;


                        while((gh!=NULL)&&(gh->getData().getCin() !=cn))
                        {

                            gh=gh->getNext();
                        }

                        if (gh->getData().getCin()==cn)
                        {
                            cout<<"     1.Nom"<<endl;
                            cout<<"     2.Prenom"<<endl;
                            cin>>x;
                            if(x==1)
                            {
                                cout<<"donner le nouveau nom"<<endl;

                                fflush(stdin);
                                getline(cin, ch1);

                                gh->data.setNom(ch1);
                            }
                            else if (x==2)
                            {
                                cout<<"donner le nouveau prenom"<<endl;
                                fflush(stdin);
                                getline(cin, ch1);
                                gh->data.setPrenom(ch1);
                            }
                        }
                    }
                    else
                    {
                        cout<<"choix invalide"<<endl;
                        system("pause");
                    }

                    system("pause");
                }
                break;
                case 5 :
                    break;

                }
            }
            while(choix!=5);
        }
        break;
        case 2 :
        {
            do
            {
                menu2();
                cin>>choix;
                switch(choix)
                {
                case 1 :
                {
                    system("cls");
                    cout<<"vous voulez ajouter un livre ou un document numerique"<<endl;
                    cout<<" tapez   1. Livre          2.Document numerique"<<endl;
                    cin>>a;

                    if (a==1)
                    {
                        cout<<"donner le titre du Livre "<<endl;
                        fflush(stdin);
                        getline(cin,ch1);
                        cout<<"donner l auteur du Livre "<<endl;
                        fflush(stdin);
                        getline(cin,ch2);
                        cout<<"donner le num serie "<<endl;
                        cin>>m1;
                        cout<<"donner le nombre d'exemplaires "<<endl;
                        cin>>m2;
                        cout<<"donner la collection "<<endl;
                        fflush(stdin);
                        getline(cin,ch3);
                        cout<<"donner le nombre de pages du Livre "<<endl;
                        cin>>m4;
                        cout<<"donner le genre du Livre "<<endl;
                        fflush(stdin);
                        getline(cin,ch5);
                        Livre nouv(ch1,ch2,m1,m2,ch3,m4,ch5);
                        addToEnd(livres,nouv);
                    }
                    else if(a==2)
                    {
                        cout<<"donner le titre du Document numerique"<<endl;
                        fflush(stdin);
                        getline(cin,ch1);
                        cout<<"donner l auteur du Document numerique"<<endl;
                        fflush(stdin);
                        getline(cin,ch2);
                        cout<<"donner le num serie "<<endl;
                        cin>>m1;
                        cout<<"donner le nombre d exemplaires "<<endl;
                        cin>>m2;
                        cout<<"donner la collection "<<endl;
                        fflush(stdin);
                        getline(cin,ch3);
                        cout<<"donner le type du document "<<endl;
                        fflush(stdin);
                        getline(cin,ch4);
                        cout<<"type du disque "<<endl;
                        fflush(stdin);
                        getline(cin,ch5);
                        cout<<"donner la taille du disque "<<endl;
                        cin>>m3;
                        DocNum nouv(ch1,ch2,m1,m2,ch2,ch4,ch4,m3);
                        addToEnd(docnumeriques,nouv);
                    }
                    else
                    {
                        cout<<"votre choix n'est pas valide\n"<<endl;
                        system("pause");
                    }


                }
                break;
                case 2 :
                {
                    cout<<"Donner le type du document a retirer"<<endl;
                    cout<<"1.Document numerique"<<endl;
                    cout<<"2.Livre"<<endl;
                    cin>>TypeDoc;
                    if(TypeDoc==1)
                    {
                        cout<<"Donner le numero de serie du document a retirer "<<endl;
                        cin>>NumSerie;
                        if(docnumeriques==NULL)
                        {
                            cout<<"pas de document numerique a retirer\n"<<endl;
                            system("pause");
                            break;
                        }

                        docnumeriques=supprimer_doc_num(docnumeriques,NumSerie);

                        cout<<"\n document numerique supprime\n\n"<<endl;
                        system("pause");

                    }
                    else if (TypeDoc==2)
                    {
                        cout<<"Donner le numero de serie du livre a retirer "<<endl;
                        cin>>NumSerie;

                        if(livres==NULL)
                        {
                            cout<<"pas de livre a retirer \n"<<endl;
                            system("pause");
                            break;
                        }

                        livres=supprimer_doc_livres(livres,NumSerie);

                        cout<<"\n livre supprime\n\n"<<endl;
                        system("pause");
                    }
                    else
                    {
                        cout<<"votre choix n'est pas valide\n";
                        system("pause");
                    }
                }
                break;
                case 3 :
                {
                    system("cls");
                    cout<<"vous voulez voir \n\n   1.les documents numeriques \n\n   2.les livres \n\n"<<endl;
                    cin>>TypeDoc;
                    if(TypeDoc==1)
                    {
                        Node<DocNum> *r=docnumeriques;
                        if(r==NULL)
                        {

                            cout<<" la liste est vide\n"<<endl;
                            system("pause");
                            break;
                        }
                        system("cls");
                        cout<<"\n              Liste des Documents Numeriques non encore emprunte \n\n"<<endl;
                        cout<<left<<setw(15)<<"Titre";
                        cout<<left<<setw(13)<<"Auteur";
                        cout<<left<<setw(10)<<"N.Serie";
                        cout<<left<<setw(7)<<"ex.";
                        cout<<left<<setw(15)<<"Collection";
                        cout<<left<<setw(8)<<"TypeDoc";
                        cout<<left<<setw(9)<<"TypeDisc";
                        cout<<endl;
                        cout<<"___________________________________________________________________________\n"<<endl;

                        while(r!=NULL)
                        {
                            (r->data).affiche_document();
                            r=r->getNext();
                        }
                        cout<<"___________________________________________________________________________"<<endl;


                    }
                    else if(TypeDoc==2)
                    {

                        Node<Livre> *r=livres;
                        if(r==NULL)
                        {

                            cout<<" la liste est vide\n"<<endl;
                            system("pause");
                            break;
                        }
                        system("cls");
                        cout<<"\n                       Liste des Livres non encore emprunte\n\n"<<endl;
                        cout<<left<<setw(15)<<"Titre";
                        cout<<left<<setw(13)<<"Auteur";
                        cout<<left<<setw(10)<<"NumSerie";
                        cout<<left<<setw(7)<<"exemp";
                        cout<<left<<setw(15)<<"Collection";
                        cout<<left<<setw(9)<<"NbrPage";
                        cout<<left<<setw(10)<<"Genre"<<endl;

                        cout<<"____________________________________________________________________________"<<endl;
                        cout<<endl;
                        while(r!=NULL)
                        {
                            (r->data).affiche_document();
                            r=r->getNext();
                        }
                        cout<<"____________________________________________________________________________"<<endl;
                    }
                    else
                    {
                        cout<<"votre choix n'est pas correcte\n"<<endl;
                    }
                    system("pause");
                }
                break;
                case 4 :
                {

                    system("cls");
                    cout<<"\n\n                                  Modification des documents\n\n"<<endl;
                    cout<<"                   Modifier   1. Documents numeriques    2.Livres "<<endl;
                    cin>>case7;
                    if(case7==1)
                    {

                        cout<<"donner le num serie du document numerique "<<endl;
                        cin>>cn;
                        fflush(stdin);
                        Node<DocNum>*EA=docnumeriques;

                        while((EA!=NULL)&&(EA->getData().getM_serie()!=cn))
                        {
                            EA=EA->getNext();
                        }

                        if(EA==NULL)
                        {
                            cout<<"\n             !!!n'existe pas!!!\n"<<endl;
                            system("pause");
                            break;
                        }
                        Node<DocNum> *gh=docnumeriques;


                        while((gh!=NULL)&&(gh->getData().getM_serie() !=cn))
                        {

                            gh=gh->getNext();
                        }

                        if (gh->getData().getM_serie()==cn)
                        {
                            cout<<"     1.titre"<<endl;
                            cout<<"     2.nobre d'exemplaire"<<endl;
                            cin>>x;
                            if(x==1)
                            {
                                cout<<"donner le nouveau titre"<<endl;

                                fflush(stdin);
                                getline(cin, ch1);

                                gh->data.setTitre(ch1);
                            }
                            else if (x==2)
                            {
                                cout<<"vous voulez   1.ajouter    2.supprimer"<<endl;
                                cin>>z;
                                if(z==1)
                                {
                                    cout<<"donner le nombre des elements supplementaires"<<endl;
                                    cin>>z;
                                    gh->data.setEx((gh->data.getEx()+z));
                                }
                                else if(z==2)
                                {
                                 cout<<"donner le nombre de elements a retirer"<<endl;
                                    cin>>z;
                                    gh->data.setEx((gh->data.getEx()-z));
                                }
                                else{cout<<" choix invalide"<<endl;
                                system("pause");}
                            }

                             else{cout<<" choix invalide"<<endl;
                                system("pause");}
                        }
                    }
                    else if(case7==2)
                    {

                        cout<<"donner le num serie du Livre "<<endl;
                        cin>>cn;
                        fflush(stdin);
                        Node<Livre>*EA=livres;

                        while((EA!=NULL)&&(EA->getData().getM_serie()!=cn))
                        {
                            EA=EA->getNext();
                        }

                        if(EA==NULL)
                        {
                            cout<<"\n             !!!n'existe pas!!!\n"<<endl;
                            system("pause");
                            break;
                        }
                        Node<Livre> *gh=livres;


                        while((gh!=NULL)&&(gh->getData().getM_serie() !=cn))
                        {

                            gh=gh->getNext();
                        }

                        if (gh->getData().getM_serie()==cn)
                        {
                            cout<<"     1.titre"<<endl;
                            cout<<"     2.nombre d'exemplaire"<<endl;
                            cin>>x;
                            if(x==1)
                            {
                                cout<<"donner le nouveau titre"<<endl;

                                fflush(stdin);
                                getline(cin, ch1);

                                gh->data.setTitre(ch1);
                            }
                            else if (x==2)
                            {
                                cout<<"vous voulez   1.ajouter    2.supprimer"<<endl;
                                cin>>z;
                                if(z==1)
                                {
                                    cout<<"donner le nombre des elements supplementaires"<<endl;
                                    cin>>z;
                                    gh->data.setEx((gh->data.getEx()+z));
                                }
                                else if(z==2)
                                {
                                 cout<<"donner le nombre de elements a retirer"<<endl;
                                    cin>>z;
                                    gh->data.setEx((gh->data.getEx()-z));
                                }
                                else{cout<<" choix invalide"<<endl;
                                system("pause");}
                            }

                             else{cout<<" choix invalide"<<endl;
                                system("pause");}
                        }
                    }
                break;



                }
            }
            }
            while(choix!=5);

        }
        break;
        case 3 :
        {
            do
            {
                menu3();
                cin>>choix;
                switch(choix)
                {

                case 1 :
                {

                    system("cls");
                    cout<<"                                Emprunter"<<endl;
                    cout<<"________________________________________________________________________________"<<endl;
                    cout<<"qui veut emprunter   1.enseignant    ou   2.etudiant"<<endl;
                    cin>>em;
                    if(em==1)
                    {
                        verif=0;
                        cout<<" donner le num cin "<<endl;
                        cin>>exem;
                        Node<Enseignant> *current=enseignants;

                        while(((current!= NULL)&&(current->data).getCin()!= exem))
                        {
                            current=current->getNext();
                        }
                        if(current==NULL)
                        {
                            cout<<"votre CIN n'existe pas\n"<<endl;
                            system("pause");
                            break;
                        }
                        if (current!=NULL)
                        {
                            if ((current->data).getEmprunt() > 3)
                            {
                                cout<<"vous avez depasse la limite de nombre des documents a emprunter "<<endl;
                                system("pause");
                                break;
                            }
                        }

                        cout<< "\n choisir      1.document numerique          2.livre"<<endl;
                        cin>>case3;
                        if(case3==1)
                        {

                            Node<DocNum> *d=docnumeriques;
                            cout<<" donner le numero de serie du document  "<<endl;
                            cin>>case3;
                            while((d!=NULL)&&((d->data.getM_serie())!=case3))
                            {
                                d=(d->getNext());
                            }
                            if(d==NULL)
                            {
                                cout<<"ce numero de serie ne correspond a aucun document\n"<<endl;
                                system("pause");
                            }
                            if(d!=NULL)
                            {
                                if((d->data).getEx()<1)
                                {
                                    cout<<"le stock est vide en ce document"<<endl;

                                }
                                else
                                {
                                    (current->data).setEmprunt(((current->data).getEmprunt())+1);
                                    (d->data).setEx((d->data.getEx())-1);

                                    Emprunt pp(current->getData().getNom(),current->getData().getPrenom(),exem,d->getData().getTitre(),case3,YY,MM,DD);
                                    addToEnd(emprunts,pp);
                                }
                            }

                        }
                        if(case3==2)
                        {

                            Node<Livre> *l=livres;
                            cout<<" donner le numero de serie du Livre  "<<endl;
                            cin>>case3;
                            while((l!=NULL)&&((l->data.getM_serie())!=case3))
                            {
                                l=(l->getNext());
                            }
                            if(l==NULL)
                            {
                                cout<<"ce numero de serie ne correspond a aucun document\n"<<endl;
                                system("pause");
                            }
                            if(l!=NULL)
                            {
                                if((l->data).getEx()<1)
                                {
                                    cout<<"le stock est vide en ce livre"<<endl;

                                }
                                else
                                {
                                    (current->data).setEmprunt(((current->data).getEmprunt())+1);
                                    (l->data).setEx((l->data.getEx())-1);

                                    Emprunt pp(current->getData().getNom(),current->getData().getPrenom(),exem,l->getData().getTitre(),case3,YY,MM,DD);
                                    addToEnd(emprunts,pp);
                                }
                            }

                        }
                        system("pause");
                    }
                    else if(em==2)
                    {
                        verif=0;
                        cout<<" donner le num cin "<<endl;
                        cin>>exem;
                        Node<Etudiant> *current=etudiants;

                        while(((current!= NULL)&&(current->data).getCin()!= exem))
                        {
                            current=current->getNext();
                        }
                        if(current==NULL)
                        {
                            cout<<"votre CIN n'existe pas\n"<<endl;
                            system("pause");
                            break;
                        }
                        if (current!=NULL)
                        {
                            if ((current->data).getEmprunt()  >0)
                            {
                                cout<<"vous avez depasse la limite de nombre des documents a emprunter "<<endl;
                                system("pause");
                                break;
                            }
                        }

                        cout<< "\n choisir      1.document numerique          2.livre"<<endl;
                        cin>>case3;
                        if(case3==1)
                        {

                            Node<DocNum> *d=docnumeriques;
                            cout<<" donner le numero de serie du document  "<<endl;
                            cin>>case3;
                            while((d!=NULL)&&((d->data.getM_serie())!=case3))
                            {
                                d=(d->getNext());
                            }
                            if(d==NULL)
                            {
                                cout<<"ce numero de serie ne correspond a aucun document\n"<<endl;
                                system("pause");
                            }
                            if(d!=NULL)
                            {
                                if((d->data).getEx()<1)
                                {
                                    cout<<"le stock est vide en ce document"<<endl;

                                }
                                else
                                {
                                    (current->data).setEmprunt(((current->data).getEmprunt())+1);
                                    (d->data).setEx((d->data.getEx())-1);

                                    Emprunt pp(current->getData().getNom(),current->getData().getPrenom(),exem,d->getData().getTitre(),case3,YY,MM,DD);
                                    addToEnd(emprunts,pp);
                                }
                            }

                        }
                        if(case3==2)
                        {

                            Node<Livre> *l=livres;
                            cout<<" donner le numero de serie du Livre  "<<endl;
                            cin>>case3;
                            while((l!=NULL)&&((l->data.getM_serie())!=case3))
                            {
                                l=(l->getNext());
                            }
                            if(l==NULL)
                            {
                                cout<<"ce numero de serie ne correspond a aucun document\n"<<endl;
                                system("pause");
                            }
                            if(l!=NULL)
                            {
                                if((l->data).getEx()<1)
                                {
                                    cout<<"le stock est vide en ce livre"<<endl;

                                }
                                else
                                {
                                    (current->data).setEmprunt(((current->data).getEmprunt())+1);
                                    (l->data).setEx((l->data.getEx())-1);

                                    Emprunt pp(current->getData().getNom(),current->getData().getPrenom(),exem,l->getData().getTitre(),case3,YY,MM,DD);
                                    addToEnd(emprunts,pp);
                                }
                            }

                        }
                        system("pause");
                    }
                }
                break;
                case 2 :
                {

                    if(emprunts==NULL)
                    {

                        cout<<"la liste des emprunts est vide!! \n\n"<<endl;
                        system("pause");
                        break;
                    }
                    else
                    {
                        cout<<"donnez le type du document\n\n 1.document numerique      2.livre "<<endl;
                        cin>>TypeDoc;
                        cout<<"donnez la CIN"<<endl;
                        cin>>carteIN;
                        cout<<"donnez le numero de serie du document"<<endl;
                        cin>>NumSerie;
                        Node<Emprunt>*d=emprunts;
                        while(d!=NULL&&((d->data).getM_serie()!=NumSerie)||(d->data).getCi()!=carteIN)
                        {
                            d=d->getNext();
                        }
                        if(d==NULL)
                        {
                            cout<<"document n'existe pas \n\n"<<endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            Node<Enseignant>*ens=enseignants;
                            Node<Etudiant>*etu=etudiants;
                            while(ens!=NULL&&((ens->data).getCin()!=carteIN))
                            {

                                ens=ens->getNext();
                            }

                            while(etu!=NULL&&((etu->data).getCin()!=carteIN))
                            {

                                etu=etu->getNext();
                            }

                            if(ens!=NULL)
                            {
                                cout<<"C'est monsieu "<<(ens->data).getNom()<<" "<<(ens->data).getPrenom()<<" qui a emprunte le document \n\n"<<endl;
                                system("pause");
                                ((ens->data).setEmprunt((ens->data).getEmprunt()-1));
                            }
                            else if (etu!=NULL)
                            {
                                cout<<"C'est  "<<(etu->data).getNom()<<" "<<(etu->data).getPrenom()<<" qui a emprunte le document \n"<<endl;
                                system("pause");
                                ((etu->data).setEmprunt((etu->data).getEmprunt()-1));
                            }
                            if(TypeDoc==1)
                            {
                                Node<DocNum>*doc=docnumeriques;
                                while(doc!=NULL&&((doc->data).getM_serie()!=NumSerie))
                                {
                                    doc=doc->getNext();
                                }
                                if(doc!=NULL)
                                {
                                    ((doc->data).setEx((doc->data).getEx()+1));
                                }
                                else
                                {
                                    cout<<" \n\n veillez verifier le type du document!!! \n\n"<<endl;
                                    system("pause");
                                    break;
                                }
                            }
                            else if(TypeDoc==2)
                            {
                                Node<Livre>*liv=livres;
                                while(liv!=NULL&&((liv->data).getM_serie()!=NumSerie))
                                {
                                    liv=liv->getNext();
                                }
                                if(liv!=NULL)
                                {
                                    ((liv->data).setEx((liv->data).getEx()+1));

                                }
                                else
                                {
                                    cout<<" \n\n veillez verifier le type du document!!! \n\n"<<endl;
                                    system("pause");
                                    break;
                                }
                            }
                            else
                            {
                                cout<<"\n\n choix incorrect !!\n\n"<<endl;
                                system("pause");
                                break;
                            }
                            emprunts=supprimer_emprunt(emprunts,NumSerie,carteIN);
                            cout<<"\n \n restitution finie \n\n"<<endl;
                            system("pause");
                        }
                    }
                }
                break;
                case 3 :
                {
                    Node<Emprunt> *tmp=emprunts;
                    system("cls");
                    cout<<"\n                        Liste des Emprunts\n\n"<<endl;
                    if(tmp==NULL)
                    {
                        cout<<"la liste des emprunts est vide !!\n\n"<<endl;
                        system("pause");
                        break;
                    }
                    cout<<left<<setw(10)<<"Nom";
                    cout<<left<<setw(10)<<"Prenom";
                    cout<<left<<setw(10)<<"NumCIN";
                    cout<<left<<setw(15)<<"Titre";
                    cout<<left<<setw(9)<<"NumSerie";
                    cout<<left<<setw(14)<<"D.Emprunt";
                    cout<<left<<setw(14)<<"DateRetour"<<endl;
                    cout<<"______________________________________________________________________________"<<endl;

                    while(tmp!=NULL)
                    {
                        (tmp->data).affiche_liste_des_emprunts();
                        tmp=tmp->getNext();
                        cout<<"\n"<<endl;
                    }
                    cout<<"______________________________________________________________________________"<<endl;
                    system("pause");
                }
                break;
                case 4 :
                {
                    Date DR(YY,MM,DD);
                    Node<Emprunt> *cEMp=emprunts;
                    system("cls");
                    cout<<"\n\n                              Black List"<<endl;
                    cout<<left<<setw(10)<<"Nom";
                    cout<<left<<setw(10)<<"Prenom";
                    cout<<left<<setw(10)<<"NumCIN";
                    cout<<left<<setw(15)<<"Titre";
                    cout<<left<<setw(10)<<"NumSerie";
                    cout<<left<<setw(21)<<"DateRetour"<<endl;
                    cout<<"______________________________________________________________________________"<<endl;
                    while ((cEMp != NULL)&&(diffDate(cEMp->getData().dateR,DR)<0))
                    {
                        (cEMp->data).affiche_liste_des_emprunts();
                        cEMp=cEMp->getNext();
                        cout<<"\n"<<endl;
                    }
                    system("pause");

                }
                break;


                }
            }
            while(choix!=5);
        }
        break;

        case 4 :
        {
            system("cls");
            cout<<"\n\n\n                                  Rechercher un element"<<endl;
            cout<<"\n\n                _________________________________________________________"<<endl;
            cout<<"                    1.Rechercher un livre"<<endl;
            cout<<"                    2.Rechercher un document numerique"<<endl;
            cout<<"                    3.Rechercher un etudiant"<<endl;
            cout<<"                    4.Rechercher un enseignant"<<endl;
            cout<<"                    5.Quitter"<<endl;

            cout<<"                    _________________________________________________________"<<endl;
            cin>>m1;
            system("cls");
            switch(m1)
            {
            case 1:
            {
                cout<<"\n\n                          Rechercher un livre \n\n"<<endl;
                cout<<"     donner le mot cle:  "<<endl;
                fflush(stdin);
                getline(cin,ch11);
                system("cls");
                Node<Livre>*der=livres;
                m1=0;
                cout<<"\n\n\n"<<endl;
                cout<<left<<setw(15)<<"Titre";
                        cout<<left<<setw(13)<<"Auteur";
                        cout<<left<<setw(10)<<"NumSerie";
                        cout<<left<<setw(7)<<"exemp";
                        cout<<left<<setw(15)<<"Collection";
                        cout<<left<<setw(9)<<"NbrPage";
                        cout<<left<<setw(10)<<"Genre"<<endl;

                        cout<<"____________________________________________________________________________"<<endl;
                while(der!=NULL)
                {
                    if (recherche_particuliere(ch11,der->getData().getTitre())!=-1)
                    {
                        m1=m1+1;

                        (der->getData()).affiche_document();
                    }
                    der=der->getNext();
                }
                if(m1==0)
                {
                    system("cls");
                    cout<<"\n\n\n         Desole,on n'a pas un livre portant ce nom\n\n"<<endl;
                }
                system("pause");

            }
            break;
            case 2:
            {
                system("cls");
                cout<<"\n\n             Rechercher un document numerique  \n\n"<<endl;

                cout<<"donner le mot cle"<<endl;
                fflush(stdin);
                getline(cin,ch11);
                Node<DocNum>*az=docnumeriques;
                m1=0;
                system("cls");
                cout<<"\n\n\n"<<endl;
                cout<<left<<setw(15)<<"Titre";
                        cout<<left<<setw(13)<<"Auteur";
                        cout<<left<<setw(10)<<"N.Serie";
                        cout<<left<<setw(7)<<"ex.";
                        cout<<left<<setw(15)<<"Collection";
                        cout<<left<<setw(8)<<"TypeDoc";
                        cout<<left<<setw(9)<<"TypeDisc";
                        cout<<endl;
                        cout<<"___________________________________________________________________________\n"<<endl;
                while(az!=NULL)
                {
                    if (recherche_particuliere(ch11,az->getData().getTitre())!=-1)
                    {
                        m1=m1+1;
                        (az->getData()).affiche_document();
                    }
                    az=az->getNext();
                }
                if(m1==0)
                {
                    system("cls");
                    cout<<"\n\n\n                Desole,on n'a pas un document numerique portant ce nom\n\n\n"<<endl;
                }
                system("pause");

            }
            break;
            case 3 :
            {
                system("cls");
                cout<<"\n\n\n                     Rechercher un etudiant \n\n\n"<<endl;
                cout<<"          donner le mot cle:"<<endl;
                fflush(stdin);
                getline(cin,ch11);
                Node<Etudiant>*etuetu=etudiants;
                m1=0;
                cout<<left<<setw(20)<<"NomEtudiant";
                        cout<<left<<setw(20)<<"PrenomEtudiant";
                        cout<<left<<setw(20)<<"NumCarteNational";
                        cout<<left<<setw(20)<<"NombreEmprunt"<<endl;
                        cout<<"________________________________________________________________________________"<<endl;
                while(etuetu!=NULL)
                {
                    if ((recherche_particuliere(ch11,etuetu->getData().getNom())!=-1)||(recherche_particuliere(ch11,etuetu->getData().getPrenom())!=-1))
                    {
                        m1=m1+1;
                        (etuetu->getData()).afficher();
                    }
                    etuetu=etuetu->getNext();
                }
                if(m1==0)
                {
                    system("cls");
                    cout<<"\n\n\n\n                   Desole,on n'a pas un etudiant portant ce nom ou prenom"<<endl;
                }
                system("pause");

            }
            break;
            case 4:
            {
                system("cls");
                cout<<"\n\n\n                         Rechercher un enseignant \n\n\n"<<endl;

                cout<<"                   Donner le mot cle"<<endl;
                fflush(stdin);
                getline(cin,ch11);
                Node<Enseignant>*ensens=enseignants;
                m1=0;
                cout<<left<<setw(20)<<"NomEnseignant";
                        cout<<left<<setw(20)<<"PrenomEnseignant";
                        cout<<left<<setw(20)<<"NumCarteNational";
                        cout<<left<<setw(20)<<"NombreEmprunt"<<endl;

                        cout<<"________________________________________________________________________________"<<endl;
                while(ensens!=NULL)
                {
                    if ((recherche_particuliere(ch11,ensens->getData().getNom())!=-1)||(recherche_particuliere(ch11,ensens->getData().getPrenom())!=-1))
                    {
                        m1=m1+1;
                        (ensens->getData()).afficher();
                    }
                    ensens=ensens->getNext();
                }
                if(m1==0)
                {
                    system("cls");
                    cout<<"\n\n\n                          Desole on n'a pas un enseignant portant ce nom ou prenom\n\n\n "<<endl;
                }
                system("pause");

            }
            break;

            }

        }
        break;

        case 5 :
            break;
        }


    }
    while(a!=5);
    string const nomFichier("etudiant.txt");
    ofstream monFlux(nomFichier.c_str());
    if(monFlux)
    {
        Node<Etudiant> *op=etudiants;
        while(op!=NULL)
        {
            monFlux<<op->getData().getNom()<<endl;
            monFlux<<op->getData().getPrenom()<<endl;
            monFlux<<op->getData().getCin()<<endl;
            monFlux<<op->getData().getEmprunt()<<endl;
            op=op->getNext();
        }


    }
    string const nomFich("enseignant.txt");
    ofstream monFl(nomFich.c_str());
    if(monFl)
    {
        Node<Enseignant> *op=enseignants;
        while(op!=NULL)
        {
            monFl<<op->getData().getNom()<<endl;
            monFl<<op->getData().getPrenom()<<endl;
            monFl<<op->getData().getCin()<<endl;
            monFl<<op->getData().getEmprunt()<<endl;
            op=op->getNext();
        }


    }
    string const nomFic("livre.txt");
    ofstream monF(nomFic.c_str());
    if(monF)
    {
        Node<Livre> *po=livres;
        while(po!=NULL)
        {
            monF<<po->getData().getTitre()<<endl;
            monF<<po->getData().getAuteur()<<endl;
            monF<<po->getData().getM_serie()<<endl;
            monF<<po->getData().getEx()<<endl;
            monF<<po->getData().getCollection()<<endl;
            monF<<po->getData().getNbrepage()<<endl;
            monF<<po->getData().getGenre()<<endl;

            po=po->getNext();
        }


    }
    string const nFic("docnum.txt");
    ofstream mF(nFic.c_str());
    if(mF)
    {
        Node<DocNum> *por=docnumeriques;
        while(por!=NULL)
        {
            mF<<por->getData().getTitre()<<endl;
            mF<<por->getData().getAuteur()<<endl;
            mF<<por->getData().getM_serie()<<endl;
            mF<<por->getData().getEx()<<endl;
            mF<<por->getData().getCollection()<<endl;
            mF<<por->getData().getType_Du_Document()<<endl;
            mF<<por->getData().getType_Du_Disque()<<endl;
            mF<<por->getData().getTaille_Sur_Disque()<<endl;
            por=por->getNext();
        }


    }

    string const nmFic("emprunt.txt");
    ofstream mFx(nmFic.c_str());
    if(mFx)
    {
        Node<Emprunt> *liEm=emprunts;
        while(liEm!=NULL)
        {
            mFx<<liEm->getData().getNM()<<endl;
            mFx<<liEm->getData().getPR()<<endl;
            mFx<<liEm->getData().getCi()<<endl;
            mFx<<liEm->getData().getTT()<<endl;
            mFx<<liEm->getData().getM_serie()<<endl;
            mFx<<liEm->getData().getAn()<<endl;
            mFx<<liEm->getData().getMois()<<endl;
            mFx<<liEm->getData().getJour()<<endl;
            liEm=liEm->getNext();
        }
    }
    return 0;
}
template <class T>
int Length(Node<T> *head)
{
    Node<T> *current=head;
    int count=0;

    while (current != NULL)
    {
        count++;
        current = current->getNext();
    }
    return(count);
}


///////////////////////////////////
template <class T>
void printList(Node<T> *head)
{
    Node<T> *current=head;
    int count=0;

    while (current != NULL)
    {
        cout << "Lien " << count << " contient " << current->getData() << endl;
        current = current->getNext();
        count++;
    }

}

//////////////////////////////////////////////
// add a link at the start of the list.
// Since the head of the list is being changed
// it must be passed by reference
template <class T>
void addToStart(Node<T> *&headRef, T NewData)
{
    Node<T> *newNode = new Node<T>;

    newNode->setData(NewData);
    newNode->setNext(headRef);

    headRef=newNode;
}

template <class T>
void addToEnd(Node<T> *&headRef, T NewData)
{
    Node<T> *newNode = new Node<T>;
    newNode->setData(NewData);
    newNode->setNext(NULL);

    if (headRef==NULL) // if list is empty
        headRef=newNode;
    else // Find the end of the list
    {
        Node<T> *current=headRef;
        while (current->getNext() != NULL)
            current = current->getNext();

        current->setNext(newNode);
    }
}
template <class T>
void supprim(Node<T> *&headRef, int position)
{
    int k=1;
    Node<T> *newNode=new Node<T>;
    newNode=headRef;
    if(headRef==NULL)
        cout<<"la liste est vide"<<endl;
    else

    {
        Node<T> *current=new Node<T>;
        current=headRef;
        Node<T> *cur=new Node<T>;
        cur=headRef;

        while ((current->getNext() !=NULL)&&(k<position))
        {

            newNode=current;
            current=current->getNext();
            k=k+1;
        }

        if(position==1)
        {
            cur=headRef;
            headRef=headRef->getNext();
            cur=NULL;
        }
        cur=newNode->getNext()->getNext();
        newNode->setNext(cur);
        current=NULL;


    }

}
Node<Emprunt> *supprimer_emprunt(Node<Emprunt> *emprunts,int numero_serie,int carteIN)
{


    Node<Emprunt> *p=emprunts;
    Node<Emprunt> *tmp=emprunts;

    if(((tmp->data).getM_serie()==numero_serie)&&(tmp->data).getCi()==carteIN)
    {
        emprunts=(tmp->getNext());
        delete tmp;
        return emprunts;
    }
    while((((tmp->data).getCi()!=carteIN)||((tmp->data).getM_serie()!=numero_serie))&&(tmp->getNext()!=NULL))
    {
        p=tmp;
        tmp=tmp->getNext();
    }
    if(((tmp->data).getM_serie()==numero_serie)&&((tmp->data).getCi()==carteIN))
    {
        Node<Emprunt>*a=emprunts;
        a=((p->getNext())->getNext());
        p->setNext(a);
        delete tmp;
    }
    return emprunts;
}
Node<DocNum> *supprimer_doc_num(Node<DocNum> *docnumeriques, int NumSerie)
{

    Node<DocNum> *p=docnumeriques;
    Node<DocNum> *tmp=docnumeriques;


    if(((tmp->data).getM_serie()==NumSerie))
    {
        docnumeriques=(tmp->getNext());
        delete tmp;
        return docnumeriques;
    }
    while((((tmp->data).getM_serie()!=NumSerie))&&(tmp->getNext()!=NULL))
    {
        p=tmp;
        tmp=tmp->getNext();
    }
    if(((tmp->data).getM_serie()==NumSerie))
    {
        Node<DocNum>*a=docnumeriques;
        a=((p->getNext())->getNext());
        p->setNext(a);
        delete tmp;
    }

    return docnumeriques;

}

Node<Livre> *supprimer_doc_livres(Node<Livre> *livres, int NumSerie)
{

    Node<Livre> *p=livres;
    Node<Livre> *tmp=livres;


    if(((tmp->data).getM_serie()==NumSerie))
    {
        livres=(tmp->getNext());
        delete tmp;
        return livres;
    }
    while((((tmp->data).getM_serie()!=NumSerie))&&(tmp->getNext()!=NULL))
    {
        p=tmp;
        tmp=tmp->getNext();
    }
    if(((tmp->data).getM_serie()==NumSerie))
    {
        Node<Livre>*a=livres;
        a=((p->getNext())->getNext());
        p->setNext(a);
        delete tmp;
    }

    return livres;

}
int recherche_particuliere(string mot_cle,string titre)  /*cette fonction permet la recherche d'une chaine de caractére dans une autre en retournant -1  en cas d'inexistence ,sinon ,elle retourne l'indice de debut d'existence*/
{
    int carac, pat, longueurPatron, longueurTexte;
    longueurPatron = mot_cle.size();
    longueurTexte = titre.size();
    pat = 0;
    if(longueurPatron <= longueurTexte)
    {
        carac = 0;
        do
        {
            if((mot_cle[pat] == titre[carac])||(('a'<=mot_cle[pat]<='z')&&(mot_cle[pat]-32)==titre[carac])||(('A'<=mot_cle[pat]<='Z')&&(mot_cle[pat]+32)==titre[carac]))
            {
                pat++;
                carac++;
            }
            else
            {
                carac = carac - pat + 1; // avance dans Texte
                pat = 0;
            } //if
        }
        while(pat < longueurPatron && carac < longueurTexte);
    } //if;
    if((pat >= longueurPatron)) // trouvé
        return carac - longueurPatron;
    else
        return -1;
}
Node<Etudiant> *supprimer_etud(Node<Etudiant> *etudiants, int NumCIN)
{

    Node<Etudiant> *p=etudiants;
    Node<Etudiant> *tmp=etudiants;


    if(((tmp->data).getCin()==NumCIN))
    {
        etudiants=(tmp->getNext());
        delete tmp;
        return etudiants;
    }
    while((((tmp->data).getCin()!=NumCIN))&&(tmp->getNext()!=NULL))
    {
        p=tmp;
        tmp=tmp->getNext();
    }
    if(((tmp->data).getCin()==NumCIN))
    {
        Node<Etudiant>*a=etudiants;
        a=((p->getNext())->getNext());
        p->setNext(a);
        delete tmp;
    }

    return etudiants;

}

Node<Enseignant> *supprimer_ens(Node<Enseignant> *enseignants, int NumCIN)
{

    Node<Enseignant> *p=enseignants;
    Node<Enseignant> *tmp=enseignants;


    if(((tmp->data).getCin()==NumCIN))
    {
        enseignants=(tmp->getNext());
        delete tmp;
        return enseignants;
    }
    while((((tmp->data).getCin()!=NumCIN))&&(tmp->getNext()!=NULL))
    {
        p=tmp;
        tmp=tmp->getNext();
    }
    if(((tmp->data).getCin()==NumCIN))
    {
        Node<Enseignant>*a=enseignants;
        a=((p->getNext())->getNext());
        p->setNext(a);
        delete tmp;
    }

    return enseignants;

}
