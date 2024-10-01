#include<bits/stdc++.h>
using namespace std;

struct disjoint_set{
    int n;
    vector<int> sum, rank, checked, parent;

    disjoint_set(int x){
        n = x;
        sum.resize(n);
        rank.resize(n);
        checked.resize(n);
        parent.resize(n);

        for(int i = 0; i < n; i++){
            sum[i] = 0;
            rank[i] = 0;
            checked[i] = 0;
            parent[i] = i;
        }
    }

    inline int find(int u){
        if(parent[u] == u) return u;

        return (parent[u] = find(parent[u]));
    }

    inline bool same(int u, int v){
        return find(u) == find(v);
    }
    
    inline void union_find(int u, int v){
        if(not same(u, v)){
            int x = find(u), y = find(v);
            checked[x] = 1;
            sum[y] += sum[x];
            parent[x] = y;
        }
    }
};

int main(){
    int ncases; cin >> ncases;
    while(ncases--){
        int n, m; cin >> n >> m;

        disjoint_set frns(n);

        for(int i = 0; i < n; i++) cin >> frns.sum[i];

        while(m--){
            int temp0, temp1; cin >> temp0 >> temp1;
            frns.union_find(temp0, temp1);
        }

        for(int i= 0; i < n; i++){
            if(!frns.checked[i] and frns.sum[i]){
                cout << "IM"; break;
            }
        }

        cout << "POSSIBLE\n";
    }
}