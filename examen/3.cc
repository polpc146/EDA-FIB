#include <iostream>
#include <vector>

using namespace std;

void pou (const vector<int>& v, vector<bool>& usat, vector<int>& vpou, int k) {
    
    int n = v.size();
    if (k == n) {
        
        cout << "(";
        for (int i = 0; i < n; ++i) {
            
            if (i == n -1) cout << vpou[i] << ")" << endl;
            else cout << vpou[i] << ",";
        }
    }
    else {
        
        for (int i = 0; i < n; i++) {
            
            if (not usat[i+1]) {
                
                if (k > 1) {
                    
                    if (v[i]+vpou[k-2] <= 2*vpou[k-1]) {
                        
                        usat[i+1] = true;
                        vpou.push_back(v[i]);
                        pou(v, usat, vpou, k+1);
                        usat[i+1] = false;
                        vpou.pop_back();
                    }
                }
                else {
                    
                    usat[i+1] = true;
                    vpou.push_back(v[i]);
                    pou(v, usat, vpou, k+1);
                    usat[i+1] = false;
                    vpou.pop_back();
                }
            }
        }
    }
}

void pou(int n) {
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
    }
    vector<bool> usat(n+1, false);
    vector<int> vpou;
    pou(v, usat, vpou, 0);
}

int main () {
    
    int n;
    cin >> n;
    pou(n);
}
