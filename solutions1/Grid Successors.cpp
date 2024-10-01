#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int t0; cin >> t0;

    int moves[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    while(t0--){

        vector<bitset<3>> grid(3);
        bool is_zero = 1;

        for(int i = 0; i < 3; i++){
            string temp; cin >> temp;

            for(int j = 0; j < 3; j++){
                grid[i][j] = temp[j] - '0';
                if(grid[i][j]) is_zero = 0;
            }
        }

        if(is_zero) cout << "-1\n";
        else{
            vector<bitset<3>> temp(3);
            int sum = 1, idx = -1;

            while(!is_zero){
                ++idx;
                is_zero = 1;

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){

                        bool sum = 0;
                        for(int m = 0; m < 4; m++){
                            int y = moves[m][0] + i;
                            int x = moves[m][1] + j;

                            if(y > -1 and x > -1 and y < 3 and x < 3){
                                sum = grid[y][x] ^ sum;

                            }

                        }

                        temp[i][j] = sum;
                        if(temp[i][j]) is_zero = 0;
                    
                    }
                }

                grid = temp;
            }

            cout << idx << '\n';
        }

    }
}

MAIN