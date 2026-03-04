//Feladat: ua. mint az 1. feladat de a megoldáshoz írjunk egy összegzés nevû függvényt!
// Adott egy pontok.txt nevû fájl, melyben egy 20 fõs csoport tagjainak keresztneve és az általuk szerzett 
//bónuszpontok találhatók.A függvényt felhasználva írassuk ki a csoport össz.pontszámát és a csoport átlagpontszámát is!
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct adat
{
	string nev;
	int pont;
};
float Osszegez(adat* tmb); //  a feladatban most isnerjük a tanulók számát -20 - ezért nem kell a tömb elemszámát átadni
int main()
{
	adat csoport[20];
	ifstream be("pontok.txt");
	if (be.fail())
	{
		cout << "Hiba a file beolvasasnal.";
		system("pause");
		exit(1);
	}
	int i=0;
	cout.setf(ios::left);
	while (!be.eof())
	{
		be >> csoport[i].nev;
		be >> csoport[i].pont;
		cout << setw(10) << csoport[i].nev << "\t"<< csoport[i].pont << endl;
		i++;
	}
	be.close();

	cout << "\nA csoport osszpontszama: " << Osszegez(csoport) << endl;
	cout << "Az atlag bonuszpontszam: " << Osszegez(csoport) / 20 << endl;
	return 0;
}
float Osszegez(adat* tmb)
{
	float ossz = 0;
	for (int i = 0; i < 20; i++) ossz += tmb[i].pont;
	return ossz;
}