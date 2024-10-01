#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

void solve() {
    int W, H, N;

    while ((cin >> W >> H >> N), W || H || N) {
        vector<vector<int>> board(H, vector<int>(W, 0));  
        for (int i = 0; i < N; i++) {
            int temp0, temp1, temp2, temp3;
            cin >> temp0 >> temp1 >> temp2 >> temp3;

            temp0--; temp1--;
            temp2--; temp3--;

            int x1 = min(temp0, temp2), x2 = max(temp0, temp2);
            int y1 = min(temp1, temp3), y2 = max(temp1, temp3);

            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y <= y2; y++) {
                    board[y][x] = 1; 
                }
            }
        }

        int empty_slots = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!board[i][j]) ++empty_slots;
            }
        }

        if (empty_slots == 0)
            cout << "There is no empty spots.\n";
        else if (empty_slots == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << empty_slots << " empty spots.\n";
    }
}

MAIN
