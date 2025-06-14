class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            j=i;
            break;
            }
        }
        if(j==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int k;
        for(int i = n-1;i>j;i--){
            if(nums[i]>nums[j]){
                k=i;
                break;
            }
        }
        swap(nums[j],nums[k]);
        reverse(nums.begin()+j+1,nums.end());
        
    }
};