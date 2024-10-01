#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int n; 
    while(cin >> n and n){
        priority_queue<int, vector<int>, greater<int>> ordering;
        while(n--){
            int temp; cin >> temp;
            ordering.push(temp);
        }

        int total = 0;
        while(ordering.size() - 1){
            int sum = 0;
            sum += ordering.top();
            ordering.pop();
            sum += ordering.top();

            total += sum;
            ordering.pop();
            ordering.push(sum);
        }

        cout << total << '\n';
    }
}

MAIN