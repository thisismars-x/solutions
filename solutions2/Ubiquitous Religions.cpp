#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

int p[50010], r[50010];

int find(int u){
    return p[u] == u? p[u] : p[u] = find(p[u]);
}

void init(int u){
    p[u] = u, r[u] = 0;
}

int result;
void union_sets(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;

    result--;
    if(r[u] > r[v]) p[v] = u;
    else{
        p[u] = v;
        if(r[u] == r[v]) r[v]++;
    }
}


void solve() {
    int n, m;

    int cs = 0;
    while(cin >> n >> m, n){
        for(int i = 0; i < n; i++) init(i);

        result = n;
        while(m--){
            int temp0, temp1; cin >> temp0 >> temp1;
            union_sets(temp0, temp1);
        }

        cout << "Case " << ++cs << ": " << result << '\n';
    }
}

MAIN