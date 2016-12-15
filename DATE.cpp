#include"DATE.h"
#include <iostream>
#include <string>
using namespace std;


Date::Date(int annee,int mois,int jour)
{
    this->annee=annee;
    this->mois=mois;
    this->jour=jour;
}
Date::~Date()
{

}
int diffDate(Date date1,Date date2)
{
    int a;
    a=(date1.annee-date2.annee)*365 +(date1.mois-date2.mois)*30 + date1.jour-date2.jour;
    return a;

}
Date retour(int n ,Date date1)
{
    int j=date1.jour;
    int a=date1.annee;
    int m=date1.mois;
    Date dateR;
    j=date1.jour+n;

    if(j>30)
    {
        m=m+1;
        j=j-30;
        }
    if (m>12)
    {
        a=a+1;
        m=m-12;
    }
    dateR.annee=a;
    dateR.mois=m;
    dateR.jour=j;
    return dateR;
}



