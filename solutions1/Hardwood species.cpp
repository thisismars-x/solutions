#include<bits/stdc++.h>
using namespace std;

int main(){
    int ncase; 
    scanf("%d", &ncase);
    getchar();
    getchar();

    while(ncase--)
    {
        map<string, double> ordering;
        string temp;
        int total = 0;

        while(getline(cin, temp)){
            if(temp.compare("") == 0) break;
            ordering[temp]++;
            total++; 
        }

        for(auto it = ordering.begin(); it != ordering.end(); it++){
            cout << it->first << " " << fixed << setprecision(4) << it->second * 100.0 / total << '\n';
        }
        if (ncase) {
            cout << '\n'; 
        }
    }
    return 0;
}

