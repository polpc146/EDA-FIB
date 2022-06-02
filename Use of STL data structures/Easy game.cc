#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct tamany {
    
    bool operator () (const string& a, const string& b) const{
        
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};

int main () {
    
    int partida = 1;
    string word;
    cin >> word;
    set <string> has;
    set <string, tamany> had;
    while (word != "QUIT") {
        
        while (word != "END" and word != "QUIT") {
            
            if (not has.count(word)) {
                
                has.insert(word);
                had.erase(word);
            }
            else {
                
                has.erase(word);
                had.insert(word);
            }
            cin >> word;
        }
        cout << "GAME #" << partida << endl << "HAS:" << endl;
        for (string it : has) cout << it << endl;
        cout << endl << "HAD:" << endl;
        for (string it : had) cout << it << endl;
        if (word != "QUIT") cout << endl;
        ++partida;
        has.erase (has.begin(), has.end());
        had.erase (had.begin(), had.end());
        cin >> word;
    }
}
