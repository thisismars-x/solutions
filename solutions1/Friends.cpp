#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }
int p[30010], r[30010];


void init(int n){
    for(int i = 0; i <= n; i++) p[i] = i, r[i] = 1;
}

int find(int u){
    return p[u] == u ? p[u]: p[u] = find(p[u]);
}

void union_sets(int u, int v){
    u = find(u), v = find(v);
    if(u != v){
        if(r[u] > r[v]) r[u] += r[v], p[v] = u;
        else r[v] += r[u], p[u] = v;
    }
}


void solve() {
    int ncase; cin >> ncase;

    while(ncase--){
        int n, m; cin >> n >> m;
        init(n);
        while(m--){
            int temp0, temp1; cin >> temp0 >> temp1;
            union_sets(temp0, temp1);
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            result = (result > r[i+1]? result: r[i+1]);
        }

        cout << result << '\n';
    }
}

MAIN