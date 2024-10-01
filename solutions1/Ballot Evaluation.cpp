#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }




void solve() {
    int n = 1;
    int nparties, nguess;
    cin >> nparties >> nguess;

    map<string, int> votes;
    float num;
    while(nparties--){
        char temp[1000];
        char ignore;
        int temp1, temp2;
        scanf("%s %d.%d", temp, &temp1, &temp2);
        votes[temp] = temp1*10 + temp2;
    }

    cin.ignore();
    while(nguess--){
        string s;
        getline(cin, s);
        istringstream ss(s);

        cout << "Guess #" << n++ << " was ";
        int total = 0;

        
        while(ss >> s){
            if(s ==  "+")  continue;
            if(s ==  "<"){
                ss >> num;
                if(total < num * 10){
                    cout << "correct.\n";
                }else cout << "incorrect.\n";

                break;
            }
            if(s ==  ">"){
                ss >> num;
                if(total > num * 10){
                    cout << "correct.\n";
                }else cout << "incorrect.\n";

                break;
            }
            if(s == ">="){
                ss >> num;
                if(total >= num * 10){
                    cout << "correct.\n";
                }else cout << "incorrect.\n";

                break;
            }
            if(s ==  "<="){
                ss >> num;
                if(total <= num * 10){
                    cout << "correct.\n";
                }else cout << "incorrect.\n";

                break;
            }
            if(s == "="){
                ss >> num;
                if(total == num * 10){
                    cout<< "correct.\n";
                }else cout << "incorrect.\n";

                break;
            }

            total += votes[s];
        }
    }
}

MAIN