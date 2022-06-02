#include <iostream>
#include <map>
using namespace std;

int main () {
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
    map <int, int> mesures;
    string orden;
    int cont = 0;
    double suma = 0, num;
    double med;
    while (cin >> orden) {
        
        if (orden == "number") {
            
            cin >> num;
            ++cont;
            ++mesures[num];
            suma += num;
        }
        else if (orden == "delete" and cont > 0) {
            
            --cont;
            auto it = mesures.begin();
            suma -= it->first;
            if (it->second == 1) mesures.erase(it);
            else --it->second;
        }
        if (cont == 0) cout << "no elements" << endl;
        else {
            
            med = suma/cont;
            auto it = --mesures.end();
            cout << "minimum: " << mesures.begin()->first << ", maximum: " << it->first << ", average: " << med << endl;
        }
    }
}
