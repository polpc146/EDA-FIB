#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    priority_queue<int> pq;
    char c;
    while (cin >> c) {
        
        int x; 
        if(c != 'A' and c!= 'R') cin >> x;
        if (c == 'S') pq.push(x);
        else if (pq.empty()) cout << "error!" << endl;
        else if (c == 'A') cout << pq.top() << endl;
        else if (c == 'R') pq.pop();
        else {
            
            int y = pq.top();
            if (c == 'I') {
                pq.pop();
                pq.push(y+x);
            }
            else {
                pq.pop();
                pq.push(y-x);
            }
        }
    }
}
