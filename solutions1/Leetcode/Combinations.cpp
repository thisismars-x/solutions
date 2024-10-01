class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> soln;
        vector<int> temp;

        backtrace(1, temp, soln, n, k); return soln;
    }

    void backtrace(int s, vector<int>& temp, vector<vector<int>>& soln, int n, int k){
        if(temp.size() == k){
            soln.push_back(temp);
            return;
        }


        for(int i = s; i < n+1; i++){
            temp.push_back(i);
            backtrace(i+1, temp, soln, n, k);
            temp.pop_back();
        }
    }
};