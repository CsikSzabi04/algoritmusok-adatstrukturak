#include <iostream>
using namespace std;
double fakt(int x);
int main()
{
      int szam;
      cout<<"\nAdjon meg egy 0 -nál nagyobb szamot szamot\n";
      cin>>szam;
      cout<<"A szam faktorialisa : "<<fakt(szam)<<endl;
    return 0;
}
double fakt(int x )
{
       double szorzat;
       if (x == 0) szorzat = 1;
       else szorzat = x * fakt(x - 1);
return szorzat;
}
