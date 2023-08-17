class Solution {
public:
  
        
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        //base case
        for(int prev_index=-1;prev_index<n;prev_index++)
        {
            dp[n][prev_index+1]=0;
        }
        
        
       for(int index=n-1;index>=0;index--)
       {
           for(int prev_index=index-1;prev_index>=-1;prev_index--)
           {
               

                int len=0;
                // not take
                len=0+dp[index+1][prev_index+1];
                //take
                if(prev_index==-1 or nums[index]>nums[prev_index])
                {
                    len=max(len,1+dp[index+1][index+1]);
                }

                 dp[index][prev_index+1]=   len;


               
           }
       }
        return dp[0][-1+1];
       
        
        
    }
};