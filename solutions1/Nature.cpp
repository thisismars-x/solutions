#include<bits/stdc++.h>
using namespace std;

int r[5010], p[5010];

int find(int u){
    return p[u] == u ? u: p[u] = find(p[u]);
}

void join_sets(int u, int v){
    u = find(u), v = find(v);
    if(u != v){
        p[u] = v;
        r[v] += r[u];
    }
}

int main(){
    int t1, t2;

    while(cin >> t1 >> t2, t1){
        map<string, int> ordering;
        string temp;

        for(int i = 0; i < t1; i++){
            cin >> temp;
            ordering[temp] = i;
            r[i] = 1, p[i] = i;
        }

        for(int i = 0; i < t2; i++){
            cin >> temp;
            int temp0 = ordering[temp];
            cin >> temp;
            int temp1 = ordering[temp];
            join_sets(temp0, temp1);
        }

        int result = 0;
        for(int i = 0; i < t1; i++){
            if(r[i] > result) result = r[i];
        }

        cout << result << '\n';
    }
}