/*Egy utazó ügynök az alábbi városokban járt januárban:
Kecskemet, Szeged, Pecs, Baja, Gyor, Miskolc, Vac, Cegled, Sopron, Eger
Februárban az alábbi városokat látogatta meg:
Budapest, Kecskemet, Szeged,Pecs,Baja, Esztergom, Salgotarjan
Azt tudjuk, hogy január hónapban 10 napot februárben 7 napot dolgozott.
Készítsünk programot mely kimutatja:
1 - Mely városokban járt mindkét hónapban ? (Metszet)
2 - Mely városokban volt legalább egyszer a két hónap alatt? (Unio) 
3- A feladatot függvényekkel oldjuk meg! ( használhatunk a vector típust is a tároláshoz*/
#include <iostream>
#include <string> 
using namespace std;
int Metszetkepzes(string* t1, string *t2, string* M, int a, int b);
int Uniokepzes(string* t1, string* t2, string* U, int a, int b);
int main()
{
	// Adatbevitel 
	string A[] = { "Kecskemet","Szeged",  "Baja", "Gyor", "Miskolc", "Vac", "Cegled", "Sopron","Eger","Pecs" };
	string B[] = { "Budapest", "Kecskemet", "Szeged","Pecs","Baja", "Esztergom", "Salgotarjan" };
	int jdb = 10;	// januári napok száma	
	int fdb = 7;	// februári napok száma
	string Metszet[7], Unio[17];
		cout << endl << "Az alabbi varosokban jart mindket honapban :\n";
	int Metszdb = 0;                        // mindkét hónapban darabszáma
	Metszdb = Metszetkepzes(A, B, Metszet, jdb, fdb);
	for (int i = 0; i < Metszdb; i++)
	{
		cout << Metszet[i] << " ";
	}
	cout << endl << "Az alabbi varosokban jart valamelyik honapban :\n";
	int Uniodb = 0;                        // Egyik hónap ( unio) darabszáma
	Uniodb = Uniokepzes(A, B, Unio, jdb, fdb);
	for (int i = 0; i < Uniodb; i++)
	{
		cout << Unio[i] << " ";
	}
	return 0;
}
int Metszetkepzes(string* t1, string* t2, string* M, int a, int b)
{
	int Mdb = 0;					// a metszettömb indexe
	for (int i = 0; i < a; i++)
	{
		int j = 0;
		while (j < b && t1[i] != t2[j])
			j++;
		if (j < b)
		{
			M[Mdb] = t1[i];
			Mdb++;
		}
	}
	return Mdb;
}
int Uniokepzes(string* t1, string* t2, string* U, int a, int b)
{
	int Udb = 0;				 //az uniotömb indexe
	for (int i = 0; i < a; i++)
	{
		U[i] = t1[i];
	}
	Udb=a;
	for (int j = 0; j < b; j++)
	{
		int i = 0;
		while (i < a && t1[i] != t2[j])
			i++;
		if (i ==a)
		{
			U[Udb] = t2[j];

			Udb++;
		}
	}
	return Udb;
}
