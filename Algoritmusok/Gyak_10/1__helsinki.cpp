#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct hell
{
	int hely, csap;
	string sag, vnev;
};
int main()
{
	int i = 0, j = 0, k = 0, ossz = 0, min = 0, max = 0;
	hell a[200];

	// 2. feladat adatbeolvasás
	ifstream be("helsinki.txt");
	if (be.fail()) { cout << "Nem sikerült megnyitni az adatallomanyt"; return 1; }
	while (be >> a[i].hely >> a[i].csap >> a[i].sag >> a[i].vnev)
	{
		cout << a[i].hely << " " << a[i].csap << " " << a[i].sag << " " << a[i].vnev << endl;
		i++;
	}
	int db = i;
	// 3. feladat - Hány pontszerzõ helyezést értek el a magyarok
	cout << "3. feladat\n";
	cout << "Pontszerzo helyezesek szama: " << db << endl;
	
	// 4. feladat - Hány elsõ helyezést értek el a magyarok
	cout << "4. feladat\n";
	int elso = 0;
	for (i = 0; i < db; i++)
	{
		if (a[i].hely == 1) elso++;
	}
	cout << "Elso helyezezek szama: " << elso << endl;

	// 5. feladat Statisztika a megszerzett érmek számáról
	cout<< "5. feladat\n";
	int gold[3] = { 0 };
	for (i = 0; i<db; i++)
	{
		if (a[i].hely < 4) gold[a[i].hely - 1]++;
	}
	cout << "Arany: " << gold[0] << endl << "Ezust: " << gold[1] << endl << "Bronz: " << gold[2] << endl << "Osszesen: " << gold[0] + gold[1] + gold[2] << endl;
	// 6. feladat melyik pontszerzõ helyezés sportágában volt a legtöbb sportolónk
	cout << "6. feladat\n";
	max = 0;
	for (i = 1; i < db; i++)
	{
		if (a[i].csap > a[max].csap)max = i;
	}
	cout << a[max].hely << " " << a[max].sag << " " << a[max].vnev << " " << a[max].csap << endl;
	// 7. feladat hány pontot kaptunk összesen
	cout << "7. feladat\n";
	int l[6] = { 7,5,4,3,2,1 };
	for (i = 0; i<db; i++)
	{
		ossz = ossz + l[a[i].hely - 1];
	}
	cout << "Olimpia pontok szama: " << ossz << endl;
	
	// 8. feladat Úszás és tornasport érmeinek száma, melyikbõl volt több
	int n[2] = { 0 };
	cout << "8. feladat\n";
	for (i = 0; i<db; i++)
	{
		if (a[i].hely<4)
		{
			if (a[i].sag == "uszas")	n[0]++;
			if (a[i].sag == "torna")	n[1]++;
		}
	}
	if (n[0] > n[1])cout << "Uszas sportagban szereztek tobb ermet\n";
	else if (n[0] == n[1])cout << "Egyenlo volt az ermek szama\n";
	else cout << "Torna sportagban szereztek tobb ermet\n";
	return 0;
}