#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;

    vector<string> solution;
    while((cin >> n) and (n != 0)){
        cin >> m;

        set<string> courses;
        for(int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            courses.insert(temp);
        }

        string r = "yes";  
        for(int i = 0; i < m; i++){
            int total, mins;
            cin >> total >> mins;
            
            set<string> names;
            string temp;
            for(int j = 0; j < total; j++){
                cin >> temp;
                names.insert(temp);
            }

            vector<string> play;
            set_intersection(courses.begin(), courses.end(), names.begin(), names.end(), back_inserter(play));


            if(play.size() < mins) {
                r = "no";
            }
        }
        solution.push_back(r);  
    }

    for(auto i : solution) cout << i << '\n';  
}

int main(){ 
    solve(); 
}
