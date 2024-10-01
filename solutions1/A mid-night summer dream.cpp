#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int t; 

    while(cin >> t){
        vector<int> v(t);
        
        for(int i = 0; i < t; i++) cin >> v[i];

        sort(v.begin(), v.end());
        int a, b, c;

        a = v[(v.size()-1) / 2];
        b = upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a);

        if(v.size() % 2){
            c = 1;
        }else{
            c = v[(v.size()-1) / 2] == v[v.size() / 2] ? 1 : v[v.size() / 2] - v[(v.size()-1) / 2] + 1;
            if(c != 1){
                int median2 = v[v.size() >> 1];
                b += upper_bound(v.begin(), v.end(), median2) - lower_bound(v.begin(), v.end(), median2);
            }
        }

        cout << a << " " << b << " " << c << '\n';
    }

}

MAIN