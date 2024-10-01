#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    while (cin >> s) {
        list<char> output;   
        auto it = output.begin();  

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                it = output.begin();  
            } 
            else if (s[i] == ']') {
                it = output.end();    
            } 
            else {
                output.insert(it, s[i]);  
            }
        }

        string out(output.begin(), output.end());
        cout << out << '\n';
    }
}

int main() { solve(); }
