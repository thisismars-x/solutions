#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    
    int ncases;
    cin >> ncases;

    int c = 0;
    while(ncases--){
        int num; cin >> num;
        int p[100001], q[100001];

        for(int i = 0; i < num; i++) cin >> p[i];
        for(int i = 0; i < num; i++) cin >> q[i];

        long long sum = 0, mn = 111111111111111;
        for(int i = 0; i < num; i++){
            sum += p[i] - q[i];
            mn = min(sum, mn);
        }

        int idx = 0;
		while (mn < 0 && idx < num) {
			mn -= p[idx] - q[idx++];
		}
		cout << "Case " << ++c << ": ";
		if (idx == num || sum < 0)
			cout << "Not possible\n";
		else
			cout << "Possible from station " << idx + 1 << "\n";
    }
}

MAIN