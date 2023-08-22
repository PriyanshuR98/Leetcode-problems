class Solution {
public:
    int counter(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int maxi=-1e9;
        for(int burst=i;burst<=j;burst++)
        {
            int coins= nums[burst]*nums[j+1]*nums[i-1]+ counter(i,burst-1,nums,dp)+counter(burst+1,j,nums,dp);
            maxi=max(maxi,coins);
        }

        return dp[i][j]=maxi;
        
    }
    int maxCoins(vector<int>& nums) {

          int n=nums.size();
          vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        nums.push_back(1);
       
        nums.insert(nums.begin(),1);
       
        return counter(1,n,nums,dp);
        
    }
};