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

int Adatbeolvas( hell * a, string fnev);
int Elsokszama(hell* a, int db);
void Ermekszama(hell* a, int db, int *gold);
hell Legtöbb(hell* a, int db);
int Osszpont(hell* a, int db);
string Melyik_tobb(hell* a, int db);

int main()
{
	// 2. feladat
	hell tmb[200];
	string filenev = "helsinki.txt";
	int pontszerzok = Adatbeolvas(tmb,filenev);
	// 3. feladat - Hány pontszerzõ helyezést értek el a magyarok
	cout << "3. feladat\n";
	cout << "Pontszerzo helyezesek szama: " << pontszerzok << endl;
	
	// 4. feladat - Hány elsõ helyezést értek el a magyarok
	cout << "4. feladat\n";
	cout << "Elso helyezezek szama: " << Elsokszama(tmb, pontszerzok) << endl;

	// 5. feladat Statisztika a megszerzett érmek számáról
	cout<< "5. feladat\n";
	int Gold[3] = {0};
	Ermekszama(tmb, pontszerzok, Gold);
	
	cout << "Arany: " << Gold[0] << endl << "Ezust: " << Gold[1] << endl << "Bronz: " << Gold[2] << endl;
	cout<< "Osszesen: " << Gold[0] + Gold[1] + Gold[2] << endl;
	
	// 6. feladat melyik pontszerzõ helyezés sportágában volt a legtöbb sportolónk
	cout << "6. feladat\n";
	hell max = Legtöbb(tmb, pontszerzok);
	cout << max.hely << " " << max.sag << " " << max.vnev << " " << max.csap << endl;
	
	// 7. feladat hány pontot kaptunk összesen
	cout << "7. feladat\n";
	cout << "Olimpia pontok szama: " << Osszpont(tmb, pontszerzok) << endl;
	
	// 8. feladat Úszás és tornasport érmeinek száma, melyikbõl volt több
	cout << "8. feladat\n";
	cout << Melyik_tobb(tmb, pontszerzok) << endl;

	return 0;
}
int Adatbeolvas(hell* a, string fnev)
{
	int i = 0;
	ifstream be(fnev);
	if (be.fail()) { cout << "Nem sikerült megnyitni az adatallomanyt"; return 1; }
	while (be >> a[i].hely >> a[i].csap >> a[i].sag >> a[i].vnev)
	{
		cout << a[i].hely << " " << a[i].csap << " " << a[i].sag << " " << a[i].vnev << endl;
		i++;
	}
	return i;
}
int Elsokszama(hell* a, int db)
{
	int elso = 0;
	for (int i = 0; i < db; i++)
	{
		if (a[i].hely == 1) elso++;
	}
	return elso;
}
void Ermekszama(hell* a, int db, int * gold)
{
	for (int i = 0; i < db; i++)
	{
		if (a[i].hely < 4) gold[a[i].hely - 1]++;
	}
}
hell Legtöbb(hell* a, int db)
{
	int max = 0;
	for (int i = 1; i < db; i++)
	{
		if (a[i].csap > a[max].csap)max = i;
	}
	return a[max];
}
int Osszpont(hell* a, int db)
{
	int ossz = 0;
	int l[6] = { 7,5,4,3,2,1 };
	for (int i = 0; i < db; i++)
	{
		ossz = ossz + l[a[i].hely - 1];
	}
	return ossz;
}
string Melyik_tobb(hell* a, int db)
{
	int n[2] = { 0 };
	for (int i = 0; i < db; i++)
	{
		if (a[i].hely < 4)
		{
			if (a[i].sag == "uszas")	n[0]++;
			if (a[i].sag == "torna")	n[1]++;
		}
	}
	if (n[0] > n[1])	return "Uszas sportagban szereztek több ermet";
	else if (n[0] == n[1])return "Egyenlo volt az ermek szama";
	else return "Torna sportagban szereztek tobb ermet\n";
}