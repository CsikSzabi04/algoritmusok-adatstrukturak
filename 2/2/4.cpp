# include <iostream>
# include <string>
using namespace std;
int main(){

	string varosok[10] = { "Vac", "Pecs","Szeged", "Tata", "Vac", "Gyor", "Pecs", "Tata","Vac", "Eger" };
	string uj[10];
	int ujdb = 0;
	for (int i = 0; i < 10; i++){
		int j = 0;
		while (j < ujdb && varosok[i] != uj[j]) j++;
		if (j == ujdb) {
			uj[ujdb] = varosok[i];
			ujdb++;
		}
	}
	for (int i = 0; i < ujdb; i++) cout << uj[i] << " ";
	
	return 0;
}