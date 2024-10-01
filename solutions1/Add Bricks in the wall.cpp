#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int T; cin >> T;
    int array[10][10]{0};

    while(T--){
        for(int i = 0; i < 9; i += 2){
            for(int j = 0; j <= i; j+=2){
                cin >> array[i][j];
            }
        }

        for(int i = 8; i > 0; i -= 2){
            for(int j = 0; j < 9; j += 2){
                array[i][j+1] = (array[i-2][j] - array[i][j] - array[i][j+2]) >> 1;
                array[i-1][j] = array[i][j] + array[i][j+1];
                array[i-1][j+1] = array[i][j+1] + array[i][j+2];
            }
        }

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j <= i; j++) {
                if(j)   cout << ' ';
                cout << array[i][j];
            }

            cout << endl;
        }
    }


}

MAIN