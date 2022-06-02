#include <iostream>
using namespace std;

int potencia (int n, int k, int m) {
    
    if (k == 0) return 1;
    int x = potencia (n, k/2, m);
    x = (x*x) % m;
    if (k%2) x = (x*n) % m;
    return x;
}

int main () {
     
     int n, k, m;
     while (cin >> n >> k >> m) {
         
         cout << potencia (n, k, m) << endl;
    }
}
