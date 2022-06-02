#include <iostream>
#include <set>
using namespace std;

int main() {
    
    set <string> lista;
    string palabra;
    cin >> palabra;
    if (palabra != "END") {
        
        cout << palabra << endl;
        int cont = 1;
        lista.insert(palabra);
        auto it = lista.find(palabra);
        while (cin >> palabra and palabra != "END") {
        
            ++cont;
            lista.insert(palabra);
            if (palabra < *it) --it;
            if (cont % 2 == 1) ++it;
            cout << *it << endl;
        }     
    }
}
