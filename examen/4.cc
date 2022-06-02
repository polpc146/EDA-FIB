#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

using P = pair<int,int>;

int best_solution = __INT_MAX__;

int max_element (const vector<int>& partial_solution) {
    
    int n = partial_solution.size();
    int max = partial_solution[0];
    for (int i = 1; i < n; ++i) {
        
        if (partial_solution[i] > max) max = partial_solution[i];
    }
    return max;
}

void cami_curt (const vector<vector<P>>& g, vector<bool>& usat, vector<int>& partial_solution, int k, int u) {
    
    if (u == 1) {
        
        int max = max_element(partial_solution);
        if (max < best_solution) best_solution = max;
    }
    else {
        
        for (int i = 0; i < g[u].size(); ++i) {
            
            if (not usat[g[u][i]]) {
                
                usat[g[u][i]] = true;
                partial_solution.push_back(g[u][i].second);
            }
        }
    }
}

int main () {
    
    int n, m;
    while (cin >> n >> m) {
        
        vector<vector<P>> g(n);
        while (m--) {
            
            int x, y, l;
            cin >> x >> y >> l;
            g[x].push_back({y,l});
        }
        vector<bool> usat(n, false);
        vector<int> partial_solution;
        usat[0] = true;
        cami_curt (g, usat, partial_solution, 0, 0);
    }
}
