#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

class Date
{
public:
    int annee;
    int mois;
    int jour;
public:
    Date(int annee=0,int mois=0,int jour=0);
    ~Date();

    friend int diffDate(Date date1,Date date2);

    friend Date retour(int n ,Date date1);

};


#endif // DATE_H_INCLUDED
