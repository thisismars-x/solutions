#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }
#define pb push_back

void solve() {
    
    while(true){
        int nlines; cin >> nlines;
        if(nlines == 0) break;

        char character;
        int maxl{0};

        vector<int>rowl(nlines);

        for(int i = 0; i < nlines; i++){
            int numberx{0};
            char character; cin >> character;

            for(int j = 0; j < 25; j++){
                cin.read(&character, 1);
                if(character == 'X') ++numberx;
            }

            maxl = max(maxl, numberx);
            rowl[i] = numberx;
        }

        int spaces = 0;
        for(int i = 0; i < nlines; i++){
            spaces += maxl - rowl[i];
        }

        cout << spaces << '\n';

    }
}

MAIN