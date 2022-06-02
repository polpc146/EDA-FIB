#include <iostream>
#include <vector>

using namespace std;

void rec (int k, int a, int b, vector<char>& ab, int n) {
    
    if (k == n) {
        
        for (auto& x: ab) cout << x;
        cout << endl;
    }
    else {
        
        if (abs(a-b) < 2 or b - a >= 2) {
            
            ab[k] = 'a';
            rec(k+1, a+1, b, ab, n);
        }
        if (abs(b-a) < 2 or a - b >= 2) {
            
            ab[k] = 'b';
            rec(k+1, a, b+1, ab, n);
        }
    }
}

int main () {
    
    int n;
    cin >> n;
    vector <char> ab(n);
    rec(0, 0, 0, ab, n);
}
