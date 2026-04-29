/*
4 gyakorlat folytatása...
Egy 16 csapatos labdarúgó bajnokság egyik fordulójának eredményeit 
tároljuk a merkozes.txt állományban. Ebben a fordulóban nem biztos, hogy 8 mérkõzés volt,
néhány meccs elmaradt a rossz idõjárás miatt. Minden merkozes
eredmenye uj sorban van es a golok v. mint a csapatok szama
szoközzel elválasztva. (3 2 ute vac)
Olvassa be a fájlt egy olyan adatszerkezetbe amit az alábbi
kérdésekhez fel tud hasznalni (struktúra)) és írassa ki hány mérkõzés volt a fordulóban!
! Rendezze acsapatokat névsor szerint növekvõ sorrendben
és írja ki a csapatok txt állományba*/

#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
struct fordulo
{
   int lott, kapott ;
   string nev1, nev2;    
};
int main()
{
    // Adatbevitel 

    ifstream be("merkozes.txt");
    if (be.fail()) { cerr << "hiba"; system("pause"); exit(1); }
    int db = 0;
    fordulo A[8];
    while(be >> A[db].lott>> A[db].kapott>>A[db].nev1>>A[db].nev2)
    {
        cout << A[db].lott << " " << A[db].kapott << " " << A[db].nev1 << " " << A[db].nev2 << endl;
        db++;
    }
    cout << "\n A forduloban :" << db << " merkozest jatszottak" << endl;
    be.close();
    cout << endl;
    //Rendezze acsapatokat névsor szerint növekvõ sorrendben
    //és írja ki a csapatok.txt állományba
    string seged[16];
    string temp;
    int j = 0;
    for (int i = 0; i < db; i++)
    {
        seged[j] = A[i].nev1;
        j++;
        seged[j] = A[i].nev2;
        j++;
    }
    ofstream ki("csapatok.txt");
    if (ki.fail()) { cerr << "hiba"; system("pause"); exit(1); }

    for (int i = 0; i < 2 * db - 1; i++)
    {
        for (j = i + 1; j < 2 * db; j++)
        {
            if (seged[i] > seged[j])
            {
                temp = seged[i];
                seged[i] = seged[j];
                seged[j] = temp;
            }
        }
    }
    for (int i = 0; i < 2 * db; i++)
    {
        cout << seged[i] << endl;
        ki << seged[i] << endl;
    }
    ki.close();
    return 0;
}

