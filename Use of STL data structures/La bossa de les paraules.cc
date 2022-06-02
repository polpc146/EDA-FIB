#include <iostream>
#include <map>
using namespace std;

int main () {
    
    string orden, palabra;
    map <string, int> bolsa;
    while (cin >> orden) {
        
        if (orden == "store") {
            
            cin >> palabra;
            ++bolsa[palabra];
        }
        else if (orden == "delete") {
            
            cin >> palabra;
            auto it = bolsa.find(palabra);
            if (it != bolsa.end()) {
                
                if (it->second == 1) bolsa.erase(it);
                else --it->second;
            }
        }
        else if (orden == "minimum?") {
            
            if (bolsa.empty()) cout << "indefinite minimum" << endl;
            else {
                
                auto it = bolsa.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (orden == "maximum?") {
            
            if (bolsa.empty()) cout << "indefinite maximum" << endl;
            else {
                
                auto it = --bolsa.end();
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}
