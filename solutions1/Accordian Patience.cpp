#include<bits/stdc++.h>
using namespace std;

#define pb      push_back
#define ss      stack<string>


inline bool check(string s1, string s2){
    return s1[0] == s2[0] || s1[1] == s2[1];
}

int main(){
    string current;
    while(cin >> current, current != "#"){
        vector<ss> piles(1);
        piles[0].push(current);

        for(int i = 0; i < 51; i++){
            cin >> current;
            ss p; p.push(current);
            piles.pb(p);

            bool change = false;

            do{
                change = false;
                for(int j = 1; j < piles.size(); j++){
                    current = piles[j].top();
                    int current_index = j - 1;

                    if(j > 2 and check(current, piles[j - 3].top()))
                        current_index -= 2;

                    string card = piles[current_index].top();
                    if(check(card, current)){
                        piles[current_index].push(current);
                        piles[j].pop();

                        if(piles[j].empty()){
                            piles.erase(piles.begin() + j);

                        }

                        change = true;
                        break;
                    }
                }
            }while(change);
        }

        cout << piles.size() << " pile" 
            << (piles.size() == 1? " ":"s ") << "remaining: ";


        for(int i = 0; i < piles.size(); i++){
            cout << piles[i].size();

            if(i+1 != piles.size())
                cout << " ";
        }

        cout << '\n';
    }
}