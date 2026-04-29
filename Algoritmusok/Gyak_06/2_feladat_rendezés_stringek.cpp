#include <iostream>
#include <string>
using namespace std;
// Egy utazó ügynök 6 várost látogatott meg a héten. A meglátogatott városok neveit egy tömbben tárolta.
// Rendezzük a tömbben lévõ 6 város nevét abc sorrendbe!
int main()
{	
// Adatbevitel 
	int i=0,j;
	string tmb[6]={ "Cegled", "Pecs", "Vac", "Miskolc", "Ada", "Kaposvar" };
	// rendezés elõtt
	cout<<"Rendezes elott :"<<endl;
	for (int i = 0; i < 6; i++)
	{
		cout<< tmb[i]<< " ";
	}	
//RENDEZÉS
	string seged;
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<6;j++)
		{     
			if(tmb[i]>tmb[j])
			{
				seged=tmb[i];
				tmb[i]=tmb[j];
				tmb[j]=seged;
			}
	    }
     }		
//Rendezett tömb kiíratása a képernyõre  
	cout << "\nRendezes utan :" << endl;
	for(i=0; i<6;i++)
    { 	   
	   cout<<tmb[i]<<" ";
	} 
	cout << endl;
 return 0;
}
