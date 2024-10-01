#include<bits/stdc++.h>
using namespace std;

#define maxN 100000+5
int n, a[maxN], numword;
string s;
map<string, int> Val;
int p, q;

void init() {
    numword = n = 0; Val.clear();
}

void process() {
    char ch[200];
    while (scanf("%s", ch)) {
        s = ch;
        if (s == "END") break;
        int i = 0, k, len;
        string tmp;
        len = s.length();
        while (i < len) {
            while (i < len && !isalpha(s[i])) i++;
            if (i >= len) break;
            k = 1;
            while (i + k < len && isalpha(s[i + k])) k++;
            tmp = s.substr(i, k);
            i += k;

            int u = Val[tmp];
            if (u == 0) {  
                Val[tmp] = ++numword;
                a[n++] = numword;
            } else {  
                a[n++] = u;
            }
        }
    }
}

void solve() {
    int kount, t[numword + 5];
    kount = numword; 
    for (int i = 1; i <= numword; i++) t[i] = 0; 
    p = n; q = 0; 
    
    for (int i = 0, j = 0; i < n; i++) {
        if (++t[a[i]] == 1) kount--;  
        while (j < n && t[a[j]] - 1 > 0) {  
            t[a[j]]--;
            j++;
        }
        if (!kount && i - j < p - q) { 
            p = i;
            q = j;
        }
    }
}

int main() {
    int kase;
    scanf("%d", &kase);
    cin.ignore();  

    for (int kk = 1; kk <= kase; ++kk) {
        init();         
        process(); 
        solve();         

        cout << "Document " << kk << ": " << q+1 << " " << p+1 << '\n';
    }

}
