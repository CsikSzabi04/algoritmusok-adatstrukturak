/*2 Kockával dobunk egyszerre- 100 -szor
    a - Töltsünk fel egy tömböt, írassuk ki a képernyõre
    c - írassuk ki , hogy az egyes dobásokból mennyi volt
A feladatra bemutatok  3 megoldást.   */    
#include<ctime>
# include <iostream>			
using namespace std;
int main( )
{
	srand((unsigned)time(NULL));
    int atlag=0,i,Kocka[100];
 //tombfeltoltés 
    int ered[6]={0};
    for( i=0; i<100; i++)
    {
     Kocka[i]=rand()%6+1;
     cout<<Kocka[i]<<" ";
    }
    
// 1. - nagyon gyenge megoldás ( if else -k egymásba ágyazva jobb lenne!)
    
    for( i=0; i<100; i++)
    {
     if(Kocka[i]==1) ered[0]++;
     if(Kocka[i]==2) ered[1]++;
     if(Kocka[i]==3) ered[2]++;
     if(Kocka[i]==4) ered[3]++;
     if(Kocka[i]==5) ered[4]++;
     if(Kocka[i]==6) ered[5]++;    
    }
// 2. - gyenge megoldás
/*
 for( i=0; i<100; i++)
    {
    switch(Kocka[i])
    {
     case 1: ered[0]++;break;
     case 2: ered[1]++;break; 
     case 3: ered[2]++;break; 
     case 4: ered[3]++;break; 
     case 5: ered[4]++;break;
     case 6: ered[5]++;break;
    }
    } 
    */  
//3. - hatékonyabb megoldás - elágazás helyett indexelt változók
 
   for( i=0; i<100; i++)
        ered[Kocka[i]-1]++;
       
 // kiíratás
 
 for (i=0; i<6; i++)
     cout<<"\nAz "<<i+1<<"-es dobasok szama :"<<ered[i];

    cout<<endl;
system("pause");
return 0;
}
