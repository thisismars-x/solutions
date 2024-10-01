#include<bits/stdc++.h>
using namespace std;

struct record{
    int month, day, hour, mins, loc;
    bool exit;

    int time(){
        return mins + hour * 60 + day * 24 * 60;
    }
};

int main(){
    int ncase; cin >> ncase;
    getchar(); getchar();

    while(ncase--){
        int fare[24]{};
        map<string, vector<record>> license;

        for(int i = 0; i < 24; i++) cin >> fare[i];

        cin.ignore();
        string in;
        while(getline(cin, in), !in.empty()){

            istringstream ss(in);
            string plate, command;
            record r;

            char ignore;
            ss >> plate >> r.month >> ignore >> r.day >> ignore >> r.hour >> ignore >> r.mins >> command >> r.loc;
            r.exit = (command == "exit");
            license[plate].push_back(r);
        }

        for(auto &p : license){
            sort(p.second.begin(), p.second.end(), [](record a, record b){
                return a.time() < b.time();
            });


            int cents = 200;

            for(int i = 0; i < p.second.size(); i++){
                if(!p.second[i].exit and i+1<p.second.size() and p.second[i+1].exit){
                    int dist = abs(p.second[i].loc - p.second[i+1].loc);
                    cents += dist * fare[p.second[i].hour];
                    cents += 100;
                }
            }

            if(cents != 200){
                cout << p.first << " $" << setprecision(2) << fixed << cents/100.0 << '\n';
            }
        }
    if(ncase) cout << '\n';
    }

    


}