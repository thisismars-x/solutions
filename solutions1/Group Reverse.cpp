#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int ngroups;
        cin >> ngroups;

        if(!ngroups) break;

        string in; cin >> in;
        int size = in.size();

        int gsize = size / ngroups;
        
        for(int i = 0; i < size; i+=gsize){
            for(int z = i, p = i -1 + gsize; z < p; ++z, --p){
                char temp(in[z]);
                in[z] = in[p];
                in[p] = temp;
            }

        }

        cout << in << endl;
    }
}