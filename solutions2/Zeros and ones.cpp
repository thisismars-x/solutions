#include<iostream>
#include<vector>
using namespace std;

bool same(string s, int x, int y){
    
    int a = min(x,y);
    int b = max(x,y);
    for(int i = a; i < b; i++){
        if(s[i] != s[i+1]) return false;
    }
    return true;
}

int main(){

    string s;
    int tries;
    vector<vector<string>> answer;
    bool run = true;
    while(run && (cin >> s >> tries) && tries > 0){

        vector<string> sanswer;
        for(int i = 0; i < tries; i++){
            int a, b;
            cin >> a >> b;
            if(same(s, a, b)){
                sanswer.push_back("Yes");
            }else{
                sanswer.push_back("No");
            }if(a == 0 && b == 0) run = false;
        }

        answer.push_back(sanswer);
    }

    int x = 0;

    for(auto i : answer){
        cout << "Case " << ++x << ":\n";
        for(auto j : i){
            cout << j << '\n';
        }
    }
}