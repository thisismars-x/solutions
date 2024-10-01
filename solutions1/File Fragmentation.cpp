#include<bits/stdc++.h>
using namespace std;


void start_solving(){
    string s;
    getline(cin, s);
    int ncase; 
    istringstream ss{s};
    ss >> ncase;

    getline(cin, s);
    while(ncase--){
        vector<string> fragments;
        while(getline(cin, s), not s.empty()){
            ss.clear();
            ss.str(s);

            string fragment;
            ss >> fragment;
            fragments.push_back(fragment);
        }

        map<string, int> memo;
        for(int i = 0; i < fragments.size(); ++i)
            for(int j = i + 1; j < fragments.size(); ++j){
                ++memo[fragments[i] + fragments[j]];
                ++memo[fragments[j] + fragments[i]];
            }

        auto iter = memo.begin(), file = memo.end();

        for(; iter != memo.end(); ++iter){
            if(iter->second > file->second) file = iter;
        }

        cout << file->first << '\n';
        if(ncase) cout << '\n';
        
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start_solving();
}