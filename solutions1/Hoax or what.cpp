#include<set>
#include<iostream>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int n; 
    while(cin >> n, n){
        multiset<int> payers;
        long long total = 0;

        while(n--){
            int temp; cin >> temp;
            while(temp--){
                int temp1; cin >> temp1;
                payers.insert(temp1);
            }

            auto end = --payers.end();
            auto start = payers.begin();
            total += *end - *start;
            payers.erase(end); payers.erase(payers.begin());

        }

        cout << total << '\n';

    }

}

MAIN