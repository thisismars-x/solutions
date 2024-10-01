#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n, temp;
    while(cin >> n, n){
        queue<int> deck;

        for(int i = 0; i < n; i++) deck.push(i+1);

        int flag = 0;
        int ansflag = 0;

        cout << "Discarded cards:";
        while(!deck.empty()){
            temp = deck.front();
            deck.pop();

            if(deck.size() == 0) break;

            if(!flag){
                if(ansflag){
                    cout << ",";
                }
                ansflag = 1;
                cout << " " << temp;
            }else deck.push(temp);

            flag ^= 1;
        }

        cout << "\nRemaining card: " << temp << '\n';
    }
}