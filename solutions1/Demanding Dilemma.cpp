#include<bits/stdc++.h>
using namespace std;

int main(){
    int ncases; cin >> ncases;

    while(ncases--){
        int n, m; cin >> n >> m;
        
        vector<vector<int>> edge(m);
        for(int i = 0; i < n ; i++)
            for(int j = 0 ; j < m; j++){
                int temp; cin >> temp;
                if(temp) edge[j].push_back(i);
        }

        bool incidence = true;
        for(int j = 0; j < m; j++){
            if(edge[j].size() != 2){
                incidence = false; break;
            }
        }

        if(incidence){
            set<pair<int, int>> vertices;
            for(int j = 0; j < m; j++)
                vertices.insert(make_pair(edge[j][0], edge[j][1]));

            if(vertices.size() != m) cout << "No\n";
            else cout << "Yes\n";
        }
        else cout << "No\n";
    }
}