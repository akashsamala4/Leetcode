class Solution {
public:
    void backtrack(int i,vector<vector<int>>& result,vector<int>& ans,vector<int>& nums){
            int n = nums.size();
            if(i>=n){
                result.push_back(ans);
                return;
            }

            ans.push_back(nums[i]);
            backtrack(i+1,result,ans,nums);
            
            ans.pop_back();
            backtrack(i+1,result,ans,nums);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>ans;
        backtrack(0,result,ans,nums);
        return result;
    }
};