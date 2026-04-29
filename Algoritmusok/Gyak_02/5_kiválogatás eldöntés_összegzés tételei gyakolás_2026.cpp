/*Állítson elõ véletlenszerûen 100 számot a 2 –500 zárt intervallumból(a 2 és az 500 is számít)  úgy, hogy  minden  szám  
csak  egyszer  fordulhat elõ. Úgy  kell  a  feladatot megoldania, hogy minden szám egyenlõ valószínûséggel szerepelhessen a 
kigenerált számok között.Az elõállított számok közül válogassa ki a prímszámokat és állítsa elõ a kigenerált számok 
közöttiprímszámok négyzet összegét.*/
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand((unsigned int)time(NULL));
	int tmb[100];
	int ossz = 0;
	// 100 különbözõ szám kigenerálása
	cout << "A 100 kulonbozo szam :" << endl;
	int j = 0;
	while (j <100)
	{
		int szam = rand()%499 +2;
		int k = 0;
		while (k < j && tmb[k] != szam)
		{
			k++;
		}
		if (k == j)
		{
			tmb[j++] = szam;
			cout << szam << " ";
		}
	}
	// prímszámok négyzetösszege
	cout << "\nA primszamok :" << endl;
	for (int i = 0;i < 100;i++)
	{
		int k = 2;
		int z = sqrt(tmb[i]);
		while(k<=z && tmb[i]%k!=0) //eldöntés tétele - eldöntjük, hogy a szám prím-e
		{
			k++;
		}
		if (k > z)
		{
			cout << tmb[i] << " ";
			ossz = ossz + tmb[i] * tmb[i]; //összegzés
		}
	}
	cout <<"\nA szamok negyzetosszege :"<< ossz;
	return 0;
}