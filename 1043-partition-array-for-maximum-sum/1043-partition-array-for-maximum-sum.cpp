class Solution {
public:
    int helper(int i, vector<int>&arr, int k, vector<int>&dp)
    {
        if(i==arr.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int maxcost=INT_MIN;
        int currmax=INT_MIN;
        
        for(int par=i;par<arr.size();par++)
        {   
            currmax=max(currmax,arr[par]);
            if(par-i+1<=k)
            {
                int cost= (par-i+1)*currmax+helper(par+1,arr,k,dp);
                maxcost=max(cost,maxcost);
            }
          
        }
        
        return dp[i]=maxcost;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(0,arr,k,dp);
        
        
    }
};