#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

vector<vector<int>> store;
int x[30000];
bool visited[30000];

queue<int> bfsq;
void solve() {
    int n, m;
    while(cin >> n >> m, n){
        store.assign(n, vector<int>());

        for(int i = 0; i < n; i++) visited[i] = false;

        for(int i = 0; i < m; i++){
            int temp; cin >> temp;
            for(int j = 0; j < temp; j++){
                cin >> x[j];
            }

            for(int j = 0; j < temp; j++){
                for(int k = 0; k < temp; k++){
                    if(j != k) store[x[j]].push_back(x[k]);
                }
            }
        }

        bfsq.push(0);
        visited[0] = true;

        int result = 0;
        while(!bfsq.empty()){
            int s = bfsq.front(); bfsq.pop();
            result++;

            for(int i = 0; i < store[s].size(); i++)
                if(not visited[store[s].at(i)]){
                    visited[store[s].at(i)] = true;
                    bfsq.push(store[s].at(i));
                }
        }

        cout << result << '\n';
    }
}

MAIN