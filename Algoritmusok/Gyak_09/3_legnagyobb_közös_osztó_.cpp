#include <iostream>
using namespace std;
int lnko(int x, int y);
int main()
{
 int szam1, szam2;
 cout<<"Adja meg a ket szamot";
 cin>>szam1>>szam2;
 cout<<"\nA ket szam legnagyobb kozos osztoja"<<lnko(szam1,szam2)<<endl;
 system("pause");
 return 0;   
}

int lnko(int x, int y)
{
	int max;
	if (x==y) return  x;
    if(x<y)max=lnko(x,y-x);
		       else max=lnko(x-y,y);
		       
	return max;
}

/*Függvény lnko(a, b : egész számok) : egész szám
ha a=b akkor lnko := a
ha a<b akkor lnko := lnko(a, b-a)
ha a>b akkor lnko := lnko(a-b, b) 
*/
