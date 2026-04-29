#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct Egyteszt
{
	string azonosito;
	string valasz;
	int pont;
};
int main()
{
	// Adatbevitel 
	ifstream be("valaszok.txt");
	if (be.fail()) { cerr << "hiba";system("pause");exit(1); }
	int i = 0, j;
	Egyteszt tmb[500];
	string megoldas;
	be >> megoldas;
	while (be >> tmb[i].azonosito>> tmb[i].valasz)
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
	// 2.	Írja ki a képernyõre, hogy hány versenyzõ vett részt a versenyen! 
	int versenyzokszama = i;
	cout << "A versenyen " << versenyzokszama << " versenyzo vett reszt" << endl;
	//3.Írja ki a legtöbb pontot elért versenyzõ azonosítóját és pontszámát!
	int max = 0;
	for (i = 1; i < versenyzokszama; i++)
	{
		if (tmb[i].pont > tmb[max].pont)
		{
			max = i;
		}
	}
	cout<<"A legtobb pontot elert versenyzo azonositoja : "<< tmb[max].azonosito<<" pontszama: "<< tmb[max].pont<<endl;
	//4.Döntse el volt e maximális pontszámot elért versenyzõ!
	i = 0;
	while (i < versenyzokszama && tmb[i].pont != 14)
	{
		i++;
	}
	if (i < versenyzokszama) cout<<"Volt maximalis pont"<<endl;
	else cout<<"Nem volt maximalis pont"<<endl;

	//5.Számolja meg hány versenyzõ nem tudott legalább a kérdések felére válaszolni!
	int hétalatt = 0;
	for (i = 0; i < versenyzokszama; i++)
	{
		if (tmb[i].pont < 7) hétalatt++;
	}
	cout<< hétalatt<<" versenyzo nem tudott legalabb a kerdesek felere valaszolni"<<endl;

	// 6.Rendezze a pontszám szerint csökkenõ en az eredményeket és írja ki az elsõ 10 helyezettet a képernyõre!
	for (i = 0; i < versenyzokszama - 1; i++)  // rendezés közvetlen kiálasztással
	{
		for (int j = i + 1; j < versenyzokszama; j++)
		{
			if (tmb[i].pont < tmb[j].pont)
			{
				Egyteszt seged = tmb[i];
				tmb[i] = tmb[j];
				tmb[j] = seged;
			}
		}
	}
	// Elsõ tíz
	for (i = 0; i < 10; i++)
	{
		cout << tmb[i].azonosito << "  " << tmb[i].pont << endl;

	}
	system("pause");
	return 0;
}