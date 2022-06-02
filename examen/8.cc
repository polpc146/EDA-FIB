#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> di = {0, 1,  0, -1};
vector<int> dj = {1, 0, -1,  0};
pair<int,int> pos;

int bfs (const vector<vector<string>>& tv, string but) {
    
    int n = tv.size();
    int m = tv[0].size();
    queue<pair<int,int>> q;
    q.push({pos.first, pos.second});
    vector<vector<int>> dist (n, vector<int>(m, -1));
    dist[pos.first][pos.second] = 0;
    while (not q.empty()) {
        
        auto p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        for (int k = 0; k < 4; ++k) {
            
            int ii = di[k] + i;
            int jj = dj[k] + j;
            if (ii >= 0 and ii < n and jj >= 0 and jj < m and tv[ii][jj] != "*") {
                
                if (dist[ii][jj] == -1) {
                    
                    dist[ii][jj] = dist[i][j] + 1;
                    if (tv[ii][jj] == but) {
                        
                        pos.first == ii;
                        pos.second == jj;
                        return dist[ii][jj] + 1;
                    }
                    q.push({ii,jj});
                }
            }
        }
    }
    return -1;
}

void prep_bfs (const vector<vector<string>>& tv, const vector<string>& button) {
    
    int n = button.size();
    int sum = 0;
    pos = {0,0};
    for (int i = 0; i < n; ++i) {
        
        int cont = bfs(tv, button[i]);
        if (cont == -1) {
            
            cout << "impossible" << endl;
            return;
        }
        sum += cont;
    }
    cout << sum << endl;
}

int main () {
    
    int n, m;
    while (cin >> n >> m) {
        
        vector<vector<string>> tv(n, vector<string>(m));
        for (auto& q: tv) {
            
            for (auto& p: q) cin >> p;
        }
        int p;
        cin >> p;
        vector<string> button(n);
        for (auto& x: button) cin >> x;
        prep_bfs(tv, button);
    }
}
