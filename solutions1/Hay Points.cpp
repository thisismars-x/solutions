#include<bits/stdc++.h>
using namespace std;

map<string, int> ordering;

int main(){
    int n, m; cin >> n >> m;

    string temp;
    int temp0;
    for(int i = 0; i < n; i++){
        cin >> temp >> temp0;
        ordering[temp] = temp0;
    }

    vector<int> res(m);
    for(int i = 0; i < m; i++){
        while(cin >> temp, temp != "."){
            if(ordering.count(temp) != 0){
                res[i] += ordering[temp];
            }
        }
    }

    for(auto i : res) cout << i << '\n';
}