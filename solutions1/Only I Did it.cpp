#include<bits/stdc++.h>
using namespace std;


void solve(){

    int tests; cin >> tests;

    for(int T = 0; T < tests; T++){
        int solved[3];
        int problems[3][1000];
        int solved_times[10001]{0};

        for(int i = 0; i < 3; i++){
            cin >> solved[i];

            for(int j = 0; j < solved[i]; j++){
                cin >> problems[i][j];
                ++solved_times[problems[i][j]];
            }

            sort(problems[i], problems[i] + solved[i]);
        }

        int solve[3];
        int maxsolved = 0;

        for(int i = 0; i < 3; i++){
            int norepeats{0};

            for(int j = 0; j < solved[i]; j++){
                if(solved_times[problems[i][j]] == 1)
                    ++norepeats;
            }

            solve[i] = norepeats;
            maxsolved = max(maxsolved, norepeats);
        }

        cout << "Case #" << T + 1 << ":\n";
        for(int i = 0; i < 3; i++){

            if(solve[i] == maxsolved){
                cout << i+1 << " " << solve[i];
                for(int j = 0; j < solved[i]; j++){
                    if(solved_times[problems[i][j]] == 1) cout << " " << problems[i][j];
                }

                cout << endl;
            }

        }
    }
}

int main(){
    solve();    
}