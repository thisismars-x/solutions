#include<iostream>
#include<queue>
using namespace std;

int main(){
    int ncase; cin >> ncase;
    while(ncase--){
        int a, b; cin >> a >> b;

        queue<int> q, qidx;
        int priority[10]{};

        for(int i = 0; i < a; i++){
            int temp; cin >> temp;
            q.push(temp), qidx.push(i);
            priority[temp]++;
        }

        int minutes = 0;
        while(true){
            int Q = q.front(); q.pop();
            int Qidx = qidx.front(); qidx.pop();

            int do_pop {1};

            for(int i = Q + 1; i < 10; i++) do_pop &= (priority[i] == 0);
            if(do_pop){
                minutes++;
                if(Qidx == b) {
                    cout << minutes << '\n';
                    break;
                }
                priority[Q]--;
            }
            else{
                q.push(Q), qidx.push(Qidx);
            }
        }
    }
}