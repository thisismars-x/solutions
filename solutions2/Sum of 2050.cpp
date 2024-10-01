#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long temp; cin >> temp;
        if(!(temp % 2050)){
            long long n = temp / 2050;

            long long sum = 0;
            while (n!=0){
                sum+=(long long)n%10;
                n/=10;
            }
            cout << sum << '\n';
        }else cout << "-1\n";
    }
}