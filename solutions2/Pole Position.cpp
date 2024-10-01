#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int n;
    while(cin >> n and n){
        int rank[10010]{0}, err = 0;
        int c, p;
        for(int i = 0; i < n; i++){
            cin >> c >> p;

            if(i+p<0 || i+p>=n) err = 1;
            if(not err and rank[i+p]) err = 1;

            if(err) continue;
            rank[i+p] = c;
        }    
        if(err) {cout << "-1\n"; continue;}
        

        cout << rank[0];
        for(int i = 1; i < n; i++)
            cout << " " << rank[i];
        
        cout << '\n';
    }    
}

MAIN