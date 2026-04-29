/*Egy 16 csapatos labdarúgó bajnokság egyik fordulójának eredményeit 
tároljuk a merkozes.txt állományban. Ebben a fordulóban nem biztos, 
hogy 8 mérkõzés volt, néhány meccs elmaradt a rossz idõjárás miatt. 
Minden merkozes eredmenye uj sorban van es a golok v. mint a csapatok szama
szoközzel elválasztva. (3 2 ute vac)
Olvassa be a fájlt egy olyan adatszerkezetbe amit az alábbi
kérdésekhez fel tud hasznalni (struktúra)) és írassa ki hány mérkõzés volt a fordulóban!
? Hány csapat nyert otthon.
? Melyik csapat rúgta a legtobb golt.
? Volt -e döntetlen.
? Hany golt lõtt az ute (tudjuk hogy játszott).
! Rendezze a csapatokat névsor szerint növekvõ sorrendbe
és írja ki a csapatok.txt állományba
Az egyes feladatrészeket függvényekkel oldja meg!*/
#include <iostream>/
#include <fstream>
#include <string> 
using namespace std;
struct fordulo
{
   int lott, kapott ;
   string nev1, nev2;    
};
int adatbe(fordulo * tmb);
void rendez(fordulo *tmb, int d);

int main()
{	
	fordulo A[8];
	int i=0,j,db=adatbe(A);
	cout<<"\n A forduloban :"<<db<<" merkozest jatszottak"<<endl;
	cout<< "A csapatok nevsora rendezve :"<<endl;
	rendez(A,db); 
    return 0;
}

int adatbe(fordulo * tmb)
{
	int db=0;	
	ifstream be("merkozes.txt");
	if(be.fail()){cout<<"hiba";system("pause");exit(1);}
	while(be >> tmb[db].lott >> tmb[db].kapott>> tmb[db].nev1>> tmb[db].nev2)
	{
 	   cout<<tmb[db].lott<<" "<<tmb[db].kapott<<" "<<tmb[db].nev1<<" "<<tmb[db].nev2<<endl;
	   db++;
	}
	be.close(); 
return db;
}
void rendez(fordulo *tmb, int d)
{
	string seged[16];
    string temp;
    int i, j=0;
    for(i=0;i<d;i++)
    {
      seged[j]=tmb[i].nev1;
      j++;
      seged[j]=tmb[i].nev2; 
      j++;            
    }
    ofstream ki("csapatok.txt");
   	if(ki.fail()){cout<<"hiba";system("pause");exit(1);}
   	
    for(i=0;i<2*d-1;i++)
   	{
       for(j=i+1;j<2*d;j++)
       {
          if(seged[i]>seged[j])
             {
             temp=seged[i];
             seged[i]=seged[j];
             seged[j]=temp;
             }
       }
    }
   	for(i=0;i<2*d;i++)
   	{
      cout<<seged[i]<<endl;
      ki<<seged[i]<<endl;
    }
    ki.close();	
}


