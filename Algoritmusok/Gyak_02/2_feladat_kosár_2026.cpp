/*
Feladat: A kosarlabda.txt állományban tároljuk egy kosárlabda csapat egyik mérkõzésének statisztikáját.  
Tárolják a játékos nevét, dobott kosarait és a mérkõzés alatt a pályán töltött idõt percben. (Csak ékezetmentes betûket írtak)
Pl.	Kovacs 13 40
	Fekete 2 23
	…..
Minden játékos adata új sorban van és a nevek, kosarak, eltöltött idõ szóközökkel elválasztva.
Tudjuk, hogy legfeljebb 14 játékos adatai vannak az állományban (nem biztos, hogy van 14)
1, Olvassa be a fájlt egy olyan adatszerkezetbe, amit az alábbi kérdésekhez fel tud használni! (struktúra))
(Ha nem tudja beolvasni az állományból az adatokat, akkor kérje be õket billentyûzetrõl!)
2, Hány játékos volt jelen a mérkõzésen?
3, Hány kosarat dobott a csapat átlagosan a mérkõzésen?	 	
4, Döntse el volt –e olyan játékos akinek 30 pont felett sikerült dobnia a mérkõzésen (igen/nem)!									
5, Kérjen be egy nevet billentyûzetrõl és döntse el, hogy játszott –e és ha igen akkor hány pontot szerzett ?
6, Írja ki a képernyõre annak a játékosnak a nevét aki a legtöbb idõt töltötte a pályán!							
7, Válogassa ki azoknak a játékosoknak a nevét egy új tömbbe akik 20 percnél többet töltöttek a pályán!					
Az egyes feladatokat függvényekkel oldja meg!
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
struct kosar
{
	string nev;
	int pont;
	int ido;
};
int Adatbeolvasas(kosar* tmb );
double Pont_atlag(kosar* tmb, int db);
bool Harminc_pont_felett(kosar* tmb, int db);
int Jatszott(kosar* tmb, int db, string jatekos);
string Legtobb(kosar* tmb, int db);
int Huszperc(kosar* tmb, int db,string *nevek);
int main()
{
	//1,  Csapat adatainak beolvasása
	kosar csapat[14];
	int letszam = Adatbeolvasas(csapat);
	
	//2,Hány játékos volt jelen a mérkõzésen?
	cout << "A merkozesen "<< letszam <<" jatekos vett reszt" << endl;

	//3, A csapat által dobott pontok átlaga
	cout << "A csapat altal dobott pontok atlaga: " << Pont_atlag(csapat, letszam) << endl;

	//4, Volt-e harminc pont felett dobó
	if (Harminc_pont_felett(csapat, letszam)) cout << "VOLT 30 pontnal tobbet elero jatekos" << endl;
	else cout << "NEM VOLT 30 pontnal tobbet elero jatekos" << endl;
	
	//5, Adjon meg egy nevet
	cout << "Adjon meg egy nevet: " << endl;
	string Nev;
	cin >> Nev;
	if (Jatszott(csapat, letszam, Nev)>=0) cout << "A jatekos jatszott es " << Jatszott(csapat, letszam, Nev) << " pontot dobott" << endl;
	else cout << "A jatekos nem jatszott " << endl;

	//6, A legtöbb idõt pályán töltõ játékos
	cout << "A legtobb idot palyan tolto jatekos neve: " << Legtobb(csapat, letszam) << endl;;
	
	//7, A 20 percnél többet pályán töltõk nevei - létrehozunk egy string tömböt a neveknek és azt is átadjuk
	// a függvénynek, a függvény ezen játékosok számát adja vissza a neveket pedig betölti a string tömbbe
	string jatekosok[14];
	cout << "Husz  percnel tobbet jatszott :" << endl;
	for (int i = 0; i < Huszperc(csapat, letszam, jatekosok); i++)
	{
		cout << jatekosok[i] << endl;
	}
}
int Adatbeolvasas(kosar* tmb )
{
	ifstream be("kosarlabda.txt");
	if (be.fail()) { cout << "Hiba a file beolvasasnal."; system("pause"); exit(1); }
	int i = 0;
	cout.setf(ios::left);
	while (!be.eof())
	{
		be >> tmb[i].nev >> tmb[i].pont >> tmb[i].ido;
		cout << setw(20) << tmb[i].nev << "\t" << tmb[i].pont << "\t" << tmb[i].ido << endl;
		i++;
	}
	be.close();
	return i;
}
double Pont_atlag(kosar* tmb, int db)
{
	float atlag = 0;
	for (int i = 0; i < db; i++)
	{
		atlag = atlag + tmb[i].pont;
	}
	return atlag/db;
}
bool Harminc_pont_felett(kosar* tmb, int db)
{
	int i = 0;
	while (i < db && tmb[i].pont <= 30)
	{
		i++;
	}
	if (i < db) return true;
	else return false;
}

int Jatszott(kosar* tmb, int db, string jatekos)
{
	int i = 0;
	while (i < db && tmb[i].nev != jatekos)
	{
		i++;
	}
	if (i < db) return tmb[i].pont;
	else return -1;
}

string Legtobb(kosar* tmb, int db)
{
	int max = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[i].ido > tmb[max].ido) max = i;
	}
	return tmb[max].nev;
}
int Huszperc(kosar* tmb, int db, string* nevek)
{
	int szam = 0;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].ido > 20)
		{
			nevek[szam] = tmb[i].nev;
			szam++;
		}
	}
	return szam;
}