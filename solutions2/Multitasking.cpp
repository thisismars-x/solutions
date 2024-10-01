#include<bits/stdc++.h>
using namespace std;

#define MAX     1000005


int main(){
    bitset<MAX> calendar;

    int n_rep, rep;
    while(cin >> n_rep >> rep,( n_rep or rep )){
        calendar.reset();
        int a, b, period;
        bool CONFLICT = false;

        while(n_rep--){
            cin >> a >> b;
            if(!CONFLICT){
                for(int i = a; i < b; i++){
                    if(calendar[i] == 1){
                        CONFLICT = true;
                        break;
                    }

                    calendar[i] = 1;
                }
            }
        }

        while(rep--){
            cin >> a >> b >> period;

            if(!CONFLICT){
                while(a < MAX){
                    for(int i = a; i < b and i < MAX; i++){
                        if(calendar[i] == 1){
                            CONFLICT = true;
                            break;
                        }

                        calendar[i] = 1;
                    }

                    a += period; b+= period;
                }
            }

        }

        if(CONFLICT) cout << "CONFLICT\n";
        else cout << "NO CONFLICT\n";

    }
}