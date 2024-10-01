#include <bits/stdc++.h>
using namespace std;

#define MAIN        int main(void) { solve(); }


void solve() {

    int ncases;
    while(cin >> ncases){
        bool df[3000];
        fill(df, df + ncases, false);
        
        int previous = -3000;
        for(int i = 0; i < ncases; i++){
            int current; cin >> current;
            int difn = abs(current - previous);
            if(difn < ncases and difn > 0){
                df[difn] = true;
            }

            previous = current;
        }

        if(count(df, df + ncases, true) == ncases-1) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
}

MAIN