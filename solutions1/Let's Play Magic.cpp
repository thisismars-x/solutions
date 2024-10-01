#include <bits/stdc++.h>
using namespace std;

#define MAIN            int main(void) { solve(); }
#define pb              push_back
#define rep(i, a, b)    for(int i = a; i < b; i++)

void solve() {
    int ncards;

    while(cin >> ncards and ncards){
        string name, word;
        int idx = -1;

        vector<string> deck(ncards);
        rep(i, 0, ncards){
            cin >> name >> word;
            int n = word.size();

            while(n){
                idx = (idx+1) % ncards;
                if(deck[idx] == "") --n;
            }

            deck[idx] = name;

        }

        rep(i, 0, ncards){
            string out = 1 + i < ncards? " ":"\n";
            cout << deck[i] << out;
        }
        
    }    
}

MAIN