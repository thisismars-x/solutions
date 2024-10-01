#include <bits/stdc++.h>
using namespace std;

#define MAIN    int main(void) { solve(); }
#define pii     pair<int, int>
#define vpii    vector<vector<pii>>

void solve() {
    int row,column;
    
    while(scanf("%d %d" ,&row, &column) != EOF){
        vpii transpose(column,vector<pii>());
        
        for(int i = 0; i < row; i++){
            int temp,temp1; cin >> temp;
            vector<int> pos;

            for(int j = 0; j < temp; j++){
                cin >> temp1;
                pos.push_back(temp1-1);
            }
            for(int j = 0; j < temp; j++){
                cin >> temp1;
                transpose[pos[j]].push_back({temp1, i+1});
            }

        }
        printf("%d %d\n",column, row);

        for(int i = 0; i < column; i++){
            cout << transpose[i].size();
            for(auto& p : transpose[i]) cout << " " << p.second;
            cout << endl;
            for(auto& p : transpose[i])
                cout << p.first << (&p == &transpose[i].back() ? "" : " ");
            cout << endl;
        }
    }
}

MAIN