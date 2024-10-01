#include<bits/stdc++.h>
using namespace std;

#define mss         unordered_map<string, string>


int main(void){
    int nlines; cin >> nlines; cin.ignore();
    mss ordering;

    while(nlines--){
        string temp1, temp2;
        getline(cin, temp1);
        getline(cin, temp2);
        ordering[temp1] = temp2;
    }

    int n; cin >> n;
    cin.ignore();
    while(n--){
        string temp; getline(cin, temp);
        cout << ordering[temp] << '\n';
    }
}