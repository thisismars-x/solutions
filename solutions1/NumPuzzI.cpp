#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    
    // a b c 
    // d e f 
    // g h i

    int move[5][2] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}};
    string in;

    for(int t0=1; getline(cin, in); t0++){

        int n = in.size();
        vector<vector<int>> grid(3, vector<int>(3));

        for(int t1=n-1; t1 >= 0; --t1){
            int vert = in[t1] - 'a'; vert /= 3;
            int hor = in[t1] - 'a'; hor %= 3;

            for(int t2=0; t2 <  5; t2++){
                int y1 = vert + move[t2][0];
                int x1 = hor + move[t2][1];

                if(y1 > -1 and x1 > -1 and y1 < 3 and x1 < 3)
                    grid[y1][x1] = (grid[y1][x1] + 1) % 10;
            }
        }

        cout << "Case #" << t0 << ":\n";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << grid[i][j];

                if(j < 2) cout << " ";
            }

            cout << '\n';
        }
        
    }
}

MAIN