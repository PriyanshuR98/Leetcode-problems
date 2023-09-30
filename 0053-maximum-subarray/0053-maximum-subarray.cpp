class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        long long int maxsum=-1e10;
        
        // maxsum=*min_element(nums.begin(),nums.end());
        
        int n=nums.size();
       long long  int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0)
            {
               
                sum=0;
                continue;
            }
            
            
        }
        
        return maxsum;

        
        
    }
};