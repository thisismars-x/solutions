#include<bits/stdc++.h>
using namespace std;

void solve() {
    int case_num = 1;  // Separate case number variable
    
    while (true) {
        int available;
        cin >> available; 

        if (available < 0) break;  

        vector<int> created(12);
        vector<int> needed(12);

        for (int i = 0; i < 12; i++) cin >> created[i];  
        for (int i = 0; i < 12; i++) cin >> needed[i];   

        cout << "Case " << case_num++ << ":\n";  
        for (int i = 0; i < 12; i++) {
            if (needed[i] <= available) {
                cout << "No problem! :D" << '\n';
                available -= needed[i];  
            } else {
                cout << "No problem. :(" << '\n';
            }


            available += created[i];
        }
    }
}

int main() { solve(); }
