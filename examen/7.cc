#include <iostream>
#include <vector>

using namespace std;

void rec (int k, int y, vector<char>& road, int n) {
    
    if (k == n) {
        
        for (auto& x: road) cout << x;
        cout << endl;
    }
    else {
        
        if (y > 0) {
            
            road[k] = 'd';
            rec(k+1, y-1, road, n);
        }
        road[k] = 'h';
        rec(k+1,y, road, n);
        road[k] = 'u';
        rec(k+1, y+1, road, n);
    }
}

int main () {
    
    int n;
    cin >> n;
    vector<char> road(n);
    rec(0, 0, road, n);
}
