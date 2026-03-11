#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
/* A szotar.txt állományban legfeljebb 150 magyar szót tárolunk abc sorrendben. Minden 
szó új sorban helyezkedik el. 
Hajtsa végre az alábbi feladatokat függvények sgítségével:
1. Olvassa be a szavakat egy tömbbe és írja ki a szavak számát!
A Beolvas() függvény két paraméterrel rendelkezzen (  a feltöltendõ tömb és a megnyitandó
állomány nevével és adja vissza a szótárban lévõ szavak számát!
2, Leghosszabb() adja vissza a leghosszabb szó értékét!
3,Keressen meg a tömbbe egy billentyûzetrõl bekért szót és írja ki a megtalált szó 
sorszámát! Használjon Linearis keresést!
Linearis() - a függvény adja vissza a megtalált szó sorszámát úgy, hogy 0-t adjon vissza
ha nincs meg a keresett szót különben pedig a szó sorszámát( a sorszámok 1-el kezdõdnek)

4, Keressen meg a tömbbe egy billentyûzetrõl bekért szót és írja ki a megtalált szó 
sorszámát! Használjon Logaritmikus keresést!
Logaritmikus() - a függvény adja vissza a megtalált szó sorszámát úgy, hogy 0-t adjon vissza
ha nincs meg a keresett szót különben pedig a szó sorszámát( a sorszámok 1-el kezdõdnek)

5, Döntse el van-e olyan szó a szótárban amiben több a magánhangzó mint a mássalhangzó!
bool Maganhangzo() */
int Beolvas(string *tmb, string fnev);
string Leghosszabb(string* tmb, int db);
int Linearis(string* tmb,int db, string szo);
int Logaritmikus(string* tmb,int db, string szo);
bool Maganhangzo(string* tmb, int db);
int main( )
{
    string szavak[150];
    int szavakszama = 0;
    string filenev = "szotar.txt";
/* 1. Olvassa be a szotar.txt állományból a szavakat, és a következõ feladatok megoldása
során ezekkel dolgozzon!*/
    szavakszama = Beolvas(szavak, filenev);
    cout<<"A szavak szama "<< szavakszama<<endl;
    cout << "A szotar leghosszabb szava: " << Leghosszabb(szavak, szavakszama)<<endl;
    
    string szoveg;
    cout << "Adjon meg egy szot " << endl;
    cin >> szoveg;
    int sorszam= Linearis(szavak, szavakszama, szoveg);
    if (sorszam) cout << "A szotarban a keresett szo a: " << sorszam << ".helyen van" << endl;
    else cout << "A szotarban nincs benne a keresett szo"<< endl;

    sorszam = Logaritmikus(szavak, szavakszama, szoveg);
    if (sorszam) cout << "A szotarban a keresett szo a: " << sorszam << ".helyen van" << endl;
    else cout << "A szotarban nincs benne a keresett szo" << endl;
    
    if (Maganhangzo(szavak, szavakszama)) cout << "Van ilyen szo szotarban" << endl;
    else cout << "Nincs ilyen szo szotarban" << endl;
    return 0;
}
int Beolvas(string* tmb, string fnev)
{
    ifstream be(fnev);
    if (be.fail()) { cout << "Hibas fajlmagnyitas"; system("pause"); exit(1); }
    int db = 0;  
    while (!be.eof())
    {
        be >> tmb[db];
        cout << tmb[db] << endl;
        db++;
    }
    be.close();
return db;
}
string Leghosszabb(string* tmb, int x)
{
    int leghossz = 0;
    for (int i = 0; i < x; i++)
    {
        if (tmb[i].size() > tmb[leghossz].size())
        {
            leghossz = i;
        }
    }
return tmb[leghossz];
}
int Linearis(string* tmb, int db, string szo)
{
    int i = 0;
    while (i < db && tmb[i] != szo)
    {
        i++;
    }
    if (i < db) return i + 1;
    else return 0;
}
int Logaritmikus(string* tmb, int db, string szo)
{
    int kozep, AH = 0, FH = db - 1;
    do
    {
        kozep = (AH + FH) / 2;
        if (tmb[kozep] < szo) AH = kozep + 1;
        if (tmb[kozep] > szo) FH = kozep - 1;
    } while (AH <= FH && tmb[kozep] != szo);
    if (AH <= FH)
    {
        return kozep + 1;
    }
    else
    {
        return 0;
    }
}
bool Maganhangzo(string* tmb, int db)
{
    int i = 0;
    while (i < db)
    {
        int magandb = 0;
        for (int j = 0; j < tmb[i].size(); j++)
        {
            if (tmb[i][j] == 'a' || tmb[i][j] == 'e' || tmb[i][j] =='i'|| tmb[i][j]=='o'|| tmb[i][j]=='u') magandb++;
        }
        if (tmb[i].size() / 2 < magandb)
        {
            cout << tmb[i] << endl;
            return true;
        }
        i++;
    }
    return false;
}