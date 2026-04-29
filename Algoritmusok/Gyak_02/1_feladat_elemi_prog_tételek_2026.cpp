/* Egyszerû példa feladatok az elemi progr. tételekre. Adott egy 15 elemû tömb
 mely 0 és 100 között tartalmazza 15 tanuló elért vizsgapontszámait. Alkalmazzuk 
 az elemi prog tételeket!
 1, Számítsuk ki a csoport átlag pontszámát! 
 2, Döntsük el volt-e MAX pontszám (100 pont)!
 3, Tudjuk, hogy volt 57 pontos dogozat. Adjuk meg annak a tanulónak a sorszámát aki 57 pontot kapott! Ha több van elég az elsõt ! ( az elsõ elem sorszáma 	0 de a tanulók számozása 1-el kezdõdik)
 4, Kérjünk be egy pontszámot és ha volt ilyen a tömbben adjuk meg a hozzá 	tartozó tanuló sorszámát!
 5, Hányan feleltek meg a vizsgán? (A pontszám > 50)
 6, Válogassuk ki a legalább 4-est elérõ tanulók (>75) sorszámát és gyûjtsük egy új tömbbe õket, majd írassuk ki az új tömb elemeit! 
 7, Hányadik tanuló érte el a legkevesebb pontot és az mennyi volt ? */
#include <iostream>			
using namespace std;

int main( )
{
	int tomb[15]={1,34,56,4,57,45,67,6,43,32,33,99,33,100,1};

// Összegzés - számítsuk ki a csoport átlag pontszámát
   int i,sum=0;
   for (i = 0; i < 15; i++)
   {
       sum = sum + tomb[i];
   }
   cout<<"A csoport atlagpontszama: "<<(float)sum/i<<endl;
   
// Eldöntés - döntsük el volt-e MAX pontszám (100 pont)
   i=0;
   while (i < 15 && tomb[i] != 100)
   {
	   i++;
   }
   if(i<15) cout<<"Volt 100 pontos dolgozat."<<endl;
     else cout<<"Nem volt 100 pontos dolgozat."<<endl;

// Kiválasztás - Tudjuk, hogy volt 57 pont adjuk meg a  hozzá tartozó tanuló sorszámát!
//(a tanuló sorszáma a tömmbeli index+1 elem sorszáma)
   i=0;
   while (tomb[i] != 57)
   {
	   i++;
   }
   
   cout<<"A keresett sorszam a "<<i+1<<endl;    
    
//Lineáris keresés kérjünk be egy pontszámot és ha volt ilyena tömbben adjuk meg a hozzá tartozó
//tanuló sorszámát! 
    int szam;
    cout<<"Adja meg a keresett szamot!";
    cin>>szam;
    i=0;
	while (i < 15 && tomb[i] != szam)
	{
		i++;
	}
    if(i<15)cout<<" A keresett tanulo sorszama: "<<i+1<<endl;
    else cout<<" Nincs a keresett szam a tombben!"<<endl;
    
// Megszámlálás- Hányan feleltek meg a vizsgán? (A pontszám > 50)
    int db50=0;
	for (i = 0; i < 15; i++)
	{
		if (tomb[i] > 50) db50++;
	}
    cout<<"A megfeleltek szama: "<<db50<<endl;
    
// Kiválogatás- válogassuk ki a legalább 4-est elérõk (>75) indexét
// és gyûjtsük egy új tömbbe õket, majd írassuk ki az új tömb elemeit! 
    int cdb=0,c[15];
	for (i = 0; i < 15; i++)
	{
		if (tomb[i] > 75)
		{
			c[cdb++] = i + 1;
		}
	}
    cout<<"A 4-est elerok sorszamai: " <<endl;
	for (i = 0; i < cdb; i++)
	{
		cout << c[i] << "  ";
	}
    cout<<endl;   
// Minimum/Maximum kiválasztás - hányadik tanuló érte el a legkevesebb pontot
// és az mennyi volt ?
    int min=0;
    for (int i = 1; i < 15; i++)
    {
        if (tomb[i] < tomb[min])
        {
            min = i;
        }
    }
    cout<<"A leggyengebb tanulo eredmenye "<<tomb[min]<<" sorszama "<<min+1<<endl; // a tanuló sorszáma a kérdés
    return 0;
}
 

