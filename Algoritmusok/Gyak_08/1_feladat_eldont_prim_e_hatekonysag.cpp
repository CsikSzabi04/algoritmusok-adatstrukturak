/* A feladatban bekérünk egy számot és eldöntjük, hogy prím-e?
A feladatra 7 megoldást adunk ahol is a kevésbé hatékony felõl haladunk az
egyre hatékonyabb megoldás felé */
# include <iostream>
# include <cmath>		// a matematikai függvények szerepelnek ebben az állományban
using namespace std;
int main( )
{
    int i,szam,osztok=0;
	cout<<"Adjon meg egy számot";
    cin>>szam;
   /* for(i=2;i<szam-1;i++)                         //1. megoldás 
       if(szam%i==0) osztok++;
    if(osztok==0) cout<<"prim";
                    else cout<<"nem prim"; 
                    */
                    
   /* for(i=2;i<=szam/2;i++)                         //2. megoldás 
       if(szam%i==0) osztok++;
    if(osztok==0) cout<<"prim";
                    else cout<<"nem prim";  */
                    
   
   
    /*for(i=2;i<=sqrt((float)szam);i++)             //3. megoldás 
       if(szam%i==0) osztok++;
    if(osztok==0) cout<<"prim";
                    else cout<<"nem prim"; */                     
        
    /* for(i=2;i<=sqrt((float)szam)&& osztok==0;i++)  //4. megoldás 
       if(szam%i==0) osztok++;
    if(osztok==0) cout<<"prim";
                    else cout<<"nem prim";   */
    
    /*
    for(i=2;i<=sqrt((float)szam);i++)                 //5. megoldás 
       if(szam%i==0) break;
       if(i<=sqrt((float)szam)) cout<<"nem prim";
                    else cout<<"prim"; */
    /* i=2;              
     while(i<=sqrt((float)szam)&& szam%i!=0)	      //6. megoldás
        i++;
      if(i<=sqrt((float)szam)) cout<<"nem prim";
                    else cout<<"prim";             
      */                           
        i=2;  
        int x= sqrt((float)szam);           
     while(i<=x&& szam%i!=0)	                      //7. megoldás
        i++;
      if(i<=x) cout<<"nem prim";
                    else cout<<"prim";                       
     cout<<endl;	
   return 0;
}

   
