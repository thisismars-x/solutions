#include<bits/stdc++.h>
using namespace std;

int main(){
    string temp;

    int T;
    cin >> T;
    cin.ignore();

    while(T--){
        getline(cin, temp);

        int k = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == 'M') {++k;}
            else if(temp[i] == 'F') {--k;}
        }

        if(temp.size() > 3 and k == 0) {cout << "LOOP\n";}
        else {cout << "NO LOOP\n";}
    }
}