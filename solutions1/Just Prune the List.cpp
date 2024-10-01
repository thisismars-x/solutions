#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int ncase; cin >> ncase;
    while(ncase--){
        int size1, size2; cin >> size1 >> size2;

        map<int, int> ordering;
        while(size1--){
            int temp; cin >> temp;
            ordering[temp]++;
        }
        
        while(size2--){
            int temp; cin >> temp;
            ordering[temp]--;
        }

        int total = 0;
        for(auto &i : ordering) total += abs(i.second);

        cout << total << '\n';
    }
}

MAIN