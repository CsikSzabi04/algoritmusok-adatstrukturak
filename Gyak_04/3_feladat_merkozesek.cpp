/* Egy 16 csapatos labdarúgó bajnokság egyik fordulójának eredményeit 
tároljuk a merkozes.txt állományban. Ebben a fordulóban nem biztos, hogy 8 mérkõzés volt,
néhány meccs elmaradt a rossz idõjárás miatt. Minden mérkõzés
eredménye új sorban van és a gólok v.mint a csapatok száma szóközzel elválasztva. (3 2 ute vac)
1, Olvassa be a fájlt egy olyan adatszerkezetbe amit az alábbi
kérdésekhez fel tud használni (struktúra)) és írassa ki: 
Hány mérkõzés volt a fordulóban!
2, Hány csapat nyert otthon?
3, Melyik csapat rúgta a legtöbb gólt?
4, Volt -e döntetlen?
5, Hány golt lõtt az ute?(Nem tudjuk, hogy egyáltalán játszott-e)
AZ EGYES RÉSZFELADATOKAT FÜGGVÉNYEKKEL OLDJUK MEG!!!
*/
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct fordulo
{
   int lott, kapott;
   string nev1, nev2;    
};
int Beolvas(fordulo* tmb, string nev);
int Hazai_nyert(fordulo* tmb, int n);
string Legtobb_gol(fordulo* tmb, int n);
bool Dontetlen(fordulo* tmb, int n);
int UTE_gol(fordulo* tmb, int n, string nev);
int main()
{	
    fordulo A[8];
    string fnev = "merkozes.txt";
    int db = Beolvas(A,fnev);
    cout << "A forduloban: " << db << " merkozest jatszottak" << endl;
    cout<<Hazai_nyert(A,db)<<" Csapat gyozott otthon"<<endl;
    cout << "A legtobb golt a " << Legtobb_gol(A,db) << " lotte" << endl;
    if(Dontetlen(A,db)) cout<<"Volt dontetlen merkozes" << endl;
        else cout<< "Nem volt dontetlen merkozes" << endl;
    int utegol = UTE_gol(A, db, "ute");
    if (utegol > -1) cout << utegol << " golt lott az  ute" << endl;
    else cout<<"Nem jatszott az UTE" << endl;
    return 0;
}
// Adatbevitel 
int Beolvas(fordulo* tmb, string nev)
{
    ifstream be(nev);
    if (be.fail()) { cout << "hiba"; system("pause"); exit(1); }
    int i = 0, j, db = 0;
    while (!be.eof())
    {
        be >> tmb[i].lott >> tmb[i].kapott >> tmb[i].nev1 >> tmb[i].nev2;
        i++;
    }
    be.close();
    return i;
}
//  ? csapat nyert otthon.  
int Hazai_nyert(fordulo* tmb, int n)
{
    int nyert = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmb[i].lott > tmb[i].kapott)
            nyert++;
    }
    return nyert;
}
//  ? Melyik csapat rúgta a legtöbb gólt?    
string Legtobb_gol(fordulo* tmb, int n)
{
    string maxcsapat = tmb[0].nev1; // most nem a sorszámot jegyezzük meg, mert minden sorban(struktúra adatban) két adat -hazai, vendég van
    int max = -1;                       // a legtöbb gól száma
    for (int i = 0; i < n; i++)
    {
        if (tmb[i].lott > max) { max = tmb[i].lott; maxcsapat = tmb[i].nev1; }
        if (tmb[i].kapott > max) { max = tmb[i].kapott; maxcsapat = tmb[i].nev2;}
    }
    return maxcsapat;
}
// Volt-e döntetlen?
bool Dontetlen(fordulo* tmb, int n)
{
    int i = 0;
    while (i < n && tmb[i].lott != tmb[i].kapott)
        i++;
    if (i < n) return true;
    else return false;
}
//  ? golt lott az ute -- nem tudjuk, hogy jatszott-e
int UTE_gol(fordulo* tmb, int n, string nev)
{
    int i = 0;
    while (i < n && !(tmb[i].nev1 == nev || tmb[i].nev2 == nev))
        i++;
    if (i == n) return -1;
    else
        if (tmb[i].nev1 == nev) return tmb[i].lott;
        else return tmb[i].kapott;
}