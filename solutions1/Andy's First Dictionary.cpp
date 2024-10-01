#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    string in;
    set<string> result;

    while(getline(cin, in)){
        in = regex_replace(in, regex("[^a-zA-Z]"), " ");
        transform(in.begin(), in.end(), in.begin(), ::tolower);

        istringstream ss(in);
        while(ss >> in) result.insert(in);
    }

    for(auto &s: result) cout << s << '\n';
}

MAIN