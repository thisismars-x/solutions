#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> out;
        vector<int> stack;

        backtrace(0, target, candidates, out, stack);
        return out;
    }

    void backtrace(int idx, int target, vector<int>& cand, vector<vector<int>>& out, vector<int> &stack){
        if(target == 0) { out.push_back(stack); return; }

        for(int j = idx; j < cand.size(); j++){
            if( j > idx && cand[j] == cand[j-1]) continue;
            if(cand[j] > target) break;
            stack.push_back(cand[j]);
            backtrace(j + 1, target-cand[j], cand, out, stack);
            stack.pop_back();
        }
    }
};

int main(){
    Solution x;
    vector<int> candidates{10,1,2,7,6,1,5};
    vector<vector<int>> out = x.combinationSum2(candidates, 8);

    for(auto i : out){ for(auto j : i) {
        cout << j << " ";
    } cout << '\n';}
}