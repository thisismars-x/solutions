#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;


    int n = 0;
    while(t--){
        int a, b, c, d, e[3];
        cin >> a >> b >> c >> d >> e[0] >> e[1] >> e[2];
        sort(e, e + 3);

        double f = a + b + c + d + (e[1] + e[2]) / 2;

        cout << "Case " << ++n << ": ";

        if(f >= 90) cout << "A\n";
        else if(f >= 80) cout << "B\n";
        else if(f >= 70) cout << "C\n";
        else if(f >= 60) cout << "D\n";
        else cout << "F\n";

    }
}