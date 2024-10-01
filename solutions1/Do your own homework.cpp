#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t;
    int n = 1;

    while(t--){
        int nsubj; cin >> nsubj;
        map<string, int>  days;

        while(nsubj--){
            string temp;
            int temp0;
            cin >> temp >> temp0;
            days[temp] = temp0;
        }

        int d;
        string subj;
        cin >> d >> subj;

        cout << "Case " << n++ << ": ";


        if(!days.count(subj) || days[subj] > d + 5) cout << "Do your own homework!";
        else if(days[subj] <= d) cout << "Yesss";
        else cout << "Late";

        cout << '\n';
    }
}