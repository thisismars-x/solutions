#include <bits/stdc++.h>
using namespace std;

#define MAIN int main(void) { solve(); }


void solve() {
    string in, temp;
    set<string> result;

    bool hyphen = false;
    while(getline(cin, temp)){
        in += temp;
        if(in.back() == '-'){
            hyphen = true; in.pop_back();
        }
        else in += " ";
    }

    in = regex_replace(in, regex("[^a-zA-Z\-]"), " ");
    transform(in.begin(), in.end(), in.begin(), ::tolower);

    istringstream ss{in};
    while(ss >> in)
        result.insert(in);

    for(auto &s: result) cout << s << '\n';
}

MAIN