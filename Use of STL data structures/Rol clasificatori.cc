#include <iostream>
#include <map> 
#include <set>
using namespace std;

struct ranking {
    
    bool operator() (const pair <string, int>& p1, const pair <string, int>& p2) const {
        
        if (p1.second == p2.second) return p1 < p2;
        return p1.second > p2.second;
    }
};

int main () {
    
    map <string, pair <int, bool>> jugadores;
    string orden, j1, j2;
    map <string, pair <int, bool>>::iterator it, it2;
    while (cin >> orden >> j1) {
        
        it = jugadores.find(j1);
        if (orden == "LOGIN") {
            
            if (it == jugadores.end()) jugadores[j1] = make_pair(1200,true);
            else it->second.second = true;
        }
        else if (orden == "LOGOUT") {
            
            if (it != jugadores.end()) it->second.second = false;
        }
        else if (orden == "PLAY") {
            
            cin >> j2;
            it2 = jugadores.find(j2);
            if (it == jugadores.end() or it2 == jugadores.end() or it->second.second == false or it2->second.second == false) cout << "jugador(s) no connectat(s)" << endl;
            else {
                
                it->second.first += 10;
                if (it2->second.first > 1200) it2->second.first -= 10;
            }
        }
        else if (orden == "GET_ELO") cout << j1 << " " << it->second.first << endl;
    }
    cout << endl << "RANKING" << endl;
    set <pair <string, int>, ranking> rank;
    for (auto it : jugadores) rank.insert(make_pair(it.first, it.second.first));
    for (auto it : rank) cout << it.first << " " << it.second << endl;
}

