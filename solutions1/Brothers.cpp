
#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

void battle(vector<vector<int>>& grid, int nsons){

    vector<vector<int>> next(grid);
    int rows = grid.size(), cols = grid[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

            int enemy = (grid[i][j] + 1) % nsons;

            if(i!=0 and grid[i-1][j] == enemy) next[i-1][j] = grid[i][j];
            if(j!=0 and grid[i][j-1] == enemy) next[i][j-1] = grid[i][j];
            if(i+1!=rows and grid[i+1][j] == enemy) next[i+1][j] = grid[i][j];
            if(j+1!=cols and grid[i][j+1] == enemy) next[i][j+1] = grid[i][j];

        }
    }

    grid = next;

}


void solve() {
    int N, R, C, K;
    while((cin >> N >> R >> C >> K), N){

        vector<vector<int>> grid(R, vector<int>(C));
        
        int temp;
        for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) cin >> grid[i][j];
        
        while(K--) battle(grid, N);

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout << grid[i][j] << (j + 1 == C? "\n": " ");
            }
        }
    }


}

MAIN