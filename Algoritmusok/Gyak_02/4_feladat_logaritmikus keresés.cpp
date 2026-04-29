//A Pontszam 8 elemû tömbben egy felmérõ pontszámait helyeztük el (0-100) 
//növekvõ sorrendben. Határozzuk meg, hogy egy billentyûzetrõl bekért pontszám
//eleme -e a tömbnek és ha igen hányadik? - LOGARITMIKUS KERESÉS
#include <iostream>			
using namespace std;
int main( )
{
	int Pontszam[8]={2,67,78,89,90,92,95,100,};
	int pont,k, A=0, F=7;
	cout<<"Adja meg a keresett pontot!";
	cin>>pont;
    do
    {
        k=(A+F)/2;
        if(Pontszam[k]<pont){A=k+1;}
        if(Pontszam[k]>pont){F=k-1;}
    }
    while(A<=F&&Pontszam[k]!=pont);
    if(A<=F)cout<<"A keresett pont a Pontszam tomb "<<k<<". indexu eleme";  //0 az elsõ elem
    else cout<<"A keresett pont nincs a Pontszam tombben";
    cout<<endl; 
    return 0;
}
	
