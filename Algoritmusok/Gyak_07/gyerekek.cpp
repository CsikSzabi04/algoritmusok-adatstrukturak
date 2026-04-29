
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct tanulo
{
   int ev1, ev2 ;
   string nev1,nev2;    
};

int main()
{	
// 1, Adatbevitel 
	ifstream be("gyerek.txt");
	if(be.fail()){cout<<"hiba";system("pause");exit(1);}
	int i=0,j;
	tanulo csalad[10];
	while(!be.eof())
      {
 	   be>>csalad[i].ev1;
	   be>>csalad[i].ev2;
	   be>>csalad[i].nev1;
	   be>>csalad[i].nev2;
       cout<<csalad[i].ev1<<" "<<csalad[i].ev2<<" "<<csalad[i].nev1<<" "<<csalad[i].nev2<<endl;
	   i++;
	  }
    be.close();
	int db = i;
    cout<<endl;


 // 2, Hány gyermek múlt el már 10 éves?
 int tizeves=0;
 for(i=0;i<db;i++)
    {
        if(csalad[i].ev1>10)tizeves++;
        if(csalad[i].ev2>10)tizeves++;
    }
  cout<<"A tiz ev felettiek szama : "<<tizeves<<endl;  
    
//  3, Mennyi a gyerekek átlagéletkora?	
    
    int atl=0;
    for(i=0; i<db;i++)
     atl=atl+csalad[i].ev1+csalad[i].ev2;
    cout<<"A gyerekek atlageletkora : "<<(float)atl/(2*db)<<endl;

//4, Döntse el vannak-e ikrek a gyerekek között! 	
  
    i=0;
    while((i<db)&&(csalad[i].ev1!=csalad[i].ev2))
    i++;
    if(i<db) cout<<"\nvan iker a gyerekek kozott"<<endl;

//5, Írja ki a képernyõre a gyerekek nevét névsor szerint növekvõ sorrendben!
    string seged[20];
    string temp;
    for(i=0;i<db;i++)
    {
      seged[i]=csalad[i].nev1;
      seged[i+db]= csalad[i].nev2;     
    }
    for(i=0;i<2*db;i++)
   	{
       for(j=i+1;j<2*db;j++)
       {
          if(seged[i]>seged[j])
             {
             temp=seged[i];
             seged[i]=seged[j];
             seged[j]=temp;
             }
       }
    }
   	for(i=0;i<2*db;i++)
      cout<<seged[i]<<endl;

// 6. Gyûjtsük a gyerekek nevét egy tömbbe, de úgy, hogy minden név csak egyszer szerepeljen!
	string egyszer[20];
	int egyszerdb = 0;
	for (i = 0; i < 2 * db; i++)
	{
		int j=0;
		while (j < egyszerdb && egyszer[j] != seged[i])
			j++;
		if (j == egyszerdb)
		{
			egyszer[egyszerdb] = seged[i];
			egyszerdb++;
		}
	}
	cout << "\nKulonfele nevek :"<< endl;
	for (i = 0; i<egyszerdb; i++)
		cout << egyszer[i] << endl;

cout<<endl<<endl;
system("PAUSE");
return 0;
}
   
