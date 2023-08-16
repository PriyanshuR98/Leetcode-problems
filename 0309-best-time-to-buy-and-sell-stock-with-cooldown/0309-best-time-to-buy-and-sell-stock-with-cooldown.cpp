class Solution {
public:
    int helper(int index, vector<int>prices, bool bought , vector<vector<int>>&dp)
    {
        if(index>=prices.size())
        {
            return 0;
        }
        
        if(dp[index][bought]!=-1)
              {
                  return dp[index][bought];
              }
        int profit=0;
        
        if(bought==0)  //can buy
        {
            profit=max(-prices[index]+helper(index+1,prices,1,dp) ,  helper(index+1,prices,0,dp));
        }
        
        else
        {
             profit=max(+prices[index]+helper(index+2,prices,0,dp) ,  helper(index+1,prices,1,dp));
        }
        
        return dp[index][bought]=profit;
    
    }
    int maxProfit(vector<int>& prices) {
        
    int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
       return helper(0,prices,0,dp);
        
    }
};