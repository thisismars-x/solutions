class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtrace(s, 0, temp, result);
        return result;        
    }

    bool check(string temp, int start, int end){
        while(start <= end){
            if(temp[start++] != temp[end--]) return false;
        }
        return true;
    }

    void backtrace(string s, int idx, vector<string> temp,
    vector<vector<string>>& result){
        if(idx == s.size()){
            result.push_back(temp); return;
        }

        for(int i = idx; i < s.size(); i++){
            if(check(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                backtrace(s, i+1, temp, result);
                temp.pop_back();
            }
        }
    }
};