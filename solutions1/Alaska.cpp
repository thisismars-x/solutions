#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    int t0;

    while(cin >> t0 and t0){

        vector<int> stations(1, 1522);

        while(t0--){
            int temp; cin >> temp;
            stations.push_back(temp);
        }

        sort(stations.begin(), stations.end());
        vector<int> diff(stations.size());

        adjacent_difference(stations.begin(), stations.end(), diff.begin());
        auto it = max_element(diff.begin(), diff.end());

        if(*it > 200) cout << "IMPOSSIBLE\n";
        else cout << "POSSIBLE\n";

    }
}

MAIN