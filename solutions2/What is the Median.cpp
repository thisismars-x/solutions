#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    vector<int> numbers;

    int temp;
    while(cin >> temp){
        numbers.push_back(temp); sort(numbers.begin(), numbers.end());
        int n = numbers.size();

        if(n % 2 == 0){
            cout << (int)(numbers[n/2-1] + numbers[n / 2]) / 2 << '\n';
        }else cout << numbers[n / 2] << '\n';
    }
}

MAIN