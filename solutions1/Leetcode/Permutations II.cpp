#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> solution;
        int n = nums.size();
        vector<int> temp;
        for(int i = 0; i < factorial(n); i++){
            next_permutation(nums.begin(), nums.end());
            solution.insert(nums);
        }
        
        vector<vector<int>> s{solution.begin(), solution.end()};
        return s;   
    }
    int factorial(int n){
        if(n == 1) return 1;
        else return n * factorial(n-1);
    }

};

int main(){
    Solution x;
    vector<int> numbers{1,2, 3};
    vector<vector<int>> solution = x.permuteUnique(numbers);

    for(auto i: solution) {
        cout << endl;
        for(auto j: i){
            cout << j << " " ;
        }
    }
}