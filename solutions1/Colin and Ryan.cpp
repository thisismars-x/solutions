#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

set<int> answer;

void solve() {
    int n; cin >> n;
    int c, r;

    int ncase = 1;
    while(n--){
        cin >> c >> r;

        cout << "Case #" << ncase++ << ":";
        if(c == r) {cout << " 0\n"; continue;}
        
        c -= r;
        int limit = 1 + sqrt(c); answer.clear();

        for(int i = 1; i < limit; i++){
            if(c % i == 0) {
                if(i > r) answer.insert(i);
                if(c/i > r) answer.insert(c/i);
            }
        }

        auto start = answer.begin(), end = answer.end();

        
        for(auto it = start; it != end; it++){
            cout << " " << *it;
        }

        cout << '\n';
    }
}

MAIN