#include<bits/stdc++.h>
using namespace std;

int main(void){

    int a, b;

    vector<int> solution;
    while((cin >> a >> b) && (a!=-1 && b!=-1)){
        int c = min(a,b);
        int d = max(a,b);

        int e = (c + (100 - d));
        int f = d - c;
        solution.push_back(min(e, f));
    }

    for(auto i : solution) cout << i << '\n';
}