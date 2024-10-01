#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string temp;

        backtrace(output, temp, 0, 0, n);
        return output;
    }

    void backtrace(vector<string>& out, string& temp, int open, int close, int n){
        if(close == open and open == n){
            out.push_back(temp);
        }

        if(open < n){
            temp.push_back('(');
            backtrace(out, temp, open + 1, close, n);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            backtrace(out, temp, open, close + 1, n);
            temp.pop_back();
        }
    }
};

int main(){
    Solution x;
    vector<string> out = x.generateParenthesis(3);
    for(auto i: out) cout << i << endl;
}