#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }

void rotate_90(vector<vector<char>>& matrix, int n) {
    vector<vector<char>> other(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            other[i][j] = matrix[n - 1 - j][i];
        }
    }
    matrix = other;
}

int find(vector<vector<char>>& big, vector<vector<char>>& small, int N, int n) {
    int result = 0;
    for (int i = 0; i + n <= N; i++) {
        for (int j = 0; j + n <= N; j++) {
            bool match = true;
            for (int k = 0; k < n && match; k++) {
                for (int l = 0; l < n && match; l++) {
                    if (big[i + k][j + l] != small[k][l]) {
                        match = false;
                    }
                }
            }
            if (match) ++result;
        }
    }
    return result;
}

void solve() {
    int N, n;
    while ((cin >> N >> n), N || n) {  
        vector<vector<char>> big(N, vector<char>(N));
        vector<vector<char>> small(n, vector<char>(n));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> big[i][j]; 
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> small[i][j]; 
            }
        }

   
        for (int i = 0; i < 4; i++) {
            if (i != 0) rotate_90(small, n);  
            int result = find(big, small, N, n);

            if (i != 0) cout << " ";  
            cout << result;
        }
        cout << endl;
    }
}

MAIN
