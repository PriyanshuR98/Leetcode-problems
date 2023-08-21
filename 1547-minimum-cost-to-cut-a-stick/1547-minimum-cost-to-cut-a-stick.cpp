class Solution {
public:
    int helper( int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=1e9;
        
        for(int par=i;par<=j;par++)
        {
            mini=min(mini,cuts[j+1]-cuts[i-1]+helper(i,par-1,cuts,dp)+helper(par+1,j,cuts,dp));
        }

        return dp[i][j]=mini;


    }
    int minCost(int n, vector<int>& cuts) {
        int c= cuts.size();

        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end());

        return helper(1,c,cuts,dp);

        
    }
};