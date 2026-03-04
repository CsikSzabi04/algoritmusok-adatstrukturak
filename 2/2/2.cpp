#include <iostream>
using namespace std;

int main() {

	int tomb[15] = { 1,34,56,4,57,45,67,6,43,32,33,99,33,100,1 };

	int i, sum = 0;
	for (i = 0; i < 15; i++) sum = sum + tomb[i];
	cout << "A csoport atlagpontszama: " << (float)sum / i << endl;

	i = 0;
	while (i < 15 && tomb[i] != 100) i++;
	if (i < 15)cout << "Volt 100 pontos dolgozat.\n";
	else cout << "Nem volt 100 pontos dolgozat.\n";

	i = 0;
	while (tomb[i] != 57) i++;
	cout << "A keresett sorszám a " << i + 1 << "\n";

	int szam;
	cout << "Adja meg a keresett szamot!";
	cin >> szam;
	i = 0;
	while (i < 15 && tomb[i] != szam) i++;
	if (i < 15)cout << " A keresett tanulo sorszama: " << i + 1 << endl;
	else cout << " Nincs a keresett szam a tombben!" << endl;

	int db50 = 0;
	for (i = 0; i < 15; i++)if (tomb[i] > 50) db50++;
	cout << "A megfeleltek szama: " << db50 << endl;


	int cdb = 0, c[15];
	for (i = 0; i < 15; i++)if (tomb[i] > 75) c[cdb++] = i + 1;
	cout << "A 4-est elerok sorszamai: " << endl;

	for (i = 0; i < cdb; i++) cout << c[i] << " ";
	cout << endl;

	int min = 0;
	for (int i = 1; i < 15; i++) if (tomb[i] < tomb[min]) min = i;
	cout << "A leggyengebb tanulo eredmenye " << tomb[min] << " sorszama " << min + 1 << endl;
}