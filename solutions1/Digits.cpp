#include<bits/stdc++.h>
using namespace std;

void solve(){
    char number[1000000];

    while(scanf("%s", number) != EOF){
        
        if(number[0] == 'E'){ return;}

        int n = atoi(number);
        int size = strlen(number);

        int s = 1;
        while(size != n){
            n = size;
            size = (int)log10(double(size)) + 1;
            ++s;
        }

        cout << s << '\n';
    }
}

int main(){ solve(); }