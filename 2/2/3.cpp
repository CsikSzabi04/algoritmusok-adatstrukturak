#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
struct kosar
{
	string nev;
	int pont;
	int ido;
};

int Adatbeolvasas(kosar* tmb);
double Pont_atlag(kosar* tmb, int db);
bool Harminc_pont_felett(kosar* tmb, int db);
int Jatszott(kosar* tmb, int db, string jatekos);
string Legtobb(kosar* tmb, int db);
int Huszperc(kosar* tmb, int db, string* nevek);

int main() {

	kosar csapat[14];
	int letszam = Adatbeolvasas(csapat);
	cout << "A merkozesen " << letszam << " jatekos vett reszt\n";
	cout << "A csapat altal dobott pontok atlaga " << Pont_atlag(csapat, letszam) << endl;

	if (Harminc_pont_felett(csapat,letszam)) cout << "VOLT 30 pontnal tobbet elero jatekos\n";
	else cout << "NEM VOLT 30 pontnal tobbet elero jatekos\n";

	cout << "Adjon meg egy nevet: \n";
	string Nev;
	if (Jatszott(csapat, letszam, Nev) > 0) cout << "A jatekos jatszott es " << Jatszott(csapat, letszam, Nev) << " pontot dobott\n";

	cout << "A elgtobb idot palyan tolto jatekos neve: " << Legtobb(csapat, letszam) << endl;

	cout << "Husz percnel tobbet jatszott: \n";
	string jatekosok[14];
	for (int i = 0; i < Huszperc(csapat, letszam, jatekosok); i++) cout << jatekosok[i] << endl;
}

int Adatbeolvasas(kosar* tmb) {
	ifstream be("kosarlabda.txt");
	if (be.fail()) { cout << "Hiba a file beolvasasnal"; system("pause"); exit(1); }
	int i = 0;
	cout.setf(ios::left);
	while (!be.eof()) {
		be >> tmb[i].nev >> tmb[i].pont >> tmb[i].ido;
		cout << setw(20) << tmb[i].nev << "\t" << tmb[i].pont << "\t" << tmb[i].ido << endl;		i++;
	}
	be.close();
	return i;

	}

double Pont_atlag(kosar* tmb, int db){
	float atlag = 0;
	for (int i = 0; i < db; i++) atlag = atlag + tmb[i].pont;
	return atlag / db;
}
bool Harminc_pont_felett(kosar* tmb, int db){
	int i = 0;
	while (i < db && tmb[i].pont <= 30)i++;
	if (i < db) return true;
	else return false;
}

int Jatszott(kosar* tmb, int db, string jatekos){
	int i = 0;
	while (i < db && tmb[i].nev != jatekos) i++;
	
	if (i < db) return tmb[i].pont;
	else return -1;
}

string Legtobb(kosar* tmb, int db){
	int max = 0;
	for (int i = 1; i < db; i++) if (tmb[i].ido > tmb[max].ido) max = i;
	return tmb[max].nev;
}

int Huszperc(kosar* tmb, int db, string* nevek){
	int szam = 0;
	for (int i = 0; i < db; i++)
	{
		if (tmb[i].ido > 20)
		{
			nevek[szam] = tmb[i].nev;
			szam++;
		}
	}
	return szam;
}