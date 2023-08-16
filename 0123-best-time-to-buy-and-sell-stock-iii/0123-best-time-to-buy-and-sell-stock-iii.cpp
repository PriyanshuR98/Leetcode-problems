class Solution {
public:
        int solver(vector<int>&prices, int index, int transactions ,  vector<vector<int>>&dp)
        {
            if(index==prices.size() or transactions>=4)
            {
                return 0;
            }
            
            if(dp[index][transactions]!=-1)
            {
                return dp[index][transactions];
            }
            
            int profit=0;
            if(transactions%2==0)  // can buy
            {
                
                profit=max(-prices[index]+solver(prices,index+1,transactions+1,dp)  , solver(prices,index+1,transactions,dp) );  
            }
            else  // can sell
            {
                profit=max(+prices[index]+solver(prices,index+1,transactions+1,dp)  , solver(prices,index+1,transactions,dp) );  
            }
            
            return dp[index][transactions]= profit;
        }
    int maxProfit(vector<int>& prices) {
        
        // b s b s ..  0 1 2 3
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
        return solver(prices,0,0,dp);
        
        
        
    }
};