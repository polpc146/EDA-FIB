#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main () {
    
    int n;
    string s;
    while (getline(cin, s)) {
        
        istringstream ss (s);
        set <int> seq;
        int cont = 0;
        while (ss >> n) seq.insert(n);
        auto it = seq.begin();
        bool par = ((*it) % 2) == 0;
        while (it != seq.end()) {
            
            if (it == seq.begin()) ++cont;
            else if (par and (*it) % 2 != 0) {
                    
                ++cont;
                par = false;
            }
            else if (not par and (*it) % 2 == 0) {
                    
                ++cont;
                par = true;
            }
            ++it;
        }
        cout << cont << endl;
    }
}

