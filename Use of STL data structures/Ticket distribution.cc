#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string w;
struct ordre {
    
    bool operator () (const string& a, const string& b) {
        
        if (a.length() == b.length()) {
            
            string w1 = w.substr(0,a.length());
            if (a == w1) return false;
            if (b == w1) return true;
            if (a < b) {
                
                if (a < w1 and b > w1) return true;
                else return false;
            }
            else {
                
                if (b < w1 and a > w1) return false;
                else return true;
            }
        }
        return a.length() > b.length();
    } 
};

int main () {
    
    string orden, codigo;
    while (cin >> w) {
        
        int tickets = 0;
        priority_queue <string, vector<string>, ordre> codes;
        while (cin >> orden and orden != "E") {
            
            if (orden == "S") {
                
                cin >> codigo;
                codes.push(codigo);
            }
            else if (orden == "T") ++tickets;
            while (tickets > 0 and not codes.empty()) {
            
            cout << codes.top() << endl;
            codes.pop();
            --tickets;
        }
        }
        cout << tickets << " ticket(s) left" << endl;
        cout << codes.size() << " supporter(s) with no ticket" << endl << endl;
    }
}
