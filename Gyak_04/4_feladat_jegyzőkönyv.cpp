#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<fstream>
/*
Egy 7 fõs kézilabdalabda csapatról egy mérkõzésen statisztika készült. Tárolták a  játékosok nevét, 
játékidejét, és dobott góljait egy jegyzokonyv.txt nevû állományban.
Sajnos a jegyzõkönyv megsérült és csak a játékosok neve maradt meg az állományban.
Állítsuk vissza az adatokat úgy, hogy a neveket a fájlból, a játékidõt (0-60) és a 
 dobott gólokat(0-12) véletlen generátorral állítsuk elõ!
1, Hozzunk létre egy megfelelõ adatszerkezetet az adatok tárolására!
2, Töltsük fel a struktúratömböt adatokkal úgy, hogy a nevet a fájlból olvassuk be,
 a játékidõt (0-60) és a dobott gólokat(0-12) véletlen generátorral állítsuk elõ!
3, Írassuk ki az adatokat táblázatosan!
4, Számítsuk ki hány gólt dobott a csapat összesen!
5, Ki dobta a legtöbb gólt (adjuk meg a nevét és góljainak számát)?
6, Számoljuk meg hányan dobtak 6 gól felett?
7, Írassuk ki azoknak a nevét és játékidejét, akik legalább 20 percet a pályán töltöttek!
8, A kiegészített adatbázist, név, játékidõ, gólok mentsük el az uj_jegyzokonyv.txt állományba!
*/
using namespace std;
struct jatekos
{
	string nev;
	int jatekido;
	int gol;
};
int main()
{
	int letszam;
	//1,Struktúra tömb létrehozása az adatok tárolásához - tudjuk, hogy 7 fõ játszott
	jatekos csapat[7];
	//2,  Csapat adatainak bekérése
	ifstream be("jegyzokonyv.txt");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 7; i++)
	{
		getline(be, csapat[i].nev);
		csapat[i].jatekido = rand() % 61;
		csapat[i].gol=rand()%11;
	}
	//3, Csapattagok adatainak táblázatos kiíratása //  formázott kiírás
	cout.setf(ios::left);
	for (int i = 0; i < 7; i++)
	{
		cout << setw(20) << csapat[i].nev << setw(2) << csapat[i].jatekido << " " << csapat[i].gol << endl;
	}
	//4, Számítsuk ki a csapat össz. dobott góljának számát!
	int ossz = 0;
	for (int i = 0; i < 7; i++)
	{
		ossz = ossz + csapat[i].gol;
	}
	cout << "A csapat osszgolszama: " << ossz << endl;
	//5, Legtobb golt dobo jatekos neve, dobott goljainak szama
	int max = 0;
	for (int i = 1; i < 7; i++)
	{
		if (csapat[i].gol > csapat[max].gol) { max = i; }
	}
	cout << "A legtobb golt dobo jatekos: " << csapat[max].nev << " goljainak szama: " << csapat[max].gol << endl;
	//6, A 6 gól  felett dobók száma
	int db6 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (csapat[i].gol > 6)
		{
			db6++;
		}
	}
	cout << "A hat gol felett dobok szama: " << db6 << endl;
	// 7, Írassuk ki azoknak a nevét és játékidejét akik legalább 20 percet a pályán töltöttek
	cout << "A legalabb 20 percet jatszo jatekosok: " << endl;
	for (int i = 0; i < 7; i++)
	{
		if (csapat[i].jatekido >= 20)
		{
			cout << setw(20) << csapat[i].nev << " " << csapat[i].jatekido << endl;
		}
	}
	//8,A kiegészített adatbázist, név, játékidõ, gólok mentsük el az uj_jegyzokonyv.txt állományba!
	ofstream ki("uj_jegyzokonyv.txt");
	ki.setf(ios::left);
	for (int i = 0; i < 7; i++)
	{
		ki<< setw(20) << csapat[i].nev << setw(2) << csapat[i].jatekido << " " << csapat[i].gol << endl;
	}
	return 0;
}