#include <iostream>
#include <map>
using namespace std;

int main () {
    
    map <string, int> casino;
    string s, q;
    while (cin >> s) {
        
        cin >> q;
        auto it = casino.find(s);
        if (q == "enters") {
            
            if (it != casino.end()) cout << s << " is already in the casino" << endl;
            else casino[s];
        }
        else if (q == "wins") {
                
            int x;
            cin >> x;
            if (it == casino.end()) cout << s << " is not in the casino" << endl;
            else casino[s]+=x;
        }
        else if (q == "leaves") {
                
            if (it == casino.end()) cout << s << " is not in the casino" << endl;
            else {
               
                cout << s << " has won " << it->second << endl;
                casino.erase(it);
            }
        }
    }
    
    cout << string(10,'-') << endl;
    for (auto p : casino) cout << p.first << " is winning " << p.second << endl;
}
