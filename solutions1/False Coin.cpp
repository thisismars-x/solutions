#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int ntests; cin >> ntests;

    bitset<100> realn;

    for(int i = 0; i < ntests; i++){
        realn.reset();

        int coins, tests; cin >> coins >> tests;

        for(int j = 0; j < tests; j++){
            int tested;
            cin >> tested;

            tested <<= 1;
            vector<int> testedcoins(tested);
            for(int k = 0; k < tested; k++) cin >> testedcoins[k];

            char result; cin >> result;
            if(result == '='){
                for(int k = 0; k < tested; k++){
                    realn[testedcoins[k] - 1] = 1;
                }
            }
        }

        int cnum = -1;
        for(int j = 0; j < coins; j++){
            if(!realn[j]){
                if(cnum == -1){
                    cnum = j;
                }else{
                    cnum = -1; break;
                }
            }
        }

        if(i) cout << '\n';
        cout << cnum + 1 << '\n';
    }
}

MAIN