#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

void solve() {
    
    string s;
    int n = 1;
    while(cin >> s and s[0] != 'e'){
        vector<stack<char>> store;
        store.push_back(stack<char>());
        store[0].push(s[0]);


        for(int i = 0; i < s.size(); i++){
            int mn = 30, mni;

            for(int j = 0; j < store.size(); j++){

                if(store[j].top() >= s[i] and mn > store[j].top() - s[i]){
                    mn = store[j].top() - s[i];
                    mni = j;
                }

            }

            if(mn == 30){
                store.push_back(stack<char>());
                store.back().push(s[i]);
            }
            else{
                store[mni].push(s[i]);
            }
        }

        cout << "Case " << n++ << ": " << store.size() << '\n';
    }
}

MAIN