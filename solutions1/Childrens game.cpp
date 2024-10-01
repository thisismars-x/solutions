#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

bool sort_fn(string& s1, string& s2) {return s2 + s1 < s1 + s2;}

void solve() {
    int n;
    while(cin >> n, n){
        vector<string> in(n);
        for(int i = 0; i < n; i++) cin >> in[i];

        sort(in.begin(), in.end(), sort_fn);
        
        cout << accumulate(in.begin(), in.end(), static_cast<string>("")) << '\n';
    }
}

MAIN