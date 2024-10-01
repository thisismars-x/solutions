#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int t0; cin >> t0;

    while(t0--){

        double total{0.0};
        int t1; cin >> t1;

        map<char, double> mymap;
        char temp0;
        double temp1;
        while(t1--){
            cin >> temp0 >> temp1;
            mymap[temp0] = temp1;
        }

        int t2; cin >> t2;
        string temp2;

        cin.ignore();
        while(t2--){
            getline(cin, temp2);
            for(int i = 0; i < temp2.size(); i++){
                auto it = mymap.find(temp2[i]);
                if(it != mymap.end()){
                    total += it->second;
                }
            }

        }

        total = total / 100;
        mymap.clear();

        printf("%0.2lf$\n", total);
    }
}

MAIN