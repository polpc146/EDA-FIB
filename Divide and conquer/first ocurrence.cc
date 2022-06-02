#include <iostream>
#include <vector>
using namespace std;

int mergesort (double x, const vector<double>& v, int esq, int dre) {
    
    if (esq > dre) return -1;
    int m = (esq + dre) / 2;
    if (x < v[m]) return mergesort (x, v, esq, m - 1);
    else if (x > v[m]) return mergesort (x, v, m + 1, dre);
    if (m - 1 >= 0) {
        
        int m2 = mergesort (x, v, esq, m - 1);
        if (m2 != -1) return m2;
    }
    return m;
}

int first_occurrence(double x, const vector<double>& v) {
    
    if (v.empty() or x < v[0] or x > v[v.size()-1]) return -1;
    return mergesort (x, v, 0, v.size() - 1);
}

