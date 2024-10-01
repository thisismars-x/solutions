#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int t = 1;

    while((cin >> n)){
        vector<string> names;
        map<string, int> balance;
        for(int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            names.push_back(temp);
            balance[temp] = 0;
        }

        
        for(int i = 0; i < n; i++){
            string name;
            int give;
            int n_people;
            cin >> name >> give >> n_people;

            if(!n_people) continue;
            balance[name] -= (give/n_people) * n_people;

            for(int j = 0; j < n_people; j++){
                string person;
                cin >> person;
                balance[person] += (give/n_people);
            }
        }

        if(t++ > 1) cout << '\n';
        for(auto i : names){
            cout << i << " " << balance[i] << '\n';
        }

    }

}

int main(){
    solve();
}