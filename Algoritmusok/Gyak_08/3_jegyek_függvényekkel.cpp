/*A jegyek.txt állományban egy harmadikos emeltszintû informatika tanulócsoport 
adatait  tároljuk.
Egy csoportba max. 12-en járhatnak, de nem biztos, hogy mindig betelik a létszám.
A fájlban tároljuk a tanulók második év végi és harmadik félévi jegyét és a
tanuló keresztnevét . Az állomány egy kicsit "összevisszára sikeredett"  elsõ
adat a második év végi jegy szóközzel elválasztva a név, majd
szóközzel elválasztva a harmadik félévi jegy következik. 
PL.:   4 Bela 5
	   4 Feri 2
	   3 Lajos 1
Oldja meg az alábbi feladatokat:
1, Olvassa be az állományt, írja ki az adatokat a képernyõre. 
A beolvasáshoz hozzon létre egy megfelelõ adatszerkezetet !
2, Írja ki a képernyõre hányan járnak jelenleg fakt-ra!
3, Írja ki a második év végi csoportátlagot!
4, Írja ki melyik félévben volt jobb a csoport tanulmányi eredménye!
5, Döntse el volt-e bukás valamelyik félévben!
6, Ki volt a csoportban a legjobb tanuló a harmadik oszt. félévekor?
7, Rendezze a csoportot névsor szerint növekvõ sorrendbe, és írja ki a 
képernyõre a neveket!
8, Hozzon létre egy új állományt tankor.txt néven. Az eredeti állományban lévõ 
adatok sorrendjét változtassa meg úgy hogy elöl a név utána a második év végi
majd a harmadik félévi jegy szerepeljen, majd írja ki az adatokat az állományba!
PL. 	Bela 4 5
	    Feri 4 2

A FELADATOKAT FÜGGVÉNYEKKEL OLDJA MEG!
*/ 
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

struct tanulo
{
   int mv, hf ;
   string nev;    
};
int Adatbe(tanulo* oszt, string fnev);
float Atlag_masodik(tanulo* oszt, int letszam);
int Jobb_atlag(tanulo* oszt, int letszam);
bool Volt_bukas(tanulo* oszt, int letszam);
string Legjobb(tanulo* oszt, int letszam);
void Rendez(tanulo* oszt, int letszam);
void Kiir(tanulo* oszt, int letszam);

int main()
{
    tanulo osztaly[12];
    string filenev = "jegyek.txt";
    int db = Adatbe(osztaly, filenev);
    cout << "\n" << db << " tanulo jar faktra" << endl;
    cout << "A masodik ev vegi atlag : " << Atlag_masodik(osztaly, db) << endl;
    int felev= Jobb_atlag(osztaly, db);
    if (felev == 0) cout << "Egyforma volt az eredmeny a ket felevben" << endl;
    else 
        if (felev == 2) cout << "A masodik felevben volt jobb az eredmeny" << endl;
        else cout << "A harmadik felevben volt jobb az eredmeny" << endl;
    if(Volt_bukas(osztaly, db)) cout<<"\nVolt bukas" << endl;
    else cout << "\nNem volt bukas" << endl;
    cout << "A csoport legjobb tanuloja a harmadik felevben: " << Legjobb(osztaly, db) << endl;
    cout << "A csoport nevsor szerint abc sorrendben :" << endl;
    Rendez(osztaly, db);
    Kiir(osztaly, db);
    return 0;
}
// 1 - 2, Adatbevitel, létszám meghatározása
int Adatbe(tanulo* oszt, string fnev)
{
    ifstream be(fnev);
    int i = 0;
    if (be.fail()) { cout << "hiba"; system("pause"); exit(1); }
    while (be >> oszt[i].mv >> oszt[i].nev >> oszt[i].hf)
    {
        cout << oszt[i].mv << " " << oszt[i].nev << " " << oszt[i].hf << endl;
        i++;
    }
    be.close();
    return i;
}
//  3, Írja ki a második év végi csoportátlagot!
float Atlag_masodik(tanulo* oszt, int letszam)
{
    int atl = 0;
    for (int i = 0; i < letszam; i++)
    {
        atl = atl + oszt[i].mv;
    }
    return (float)atl / letszam;
}
//4, Írja ki melyik félévben volt jobb a csoport tanulmányi eredménye!
int Jobb_atlag(tanulo* oszt, int letszam)
{
    float atl_2 = Atlag_masodik(oszt, letszam);
    float atl_3 = 0;
    for (int i = 0; i < letszam; i++)
    {
        atl_3 = atl_3 + oszt[i].hf;
    }
    atl_3 = atl_3 / letszam;
    
    if (atl_2 > atl_3) return 2;            // a félévek összehasonlítása
    else if (atl_2 == atl_3) return 0;
               else return 3;
}
//5, Döntse el volt-e bukás valamelyik félévben! 
bool Volt_bukas(tanulo* oszt, int letszam)
{
    int i=0;
    while((i<letszam)&&(oszt[i].mv!=1)&&(oszt[i].hf!=1))
    i++;
    if (i < letszam) return true; 
    else return false; 
}
//6, Ki volt a csoportban a legjobb tanuló a harmadik oszt. félévekor?    
string Legjobb(tanulo* oszt, int letszam)
{
    int max=0;
    for(int i=1; i<letszam;i++)
    {
        if(oszt[i].hf>oszt[max].hf) max=i;
    }
return oszt[max].nev; 
}
//7,Rendezés
 void Rendez(tanulo* oszt,int letszam)
 {
    string seged[12];
    string temp;
    for(int i=0;i<letszam;i++)
    {
        seged[i]=oszt[i].nev;      
    }
    for(int i=0;i<letszam-1;i++)
   	{
       for(int j=i+1;j<letszam;j++)
       {
          if(seged[i]>seged[j])
          {
            temp=seged[i];
            seged[i]=seged[j];
            seged[j]=temp;
          }
       }
    }
   	for(int i=0;i<letszam;i++)
      cout<<seged[i]<<endl;
  }  
//8, Hozzon létre egy új állományt tankor.txt néven. Az eredeti állományban lévõ adatok sorrendjét
//változtassa meg úgy hogy elöl a név utána a második év végi majd a harmadik félévi jegy szerepeljen,
//majd írja ki az adatokat az állományba!
void Kiir(tanulo* oszt,int letszam)
{   
    ofstream ki("tankor.txt");
    for (int i = 0; i < letszam; i++)
    {
        ki << oszt[i].nev << " " << oszt[i].mv << " " << oszt[i].hf << endl;
    }
    ki.close();
    cout << "\nA tankor.txt fajl letrehozva es az adatok kiirva. ";
}
   
