#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct Teszt
{
	string azonosito;
	string valasz;
	int pont;
};
int Adatbe(Teszt* tmb, string filenev);
int Legtobbpont(Teszt* tmb, int db);
bool Voltemax(Teszt* tmb, int db);
int Hetalatt(Teszt* tmb, int db);
void Elsotiz(Teszt* tmb, int db);

int main()
{
	// 1_2.	Adatbeolvasás + Írja ki a képernyõre, hogy hány versenyzõ vett részt a versenyen! 
	Teszt tomb[500];
	string fnev = "valaszok.txt";
	int versenyzokszama = Adatbe(tomb,fnev);
	cout << "A versenyen " << versenyzokszama << " versenyzo vett reszt" << endl;

	//3.Írja ki a legtöbb pontot elért versenyzõ azonosítóját és pontszámát!
	int legjobb = Legtobbpont(tomb, versenyzokszama);
	cout<<"A legtobb pontot elert versenyzo azonositoja : "<< tomb[legjobb].azonosito<<" pontszama: "<< tomb[legjobb].pont<<endl;

	//4.Döntse el volt e maximális pontszámot elért versenyzõ!
	if (Voltemax(tomb, versenyzokszama)) cout<<"Volt maximalis pont"<<endl;
	else cout<<"Nem volt maximalis pont"<<endl;

	//5.Számolja meg hány versenyzõ nem tudott legalább a kérdések felére válaszolni!
	cout<< Hetalatt(tomb, versenyzokszama)<<" versenyzo nem tudott legalabb a kerdesek felere valaszolni"<<endl;
	// 6.Rendezze a pontszám szerint csökkenõ en az eredményeket és írja ki az elsõ 10 helyezettet a képernyõre!
	Elsotiz(tomb, versenyzokszama);
return 0;
}
int Adatbe(Teszt* tmb, string filenev)
{
	ifstream be("valaszok.txt");
	if (be.fail()) { cout << "hiba"; system("pause"); exit(1); }
	int i = 0, j;
	string megoldas;
	be >> megoldas;
	while (be >> tmb[i].azonosito >> tmb[i].valasz)
	{
		int pontsz = 0;
		for (int j = 0; j < 14; j++)
		{
			if (tmb[i].valasz[j] == megoldas[j])
			{
				pontsz++;
			}
		}
		tmb[i].pont = pontsz;
		i++;
	}
	be.close();
	return i;
}
int Legtobbpont(Teszt* tmb, int db)
{
	int max = 0;
	for (int i = 1; i < db; i++)
	{
		if (tmb[i].pont > tmb[max].pont)
		{
			max = i;
		}
	}
	return max;
}
bool Voltemax(Teszt* tmb, int db)
{
	int i = 0;
	while (i < db && tmb[i].pont != 14)
	{
		i++; 
	}
	if (i < db) return true;
	else return false;
}
int Hetalatt(Teszt* tmb, int db)
{
	int hetalatt = 0;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].pont < 7) hetalatt++;
	}
	return hetalatt;
}
void Elsotiz(Teszt* tmb, int db)
{
	for (int i = 0; i < db - 1; i++)  // rendezés közvetlen kiálasztással
	{
		for (int j = i + 1; j < db; j++)
		{
			if (tmb[i].pont < tmb[j].pont)
			{
				Teszt seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}
	// Elsõ tíz
	for (int i = 0; i < 10; i++)
	{
		cout << tmb[i].azonosito << "  " << tmb[i].pont << endl;
	}
}