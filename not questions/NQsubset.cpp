#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> n{1,2,3,4,5};

    vector<vector<int>> subsets;

    //n elements array has 2**n subsets
    for(int i = 0; i < (1 << n.size()); i++){ // 0 - 32/ 00000- 11111

        // example 00100

        vector<int> subset;
        for(int j = 0; j < n.size(); j++){ // 0000 - 0101
            // example 0010
            if(i & (1 << j)) subset.push_back(n[j]);
        }

        subsets.push_back(subset);
    }

    for(auto i : subsets){
        for(auto j : i) cout << j << " ";
        cout << '\n';
    }
}