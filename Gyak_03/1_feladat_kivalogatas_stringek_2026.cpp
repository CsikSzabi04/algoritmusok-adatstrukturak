# include <iostream>
# include <string> 
using namespace std;
int main()
{
// Egy utazó ügynök az alábbi 10 városban járt januárban : Vac, Pecs,Szeged, Tata, Vac, Gyor, Pecs, Tata,
	// Vac, Eger
	// Válogassuk ki a városokat egy új tömbbe úgy hogy mindegyik név csak egyszer szerepeljen benne!
	string varosok[10] = { "Vac", "Pecs","Szeged", "Tata", "Vac", "Gyor", "Pecs", "Tata","Vac", "Eger" };
	string uj[10];
	int ujdb = 0;//az uj tömb darabszáma- jelenleg 0 üres a tömb
	for (int i = 0;i < 10;i++)   // vegyük egyenként a városokat
	{
		int j = 0;
		while (j < ujdb && varosok[i] != uj[j]) // döntsük el, hogy az adott város benne van-e már az új tömbben
		{
			j++;
		}
		if (j == ujdb)		//ha úgy szálltunk ki a ciklusból, hogy nem volt az adott város az uj tömbben
		{
			uj[ujdb] = varosok[i]; 
			ujdb++;					// növeljük az uj tömbben lévõ városok számát
		}
	}
	for (int i = 0;i < ujdb;i++)
	{
		cout << uj[i]<<" ";
	}
	return 0;
}