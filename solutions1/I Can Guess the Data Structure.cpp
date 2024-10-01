#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int n;

    while(scanf("%d", &n) != EOF){
        stack<int> stk;
        queue<int> qu;
        priority_queue<int> pqu;

        bool _stk = true, _qu = true, _pqu = true;

        while(n--){
            int temp, temp1; cin >> temp >> temp1;
            if(temp == 1){
                stk.push(temp1);
                qu.push(temp1);
                pqu.push(temp1);
            }else{
                if(stk.empty()){
                    _stk = _qu = _pqu = false;
                    continue;
                }

                if(_stk){
                    _stk = (stk.top() == temp1);
                    stk.pop();
                }
                if(_qu){
                    _qu = (qu.front() == temp1);
                    qu.pop();
                }
                if(_pqu){
                    _pqu = (pqu.top() == temp1);
                    pqu.pop();
                }
            }
        }

        if(not _stk and not _qu and not _pqu) cout << "impossible";
        else if(_stk and not _qu and not _pqu) cout << "stack";
        else if(_qu and not _stk and not _pqu) cout << "queue";
        else if(_pqu and not _stk and not _qu) cout << "priority queue";
        else cout << "not sure";



        cout << '\n';
    }
}

MAIN