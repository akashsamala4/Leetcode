class Solution {
public:
        void backtrack(int idx,vector<vector<int>>& result,vector<int>& ans,vector<int>& nums){
            int n = nums.size();
            result.push_back(ans);

            for(int i = idx;i<n;i++){
                if(i>idx && nums[i]==nums[i-1]){
                    continue;
                }
                ans.push_back(nums[i]);
                backtrack(i+1,result,ans,nums);
                
                ans.pop_back();
            }
        }
        

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>ans;
        backtrack(0,result,ans,nums);
        return result;
    }
};