#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int ncase; cin >> ncase;
    cin.ignore();

    while(ncase--){
        int nlocs; cin >> nlocs;
        int mins = nlocs;

        vector<int> result;
        cin.ignore();
        for(int i = 0; i < nlocs; i++){
            string in; getline(cin, in);
            istringstream ss(in);

            int current = 0;
            while(ss >> in) current++;
            if(current < mins){
                mins = current;
                result.clear();
            }

            if(current == mins) result.push_back(1 + i);
        }

        for(auto i : result){
            cout << i;
            if(i != result.back()) cout << " ";
            else cout << endl;
        }
    }
}

MAIN