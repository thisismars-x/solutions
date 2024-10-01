#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int T; cin >> T;


    vector<long long> out;
    while(T--){
        vector<long long> temp;

        long long temp0;
        while(cin >> temp0 and temp0 != 0){
            temp.push_back(temp0);
        }

        sort(temp.rbegin(), temp.rend());

        long long cost_ = 0;
        for(int i = 0; i < temp.size(); i++){
            cost_ += 2 * pow(temp[i], i+1);
        }

        out.push_back(cost_);

    }

    for(auto i: out){
        if(i > 5000000) cout << "Too expensive\n";
        else cout << i << '\n';
    }
}

MAIN