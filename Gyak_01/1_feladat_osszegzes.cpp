//Feladat: 
// Adott egy pontok.txt nevû fájl, melyben egy 20 fõs csoport tagjainak keresztneve és az általuk szerzett 
//bónuszpontok találhatók.Számítsuk ki a csoport átlagpontszámát! ( Összegzés tétele )
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
int main()
{
	adat csoport[20];
	int ossz = 0, i = 0;
	ifstream be("pontok.txt");
	if (be.fail())
	{
		cout << "Hiba a file beolvasasnal.";
		system("pause");
		exit(1);
	}
	cout.setf(ios::left); // a balra igazított kiíráshoz
	while (!be.eof())
	{
		be >> csoport[i].nev;
		be >> csoport[i].pont;
		cout << setw(10) << csoport[i].nev << "\t"<< csoport[i].pont << endl;
		i++;
	}
	be.close();
	
	// Tulajdonképpen ez az összegzés tétele
	for (i = 0; i < 20; i++)
	{
		ossz += csoport[i].pont;
	}
	cout << "Az atlag bonuszpontszam: " << (float)ossz / 20 << endl;
	return 0;
}