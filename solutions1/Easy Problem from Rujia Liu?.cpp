#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int n, m;
    
    while(scanf("%d %d\n", &n, &m) != EOF){
        map<int, vector<int>> positions;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            positions[temp].push_back(i+1);
        }

        for(int i = 0; i < m; i++){
            int k, v;
            cin >> k >> v;
            vector<int>& position = positions[v];


            --k;
            if(k >= position.size()) cout << 0 << '\n';
            else cout << position[k] << '\n';
        }
    }
}

MAIN