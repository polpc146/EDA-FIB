#include <iostream>
#include <vector>

using namespace std;

void dfs (const vector<vector<int>>& g, vector<bool>& usat, int u) {
    
    if (usat[u]) return;
    else {
        
        usat[u] = true;
        for (auto x : g[u]) dfs(g, usat, x);
    }
}

int main () {
    
    int n, u, v, m;
    while (cin >> n >> u >> v >> m) {
        
        vector<vector<int>> g(n);
        vector<vector<int>> i(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            i[y].push_back(x);
        }
        vector<bool> usat(n, false);
        dfs(g, usat, u);
        if (not usat[v]) cout << 0 << endl;
        else {
            
            vector<bool> usat2(n, false);
            dfs (i, usat2, v);
            int sum =-2;
            for (int i = 0; i < n; ++i) {
                
                if (usat[i] and usat2[i]) ++sum;
            }
            cout << sum << endl;
        }
    }
}
