class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxlen=1;
        for(int index=0;index<n;index++)
        {
            for(int prevind=0;prevind<index;prevind++)
            {
                if(nums[prevind]<nums[index])
                {
                    dp[index]=max(dp[index],1+dp[prevind]);
                }
                maxlen=max(maxlen,dp[index]);
            }
        }
        
        return maxlen;
        
        
        
        
        
    }
};