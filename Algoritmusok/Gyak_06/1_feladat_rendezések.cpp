//Adott egy 10 elemû sorozat, as orozat elemeit tároljuk egy tömbbn.
// Rendezzük az A tömböt közvetlen kiválasztássl, minimum kiválasztással, 
//buborék rendezéssel és beszúró rendezéssel is!*/
#include <iostream>
using namespace std;
int main()
{
	int seged,ertek,i,j;
	int A[10]={13,28,43,37,10,5,8,99,101,25};

// rendezetlen tömb kiíratása	
   for (int i=0;i<10;i++)
       cout<<A[i]<<" " ;
/************************************************** 
rendezés közvetlen kiválasztással    
    
    for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<10;j++)
		{
          if(A[i]>A[j])
             {
		     seged=A[i];
		     A[i]=A[j];
		     A[j]=seged;
		     }
		}
	}*/
/**************************************************
rendezés minimum kiválasztással
	
    for(i=0;i<9;i++)
	{
	   seged=i;
	   ertek=A[i];
	   for(j=i+1;j<10;j++)
       {
	    if(ertek>A[j])
           {
	       ertek=A[j];
	       seged=j;
	       }
       }
	   A[seged]=A[i];
	   A[i]=ertek;
	}*/
/**************************************************
buborékos rendezés
	
    for(i=1;i<10;i++)
    {
      for(j=9;j>=i;j--) 
      {
       if(A[j]<A[j-1])
         {
         seged=A[j-1];
         A[j-1]=A[j];
         A[j]=seged;
         }                 
      }
    }*/
/**************************************************
egyszerû beillesztéses rendezés*/
 
 for(j=1;j<10;j++)
    {
      i=j-1;
      seged=A[j];
     while(i>=0 && seged<A[i])
     {
       A[i+1]=A[i];
       i--;
     }
     A[i+1]=seged;
    } 
                     
// rendezett tömb kiíratása	
   cout<<endl;
   for(int i=0;i<10;i++)
      cout<<A[i]<<" ";
return 0;
}
