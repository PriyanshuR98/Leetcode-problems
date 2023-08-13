class Solution {
public:
    bool checker(int index, vector<int>&nums, vector<int>&dp)
    {
        if(index<0)
        {
            return true;
        }
        
        if(index==0)
            
        {
            return false;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        bool op1=false;
        if(index-1>=0)
        {
            if( nums[index]==nums[index-1])
            {
                op1= checker(index-2,nums,dp);
    
            }
        }
        
        bool op2=false;
        
        if(index-2>=0)
        {
            if( nums[index]==nums[index-1] and nums[index-1]==nums[index-2])
            {
                op2= checker(index-3,nums,dp );
    
            }
        }
        
        bool op3=false;
        
          if(index-2>=0)
        {
            if( nums[index]-nums[index-1]==1 and nums[index-1]-nums[index-2]==1)
            {
                op3= checker(index-3,nums,dp );
    
            }
        }
        
        return  dp[index]= op1  or  op2 or op3;
        
                    
    }
    bool validPartition(vector<int>& nums) {
        
        int n= nums.size();
        vector<int>dp(n,-1);
        return checker(nums.size()-1,nums,dp);
        
    }
};