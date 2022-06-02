#include <iostream>
#include <map>
using namespace std;

int main () {
    
    int n, x, y;
    int max = 100000000;
    while (cin >> x and cin >> y and cin >> n) {
        
        int pos = 1;
        map <int, int> cicle;
        auto it = cicle.end();
        while (n <= max and it == cicle.end()) {
            
            cicle[n] = pos;
            n = (n % 2 == 0 ? n/2 + x : n*3 + y);
            it = cicle.find(n);
            ++pos;
        }
        if (n >= max) cout << n << endl;
        else cout << pos - it->second << endl;
    }
}
