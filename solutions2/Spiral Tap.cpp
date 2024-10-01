#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }
#define l long


void solve() {
    l SZ, P;
    l ring, actual;
    while(cin >> SZ >> P, SZ, P){
        l row = (SZ/2 + SZ%2);
        l col = row;

        ring = 1;
        while(ring*ring < P){
            ring += 2;
            row++; col++;
        }

        actual = ring*ring;

        for(int i = 0; i < ring-1 and actual!=P; i++) {row--; actual--;}
        for(int i = 0; i < ring-1 and actual!=P; i++) {col--; actual--;}

        for(int i = 0; i < ring-1 and actual!=P; i++) {row++; actual--;}
        for(int i = 0; i < ring-1 and actual!=P; i++) {col++; actual--;}

        cout << "Line = " << row << ", column = " << col << ".\n";
    } 
}

MAIN