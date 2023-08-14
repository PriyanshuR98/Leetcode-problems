class Solution {
public:

    int helper(int index, vector<int>&prices, bool brought, int transactions,vector<vector<vector<int> > > &dp,int k)
    {
        if(index>=prices.size())
        {
            return 0;
        }

        if(transactions>k)
        {
            return 0;
        }

        if(dp[index][brought][transactions]!=-1)
        {
            return dp[index][brought][transactions];
        }
        int profit=0;

        if(brought==0)
        {
            
                profit= -prices[index]+helper(index+1,prices,1,transactions+1,dp,k);
            

            // we dont want to buy
            profit=max(profit, helper(index+1,prices,0, transactions,dp,k));
        }
        else  // we cans sell
        {
            profit= prices[index]+helper(index+1,prices,0,transactions,dp,k);
            profit=max(profit,helper(index+1,prices,1,transactions,dp,k));
        }

        return dp[index][brought][transactions]= profit;
    }


    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(k+1, -1)));
        
        return helper(0,prices,0,0,dp,k);

    }
};