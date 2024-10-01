class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> solution;

        int n = nums.size();
        for(int i = 0; i < (1 << n); i++){
            multiset<int> temp;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)) temp.insert(nums[j]);
            }
            vector<int> temp2{temp.begin(), temp.end()};
            solution.insert(temp2);
        }


        vector<vector<int>> s{solution.begin(), solution.end()};
        return s;
    }
};