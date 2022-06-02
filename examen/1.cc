#include <iostream>
#include <vector>

using namespace std;

void permutacions (int n, int d, vector<int>& vper, vector<bool>& usat, int k, const vector<int>& v) {
    
    if (k == n) {
        
        cout << "(";
        for (int i = 0; i < n; ++i) {
            
            if (i == n - 1) cout << vper[i] +1 << ")" << endl;
            else cout << vper[i] +1 << ",";
        } 
    }
    else {
        
        for (int i = 0; i < n; ++i) {
            
            if (not usat[i]) {
                
                if (k > 0) {
                    
                    int x = v[i] - vper[k-1];
                    if (x < 0) x *= -1;
                    if (x <= d) {
                        
                        usat[i] = true;
                        vper.push_back(v[i]);
                        permutacions(n, d, vper, usat, k+1, v);
                        usat[i] = false;
                        vper.pop_back();
                    }
                }
                else {
                    
                    usat[i] = true;
                    vper.push_back(v[i]);
                    permutacions(n, d, vper, usat, k+1, v);
                    usat[i] = false;
                    vper.pop_back();
                }
            }
        }
    }
}

void permutacions(int n, int d) {
    
    vector<int> v(n), vper;
    vector<bool> usat(n,false);
    for (int i = 0; i < n; ++i) v[i] = i;
    permutacions(n, d, vper, usat, 0, v);
}

int main () {
    
    int n, d;
    cin >> n >> d;
    permutacions(n,d);
}
