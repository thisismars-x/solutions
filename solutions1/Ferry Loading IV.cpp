#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ncase; cin >> ncase;
    while(ncase--){
        int maxl, ncars;
        cin >> maxl >> ncars;

        vector<int> carlong(ncars);
        vector<queue<int>> sides(2);
        maxl *= 100;

        for(int i = 0; i < ncars; i++){
            int l;
            string side; cin >> l >> side;

            if(side == "left") sides[0].push(i);
            else sides[1].push(i);

            carlong[i] = l;
        }

        int side = 0, moves = 0;

        while(!sides[0].empty() or !sides[1].empty()){
            int c_length = 0;

            while(!sides[side].empty() and 
            carlong[sides[side].front()] + c_length <= maxl){
                c_length += carlong[sides[side].front()];
                sides[side].pop();
            }

            moves++;
            ++side %= 2;
        }

        cout << moves << '\n';
    }
}