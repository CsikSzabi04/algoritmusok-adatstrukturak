#include <iostream>
using namespace std;
int osszeg(int* tomb, int n);
int main() {
    int t[] = { 1, 2, 3, 4, 5 };
    cout << osszeg(t, 5); // 15
    return 0;
}
int osszeg(int *tomb, int n) 
{
    if (n == 0) return 0;              // alapeset
    return tomb[n - 1] + osszeg(tomb, n - 1);
}
