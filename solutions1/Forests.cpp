#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int ncases; cin >> ncases;
    vector<bitset<101>> heard(101);

    while(ncases--){
        int p, t;
        cin >> p >> t;
        cin.ignore();

        for(int i = 0; i < p; i++) heard[i].reset();

        string temp;
        while(getline(cin, temp) and temp.size()){
            int temp0, temp1;
            istringstream ss(temp);

            ss >> temp0 >> temp1;
            heard[temp0-1][temp1-1] = 1;
        }

        int same{0};
        bitset<101> check;

        for(int i = 0; i < p; i++){
            int _same = 0;
            if(!check[i]){
                for(int j = 1 + i; j < p; j++){
                    if(heard[i] == heard[j]) check[j] = 1;
                }

                ++same;
            }
        }

        cout << same << endl;
        if(ncases) cout << '\n';
    }
}

MAIN