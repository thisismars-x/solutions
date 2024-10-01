#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;

        string mapping[10] = {"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.empty()){
            return out;
        }

        if(digits.size() == 1){
            for(int i = 0; i < mapping[digits[0] - '0'].size(); i++){
                string temp;
                temp += mapping[stoi(digits)][i];
                out.push_back(temp);
            }

            return out;
        }
        
        string temp;
        backtrace(temp, out, digits, 0, mapping);
        return out;
    }

    void backtrace(string& temp, vector<string>& out, string digits, int i, string mapping[]){
        if(i == digits.size()) {
            out.push_back(temp); return;
        }

        int does = digits[i] - '0';
        string value = mapping[does];

        for(int k = 0; k < value.length(); k++){
            temp.push_back(value[k]);
            backtrace(temp, out, digits, i+1, mapping);
            temp.pop_back();
        }
    }
};


int main(){
    Solution x;
    vector<string> out = x.letterCombinations("234");

    for(auto i : out) cout << i << '\n';
}