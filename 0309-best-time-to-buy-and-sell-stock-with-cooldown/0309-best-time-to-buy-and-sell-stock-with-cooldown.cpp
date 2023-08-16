class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
         int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
      
        dp[n][0]=0;
        dp[n][1]=0;
        dp[n+1][0]=0;
        dp[n+1][1]=0;
        
        for(int index=n-1;index>=0;index--)
        {
            for(int bought=0;bought<=1;bought++)
            {
                 int profit=0;
        
                    if(bought==0)  //can buy
                    {
                        profit=max(-prices[index]+dp[index+1][1] ,  dp[index+1][0]);
                    }

                    else
                    {
                         profit=max(+prices[index]+dp[index+2][0] ,  dp[index+1][1]);
                    }

                   dp[index][bought]=profit;
            }
        }
        
        return dp[0][0];
        
    }
};