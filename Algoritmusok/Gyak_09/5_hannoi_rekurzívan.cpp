// hannoi tornyai probléma mgoldása rekurzívan
// Kiinduló helyzet => minden korong ( tetszõleges számú) az elsõ rúdon,
// alul a legnagyobb felette egyre kisebb korongok
// Cél : helyezzük az összes korongot a 3-as rúdra a segédrúd(2)segítségével de
//kisebb korongra nagyobb nem kerülhet, Számoljuk a lépések számát is! 
#include <iostream>
using namespace std;
int hanoi(int n, char honnan, char segedrud,char hova)
{
	static int db;    // számolja hány lépésbõl áll a megoldás
	if( n>0)
		{
		hanoi(n-1,honnan, hova, segedrud); //n-1 db korong átmozgatása a "segedrudra"-re, 
		cout<<n<<" . korongot tedd a "<<honnan <<"rudrol a "<<hova<<" rudra! \n";
		hanoi(n-1,segedrud,honnan,hova); //n-1 db korong átmozgatása a "segedrud"-rõl a "hova" rudra
		db++;
		}

return db;
}
int main()
{
	int korong;
	cout<<" adja meg a korongok szamat: \t";
	cin>>korong;
	cout<<"\n\n"<<hanoi(korong,'1','2','3')<<"  lepesben lehetett athelyezni a korongokat\n"; // kiinduló helyzet minden korong az 1-es rudon
return 0;
}


