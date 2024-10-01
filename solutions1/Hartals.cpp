#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int nd, np, a[100];
        cin >> nd >> np;
        for(int i = 0; i < np; i++) cin >> a[i];

        int result = 0;
        for(int i = 1; i <= nd; i++){
            if(i%7==6 or i%7==0) continue;

            bool found = false;
            for(int j = 0; j < np; j++){
                if(i % a[j] == 0) {found = true; break; }
            }
            if(found) ++result;
        }

        cout << result << '\n';
    }
}