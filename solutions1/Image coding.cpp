#include<bits/stdc++.h>
using namespace std;

void solve();

int main(){ solve(); }

void solve(){

    int t, r, c, m, n; cin >> t;
    int nt = 1;

    while(t--){
        cin >> r >> c >> m >> n;

        char s[50];
        int counts[26]{};

        for(int i = 0; i < r; i++){
            cin >> s;
            for(int j = 0; s[j]; j++){
                counts[s[j] - 'A']++;
            }
        }

        int mx = 0, mxi = 0;
        for(int i = 0; i < 26; i++){
            if(counts[i] > mx)
                mx = counts[i], mxi = 0;
            if(counts[i] == mx)
                mxi++;
        }

        cout << "Case " << nt++ << ": " << mx*mxi*m + (r*c-mx*mxi)*n << '\n';
    }
}