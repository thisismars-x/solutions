#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;
int main(){
    int t0; cin >> t0;

    while(t0--){
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> x(c), y (c);
        int temp0, temp1;

        for(int i = 0; i < c; i++){
            cin >> temp0 >> temp1;
            x[i] = temp0; y[i] = temp1;
        } 

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        c -= (c%2 == 0);
        cout << "(Street: " << x[c/2] << ", Avenue: " << y[c/2] << ')' <<  '\n';
    }
}