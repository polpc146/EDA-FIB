#include <iostream>
#include <vector>

using namespace std;

void rec (int k, int c, vector<char>& accions, int n, int y) {
    
    if (k == n) {
        
        for (auto& x: accions) cout << x;
        cout << endl;
    }
    else {
        
        if (c > 0) {
            
            accions[k] = 'b';
            rec(k+1, c-1, accions, n, y+1);
        }
        if (y > 0) {
            
            accions[k] = 's';
            rec(k+1, c+1, accions, n, y-1);
        }
    }
}

int main () {
    
    int n, c;
    cin >> n >> c;
    vector<char> accions(n);
    rec(0, c, accions, n, 0);
}
