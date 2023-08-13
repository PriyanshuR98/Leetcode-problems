class Solution {
public:
    int solver(int index, vector<int>&prices, bool bought, vector< vector<int> >&dp)
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
        
        if(bought==false)  // can buy or not.
        {
            profit= max(profit-prices[index]+solver(index+1,prices,!bought,dp), solver(index+1,prices,bought,dp) );
        }
        
        if(bought==true)  //can sell or not..
        {
          profit=max(profit+prices[index]+solver(index+1,prices,!bought,dp),solver(index+1,prices,bought,dp));
        }
        
        return dp[index][bought]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();        
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return solver(0,prices,false,dp);
        
    }
};