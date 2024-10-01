#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


bool check(int matrix[1000][1000], int size){
    int center = size%2 + size/2;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] < 0) return false;
            if(matrix[i][j] != matrix[size - 1 - i][size - 1 - j]) return false;
        }
    }


    return true;
}

void solve() {
    int cases = 0;

    int t0; cin >> t0;
    while(t0--){

        int matrix[1000][1000];

        char temp0;
        char temp1;

        cin >> temp0 >> temp1;
        int N; cin >> N;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> matrix[i][j];
            }
        }

        cout << "Test #" << ++cases;
        if(check(matrix, N)){
            cout << ": Symmetric.\n"; 
        }else{
            cout << ": Non-symmetric.\n";
        }

    }
}

MAIN