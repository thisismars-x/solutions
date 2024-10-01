#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n, n){

        int array[105][105] = {};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> array[i][j];
            }
        }

        int row_p[100]{}, col_p[100]{};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                row_p[i] += array[j][i];
                col_p[i] += array[i][j];
            }
        }

        int RP{0}, CP{0}, rp, cp;
        for(int i = 0; i < n; i++){
            if(row_p[i] & 1) {RP++; rp = i;}
            if(col_p[i] & 1) {CP++; cp = i;}
        }

        if(RP == 0 and CP == 0) cout << "OK\n";
        else if(RP == 1 and CP == 1) cout << "Change bit (" << ++cp << "," << ++rp <<")\n";
        else cout << "Corrupt\n";
    }

}