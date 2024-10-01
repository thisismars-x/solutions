#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int values[]{-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5, 5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2};
    string in;

    while(cin >> in){

        string temp;
        
        int prev = -1;
        for(int i = 0; i < in.size(); i++){

            int value = values[in[i] - 'A'];
            if(prev != value and value != -1){
                cout << value;
            }

            prev = value;
        }

        cout << '\n';
    }
}

MAIN