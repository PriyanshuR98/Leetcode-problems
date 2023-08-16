class Solution {
public:
    int helper(int index, vector<int>&prices, int fee, int bought,  vector<vector<int>>&dp)
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
        
        if(bought==0)  // can buy
        {
            profit=max(-prices[index]+helper(index+1,prices,fee,1,dp)  ,  helper(index+1,prices,fee,0,dp));
        }
        else
        {
             profit=max(+prices[index]-fee+helper(index+1,prices,fee,0,dp)  ,  helper(index+1,prices,fee,1,dp));
        }
        
        return dp[index][bought]=profit;
        
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        
        return helper(0,prices,fee,0,dp);
        
    }
};