#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {

    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 and m == 0) return;

        map<int, int> ordering;

        while(n--){
            int temp; cin >> temp;
            ordering[temp]++;
        }

        while(m--){
            int temp; cin >> temp;
            ordering[temp]--;
        }

        int total = 0;
        for(auto &it: ordering) 
            if(it.second == 0) ++total;

        cout << total << '\n';
    }
}

MAIN