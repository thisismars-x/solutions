#include<bits/stdc++.h>
using namespace std;

int check(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

string a, b;
vector<char> st, op;

void try_all(int i, int e){
    if(e == b.length()){
        bool first = true;

        for(auto x: op){
            cout << (first? "": " ") << x;
            first = false;
        }
        cout << '\n'; return;
    }

    if(i < a.length()){
        op.push_back('i');
        st.push_back(a[i]);
        try_all(i+1, e);
        op.pop_back();
        st.pop_back();
    }

    if(st.back() == b[e] && !st.empty()){
        char temp = st.back();
        st.pop_back();
        op.push_back('o');
        try_all(i, e+1);
        st.push_back(temp);
        op.pop_back();
    }
}


int main(){
    while(cin >> a >> b){
        cout << "[\n";
        if(check(a, b)) try_all(0,0);
        cout << "]\n";
    }
}