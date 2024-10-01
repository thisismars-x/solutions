#include<bits/stdc++.h>
using namespace std;

class union_find{
    vector<int> parent, size;

    public:
        union_find(int n){
            parent.resize(n);
            size.resize(n, 1);

            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int u){
            if(parent[u] != u) parent[u] = find(parent[u]);

            return parent[u];
        }

        void unite(int u, int v){
            int root1 = find(u), root2 = find(v);

            if(root1 != root2)
                if(size[root1] < size[root2]) swap(root1, root2);
            
            parent[root2] = root1;
            size[root1] += size[root2];
        }

        int _size(int u) {
            return size[find(u)];
        }
};

int main(){
    int ncase; cin >> ncase;
    while(ncase--){
        int nfrns; cin >> nfrns;

        union_find uf(nfrns * 2);
        unordered_map<string, int> name_toid;
        int id = 0;

        while(nfrns--){
            string temp0, temp1; cin >> temp0 >> temp1;

            if(name_toid.find(temp0) == name_toid.end())
                name_toid[temp0] = id++;

            if(name_toid.find(temp1) == name_toid.end())
                name_toid[temp1] = id++;

            uf.unite(name_toid[temp0], name_toid[temp1]);
            cout << uf._size(name_toid[temp0]) << '\n';
        }
    }
}