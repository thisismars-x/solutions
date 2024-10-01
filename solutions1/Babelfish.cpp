#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> ordering;
    vector<string> out;
    string temp;

    while(getline(cin, temp) and not temp.empty()){
        istringstream ss(temp);
        string temp1, temp2;
        ss >> temp1 >> temp2;

        ordering[temp2] = temp1;
    }

    while(getline(cin, temp) and not temp.empty()){
        out.push_back(ordering.count(temp) == 0? "eh" : ordering[temp]);
    }


    for(auto i : out) cout << i << '\n';
}