class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        // bitonic means either inc or dec or inc then dec
        int n=nums.size();
        vector<int>dp1(n,1);

        // dp1 is longest increasing subseq from left
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp1[j]+1>dp1[i])
                {
                    dp1[i]=dp1[j]+1;
                }
            }
        }

      // dp1 is longest inc subseq if we look from right.. ie longest dec subseq from left..
         vector<int>dp2(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j] and dp2[j]+1>dp2[i])
                {
                    dp2[i]=dp2[j]+1;
                }
            }
        }

        int maxi=0;

        for(int i=0;i<n;i++)
        {
            if(dp1[i]>1 and dp2[i]>1)  // as min length is req 3 as per ques.
            {
                maxi=max(maxi,dp1[i]+dp2[i]-1);
            }
        }

        return nums.size()-maxi;



        
    }
};