#include<bits/stdc++.h>
using namespace std;

int M;

bool sort_func(int i, int j){
    if(i % M != j % M) return i%M < j%M;

    if(i & 1){
        if(j & 1){
            return i > j;
        }

        return true;
    }

    if(j & 1) return false;

    return i < j;
}

void solve(){
    int T;
    vector<int> array(10005);

    while((cin >> T >> M) and (cout << T << " " << M << "\n") and T and M){
        for(int i = 0; i < T; i++) cin >> array[i];

        sort(array.begin(), array.begin() + T, sort_func);

        for(int i = 0; i < T; i++){
            cout << array[i] << '\n';
        }
    }
}

int main() { solve(); }