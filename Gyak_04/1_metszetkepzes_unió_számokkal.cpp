//Adottak az A és B tömbök. Készítsük el a metszetüket és uniójukat! 
//Írjuk ki az eredeti tömböket és az eredmény tömböket is a képernyõre!
#include <iostream>
using namespace std;
int main()
{	
// Adatbevitel 
	int A_tomb[10]={13, 28, 43,37,10,5,8,99,101,2};
	int B_tomb[5]={6,43,37,10,88};
	int i, j, cdb = 0, Metszet_tomb[15], Unio_tomb[15];
// tömbök kiíratása					képzés bemutatásához
    for(i=0; i<10;i++)
    {
 	   cout<<A_tomb[i]<<" ";
    }
	cout<<endl;
	for(j=0; j<5;j++)
    {
	   cout<<B_tomb[j]<<" ";
    }
	cout<<endl<<endl;
// metszetképzés
	for(i=0;i<10;i++)
	{
	   j=0;
	   while (j < 5 && A_tomb[i] != B_tomb[j])
	   {
		   j++;
	   }
		if(j<5) 
		{ 
			Metszet_tomb[cdb]=A_tomb[i]; 
			cdb++;
		}
     }

// metszet tömb kiíratása
	for (i = 0; i < cdb; i++)
	{
		cout << Metszet_tomb[i] << " ";
	}
	
// unióképzés
 	for(i=0;i<10;i++)
    {
      Unio_tomb[i]=A_tomb[i];
    }
	cdb=10;
	for(j=0;j<5;j++)
	{
	   i=0;
	   while (i < 10 && A_tomb[i] != B_tomb[j])
	   {
		   i++;
	   }
	   if(i>9) 
	   {
		   Unio_tomb[cdb]=B_tomb[j];
		   cdb++;
	   }
    }
// unio tömb kiíratása
	 cout<< endl;
	 for (i = 0; i < cdb; i++)
	 {
		 cout << Unio_tomb[i] << " ";
	 }
	 cout<<endl;	
return 0;
}
